package main

import "github.com/neo4j/neo4j-go-driver/neo4j"

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

func resultToPatientsArray(result* neo4j.Result)  (patientResult* []PatientResult){

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
			Id: 	 id.(string),
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
