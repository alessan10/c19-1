package main

import (
	"encoding/json"
	"fmt"
	"io"
	"log"
	"math/rand"
	"net/http"
	"os"
	"strings" //per controllo errori

	"github.com/neo4j/neo4j-go-driver/neo4j"
)

// POST di un certo contatto che è diventato positivo.
// POST che uno specifico utente è guarito e si eliminano le relazioni (DELETE).
// GET di uno specifico utente e di tutti i suoi contatti (Python manda notifiche push ai suoi contatti)
// CREATE? --> ADD
// ADD al grafo di neo4j di una persona che avvia il bot telegram

type PatientResult struct {
	Patient `json:"patient"`
}

type Patient struct {
	Id      string `json:"id"`
	Name    string `json:"name,omitempty"`
	Surname string `json:"surname,omitempty"`
	Age     string `json:"age"`
	Chatid  string `json:"chatid"`
	Covid   string `json:"covid"`
	Year    string `json:"year"`
	Month   string `json:"month"`
	Day     string `json:"day"`
	WeekDay string `json:"weekday"`
	Country string `json:"country"`
}

type Neo4jConfiguration struct {
	Url      string
	Username string
	Password string
	Database string
}

func (nc *Neo4jConfiguration) newDriver() (neo4j.Driver, error) {
	unencrypted := func(conf *neo4j.Config) { conf.Encrypted = false }
	return neo4j.NewDriver(nc.Url, neo4j.BasicAuth(nc.Username, nc.Password, ""), unencrypted)
}

// func searchHandlerFunc(driver neo4j.Driver, database string) func(http.ResponseWriter, *http.Request) {
// 	return func(w http.ResponseWriter, req *http.Request) {
// 		w.Header().Set("Content-Type", "application/json")

// 		sessionConfig := neo4j.SessionConfig{AccessMode: neo4j.AccessModeRead}
// 		session, err := driver.NewSession(sessionConfig)
// 		if err != nil {
// 			log.Fatal(err)
// 		}

// 		defer session.Close()

// 		query := `MATCH (p1:Patient)
// 		where p1.name = "Adrian Weissnat"
// 		return p1.name as name, p1.chatid as chatid, p1.covid as covid`
// 		result, err := session.Run(query, map[string]interface{}{})
// 		if err != nil {
// 			log.Fatal(err)
// 		}

// 		fmt.Println("result :", result)

// 		var patientResults []PatientResult

// 		for result.Next() {
// 			record := result.Record()
// 			fmt.Println("record: ", record.GetByIndex(0))
// 			name, _ := record.Get("name")
// 			fmt.Println("name: ", name)
// 			chatid, _ := record.Get("chatid")
// 			fmt.Println("chatid: ", chatid)
// 			covid, _ := record.Get("covid")
// 			fmt.Println("covid: ", covid)
// 			patientResults = append(patientResults, PatientResult{Patient{
// 				Name:   name.(string),
// 				Chatid: chatid.(string),
// 				Covid:  covid.(string),
// 			}})
// 		}

