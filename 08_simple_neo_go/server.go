package main

import (
	"fmt"
	"log"

	"github.com/neo4j/neo4j-go-driver/neo4j"
)

func main() {
	// configForNeo4j35 := func(conf *neo4j.Config) {}
	configForNeo4j40 := func(conf *neo4j.Config) { conf.Encrypted = false }

	driver, err := neo4j.NewDriver("bolt://localhost:7687", neo4j.BasicAuth("neo4j", "movies", ""), configForNeo4j40)
	if err != nil {
		log.Fatal(err)
	}
	// handle driver lifetime based on your application lifetime requirements
	// driver's lifetime is usually bound by the application lifetime, which usually implies one driver instance per application
	defer driver.Close()

	// For multidatabase support, set sessionConfig.DatabaseName to requested database
	sessionConfig := neo4j.SessionConfig{AccessMode: neo4j.AccessModeRead}
	//AccessModeWrite
	session, err := driver.NewSession(sessionConfig)
	if err != nil {
		log.Fatal(err)
	}
	defer session.Close()

	// query := `CREATE (n:Item { id: $id, name: $name })
	// 					RETURN n.id, n.name`
	// result, err := session.Run(query, map[string]interface{}{
	// 	"id":   1,
	// 	"name": "Item 1",
	// })

	// query := `CREATE (am:CPerson {name: "Alessandro Mauro", chatid: "64597991" }),
	// 					(ac:CPerson {name: "Andrea Calabretta", chatid: "148043746" }),
	// 					(mr:CPerson {name: "Mario Rossi", chatid: "0000"}),
	// 					(pb:CPerson {name: "Paolo Bianchi", chatid: "0001"}),
	// 					(av:CPerson {name: "Antonio Verdi", chatid: "0002"}),
	// 					(mp:CPerson {name: "Marco Pappalardo", chatid: "0003"}),
	// 					(am)-[:CONTACT]->(ac),
	// 					(am)-[:CONTACT]->(mr),
	// 					(am)-[:CONTACT]->(pb),
	// 					(av)-[:CONTACT]->(ac),
	// 					(pb)-[:CONTACT]->(mp)`

	query := `MATCH (p1:CPerson)
						where p1.name = "Alessandro Mauro" 
						return p1.name as name, p1.chatid as chatid`
	result, err := session.Run(query, map[string]interface{}{})
	if err != nil {
		log.Fatal(err)
	}

	fmt.Println("result :", result)

	for result.Next() {
		record := result.Record()
		fmt.Println("record: ", record.GetByIndex(0))
		name, _ := record.Get("name")
		fmt.Println("name: ", name)
	}
}
