package main

import (
	"encoding/json"
	"fmt"
	"github.com/neo4j/neo4j-go-driver/neo4j"
	"io"
	"log"
	"math/rand"
	"net/http"
	"os"
	"strconv"
	"strings" //per controllo errori
)


func simpleSearchHandlerFunc(driver neo4j.Driver, database string) func(http.ResponseWriter, *http.Request) {
	return func(w http.ResponseWriter, req *http.Request) {
		w.Header().Set("Content-Type", "application/json")

		sessionConfig := neo4j.SessionConfig{AccessMode: neo4j.AccessModeRead}
		session, err := driver.NewSession(sessionConfig)
		if err != nil {
			log.Fatal(err)
		}
		fmt.Println("[ ENTRYPOINT ] : SEARCH PERSON WITHOUT RELATIONS ")
		defer session.Close()

		query := `MATCH (p:Patient) 
						WHERE p.name = $name AND p.surname = $surname
						RETURN p.name as name, p.surname as surname, p.age as age, p.covid as covid, p.year as year, p.month as month, p.day as day, p.weekday as weekday, p.country as country`

		result, err := session.Run(query, map[string]interface{}{
			"name":    req.URL.Query()["name"][0],
			"surname": req.URL.Query()["surname"][0],
		})

		if err != nil {
			log.Fatal(err)
		}

		patientsArray := *resultToPatientsArray(&result)

		if len(patientsArray) == 0 {
			http.Error(w, "Error: Person not fount", http.StatusNotFound)
		} else {
			err = json.NewEncoder(w).Encode(patientsArray)
			fmt.Println("ENCODED: ", patientsArray)
		}
	}
}

func searchHandlerFunc(driver neo4j.Driver, database string) func(http.ResponseWriter, *http.Request) {

	return func(w http.ResponseWriter, req *http.Request) {
		w.Header().Set("Content-Type", "application/json")

		sessionConfig := neo4j.SessionConfig{AccessMode: neo4j.AccessModeRead}
		session, err := driver.NewSession(sessionConfig)
		if err != nil {
			log.Fatal(err)
		}
		fmt.Println("[ ENTRYPOINT ] : SEARCH ")
		defer session.Close()

		query := `MATCH (p1:Patient)-[r:CONTACT]-(p2:Patient) 
					WHERE p1.name = $name AND p1.surname = $surname  									
					RETURN p2.id as id, p2.name as name, p2.surname as surname, p2.age as age, p2.chatid as chatid, p2.covid as covid, p2.year as year, p2.month as month, p2.day as day, p2.weekday as weekday, p2.country as country`
		result, err := session.Run(query, map[string]interface{}{
			"name":    req.URL.Query()["name"][0],
			"surname": req.URL.Query()["surname"][0],
		})
		if err != nil {
			log.Fatal(err)
		}

		patientsArray := *resultToPatientsArray(&result)

		if len(patientsArray) == 0 {
			http.Error(w, "Error: Patient not found", http.StatusNotFound)

		} else {
			fmt.Println("ENCODED: ", patientsArray)
			err = json.NewEncoder(w).Encode(patientsArray)
		}
	}
}

