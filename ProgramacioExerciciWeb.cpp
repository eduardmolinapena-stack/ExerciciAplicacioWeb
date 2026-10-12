#include <iostream>
#include <string>
using namespace std;

class SessioUsuari
{
private: 
	string nomUsuari;
	int tempsLlimitSegons;
	bool activa;

	void tancarSessio()
	{
		activa = false;
	}

public:
	SessioUsuari()
	{
		nomUsuari = "Convidat";
		tempsLlimitSegons = 300;
		activa = true;
	}

	explicit SessioUsuari(string nom)
	{
		nomUsuari = nom;
		tempsLlimitSegons = 600;
		activa = true;
	}

	SessioUsuari(string nom, int temps)
		: nomUsuari(nom), tempsLlimitSegons(temps <= 0 ? 60 : temps)
	{
		activa = true;
	}

	string getNomUsuari() const
	{
		return nomUsuari;
	}

	bool isActiva() const
	{
		return activa;
	}

	void ampliarTemps(int quantitat)
	{
		if (quantitat > 0)
		{
			tempsLlimitSegons = tempsLlimitSegons + quantitat;
		}
	}

	~SessioUsuari()
	{
		if (activa)
		{
			tancarSessio();

			cout << "[AUDITORIA] La sessio de '"
				<< nomUsuari
				<< "' s'ha tancat automaticament en sortir de l'ambit."
				<< endl;
		}
	}
};

int main()
{
	SessioUsuari s1;
	SessioUsuari s2("Eduard");
	SessioUsuari s3("Maria", 900);

	cout << "Usuari 1: " << s1.getNomUsuari() << endl;
	cout << "Sessio activa: " << s1.isActiva() << endl;

	cout << "Usuari 2: " << s2.getNomUsuari() << endl;

	cout << "Usuari 3: " << s3.getNomUsuari() << endl;

	s2.ampliarTemps(120);

	cout << "Les sessions s'han creat correctament." << endl;

	return 0;
}