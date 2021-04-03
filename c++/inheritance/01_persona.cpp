#include <iostream>
#include <string.h>
using namespace std;


class Persona
{
	private:
		string nome, cognome;
		int eta;
	public:
		Persona(string n, string s, int eta): nome(n), cognome(s), eta(eta){};
		void stampaNome();
		void stampaCognome();
		void stampaEta();
};
/*
Persona::Persona(string nome, string cognome, int eta)
{
	this->nome = nome;
	this->cognome = cognome;
  this->eta = eta;
}
*/


void Persona::stampaNome()
{
	cout <<"Il mio nome e' : " << nome << endl;
}

void Persona::stampaCognome()
{
	cout <<"Il mio cognome e' :" << cognome << endl;
}

void Persona::stampaEta()
{
	cout <<"La mia eta' e': " << eta << endl;
}
int main()
{
  Persona p = Persona("Andrea", "Calabretta", 33);
	p.stampaNome();
	p.stampaEta();
	cout << "Hello world!" << endl;
}
