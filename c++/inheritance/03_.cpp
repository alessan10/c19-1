#include <iostream>
#include <string.h>
using namespace std;


class Persona
{
	private:
		string nome, cognome;
	public:
		Persona(string n, string s): nome(n), cognome(s){};
		void stampaNome();
		void stampaCognome();
};

void Persona::stampaNome(){
	cout <<"Il mio nome e' : " << nome << endl;
}

void Persona::stampaCognome(){
	cout <<"Il mio cognome e' :" << cognome << endl;
}

class Dottore: public Persona
{
	private:
		string  username, password;
	public:
		Dottore(string n, string s, string usr, string psw): Persona(n, s),  username(usr), password(psw){};
		void getPassword();
};

void Dottore::getPassword(){
	cout << "La mia password e': " << password << endl;
}
int main()
{
  Persona p = Persona("Andrea", "Calabretta");
	p.stampaNome();
  string psw = "indovinami";
	Dottore d = Dottore("Federico", "Salerno", "salerno", psw);
	d.getPassword();
}


