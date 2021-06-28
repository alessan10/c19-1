package main


type PatientResult struct {
	Patient Patient `json:"patient"`

}

type PatientResultPlain struct {
	Id      string 	`json:"id"`
	Name    string	`json:"name"`
	Surname string	`json:"surname"`
	Age     string	`json:"age"`
	Country string	`json:"country"`
	Year 	string 	`json:"year"`
	Month	string 	`json:"month"`
	Day 	string	`json:"day"`
	WeekDay string	`json:"weekday"`
	ChatId  string	`json:"chatId"`
	Covid   string	`json:"covid"`
}

type Date struct {
	Year 	string 	`json:"year"`
	Month	string 	`json:"month"`
	Day 	string	`json:"day"`
	WeekDay string	`json:"weekday"`
}

type Person struct {
	Id      string 	`json:"id"`
	ChatId  string	`json:"chatId"`
	Name    string	`json:"name"`
	Surname string	`json:"surname"`
	Age     string	`json:"age"`
	Country string	`json:"country"`
}

type Patient struct {
	Person 	Person	`json:"person"`
	Date 	Date	`json:"date"`
	Covid   string	`json:"covid"`
}


