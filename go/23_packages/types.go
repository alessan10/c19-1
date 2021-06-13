package main


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