func updateHandlerFunc(driver neo4j.Driver, database string) func(http.ResponseWriter, *http.Request) {
	return func(w http.ResponseWriter, req *http.Request) {
		w.Header().Set("Content-Type", "application/json")

		sessionConfig := neo4j.SessionConfig{AccessMode: neo4j.AccessModeWrite}
		session, err := driver.NewSession(sessionConfig)
		if err != nil {
			log.Fatal(err)
		}
		fmt.Println("[ ENTRYPOINT ] : UPDATE ")
		defer session.Close()

		decoder := json.NewDecoder(req.Body)
		var patient Patient
		jsonerr := decoder.Decode(&patient)
		if jsonerr != nil {
			panic(err)
		}

		query := `MATCH (p:Patient) WHERE p.name = $old_name AND p.surname = $old_surname
							SET p.name = $name, p.surname = $surname, p.age = $age, p.covid = $covid, p.year = $year, p.month = $month, p.day = $day, p.weekday = $weekday, p.country = $country
							RETURN p.name as name, p.surname as surname, p.age as age, p.covid as covid, p.year as year, p.month as month, p.day as day, p.weekday as weekday, p.country as country`

		fmt.Println("URL old_name: ", req.URL.Query()["old_name"][0])
		fmt.Println("URL old_surname: ", req.URL.Query()["old_surname"][0])

		result, err := session.Run(query, map[string]interface{}{
			"old_name":    req.URL.Query()["old_name"][0],
			"old_surname": req.URL.Query()["old_surname"][0],
			"name":        patient.Person.Name,
			"surname":     patient.Person.Surname,
			"age":         patient.Person.Age,
			"country":     patient.Person.Country,
			"year":        patient.Date.Year,
			"month":       patient.Date.Month,
			"day":         patient.Date.Day,
			"weekday":     patient.Date.WeekDay,
			"covid":       patient.Date,
		})
		if err != nil {
			log.Fatal(err)
		}

		patientsArray := *resultToPatientsArray(&result)

		if len(patientsArray) == 0 {
			http.Error(w, "Error: Patient not found", http.StatusNotFound)
		} else {
			fmt.Println("UPDATED CORRECTLY: ", patientsArray)
			err = json.NewEncoder(w).Encode(patientsArray)
		}
	}
}

