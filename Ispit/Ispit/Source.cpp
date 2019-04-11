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
		delete[]_elementi1, _elementi2;
		_elementi1 = nullptr;
		_elementi2 = nullptr;
	}
	
	//konstruktor kopije
	Kolekcija(Kolekcija &original) {
		_trenutnoElemenata = original._trenutnoElemenata;
		for (int i = 0; i < _trenutnoElemenata; i++)
		{
			_elementi1[i] = original._elementi1[i];
			_elementi2[i] = original._elementi2[i];
		}
	}

	//operator =
	void operator=(Kolekcija &original) {
		if (this != &original) {
			delete[]_elementi1, _elementi2;

			_trenutnoElemenata = original._trenutnoElemenata;
			for (int i = 0; i < _trenutnoElemenata; i++)
			{
				_elementi1[i] = original._elementi1[i];
				_elementi2[i] = original._elementi2[i];
			}
		}
	}
	//1. AddElement :: omogucava dodavanje novog elementa u kolekciju. Onemoguciti 
	// ponavljanje elemenata (ukoliko se pojavljuju isti elementi baciti izuzetak tipa exception). 
	//Voditi raèuna ako je _trenutnoElemenata dostiglo max, te i u tom sluèaju baciti izuzetak.
	void AddElement(T1 prvi, T2 drugi) {
		for (int i = 0; i < _trenutnoElemenata; i++)
		{
			if (_elementi1[i] == prvi && _elementi2[i] == drugi)
				throw exception("Nije moguce dodavati iste elemente!");
		}
		if (_trenutnoElemenata == max)
			throw exception("Dostignut je makimalni broj elemenata!");

		_elementi1[_trenutnoElemenata] = prvi;
		_elementi2[_trenutnoElemenata] = drugi;
		_trenutnoElemenata++;
	}

	//2. RemoveElement :: na osnovu lokacije uklanja element iz kolekcije. 
	// Prilikom uklanjanja elemenata ocuvati redoslijed njihovog dodavanja. Ukoliko lokacija nije validna, baciti
	//izuzetak tipa exception
	void RemoveElement(T2 ukloni) {
		for (int i = 0; i < _trenutnoElemenata; i++)
		{
			if (_elementi2[i] == ukloni) {
				for (int j = i; j < _trenutnoElemenata - 1; j++)
				{
					_elementi1[j] = _elementi1[j + 1];
					_elementi2[j] = _elementi2[j + 1];
				}
				_trenutnoElemenata--;
				return;
			}

		}

		throw exception("Nije pronadjen element!");
	}


	//operator <<
	template <class T1, class T2, int max>
	friend ostream & operator<<(ostream &out, Kolekcija<T1, T2, max> &obj) {
		for (int i = 0; i < obj._trenutnoElemenata; i++) {
			out << obj._elementi1[i] << endl << obj._elementi2[i] << endl;
		}

		return out;
	}

	int getTrenutno() { return _trenutnoElemenata; }
	T1 &getPrvi(int i) { return _elementi1[i]; }
	T2 &getDrugi(int i) { return _elementi2[i]; }
};


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
		_dan = _mjesec = _godina = nullptr;
	}
	
	Datum(Datum &original) {
		_dan = new int(*original._dan);
		_mjesec = new int(*original._mjesec);
		_godina = new int(*original._godina);
	}
	
	//operator =
	void operator=(Datum &original) {
		if (this != &original) {
			*_dan = (*original._dan);
			*_mjesec = (*original._mjesec);
			*_godina = (*original._godina);
		}
	}
	
	//operator <<
	friend ostream & operator<<(ostream &out, const Datum &d) {
		out << *d._dan << "." << *d._mjesec << "." << *d._godina << endl;
		return out;
	}

	//operator <
	bool operator<(Datum d)
	{
		if (*_godina < *d._godina) {
			return true;
		} else if (*_godina == *d._godina) {
			if (*_mjesec < *d._mjesec) {
				return true;
			} else if (*_mjesec == *d._mjesec && *_dan < *d._dan) {
				return true;
			}
		}

		return false;
	}

	//operator ==
	bool operator==(Datum d) {
		return (*_godina == *d._godina && *_mjesec == *d._mjesec && *_dan == *d._dan);
	}
};

