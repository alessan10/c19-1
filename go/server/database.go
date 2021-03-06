package main

import (
	"os"

	"github.com/neo4j/neo4j-go-driver/neo4j"
)

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

func resultToPatientsArray(result *neo4j.Result) (patientResult *[]PatientResult) {

	var patientResults []PatientResult

	for (*result).Next() {
		record := (*result).Record()
		id, _ := record.Get("id")
		name, _ := record.Get("name")
		surname, _ := record.Get("surname")
		age, _ := record.Get("age")
		chatid, _ := record.Get("chatid")
		covid, _ := record.Get("covid")
		year, _ := record.Get("year")
		month, _ := record.Get("month")
		day, _ := record.Get("day")
		weekday, _ := record.Get("weekday")
		country, _ := record.Get("country")

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
	return &patientResults

}
