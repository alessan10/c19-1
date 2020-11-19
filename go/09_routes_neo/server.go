package main

import (
	"encoding/json"
	"fmt"
	"io"
	"log"
	"net/http"
	"os"

	"github.com/neo4j/neo4j-go-driver/neo4j"

	httpgzip "github.com/daaku/go.httpgzip"
)

// POST di un certo contatto che è diventato positivo.
// POST che uno specifico utente è guarito e si eliminano le relazioni (DELETE).
// GET di uno specifico utente e di tutti i suoi contatti (Python manda notifiche push ai suoi contatti)
// CREATE?

type CPersonResult struct {
	CPerson `json:"cperson"`
}

type CPerson struct {
	Chatid string `json:"chatid"`
	Name   string `json:"name,omitempty"`
	Covid  string `json:"covid"`
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

func searchHandlerFunc(driver neo4j.Driver, database string) func(http.ResponseWriter, *http.Request) {
	return func(w http.ResponseWriter, req *http.Request) {
		w.Header().Set("Content-Type", "application/json")

		sessionConfig := neo4j.SessionConfig{AccessMode: neo4j.AccessModeRead}
		session, err := driver.NewSession(sessionConfig)
		if err != nil {
			log.Fatal(err)
		}

		defer session.Close()

		query := `MATCH (p1:CPerson)
		where p1.name = "Alessandro Mauro" 
		return p1.name as name, p1.chatid as chatid`
		result, err := session.Run(query, map[string]interface{}{})
		if err != nil {
			log.Fatal(err)
		}

		fmt.Println("result :", result)

		var cpersonResults []CPersonResult

		for result.Next() {
			record := result.Record()
			fmt.Println("record: ", record.GetByIndex(0))
			name, _ := record.Get("name")
			fmt.Println("name: ", name)
			chatid, _ := record.Get("chatid")
			fmt.Println("chatid: ", chatid)
			covid, _ := record.Get("covid")
			fmt.Println("covid: ", covid)
			cpersonResults = append(cpersonResults, CPersonResult{CPerson{
				Name:   name.(string),
				Chatid: chatid.(string),
				Covid:  covid.(string),
			}})
		}

		err = json.NewEncoder(w).Encode(cpersonResults)
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
		fmt.Println("sono nell'UPDATE")
		defer session.Close()

		query := `MATCH (p:CPerson {name: $name})
							SET p.covid = $covid
							RETURN p.name as name, p.chatid as chatid, p.covid as covid`

		// nameRegex := fmt.Sprintf("(?i).*%s.*", req.URL.Query()["q"][0])
		fmt.Println("URL name: ", req.URL.Query()["name"][0])
		fmt.Println("URL covid: ", req.URL.Query()["covid"][0])
		// fmt.Println("nameRegex", nameRegex)
		result, err := session.Run(query, map[string]interface{}{
			"name":  req.URL.Query()["name"][0],
			"covid": req.URL.Query()["covid"][0],
		})
		if err != nil {
			log.Fatal(err)
		}

		fmt.Println("result :", result)

		var cpersonResults []CPersonResult

		for result.Next() {
			record := result.Record()
			fmt.Println("record: ", record.GetByIndex(0))
			name, _ := record.Get("name")
			fmt.Println("name: ", name)
			chatid, _ := record.Get("chatid")
			fmt.Println("chatid: ", chatid)
			covid, _ := record.Get("covid")
			fmt.Println("covid: ", covid)
			cpersonResults = append(cpersonResults, CPersonResult{CPerson{
				Name:   name.(string),
				Chatid: chatid.(string),
				Covid:  covid.(string),
			}})
		}

		err = json.NewEncoder(w).Encode(cpersonResults)
		if err != nil {
			log.Println("error writing search response:", err)
		}
	}
}

func main() {

	configuration := parseConfiguration()
	driver, err := configuration.newDriver()
	if err != nil {
		log.Fatal(err)
	}
	fmt.Println("sono dentro")
	defer unsafeClose(driver)

	serveMux := http.NewServeMux()
	//serveMux.HandleFunc("/", defaultHandler)
	serveMux.HandleFunc("/search", searchHandlerFunc(driver, configuration.Database)) //GET
	serveMux.HandleFunc("/update", updateHandlerFunc(driver, configuration.Database)) //UPDATE
	//serveMux.HandleFunc("/create", createHandler(driver, configuration.Database))
	//serveMux.HandleFunc("/graph", graphHandler(driver, configuration.Database))
	var port string
	var found bool
	if port, found = os.LookupEnv("PORT"); !found {
		port = "8081"
	}
	panic(http.ListenAndServe(":"+port, httpgzip.NewHandler(serveMux)))
}

func parseConfiguration() *Neo4jConfiguration {
	return &Neo4jConfiguration{
		Url:      lookupEnvOrGetDefault("NEO4J_URI", "bolt://localhost:7687"),
		Username: lookupEnvOrGetDefault("NEO4J_USER", "neo4j"),
		Password: lookupEnvOrGetDefault("NEO4J_PASSWORD", "movies"),
		Database: lookupEnvOrGetDefault("NEO4J_DATABASE", "movies"),
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