// 		err = json.NewEncoder(w).Encode(patientResults)
// 		if err != nil {
// 			log.Println("error writing search response:", err)
// 		}
// 	}
// }

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

		log.Println("ecco il body SEARCH:", req.Body)

		query := `MATCH (p1:Patient)-[r:CONTACT]-(p2:Patient) 
					WHERE p1.name = $name OR p1.surname = $surname  									
					RETURN p2.id as id, p2.name as name, p2.surname as surname, p2.age as age, p2.chatid as chatid, p2.covid as covid, p2.year as year, p2.month as month, p2.day as day, p2.weekday as weekday, p2.country as country`
		result, err := session.Run(query, map[string]interface{}{
			"name":    req.URL.Query()["name"][0],
			"surname": req.URL.Query()["surname"][0],
		})
		if err != nil {
			log.Fatal(err)
		}

		fmt.Println("result :", result)

		var patientResults []PatientResult

		for result.Next() {
			record := result.Record()
			fmt.Println("record: ", record.GetByIndex(0))
			id, _ := record.Get("id")
			fmt.Println("id: ", id)
			name, _ := record.Get("name")
			fmt.Println("name: ", name)
			surname, _ := record.Get("surname")
			fmt.Println("surname: ", surname)
			age, _ := record.Get("age")
			fmt.Println("age: ", age)
			chatid, _ := record.Get("chatid")
			fmt.Println("chatid: ", chatid)
			covid, _ := record.Get("covid")
			fmt.Println("covid: ", covid)
			year, _ := record.Get("year")
			fmt.Println("year: ", year)
			month, _ := record.Get("month")
			fmt.Println("month: ", month)
			day, _ := record.Get("day")
			fmt.Println("day: ", day)
			weekday, _ := record.Get("weekday")
			fmt.Println("Day Of The Week: ", weekday)
			country, _ := record.Get("country")
			fmt.Println("country: ", country)

			patientResults = append(patientResults, PatientResult{Patient{
				Id:      id.(string),
				Name:    name.(string),
				Surname: surname.(string),
				Age:     age.(string),
				Chatid:  chatid.(string),
				Covid:   covid.(string),
				Year:    year.(string),
				Month:   month.(string),
				Day:     day.(string),
				WeekDay: weekday.(string),
				Country: country.(string),
			}})
		}

		err = json.NewEncoder(w).Encode(patientResults)
		if err != nil {
			log.Println("error writing search response:", err)
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

		query := `MATCH (p:Patient {name: $name, surname: $surname})
							SET p.covid = $covid
							RETURN p.name as name, p.chatid as chatid, p.covid as covid, p.weekday as weekday, p.day as day, p.month as month, p.year as year, p2.country as country, p2.age as age`

		// nameRegex := fmt.Sprintf("(?i).*%s.*", req.URL.Query()["q"][0])
		fmt.Println("URL name: ", req.URL.Query()["name"][0])
		fmt.Println("URL surname: ", req.URL.Query()["surname"][0])
		fmt.Println("URL covid: ", req.URL.Query()["covid"][0])
		// fmt.Println("nameRegex", nameRegex)
		result, err := session.Run(query, map[string]interface{}{
			"name":    req.URL.Query()["name"][0],
			"surname": req.URL.Query()["surname"][0],
			"covid":   req.URL.Query()["covid"][0],
		})
		if err != nil {
			log.Fatal(err)
		}

		fmt.Println("result :", result)

		var patientResults []PatientResult

		for result.Next() {
			record := result.Record()
			fmt.Println("record: ", record.GetByIndex(0))
			id, _ := record.Get("id")
			fmt.Println("id: ", id)
			name, _ := record.Get("name")
			fmt.Println("name: ", name)
			surname, _ := record.Get("surname")
			fmt.Println("surname: ", surname)
			age, _ := record.Get("age")
			fmt.Println("age: ", age)
			chatid, _ := record.Get("chatid")
			fmt.Println("chatid: ", chatid)
			covid, _ := record.Get("covid")
			fmt.Println("covid: ", covid)
			year, _ := record.Get("year")
			fmt.Println("year: ", year)
			month, _ := record.Get("month")
			fmt.Println("month: ", month)
			day, _ := record.Get("day")
			fmt.Println("day: ", day)
			weekday, _ := record.Get("weekday")
			fmt.Println("Day Of The Week: ", weekday)
			country, _ := record.Get("country")
			fmt.Println("country: ", country)

			patientResults = append(patientResults, PatientResult{Patient{
				Id:      id.(string),
				Name:    name.(string),
				Surname: surname.(string),
				Age:     age.(string),
				Chatid:  chatid.(string),
				Covid:   covid.(string),
				Year:    year.(string),
				Month:   month.(string),
				Day:     day.(string),
				WeekDay: weekday.(string),
				Country: country.(string),
			}})
		}

		err = json.NewEncoder(w).Encode(patientResults)
		if err != nil {
			log.Println("error writing search response:", err)
		}
	}
}