func addHandlerFunc(driver neo4j.Driver, database string) func(http.ResponseWriter, *http.Request) {
	return func(w http.ResponseWriter, req *http.Request) {
		w.Header().Set("Content-Type", "application/json")

		sessionConfig := neo4j.SessionConfig{AccessMode: neo4j.AccessModeWrite}
		session, err := driver.NewSession(sessionConfig)
		if err != nil {
			log.Fatal(err)
		}
		fmt.Println("[ ENTRYPOINT ] : ADD ")
		defer session.Close()

		decoder := json.NewDecoder(req.Body)
		var patient Patient
		jsonerr := decoder.Decode(&patient)
		if jsonerr != nil {
			panic(err)
		}

		//----CONTROLLO ERRRORI----

		checkName := strings.Compare(patient.Person.Name, "")
		checkSurname := strings.Compare(patient.Person.Name, "")

		if checkName == 0 || checkSurname == 0 {
			http.Error(w, "Error: Missing Name or Surname ", http.StatusBadRequest)
		} else {

			query1 := `MATCH (n) RETURN count(n) as count`
			result1, err1 := session.Run(query1, map[string]interface{}{})

			if err1 != nil {
				log.Fatal(err1)
			}

			var cnt int64
			for result1.Next() {
				record := result1.Record()
				count, _ := record.Get("count")
				cnt = count.(int64)
				fmt.Println("DB ENTRIES COUNTER: ", cnt)
			}

			//prendo count, genero 5 un 0 < rnd() < count -> RND1, RND2, RND3, RND4, RND5
			var rnd [5]int64
			var rndStr [5]string
			for i := 0; i < 5; i++ {
				rnd[i] = rand.Int63n(cnt)
				//converto in 64 bit
				rndStr[i] = strconv.FormatInt(rnd[i], 10)
				rndStr[i] = PadLeft(rndStr[i], "0", 3)
				//fmt.Println("rand: ", rnd[i]) deve essere uguale a quello di sotto
				//fmt.Println("rndStr: ", rndStr[i])
			}

			//prendo 5 pazienti random dal grafo
			query2 := `MATCH (n) WHERE n.id IN [$rndStr0, $rndStr1, $rndStr2, $rndStr3, $rndStr4] 
						RETURN n.id as id, n.name as name, n.surname as surname, n.age as age, n.chatid as chatid, n.covid as covid, n.year as year, n.month as month, n.day as day, n.weekday as weekday, n.country as country`

			result2, err2 := session.Run(query2, map[string]interface{}{
				"rndStr0": rndStr[0],
				"rndStr1": rndStr[1],
				"rndStr2": rndStr[2],
				"rndStr3": rndStr[3],
				"rndStr4": rndStr[4],
			})

			if err2 != nil {
				log.Fatal(err2)
			}

			patientsArray := *resultToPatientsArray(&result2)

			if len(patientsArray) == 0 {
				log.Println("Error QUERY 2: empty response: ", err)
			} else {
				fmt.Println("ENCODED: ", patientsArray)
			}

			new_id := cnt + 1
			fmt.Println("NEW ID: ", new_id)
			stringID := strconv.Itoa(int(new_id))

			//creo il nuovo paziente inizialmente come nodo isolato
			query3 := `CREATE (p:Patient {id: $id, name: $name, surname: $surname, age: $age, chatid: $chatid, covid: $covid, year: $year, month: $month, day: $day, weekday: $weekday, country: $country })
							RETURN p.id as id, p.name as name, p.surname as surname, p.age as age, p.chatid as chatid, p.covid as covid, p.year as year, p.month as month, p.day as day, p.weekday as weekday, p.country as country`
			result3, err3 := session.Run(query3, map[string]interface{}{
				"id":      stringID,
				"name":    patient.Person.Name,
				"surname": patient.Person.Surname,
				"age":     patient.Person.Age,
				"chatid":  patient.Person.ChatId,
				"covid":   patient.Covid,
				"year":    patient.Date.Year,
				"month":   patient.Date.Month,
				"day":     patient.Date.Day,
				"weekday": patient.Date.WeekDay,
				"country": patient.Person.Country,
			})

			if err3 != nil {
				log.Fatal(err3)
				fmt.Println("QUERY 3 ISSUE: ", result3)
			}

			//collego il nuovo paziente appena creato ai 5 pazienti random presi precedentemente dal grafo
			query4 := `MATCH (a:Patient),(b:Patient) WHERE a.name = $name0 AND b.name = $name_new CREATE (a)-[r:CONTACT]->(b) RETURN type(r)
		UNION
		MATCH (a:Patient),(b:Patient) WHERE a.name = $name1 AND b.name = $name_new CREATE (a)-[r:CONTACT]->(b) RETURN type(r)
		UNION
		MATCH (a:Patient),(b:Patient) WHERE a.name = $name2 AND b.name = $name_new CREATE (a)-[r:CONTACT]->(b) RETURN type(r)
		UNION
		MATCH (a:Patient),(b:Patient) WHERE a.name = $name3 AND b.name = $name_new CREATE (a)-[r:CONTACT]->(b) RETURN type(r)
		UNION
		MATCH (a:Patient),(b:Patient) WHERE a.name = $name4 AND b.name = $name_new CREATE (a)-[r:CONTACT]->(b) RETURN type(r)`

			fmt.Printf("NEW PATIENT (ID: %v) linked with below patient: \n", new_id)
			fmt.Printf("ID[0]: %v,\nID[1]: %v,\nID[2]: %v,\nID[3]: %v,\nID[4]: %v\n",
				patientsArray[0].Patient.Person.Id,
				patientsArray[1].Patient.Person.Id,
				patientsArray[2].Patient.Person.Id,
				patientsArray[3].Patient.Person.Id,
				patientsArray[4].Patient.Person.Id)

			result4, err4 := session.Run(query4, map[string]interface{}{
				"name0":    patientsArray[0].Patient.Person.Name,
				"name1":    patientsArray[1].Patient.Person.Name,
				"name2":    patientsArray[2].Patient.Person.Name,
				"name3":    patientsArray[3].Patient.Person.Name,
				"name4":    patientsArray[4].Patient.Person.Name,
				"name_new": patient.Person.Name,
			})

			if err4 != nil {
				log.Fatal(err4)
				fmt.Println("QUERY 4 ISSUE: ", result4)
			}

			err5 := json.NewEncoder(w).Encode(patientsArray)
			if err5 != nil {
				log.Println("error writing search response:", err5)
			}
		}
	}
}

func graphHandlerFunc(driver neo4j.Driver, database string) func(http.ResponseWriter, *http.Request) {
	return func(w http.ResponseWriter, req *http.Request) {
		w.Header().Set("Content-Type", "application/json")
		w.Header().Set("Access-Control-Allow-Origin", "*")

		sessionConfig := neo4j.SessionConfig{AccessMode: neo4j.AccessModeRead}
		session, err := driver.NewSession(sessionConfig)
		if err != nil {
			log.Fatal(err)
		}
		fmt.Println("[ ENTRYPOINT ] : GRAPH ")
		defer session.Close()

		query := `MATCH (p1:Patient) 
		RETURN p1.id as id, p1.name as name, p1.surname as surname, p1.age as age, p1.chatid as chatid, p1.covid as covid, p1.year as year, p1.month as month, p1.day as day, p1.weekday as weekday, p1.country as country`

		result, err := session.Run(query, map[string]interface{}{})
		if err != nil {
			log.Fatal(err)
		}

		patientsArray := *resultToPatientsArray(&result)

		if len(patientsArray) == 0 {
			http.Error(w, "Graph is empty", http.StatusOK)

		} else {
			err = json.NewEncoder(w).Encode(patientsArray)
			fmt.Printf("ENCODED: %v and counting...", patientsArray[0])
		}

	}

}

