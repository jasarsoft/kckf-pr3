#include<iostream>
using namespace std;

template<class T1, class T2, int max>
class Kolekcija {
public:
	T1 * _elementi1;
	T2 * _elementi2;
	int _trenutnoElemenata;
	//konstruktor i destruktor funkcije
	Kolekcija() {
		_trenutnoElemenata = 0;
		_elementi1 = new T1[max];
		_elementi2 = new T2[max];

	}

	~Kolekcija() {
		delete[] _elementi1; _elementi1 = nullptr;
		delete[] _elementi2; _elementi2 = nullptr;
	}

	Kolekcija(Kolekcija &original) {
		_trenutnoElemenata = original._trenutnoElemenata;
		_elementi1 = new T1[max];
		_elementi2 = new T2[max];
		
		for (int i = 0; i < _trenutnoElemenata; i++) {
			_elementi1[i] = original._elementi1[i];
			_elementi2[i] = original._elementi2[i];
		}
	}
	
	//operator =
	void operator =(Kolekcija &original) {
		if (this != original) {
			_trenutnoElemenata = original._trenutnoElemenata;
			_elementi1 = new T1[max];
			_elementi2 = new T2[max];

			for (int i = 0; i < _trenutnoElemenata; i++) {
				_elementi1[i] = original._elementi1[i];
				_elementi2[i] = original._elementi2[i];
			}
		}
	}

	//1. AddElement :: omogucava dodavanje novog elementa u kolekciju. Onemoguciti 
	// ponavljanje elemenata (ukoliko se pojavljuju isti elementi baciti izuzetak tipa exception). 
	//Voditi raèuna ako je _trenutnoElemenata dostiglo max, te i u tom sluèaju baciti izuzetak.
	void AddElement(T1 prvi, T2 drugi) {
		if (_trenutnoElemenata == max) {
			throw exception("Dostignut je makismalni broj elementa.\n");
		}

		for (int i = 0; i < _trenutnoElemenata; i++) {
			if (_elementi1[i] == prvi && _elementi2[i] == drugi) {
				throw exception("Elementi vec postoje!\n");
			}
		}

		_elementi1[_trenutnoElemenata] = prvi;
		_elementi2[_trenutnoElemenata] = drugi;
		_trenutnoElemenata++;
	}
	
	//2. RemoveElement :: na osnovu lokacije uklanja element iz kolekcije. 
	//Prilikom uklanjanja elemenata ocuvati redoslijed njihovog dodavanja. Ukoliko lokacija nije validna, baciti
	//izuzetak tipa exception
	void RemoveElement(int lokacija) {
		if (lokacija < 0 || lokacija >= _trenutnoElemenata) {
			throw exception("Lokacija nije validna.\n");
		}

		for (int i = lokacija; i < _trenutnoElemenata - 1; i++) {
			_elementi1[i] = _elementi1[i - 1];
			_elementi2[i] = _elementi2[i - 1];
		}

		_trenutnoElemenata--;
	}
	
	//operator <<
	friend ostream & operator <<(ostream &out, Kolekcija <T1, T2, max> &k);

	int getTrenutno() { return _trenutnoElemenata; }
	T2 &getDrugi(int i) { return _elementi2[i]; }
	T1 &getPrvi(int i) { return _elementi1[i] }
};

template <class T1, class T2, int max>
ostream & operator <<(ostream &out, Kolekcija <T1, T2, max> &k) {
	for (int i = 0; i < k._trenutnoElemenata; i++) {
		out << k._elementi1[i] << " " << k._elementi2[i] << endl;
	}

	return out;
}

class Datum {
	int *_dan, *_mjesec, *_godina;

public:
	//konstruktor i destruktor funkcije
	Datum(int d = 0, int m = 0, int g = 0) {
		_dan = new int(d);
		_mjesec = new int(m);
		_godina = new int(g);
	}

	~Datum() {
		delete _dan, _mjesec, _godina;
	}

