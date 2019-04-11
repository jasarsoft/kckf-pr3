#include<iostream>
using namespace std;

template<class T1, class T2, int max>
class Kolekcija {
	T1 * _elementi1;
	T2 * _elementi2;
	int _trenutnoElemenata;
public:
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

		for (int i = 0; i < _trenutnoElemenata; i++)
		{
			_elementi1[i] = original._elementi1[i];
			_elementi2[2] = original._elementi2[i];
		}
	}

	void operator =(Kolekcija &original) {
		if (this != &original) {
			_trenutnoElemenata = original._trenutnoElemenata;
			_elementi1 = new T1[max];
			_elementi2 = new T2[max];

			for (int i = 0; i < _trenutnoElemenata; i++) {
				_elementi1[i] = original._elementi1[i];
				_elementi2[i] = original._elementi2[i];
			}
		}
	}

	//potrebne funkcije
	/*1. AddElement :: omogucava dodavanje novog elementa u kolekciju. Onemoguciti ponavljanje elemenata*/
	void AddElement(T1 prvi, T2 drugi) {
		if (_trenutnoElemenata == max) {
			throw exception("Dostignut je maksimalni limit elemenata.\n");
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

	/*2. RemoveElement :: na osnovu parametra tipa T1 uklanja elemente iz kolekcije.
	Prilikom uklanjanja elemenata ocuvati redoslijed njihovog dodavanja. Ukoliko elemenat nije pronaðen baciti exception.*/
	void RemoveElement(int lokacija) {
		if (lokacija < 0 || lokacija >= _trenutnoElemenata) {
			throw exception("Lokacija nije validna.\n");
		}

		for (int i = lokacija; i < _trenutnoElemenata - 1; i++) {
			_elementi1[i] = _elementi1[i + 1];
			_elementi2[i] = _elementi2[i + 1];
		}

		_trenutnoElemenata--;
	}

	int getTrenutno() { return _trenutnoElemenata; }
	T1 &getPrvi(int i) { return _elementi1[i]; }
	T2 &getdrugi(int i) { return _elementi2[i]; }
	
	//operator <<
	template <class T1, class T2, int max>
	friend ostream &operator <<(ostream &out, Kolekcija<T1, T2, max> &k) {
		for (int i = 0; i < k._trenutnoElemenata; i++) {
			out << k._elementi1[i] << " " << k._elementi2[i] << endl;
		}

		return out;
	}
};

class Datum {
	int *_dan, *_mjesec, *_godina;
public:
	//potrebne funkcije
	Datum(int d = 0, int m = 0, int g = 0) {
		_dan = new int(d);
		_mjesec = new int(m);
		_godina = new int(g);
	}

	~Datum() {
		delete _dan, _mjesec, _godina;
	}

	Datum(Datum &original) {
		_dan = new int(*original._dan);
		_mjesec = new int(*original._mjesec);
		_godina = new int(*original._godina);
	}

	void operator =(Datum &original) {
		if (this != &original) {
			*_dan = *original._dan;
			*_mjesec = *original._mjesec;
			*_godina = *original._godina;
		}
	}

	friend ostream &operator <<(ostream &ispis, Datum &datum) {
		ispis << *datum._dan << "." << *datum._mjesec << "." << *datum._godina << endl;
		return ispis;
	}

	bool operator <(Datum datum) {
		if (*_godina < *datum._godina) {
			return true;
		}
		else if (*_godina == *datum._godina) {
			if (*_mjesec < *datum._mjesec) {
				return true;
			}
			else if (*_mjesec == *datum._mjesec && _dan < *datum._dan) {
				return true;
			}
		}

		return false;
	}

	bool operator ==(Datum &datum) {
		return (*_godina == *datum._godina && *_mjesec == *datum._mjesec && *_godina == *datum._godina);
	}
};

class PolozeniPredmet {
	char * _nazivPredmeta;
	char * _imePrezimeNastavnika;
	Datum _datumPolaganja;
	int ocjena;
	//1. potrebne funkcije
public:
	PolozeniPredmet(char nazivPredmeta[] = "-", char imePrezimeNastavnika[] = "-", Datum datumPolaganja = 0, int ocjena = 0) {
		_nazivPredmeta = new char[strlen(nazivPredmeta) + 1];
		strcpy_s(_nazivPredmeta, strlen(nazivPredmeta) + 1, nazivPredmeta);

		_imePrezimeNastavnika = new char[strlen(imePrezimeNastavnika) + 1];
		strcpy_s(_imePrezimeNastavnika, strlen(imePrezimeNastavnika) + 1, imePrezimeNastavnika);

		_datumPolaganja = datumPolaganja;
		this->ocjena = ocjena;
	}

	~PolozeniPredmet() {
		delete[] _nazivPredmeta; _nazivPredmeta = nullptr;
		delete[] _imePrezimeNastavnika; _imePrezimeNastavnika = nullptr;
	}

	PolozeniPredmet(PolozeniPredmet &original) {
		_nazivPredmeta = new char[strlen(original._nazivPredmeta) + 1];
		strcpy_s(_nazivPredmeta, strlen(original._nazivPredmeta) + 1, original._nazivPredmeta);

		_imePrezimeNastavnika = new char[strlen(original._imePrezimeNastavnika) + 1];
		strcpy_s(_imePrezimeNastavnika, strlen(original._imePrezimeNastavnika) + 1, original._imePrezimeNastavnika);

		_datumPolaganja = original._datumPolaganja;
		this->ocjena = original.ocjena;
	}

	void operator =(PolozeniPredmet &original) {
		if (this != &original) {
			delete[] _nazivPredmeta;
			delete[] _imePrezimeNastavnika;
			
			_nazivPredmeta = new char[strlen(original._nazivPredmeta) + 1];
			strcpy_s(_nazivPredmeta, strlen(original._nazivPredmeta) + 1, original._nazivPredmeta);

			_imePrezimeNastavnika = new char[strlen(original._imePrezimeNastavnika) + 1];
			strcpy_s(_imePrezimeNastavnika, strlen(original._imePrezimeNastavnika) + 1, original._imePrezimeNastavnika);

			_datumPolaganja = original._datumPolaganja;
			ocjena = original.ocjena;
		}
	}

	bool operator ==(PolozeniPredmet &original) {
		return (strcmp(_nazivPredmeta, original._nazivPredmeta) == 0);
	}

	bool operator ==(char* imePrezimeNastavnika) {
		return strcmp(_imePrezimeNastavnika, imePrezimeNastavnika) == 0;
	}


	char* getNastavnika() { return _imePrezimeNastavnika; }
	char* getNazivPredmeta() { return _nazivPredmeta; }
	Datum getDatum() { return _datumPolaganja; }
	int getOcjena() { return ocjena; }
};

class Student {
	int _brojIndeksa;
	char * _imePrezime;
	//planom i programom je definisano da je student, tokom studija, duzan poloziti 40 predmeta
	Kolekcija<PolozeniPredmet, char*, 40> _polozeniPredmeti;//string se odnosi na napomenu
public:
	Student(char imePrezime[] = "-", int brojIndeksa = 0) {
		_imePrezime = new char[strlen(imePrezime) + 1];
		strcpy_s(_imePrezime, strlen(imePrezime) + 1, imePrezime);

		_brojIndeksa = brojIndeksa;
	}

	~Student() {
		delete[] _imePrezime; _imePrezime = nullptr;
	}

	Student(Student &original) {
		_imePrezime = new char[strlen(original._imePrezime) + 1];
		strcpy_s(_imePrezime, strlen(original._imePrezime) + 1, original._imePrezime);
		
		_brojIndeksa = original._brojIndeksa;
	}

	void operator =(Student &original) {
		if (this != &original) {
			delete[]  _imePrezime;

			_imePrezime = new char[strlen(original._imePrezime) + 1];
			strcpy_s(_imePrezime, strlen(original._imePrezime) + 1, original._imePrezime);

			_brojIndeksa = original._brojIndeksa;
		}
	}

	bool operator ==(Student &original) {
		return (strcmp(_imePrezime, original._imePrezime) == 0 && _brojIndeksa == original._brojIndeksa);
	}

	bool operator ==(char* imePrezime) {
		return strcmp(_imePrezime, imePrezime) == 0;
	}

	bool operator ==(int brojIndeksa) {
		return _brojIndeksa == brojIndeksa;
	}
	
	friend ostream &operator <<(ostream &out, Student &student) {
		out << "Ime i prezime: " << student._imePrezime << endl;
		out << "Broj indeksa: " << student._brojIndeksa << endl;

		return out;
	}



	//potrebne funkcije
	/*1.AddPolozeniIspit :: dodaje podatke o polozenom predmetu, te  napomenu.
	Onemoguciti da se dva puta doda istoimeni predmet, te da se kod istog nastavnika polazu vise od tri
	predmeta. Ukoliko nije zadovoljen neki od prethodnih uslova, funkcija treba da baci izuzetak. */
	void AddPolozeniIspit(PolozeniPredmet &predmet, char napomena[] = "Nista") {
		int brojPredmetaKodNastavnika = 0;

		for (int i = 0; i < _polozeniPredmeti.getTrenutno(); i++)
		{
			if (_polozeniPredmeti.getPrvi(i) == predmet) {
				throw exception("Predmet vec postoji.\n");
			}

			if (_polozeniPredmeti.getPrvi(i) == predmet.getNastavnika()) {
				brojPredmetaKodNastavnika++;
			}

			if (brojPredmetaKodNastavnika > 3) {
				throw exception("Nastavnik maksimalno 3 predmeta moze drzati.\n");
			}
		}

		try
		{
			_polozeniPredmeti.AddElement(predmet, napomena);
		}
		catch (const std::exception&err)
		{
			cout << err.what() << endl;
		}
	}

	/*2.RemovePolozeniIspit :: na osnovu naziva predmeta, uklanja podatke o polozenom predmetu*/
	void RemovePolozeniIspit(char* nazivPredmeta) {
		if (nazivPredmeta == nullptr && strlen(nazivPredmeta) == 0) {
			return;
		}

		for (int i = 0; i < _polozeniPredmeti.getTrenutno(); i++)
		{
			if (_polozeniPredmeti.getPrvi(i).getNazivPredmeta == nazivPredmeta) {
				_polozeniPredmeti.RemoveElement(i);
				break;
			}
		}
	}
	/*3.GetProsjekByNastavnik :: vraca prosjecnu ocjenu koju je student ostvario na predmetima kod nastavnika cije ime je odredjeno
	vrijednoscu parametra*/
	/*4.operator() :: vraca sve polozene predmete koji u napomeni posjeduju sadrzaj koji je proslijedjen kao parametar (npr.listu svih
	predmeta koji u napomeni posjeduju sadrzaj "prepisivao"). Ukoliko ne postoji niti jedan predmet sa tom napomenom, baciti izuzetak.*/
};

void main() {
	Datum d1(12, 3, 2019);
	Datum d2(15, 2, 2019);
	Datum d3(21, 1, 2019);
	PolozeniPredmet p1("Programiranje 1", "prof. Denis Music", d1);
	PolozeniPredmet p2("Raèunarske mreže", "prof. Denis Music", d2);
	PolozeniPredmet p3("Baze podataka", "prof. Jasmin Azemovic", d3);

	PolozeniPredmet p4("Programiranje 2", "prof. Denis Music", d1);
	PolozeniPredmet p5("Programiranje 3", "prof. Denis Music", d2);

	Student s("Test Test");

	try {
		char napomena[100];
		cout << "Unesite napomenu za prvi predmet: ";
		cin.getline(napomena, 100);
		s.AddPolozeniIspit(p1, napomena);

		cout << "Unesite napomenu za drugi predmet: ";
		cin.getline(napomena, 100);
		s.AddPolozeniIspit(p2, napomena);

		cout << "Unesite napomenu za treci predmet: ";
		cin.getline(napomena, 100);
		s.AddPolozeniIspit(p3, napomena);

		cout << "Unesite napomenu za cetvrti predmet: ";
		cin.getline(napomena, 100);
		s.AddPolozeniIspit(p4, napomena);

		cout << "Unesite napomenu za peti predmet: ";
		cin.getline(napomena, 100);
		s.AddPolozeniIspit(p5, napomena);//Izuzetak - pokušaj dodavanja više od 3 predmeta za istog profesora

		cout << "Unesite napomenu za sesti predmet: ";
		cin.getline(napomena, 100);
		s.AddPolozeniIspit(p2, napomena);//Izuzetak - pokušaj dodavanja istog predmeta

		cout << "::::::::::::::::::::::: STUDENT ::::::::::::::::::::::: \n";
		cout << s << endl;

		s.RemovePolozeniIspit("Raèunarske mreže");
		s.RemovePolozeniIspit("Programiranje 3");//Izuzetak - pokušaj uklanjanja predmeta koji ne postoji

		cout << "::::::::::::::::::::::: STUDENT ::::::::::::::::::::::: \n";
		cout << s << endl;


		char nastavnik[100];
		cout << "Unesite ime i prezime nastavnika za kokeg racunate prosjek: ";
		cin.getline(nastavnik, 100);
		cout << s.GetProsjekByNastavnik(nastavnik);

		PolozeniPredmet *predmeti = s("prepisivao");
		if (predmeti != nullptr)
			cout << "Predmeti pronaðeni." << endl;
	}
	catch (exception &ex) {
		cout << ex.what() << endl;
	}


	system("pause>0");
}
