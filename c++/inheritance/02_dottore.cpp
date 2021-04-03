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

void Persona::stampaNome(){
	cout <<"Il mio nome e' : " << nome << endl;
}

void Persona::stampaCognome(){
	cout <<"Il mio cognome e' :" << cognome << endl;
}

void Persona::stampaEta(){
	cout <<"La mia eta' e': " << eta << endl;
}

class Dottore: public Persona
{
	private:
		string  mat;
	public:
		Dottore(string n, string s, int eta, string m): Persona(n, s, eta),  mat(m){};
		void getMatricola();
};

void Dottore::getMatricola()
{
	cout <<"La mia matricola e': " << mat << endl;
}
int main()
{
  Persona p = Persona("Andrea", "Calabretta", 33);
	p.stampaNome();
	p.stampaEta();
	cout << "Hello world!" << endl;
	Dottore d = Dottore("Federico", "Salerno", 30, "otyuy4546");
	d.stampaNome();
	d.getMatricola();
}