	Datum(Datum &original) {
		_dan = new	int(*original._dan);
		_mjesec = new int(*original._mjesec);
		_godina = new int(*original._godina);
	}
	//operator =
	void operator =(Datum &original) {
		if (this != &original) {
			*_dan = *original._dan;
			*_mjesec = *original._mjesec;
			*_godina = *original._godina;
		}
	}
	//operator <
	bool operator <(Datum original) {
		if (*_godina < *original._godina) {
			return true;
		}
		else if (*_godina == *original._godina) {
			if (*_mjesec < *original._mjesec) {
				return true;
			}
			else if (*_mjesec == *original._mjesec && *_dan < *original._dan) {
				return true;
			}
		}

		return false;
	}

	//operator ==
	bool operator ==(Datum &original) {
		return (*_godina == *original._godina && *_mjesec == *original._mjesec && *_dan == *original._dan);
	}
	//operator <<
	friend ostream & operator <<(ostream &out, Datum *orignal) {
		out << "Datum: ";
		out << orignal->_dan << ".";
		out << orignal->_mjesec << ".";
		out << orignal->_godina << ".\n";

		return out;
	}
};

class Pregled {
	char * _dijagnoza;
	char* _terapija;
	Datum _datumPregleda;
public:
	//konstruktor i destruktor funkcije
	Pregled(char* dijagnoza, char* terapija, Datum* datumPregleda) {
		if (dijagnoza == nullptr || strlen(dijagnoza) == 0) 
			dijagnoza = new char[] { "-" };
		



	}
	//operator =
	//operator == (dvije verzije, jedna verzija prima objekat tipa Pregled, druga prima terapiju)
	//operator <<

	Datum getDatum() {
	}
};
class Pacijent {
protected:
	char *_imePrezime;
	//tip char* je za podatke o imenu i prezimenu ljekara koji je obavio pregled, a
	//objekat tipa Pregled za podatke o pregledu
	Kolekcija<char*, Pregled, 2> _preglediPacijenta;
public:
	//konstruktor i destruktor funkcije
	//operator =

	//operator []  vraca pokazivaè na zadnji Pregled kod koga je postavljena terapija proslijedjena kao parametar.
	//Ako terapija ne postoji niti za jedan pregled, baciti izuzetak tipa exception.

	//funkciju AddPregled koja dodaje podatke o novom pregledu pacijenta. Dakle prima dva parametra: pregled i ljekar. Nije dozvoljeno dodati dva 
	//identicna pregleda. U zavisnosti od uspjesnosti operacije, funkcija vraca true ili false

	//operator -= na osnovu primljenog parametra (tipa Datum) uklanja podatke o prvom pregledu
	//koji je obavljen tog datuma. U zavisnosti od uspjesnosti operacije, funkcija vraca true 
	// ili false

	//operator<< 
};
void main() {
	try {
		Datum d1(1, 1, 2018), d2(2, 2, 2019), d3(15, 3, 2019);

		Pregled p1("Dijagnoza 1", "Terapija 1", d1);
		Pregled p2("Dijagnoza 2", "Terapija 2", d2);
		Pregled p3("Dijagnoza 3", "Terapija 3", d3);

		Pacijent pacijent("Test Test");
		char lj1[] = "Ljekar1 Ljekar1";
		char lj2[] = "Ljekar2 Ljekar2";


		pacijent.AddPregled(p1, lj1);
		pacijent.AddPregled(p2, lj1);
		pacijent.AddPregled(p3, lj2);//izuzetak (max dostigao trenutnoElemenata)
		pacijent.AddPregled(p1, lj1);//izuzetak isti elementi

		cout << "\n::::::: PACIJENT 1. PUT :::::::::::::\n";
		cout << pacijent << endl;

		char terapija[] = "Terapija 1";
		Pregled *trazeniPregled = pacijent[terapija];
		cout << "TRAŽENI PREGLED JE: \n";
		cout << *trazeniPregled << endl;

		pacijent -= d1;//uklanjanje pregleda p1
		cout << "::::::: PACIJENT 2. PUT :::::::::::::\n";
		cout << pacijent << endl;

		trazeniPregled = pacijent[terapija];//pokusaj ispisa pregleda sa terapijom koji smo sada uklonili
		cout << "\nTRAŽENI PREGLED JE: \n";
		cout << *trazeniPregled << endl;
	}
	catch (exception &e) {
		cout << e.what() << endl;
	}

	system("pause>0");
}
