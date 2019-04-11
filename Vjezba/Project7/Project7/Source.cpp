#include<iostream>
using namespace std;

class Predmet
{
	char* _naziv;
	int _godinaStudija;
public:
	//Potrebne konstruktor i destruktor funkcije
	Predmet(char naziv[]="-----",int godStudija=0) {
		_naziv = new char[strlen(naziv) + 1];
		strcpy_s(_naziv, strlen(naziv) + 1, naziv);
		_godinaStudija = godStudija;
	}
	Predmet(Predmet &P)
	{
		_naziv = new char[strlen(P._naziv) + 1];
		strcpy_s(_naziv, strlen(P._naziv) + 1, P._naziv);
		_godinaStudija = P._godinaStudija;
	}
	~Predmet()
	{
		delete _naziv; _naziv = nullptr;
	}
	Predmet &operator =(Predmet &P)
	{
		if (this != &P)
		{
			_naziv = new char[strlen(P._naziv) + 1];
			strcpy_s(_naziv, strlen(P._naziv) + 1, P._naziv);
			_godinaStudija = P._godinaStudija;
		}
		return *this;
	}
	bool operator ==(Predmet &P)
	{
		return strcmp(_naziv, P._naziv) == 0;
	}
	friend ostream &operator <<(ostream &COUT, Predmet &P) {
		COUT << "Naziv: " << P._naziv << endl;
		COUT << "Godina studija: "<<P._godinaStudija << endl;
		return COUT;
		
	}
	
	// operator =
	// operator ==
	//operator <<
};
class Prisustvo
{
	char* _student; //ne smije sadržavati brojeve, regex: [0-9]
	char* _brojIndeksa;
	int _brojSati;
public:
	//Potrebne konstruktor i destruktor funkcije
	Prisustvo(char student[] = "---", char brojIndeksa[] = "000000", int brojSati = 0)
	{
		_student = new char[strlen(student) + 1];
		strcpy_s(_student, strlen(student) + 1, student);
		_brojIndeksa = new char[strlen(brojIndeksa) + 1];
		strcpy_s(_brojIndeksa, strlen(brojIndeksa) + 1, brojIndeksa);
		_brojSati = brojSati;
	}
	Prisustvo(Prisustvo &P)
	{
		_student = new char[strlen(P._student) + 1];
		strcpy_s(_student, strlen(P._student) + 1, P._student);
		_brojIndeksa = new char[strlen(P._brojIndeksa) + 1];
		strcpy_s(_brojIndeksa, strlen(P._brojIndeksa) + 1, P._brojIndeksa);
		_brojSati = P._brojSati;
	}
	void operator =(Prisustvo &P)
	{
		if (this != &P) {
			_student = new char[strlen(P._student) + 1];
			strcpy_s(_student, strlen(P._student) + 1, P._student);
			_brojIndeksa = new char[strlen(P._brojIndeksa) + 1];
			strcpy_s(_brojIndeksa, strlen(P._brojIndeksa) + 1, P._brojIndeksa);
			_brojSati = P._brojSati;
		}
	}
	bool operator ==(Prisustvo &P)
	{
		return strcmp(_student, P._student) && (_brojIndeksa, P._brojIndeksa) == 0;
	}
	
	friend ostream &operator <<(ostream &COUT, Prisustvo &P) {
		COUT << "Student: " << P._student << endl;
		COUT << "Broj indeksa: " << P._brojIndeksa << endl;
		COUT << "Broj sati: " << P._brojSati;
		return COUT;
	}
	char *getBrojIndeksa() { return _brojIndeksa; }
	// operator =
	//operator ==
	// operator <<
};
class Nastava {
	//Oznaka prostorije
	char* _prostorija;
	char *_datum;
	char* _satnica;
	char* _predavac;
	//P, V ili W
	Predmet* _predmet;
	char _tipNastave;
	int* _odrzanoSati;