func deleteHandlerFunc(driver neo4j.Driver, database string) func(http.ResponseWriter, *http.Request) {
	return func(w http.ResponseWriter, req *http.Request) {
		w.Header().Set("Content-Type", "application/json")

		sessionConfig := neo4j.SessionConfig{AccessMode: neo4j.AccessModeWrite}
		session, err := driver.NewSession(sessionConfig)
		if err != nil {
			log.Fatal(err)
		}
		fmt.Println("[ ENTRYPOINT ] : DELETE ")
		defer session.Close()

		query := `MATCH (p:Patient) 
						WHERE p.name = $name AND p.surname = $surname
						RETURN p.name as name, p.surname as surname, p.age as age, p.covid as covid, p.year as year, p.month as month, p.day as day, p.weekday as weekday, p.country as country`

		result, err := session.Run(query, map[string]interface{}{
			"name":    req.URL.Query()["name"][0],
			"surname": req.URL.Query()["surname"][0],
		})

		if err != nil {
			log.Fatal(err)
		}

		patientsArray := *resultToPatientsArray(&result)

		if len(patientsArray) == 0 {
			http.Error(w, "Error: Person not fount", http.StatusNotFound)
		} else {
			query := `MATCH (p:Patient) WHERE p.name = $name AND p.surname = $surname 
					DETACH DELETE p`

			result, err := session.Run(query, map[string]interface{}{
				"name":    req.URL.Query()["name"][0],
				"surname": req.URL.Query()["surname"][0],
			})
			if err != nil {
				log.Fatal(err)
			}
			err = json.NewEncoder(w).Encode(patientsArray)
			fmt.Printf("DELETED: \n")
			fmt.Println("result :", result)
			fmt.Println("URL name: ", req.URL.Query()["name"][0])
			fmt.Println("URL surname: ", req.URL.Query()["surname"][0])
		}

	}
}

func main() {

	configuration := parseConfiguration()
	driver, err := configuration.newDriver()
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("[ SERVER ] : UP ")
	defer unsafeClose(driver)

	/*
	ServeMux is an HTTP request multiplexer.
	It matches the URL of each incoming request against a list of registered patterns and calls the handler for the pattern
	that most closely matches the URL.
	 */
	serveMux := http.NewServeMux() //NewServeMux allocates and returns a new ServeMux.

	// HandleFunc registers the handler function for the given pattern.
	serveMux.HandleFunc("/update", updateHandlerFunc(driver, configuration.Database))             // UPDATE --c19positive
	serveMux.HandleFunc("/add", addHandlerFunc(driver, configuration.Database))                   // ADD
	serveMux.HandleFunc("/graph", graphHandlerFunc(driver, configuration.Database))               // RETURN ALL GRAPH
	serveMux.HandleFunc("/search", searchHandlerFunc(driver, configuration.Database))             // SEARCH A Patient and all of its DATA
	serveMux.HandleFunc("/delete", deleteHandlerFunc(driver, configuration.Database))             // DELETE PERSON
	serveMux.HandleFunc("/simplesearch", simpleSearchHandlerFunc(driver, configuration.Database)) // search a person without relations (for update purpose)

	var port string
	var found bool
	if port, found = os.LookupEnv("PORT"); !found {
		port = "8081"
	}
	panic(http.ListenAndServe(":"+port, serveMux))

}


func unsafeClose(closeable io.Closer) {
	if err := closeable.Close(); err != nil {
		log.Fatal(fmt.Errorf("could not close resource: %w", err))
	}
}

//to add padding in ID when created by the client
func PadLeft(str, pad string, lenght int) string {
	for len(str) < lenght {
		str = pad + str
	}
	return str[0:lenght]
}



