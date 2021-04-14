#include "persona.hh"

Persona::Persona(string nome, string cognome){
	this->nome = nome;
	this->cognome = cognome;
}

void Persona::stampaNome(){
	cout <<"Il mio nome e' : " << nome << endl;
}

void Persona::stampaCognome(){
	cout <<"Il mio cognome e' :" << cognome << endl;
}

int main(){
	cout <<"hello" << endl;
}