	Prisustvo _prisutni[50];
public:
	int _trenutnoPrisutnih;
	//Potrebne konstruktor i destruktor funkcije
	Nastava(char prostorija[]="---",char datum[]="----",char satnica[]="----",char predavac[]="----",Predmet p=0,char tipNastave='a') {
		_prostorija = new char[strlen(prostorija) + 1];
		strcpy_s(_prostorija, strlen(prostorija) + 1, prostorija);

		_datum = new char[strlen(datum) + 1];
		strcpy_s(_datum, strlen(datum) + 1, datum);

		_satnica = new char[strlen(satnica) + 1];
		strcpy_s(_satnica, strlen(satnica) + 1, satnica);

		_predavac = new char[strlen(predavac) + 1];
		strcpy_s(_predavac, strlen(predavac) + 1, predavac);

		_predmet = new Predmet(p);
		_tipNastave = tipNastave;

		_odrzanoSati = new int(0);

	}
	Nastava(Nastava &n)
	{
		_prostorija = new char[strlen(n._prostorija) + 1];
		strcpy_s(_prostorija, strlen(n._prostorija) + 1, n._prostorija);

		_datum = new char[strlen(n._datum) + 1];
		strcpy_s(_datum, strlen(n._datum) + 1, n._datum);

		_satnica = new char[strlen(n._satnica) + 1];
		strcpy_s(_satnica, strlen(n._satnica) + 1, n._satnica);

		_predavac = new char[strlen(n._predavac) + 1];
		strcpy_s(_predavac, strlen(n._predavac) + 1, n._predavac);

		_predmet = new Predmet(*n._predmet);


		_tipNastave = n._tipNastave;

		_odrzanoSati = new int(*n._odrzanoSati);
		for (int i = 0; i < *n._odrzanoSati; i++)
		{
			_prisutni[i] = n._prisutni[i];
		}
	}
	~Nastava()
	{
		delete[] _prostorija; _prostorija = nullptr;
		delete[] _datum; _datum = nullptr;
		delete[] _satnica; _satnica = nullptr;
		delete[] _predavac; _predavac = nullptr;
		delete[] _predmet; _predmet = nullptr;
		delete _odrzanoSati; _odrzanoSati = nullptr;
	}
	// operator <<
	friend ostream &operator <<(ostream &COUT, Nastava &n)
	{
		COUT << "Nastava odrzana u " << n._prostorija << ", dana " << n._datum << endl;
		COUT << "Satnica: " << n._satnica << endl;
		COUT << "Predavac: " << n._predavac << endl;
		COUT << "Predmet: " << n._predmet << " (" << n._tipNastave << ")" << endl;
		COUT << "Odrzano sati: " << *n._odrzanoSati << endl;
		COUT << "Prisutni: " << endl;
		for (int i = 0; i < n._trenutnoPrisutnih; i++)
		{
			COUT << n._prisutni[i] << endl;
		}
		return COUT;
	}
	//Preklopljeni operator+= za dodavanje objekata tipa Prisustvo u niz _prisutni
	//Onemogućiti dodavanje istog prisustva 
	bool operator +=(Prisustvo &p)
	{
		for (int i = 0; i<_trenutnoPrisutnih; i++)
		{
			if (_prisutni[i] == p)
				return false;
		}
		_prisutni[_trenutnoPrisutnih] = p;
		_trenutnoPrisutnih++;
		return true;
	}

	//Preklopljeni operator-= za uklanjanje objekata tipa Prisustvo iz niza _prisutni
	bool operator -=(Prisustvo &p)
	{
		for (int i = 0; i < _trenutnoPrisutnih; i++)
		{
			if(_prisutni[i]==p)
				for (int j = i; j < _trenutnoPrisutnih; j++)
				{
					_prisutni[i] = _prisutni[j];
					return true;
				}
		}
		return false;
	}

	//Preklopljeni operator [] koji na osnovu parametra broj indeksa  provjerava da li je 
	//odreðeni student prisustvovao nastavi
	bool operator [](const char brIndeksa[]) {
		for (int i = 0; i < _trenutnoPrisutnih; i++)
		{
			if (_prisutni[i].getBrojIndeksa() == brIndeksa)
				return true;
		}
		return false;
	}

};
void main()
{
	Prisustvo p1("Test Test", "IB111", 2);
	Prisustvo p2("Niko Nikic", "IB222", 4);
	Prisustvo p3("Miro Miric", "IB333", 6);


	Predmet predmet("Programiranje 3", 2);

	Nastava n("AMF1", "15.02.2019", "14:00-17:00", "Denis Music", predmet, 'P');
	n += p1;
	n += p2;
	n += p1;
	n -= p3;

	bool daLiJePrisustvovao = n["IB4444"];
	if (daLiJePrisustvovao)
		cout << "IB4444 je prisustvovao nastavi\n";
	else
		cout << "IB4444 nije prisustvovao nastavi\n";

	cout << n << endl;

	system("pause>0");
}