class Pregled {
	char * _dijagnoza;
	char* _terapija;
	Datum _datumPregleda;
public:
	//konstruktor i destruktor funkcije
	Pregled(const char dijagnoza[] = "-", const char terapija[] = "-", Datum datum = 0) {
		_dijagnoza = new char[strlen(dijagnoza) + 1];
		strcpy_s(_dijagnoza, strlen(dijagnoza) + 1, dijagnoza);

		_terapija = new char[strlen(terapija) + 1];
		strcpy_s(_terapija, strlen(terapija) + 1, terapija);

		_datumPregleda = datum;
	}

	~Pregled() {
		delete[] _dijagnoza, _terapija;
		_dijagnoza = _terapija = nullptr;
	}

	//konstrukor kopije
	Pregled(Pregled &original) {

		_dijagnoza = new char[strlen(original._dijagnoza) + 1];
		strcpy_s(_dijagnoza, strlen(original._dijagnoza) + 1, original._dijagnoza);
		
		_terapija = new char[strlen(original._terapija) + 1];
		strcpy_s(_terapija, strlen(original._terapija) + 1, original._terapija);

		_datumPregleda = original._datumPregleda;
	}

	//operator =
	void operator=(Pregled &original) {
		if (this != &original) {
			delete[] _dijagnoza, _terapija;

			_dijagnoza = new char[strlen(original._dijagnoza) + 1];
			strcpy_s(_dijagnoza, strlen(original._dijagnoza) + 1, original._dijagnoza);

			_terapija = new char[strlen(original._terapija) + 1];
			strcpy_s(_terapija, strlen(original._terapija) + 1, original._terapija);

			_datumPregleda = original._datumPregleda;
		}
	}

	//operator == (dvije verzije, jedna verzija prima objekat tipa Pregled, druga prima terapiju)
	bool operator==(Pregled p) {
		return (strcmp(_dijagnoza, p._dijagnoza) == 0 
				&& strcmp(_terapija, p._terapija) == 0 
				&& _datumPregleda == p._datumPregleda);
	}

	bool operator==(char *terapija) {
		return (strcmp(_terapija, terapija) == 0);
	}

	//operator <<
	friend ostream & operator<<(ostream &out, const Pregled &p) {
		out << "Dijagnoza: " << *p._dijagnoza << endl;
		out << "Terapija: " << *p._terapija << endl;
		out << "Datum pregleda: " << p._datumPregleda << endl;
		
		return out;
	}

