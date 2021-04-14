#ifndef PERSONA_HH
#define PERSONA_HH

#include <iostream>
#include <string>

using namespace std;

class Persona
{
	private:
		string nome, cognome;
	public:
		Persona(string nome, string cognome);
		void stampaNome();
		void stampaCognome();
};
#endif