func healedHandlerFunc(driver neo4j.Driver, database string) func(http.ResponseWriter, *http.Request) {
	return func(w http.ResponseWriter, req *http.Request) {
		w.Header().Set("Content-Type", "application/json")

		sessionConfig := neo4j.SessionConfig{AccessMode: neo4j.AccessModeWrite}
		session, err := driver.NewSession(sessionConfig)
		if err != nil {
			log.Fatal(err)
		}
		fmt.Println("[ ENTRYPOINT ] : HEALED ")
		defer session.Close()

		query := `MATCH (p:Patient {name: $name})-[r:CONTACT]-()
									DELETE r
									SET p.covid = "healed"
									RETURN p.name as name, p.chatid as chatid, p.covid as covid, p.weekday as weekday, p.day as day, p.month as month, p.year as year, p.country as country, p.age as age`

		fmt.Println("URL name: ", req.URL.Query()["name"][0])
		result, err := session.Run(query, map[string]interface{}{
			"name": req.URL.Query()["name"][0],
		})
		if err != nil {
			log.Fatal(err)
		}

		fmt.Println("result :", result)

		var patientResults []PatientResult

		for result.Next() {
			record := result.Record()
			fmt.Println("record: ", record.GetByIndex(0))
			id, _ := record.Get("id")
			fmt.Println("id: ", id)
			name, _ := record.Get("name")
			fmt.Println("name: ", name)
			surname, _ := record.Get("surname")
			fmt.Println("surname: ", surname)
			age, _ := record.Get("age")
			fmt.Println("age: ", age)
			chatid, _ := record.Get("chatid")
			fmt.Println("chatid: ", chatid)
			covid, _ := record.Get("covid")
			fmt.Println("covid: ", covid)
			year, _ := record.Get("year")
			fmt.Println("year: ", year)
			month, _ := record.Get("month")
			fmt.Println("month: ", month)
			day, _ := record.Get("day")
			fmt.Println("day: ", day)
			weekday, _ := record.Get("weekday")
			fmt.Println("Day Of The Week: ", weekday)
			country, _ := record.Get("country")
			fmt.Println("country: ", country)

			patientResults = append(patientResults, PatientResult{Patient{
				Id:      id.(string),
				Name:    name.(string),
				Surname: surname.(string),
				Age:     age.(string),
				Chatid:  chatid.(string),
				Covid:   covid.(string),
				Year:    year.(string),
				Month:   month.(string),
				Day:     day.(string),
				WeekDay: weekday.(string),
				Country: country.(string),
			}})
		}

		err = json.NewEncoder(w).Encode(patientResults)
		if err != nil {
			log.Println("error writing search response:", err)
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

		log.Println("ecco il body ADD:", req.Body)
		decoder := json.NewDecoder(req.Body)
		var person Patient
		jsonerr := decoder.Decode(&person)
		if jsonerr != nil {
			panic(err)
		}

		log.Println("Id :", person.Id)
		log.Println("Nome :", person.Name)
		log.Println("Cognome :", person.Surname)
		log.Println("Age :", person.Age)
		log.Println("Chatid :", person.Chatid)
		log.Println("Covid :", person.Covid)
		log.Println("Year :", person.Year)
		log.Println("Month :", person.Month)
		log.Println("Day :", person.Day)
		log.Println("Day of the week :", person.WeekDay)
		log.Println("Country :", person.Country)

		//----CONTROLLO ERRRORI----

		checkName := strings.Compare(person.Name, "")
		checkSurname := strings.Compare(person.Surname, "")

		if checkName == 0 {
			fmt.Println("[MISSING]: NAME", checkName)
		} else if checkSurname == 0 {
			fmt.Println("[MISSING]: SURNAME", checkSurname)
		}

		//-----FINE----

		query1 := `MATCH (n) RETURN count(n) as count`
		result1, err1 := session.Run(query1, map[string]interface{}{})

		if err1 != nil {
			log.Fatal(err1)
		}

		fmt.Println("result1 :", result1)

		var cnt int64
		for result1.Next() {
			record := result1.Record()
			fmt.Println("record: ", record.GetByIndex(0))
			count, _ := record.Get("count")
			fmt.Println("count: ", count)
			cnt = count.(int64)

			fmt.Println(" count", cnt)
		}

		//prendo count, genero 5 un 0 < rnd() < count -> RND1, RND2, RND3, RND4, RND5
		var rnd [5]int64
		for i := 0; i < 5; i++ {
			rnd[i] = rand.Int63n(cnt)
			//64 bit perchè potenzialmente l'app deve funzionare con più di 9 miliardi di persone
			fmt.Println("rand: ", rnd[i])

		}

		// query2 := `MATCH (s) WHERE ID(s) IN [2, 5, 60, 80, 88] RETURN s`
		query2 := `MATCH (s) WHERE ID(s) IN [$rnd0, $rnd1, $rnd2, $rnd3, $rnd4] 
		RETURN s.id as id, s.name as name, s.surname as surname, s.age as age, s.chatid as chatid, s.covid as covid, s.year as year, s.month as month, s.day as day, s.weekday as weekday, s.country as country`

		result2, err2 := session.Run(query2, map[string]interface{}{
			"rnd0": rnd[0],
			"rnd1": rnd[1],
			"rnd2": rnd[2],
			"rnd3": rnd[3],
			"rnd4": rnd[4],
		})

		if err2 != nil {
			log.Fatal(err2)
		}

		fmt.Println("result2 :", result2)

		var patientResults []PatientResult

		for result2.Next() {
			record := result2.Record()
			fmt.Println("record: ", record.GetByIndex(0))
			id, _ := record.Get("id")
			fmt.Println("id: ", id)
			name, _ := record.Get("name")
			fmt.Println("name: ", name)
			surname, _ := record.Get("surname")
			fmt.Println("surname: ", surname)
			age, _ := record.Get("age")
			fmt.Println("age: ", age)
			chatid, _ := record.Get("chatid")
			fmt.Println("chatid: ", chatid)
			covid, _ := record.Get("covid")
			fmt.Println("covid: ", covid)
			year, _ := record.Get("year")
			fmt.Println("year: ", year)
			month, _ := record.Get("month")
			fmt.Println("month: ", month)
			day, _ := record.Get("day")
			fmt.Println("day: ", day)
			weekday, _ := record.Get("weekday")
			fmt.Println("Day Of The Week: ", weekday)
			country, _ := record.Get("country")
			fmt.Println("country: ", country)

			patientResults = append(patientResults, PatientResult{Patient{
				Id:      id.(string),
				Name:    name.(string),
				Surname: surname.(string),
				Age:     age.(string),
				Chatid:  chatid.(string),
				Covid:   covid.(string),
				Year:    year.(string),
				Month:   month.(string),
				Day:     day.(string),
				WeekDay: weekday.(string),
				Country: country.(string),
			}})
		}

		// query3 := `MATCH (u:User {username:'admin'}), (r:Role {name:'ROLE_WEB_USER'})
		// CREATE (u)-[:HAS_ROLE]->(r)`

		query3 := `CREATE (p:Patient { id: $id name: $name, surname: $surname, age: $age, chatid: $chatid, covid: $covid, year: $year, month: $month, day: $day, weekday: $weekday, country: $country })
							RETURN p.name as name`
		result3, err3 := session.Run(query3, map[string]interface{}{
			"id":      person.Id,
			"name":    person.Name,
			"surname": person.Surname,
			"age":     person.Age,
			"chatid":  person.Chatid,
			"covid":   person.Covid,
			"year":    person.Year,
			"month":   person.Month,
			"day":     person.Day,
			"weekday": person.WeekDay,
			"country": person.Country,
		})

		if err3 != nil {
			log.Fatal(err3)
		}

		fmt.Println("result3 :", result3)
		//FUNZIONAAAAA -->
		// query4 := `MATCH (a:Patient),(b:Patient)
		// WHERE a.name = $name0 AND b.name = $name_new
		// CREATE (a)-[r:CONTACT]->(b)
		// RETURN type(r)`

		query4 := `MATCH (a:Patient),(b:Patient) WHERE a.name = $name0 AND b.name = $name_new CREATE (a)-[r:CONTACT]->(b) RETURN type(r)
		UNION
		MATCH (a:Patient),(b:Patient) WHERE a.name = $name1 AND b.name = $name_new CREATE (a)-[r:CONTACT]->(b) RETURN type(r)
		UNION
		MATCH (a:Patient),(b:Patient) WHERE a.name = $name2 AND b.name = $name_new CREATE (a)-[r:CONTACT]->(b) RETURN type(r)
		UNION
		MATCH (a:Patient),(b:Patient) WHERE a.name = $name3 AND b.name = $name_new CREATE (a)-[r:CONTACT]->(b) RETURN type(r)
		UNION
		MATCH (a:Patient),(b:Patient) WHERE a.name = $name4 AND b.name = $name_new CREATE (a)-[r:CONTACT]->(b) RETURN type(r)`

		fmt.Println("patientResults[0].Name:", patientResults[0].Name)
		fmt.Println("name_new:", person.Name)
		result4, err4 := session.Run(query4, map[string]interface{}{
			"name0":    patientResults[0].Name,
			"name1":    patientResults[1].Name,
			"name2":    patientResults[2].Name,
			"name3":    patientResults[3].Name,
			"name4":    patientResults[4].Name,
			"name_new": person.Name,
		})

		if err4 != nil {
			log.Fatal(err4)
		}

		fmt.Println("result4 :", result4)

		err5 := json.NewEncoder(w).Encode(patientResults)
		if err5 != nil {
			log.Println("error writing search response:", err5)
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

		log.Println("ecco il body GRAPH:", req.Body)

		query := `MATCH (p1:Patient) 
		RETURN p1.id as id, p1.name as name, p1.surname as surname, p1.age as age p1.chatid as chatid, p1.covid as covid, p1.year as year, p1.month as month, p1.day as day, p1.weekday as weekday, p1.country as country`

		result, err := session.Run(query, map[string]interface{}{})
		if err != nil {
			log.Fatal(err)
		}

		fmt.Println("result :", result)

		var patientResults []PatientResult

		for result.Next() {
			record := result.Record()
			fmt.Println("record: ", record.GetByIndex(0))
			id, _ := record.Get("id")
			fmt.Println("id: ", id)
			name, _ := record.Get("name")
			fmt.Println("name: ", name)
			surname, _ := record.Get("surname")
			fmt.Println("surname: ", surname)
			age, _ := record.Get("age")
			fmt.Println("age: ", age)
			chatid, _ := record.Get("chatid")
			fmt.Println("chatid: ", chatid)
			covid, _ := record.Get("covid")
			fmt.Println("covid: ", covid)
			year, _ := record.Get("year")
			fmt.Println("year: ", year)
			month, _ := record.Get("month")
			fmt.Println("month: ", month)
			day, _ := record.Get("day")
			fmt.Println("day: ", day)
			weekday, _ := record.Get("weekday")
			fmt.Println("Day Of The Week: ", weekday)
			country, _ := record.Get("country")
			fmt.Println("country: ", country)

			patientResults = append(patientResults, PatientResult{Patient{
				Id:      id.(string),
				Name:    name.(string),
				Surname: surname.(string),
				Age:     age.(string),
				Chatid:  chatid.(string),
				Covid:   covid.(string),
				Year:    year.(string),
				Month:   month.(string),
				Day:     day.(string),
				WeekDay: weekday.(string),
				Country: country.(string),
			}})
		}

		err = json.NewEncoder(w).Encode(patientResults)
		if err != nil {
			log.Println("error writing search response:", err)
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

		query := `MATCH (p:Patient) WHERE p.name = $name OR p.surname = $surname 
					DETACH DELETE p`

		fmt.Println("URL name: ", req.URL.Query()["name"][0])
		fmt.Println("URL surname: ", req.URL.Query()["surname"][0])
		result, err := session.Run(query, map[string]interface{}{
			"name":    req.URL.Query()["name"][0],
			"surname": req.URL.Query()["surname"][0],
		})
		if err != nil {
			log.Fatal(err)
		}

		fmt.Println("result :", result)

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

	serveMux := http.NewServeMux()
	//serveMux.HandleFunc("/", defaultHandler)
	//serveMux.HandleFunc("/search", searchHandlerFunc(driver, configuration.Database)) //GET di prova, inutile
	serveMux.HandleFunc("/update", updateHandlerFunc(driver, configuration.Database)) // UPDATE --c19positive
	serveMux.HandleFunc("/healed", healedHandlerFunc(driver, configuration.Database)) // DELETE --c19healed
	serveMux.HandleFunc("/add", addHandlerFunc(driver, configuration.Database))       // ADD
	serveMux.HandleFunc("/graph", graphHandlerFunc(driver, configuration.Database))   // RETURN ALL GRAPH
	serveMux.HandleFunc("/search", searchHandlerFunc(driver, configuration.Database)) // SEARCH A Patient and all of its DATA
	serveMux.HandleFunc("/delete", deleteHandlerFunc(driver, configuration.Database)) // DELETE PERSON

	var port string
	var found bool
	if port, found = os.LookupEnv("PORT"); !found {
		port = "8081"
	}
	panic(http.ListenAndServe(":"+port, serveMux))
	//panic(http.ListenAndServe(":"+port, httpgzip.NewHandler(serveMux)))
}

func parseConfiguration() *Neo4jConfiguration {
	return &Neo4jConfiguration{
		Url:      lookupEnvOrGetDefault("NEO4J_URI", "bolt://localhost:7687"),
		Username: lookupEnvOrGetDefault("NEO4J_USER", "neo4j"),
		Password: lookupEnvOrGetDefault("NEO4J_PASSWORD", "c19"),
		Database: lookupEnvOrGetDefault("NEO4J_DATABASE", "c19"),
	}
}

func lookupEnvOrGetDefault(key string, defaultValue string) string {
	if env, found := os.LookupEnv(key); !found {
		return defaultValue
	} else {
		return env
	}
}

func unsafeClose(closeable io.Closer) {
	if err := closeable.Close(); err != nil {
		log.Fatal(fmt.Errorf("could not close resource: %w", err))
	}
}