	Datum getDatum() {
		return _datumPregleda;
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
	Pacijent(const char ime[] = "-") {
		_imePrezime = new char[strlen(ime) + 1];
		strcpy_s(_imePrezime, strlen(ime) + 1, ime);		
	}

	~Pacijent() {
		delete[] _imePrezime;
		_imePrezime = nullptr;
	}

	Pacijent(Pacijent &original) {
		
		_imePrezime = new char[strlen(original._imePrezime) + 1];
		strcpy_s(_imePrezime, strlen(original._imePrezime) + 1, original._imePrezime);

		_preglediPacijenta = original._preglediPacijenta;
	}
	//operator =
	void operator=(Pacijent &original) {
		if (this != &original) {
			delete[] _imePrezime;

			_imePrezime = new char[strlen(original._imePrezime) + 1];
			strcpy_s(_imePrezime, strlen(original._imePrezime) + 1, original._imePrezime);

			_preglediPacijenta = original._preglediPacijenta;
		}
	}

	//operator<< 
	friend ostream & operator<<(ostream &out, Pacijent &p) {
		out << "Pacijent: " << p._imePrezime << endl;
		out << "Pregledi:\n";
		out << p._preglediPacijenta << endl;
		
		return out;
	}


	//operator []  vraca pokazivaè na zadnji Pregled kod koga je postavljena terapija proslijedjena kao parametar.
	//Ako terapija ne postoji niti za jedan pregled, baciti izuzetak tipa exception.
	Pregled* operator[](char* terapija) {
		if (terapija == nullptr || strlen(terapija) == 0) {
			throw exception("Greska: Terapija nije unesena!");
		}

		for (int i = 0; i < _preglediPacijenta.getTrenutno(); i++) {
			if (_preglediPacijenta.getDrugi(i) == terapija) {
				return &(_preglediPacijenta.getDrugi(i));
			}
		}
		
		return nullptr;
	}

	//operator -= na osnovu primljenog parametra (tipa Datum) uklanja podatke o prvom pregledu
	//koji je obavljen tog datuma. U zavisnosti od uspjesnosti operacije, funkcija vraca true 
	// ili false
	bool operator -=(Datum d) {
		//if (d == 0 || &d == nullptr) {
		//	throw exception("Greska: Datum nije unesen!"); // ili return false;
		//}

		for (int i = 0; i < _preglediPacijenta.getTrenutno(); i++) {
			if (_preglediPacijenta.getDrugi(i).getDatum() == d) {
				_preglediPacijenta.RemoveElement(_preglediPacijenta.getDrugi(i));
				return true;
			}
		}

		return false;
	}

	
	int getTrenutniPregled() {
		return _preglediPacijenta.getTrenutno();
	}

	Pregled getPregled(int i) {
		return _preglediPacijenta.getDrugi(i);
	}

	//funkciju AddPregled koja dodaje podatke o novom pregledu pacijenta. Dakle prima dva parametra: pregled i ljekar. Nije dozvoljeno dodati dva 
	//identicna pregleda. U zavisnosti od uspjesnosti operacije, funkcija vraca true ili false
	bool AddPregled(Pregled pregled, char* ljekar) {

		if (&pregled == nullptr) {
			throw exception("Greska: Unesite pregled!"); // ili return false;
		}

		if (&ljekar == nullptr || strlen(ljekar) == 0) {
			throw exception("Greska: Unesite ime i prezime ljekara!"); // ili return false;
		}

		for (int i = 0; i < _preglediPacijenta.getTrenutno(); i++) {
			if (_preglediPacijenta.getDrugi(i) == pregled /*&& strcmp(_preglediPacijenta.getPrvi(i), ljekar) == 0*/) //izbacio sam zbog maina
				throw exception("Greska: Pregled vec postoji!\n"); // ili return false;
		}

		try {
			_preglediPacijenta.AddElement(ljekar, pregled);
			return true;
		}
		catch (exception &err) {
			cout << err.what() << endl;
		}

		return false;
	}
};
//template<class T1, class T2, int max> getPreglediPacijenata{
//	return _preglediPacijenta;
//}

//Globalna funkcija GetPregledi koja vraæa sve preglede pacijenta koji su obavljeni nakon proslijeðenog datuma. 
//Napomena: u mainu-u nije pozvana ova funkcija. Te ukoliko je želite testirati, trebate pozvati istu.
//Pregled* GetPregledi(Pacijent pacijent, Datum datum);
Pregled* GetPregledi(Pacijent pacijent, Datum datum) {

	int k = 0;
	int brojac = 0;

	for (int i = 0; i < pacijent.getTrenutniPregled(); i++)
	{
		if (pacijent.getPregled(i).getDatum() < datum) {
			continue;
		}

		brojac++;
	}
	if (brojac == 0) return nullptr;
	Pregled* p = new Pregled[brojac];
	
	for (int i = 0; i < pacijent.getTrenutniPregled(); i++) {
		if (pacijent.getPregled(i).getDatum() < datum) {
			continue;
		}

		p[k++] = pacijent.getPregled(i);
	}

	return p;
}


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
		//pacijent.AddPregled(p1, lj1);//izuzetak isti elementi

		//test getpregledi, radi
		Pregled *p = GetPregledi(pacijent, d1);
		cout << p[0].getDatum() << endl;
		cout << p[1].getDatum() << endl;

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

