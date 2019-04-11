#include<iostream>
//#include "Source.h"
using namespace std;

//U programu implementirati nasljeðivanje izmeðu odgovarajuæih klasa
//Klasu deklarisati kao apstraktnu
class Osoba//proglasiti je apstraktnom
{
protected:
	char* _ime;
	char* _prezime;
	char* _adresa;
	char _telefon[15];
public:
	//Potrebne konstruktor i destruktor funkcije
	Osoba(char* ime, char* prezime, char* adresa, char* telefon) {
		int len = strlen(ime) + 1;
		_ime = new char[len];
		strcpy_s(_ime, len, ime);

		len = strlen(prezime) + 1;
		_prezime = new char[len];
		strcpy_s(_prezime, len, prezime);

		len = strlen(adresa) + 1;
		_adresa = new char[len];
		strcpy_s(_adresa, len, adresa);

		strcpy_s(_telefon, 15, telefon);
	}

	Osoba(Osoba& osoba) {
		int len;

		len = strlen(osoba._ime) + 1;
		this->_ime = new char[len];
		strcpy_s(this->_ime, len, osoba._ime);

		len = strlen(osoba._prezime) + 1;
		this->_prezime = new char[len];
		strcpy_s(this->_prezime, len, osoba._prezime);

		len = strlen(osoba._adresa) + 1;
		this->_adresa = new char[len];
		strcpy_s(this->_adresa, len, osoba._adresa);

		strcpy_s(this->_telefon, 15, osoba._telefon);
	}

	~Osoba() {
		delete[] _ime;		_ime = NULL;
		delete[] _prezime;	_prezime = NULL;
		delete[] _adresa;	_adresa = NULL;
	}

	//Kreirati funkciju Info za ispis svih vrijednosti atributa klase
	void Ispis() {
		cout << "Ime: " << _ime << endl;
		cout << "Prezime: " << _prezime << endl;
		cout << "Adresa: " << _adresa << endl;
		cout << "Telefon: " << _telefon << endl;
	}
};

static int pom = 1;

class Klijent : public Osoba
{
protected:
	int _id;
	double _mjesecnaPotrosnja;
	char* _email;
public:
	char * getIme() { return this->_ime; }
	char * getPrezime() { return this->_prezime; }
	//Potrebne konstruktor i destruktor funkcije, konstruktor kopije
	Klijent(char* ime, char* prezime, char* adresa, char* telefon, 
		double mjesecnaPostrosnja, char* email)
			: Osoba(ime, prezime, adresa, telefon) {
		_id = pom++;
		_mjesecnaPotrosnja = mjesecnaPostrosnja;

		_email = new char[strlen(email) + 1];
		strcpy_s(_email, strlen(email) + 1, email);
	}

	~Klijent() {
		delete[] _email;
		_email = NULL;
	}

	Klijent(Klijent &klijent) : Osoba(klijent) {
		_id = pom++;
		_mjesecnaPotrosnja = klijent._mjesecnaPotrosnja;
		_email = new char[strlen(klijent._email) + 1];
		strcpy_s(_email, strlen(klijent._email) + 1, klijent._email);
	}

	//Kreirati funkciju za izmjenu mail adrese.

	void IzmijeniMail(char *novi) {
		setMail(novi);
	}

	void setMail(char * Mail) {
		_email = new char[strlen(Mail) + 1];
		strcpy_s(_email, strlen(Mail) + 1, Mail);
	}
	
	char * GetMail() { 
		return _email;
	}
	
	double getPotrosnja() {
		return _mjesecnaPotrosnja;
	}
};

class Zaposlenik : public Osoba {
protected:
	char _radnoMjesto[30];
	int _godineStaza;
public:
	//Potrebne konstruktor i destruktor funkcije, konstruktor kopije
	Zaposlenik(char* ime, char* prezime, char* adresa, char* telefon, 
		char* radnoMjesto, int godineStaza)
		: Osoba(ime, prezime, adresa, telefon) {
		
		strcpy_s(_radnoMjesto, 30, radnoMjesto);
		_godineStaza = godineStaza;
	}

	char * GetRM() {
		//vraca radno mjesto zaposlenika
		return _radnoMjesto;
	}
};

class VIPKlijent :public Klijent
{
	double _popust;
	char* _parkingOznaka;
public:

	//Potrebne konstruktor i destruktor funkcije, kao i konstruktor kopije
	VIPKlijent(char* ime, char* prezime, char* adresa, char* telefon,
		double mjesecnaPotrosnja, char* email,
		double popust, char* parkingOznaka) 
		: Klijent(ime, prezime, adresa, telefon, mjesecnaPotrosnja, email) {

		_popust = popust;
		_parkingOznaka = new char[strlen(_parkingOznaka) + 1];
		strcpy_s(_parkingOznaka, strlen(_parkingOznaka) + 1, parkingOznaka);
	}


	void SmanjiPotrosnju() {
		//Funkciju koja treba da izmijeni vrijednost mjeseène potrošnje na naèin da se 
		//uraèuna popust (prosjeèna potrošnja treba da se umanji)
		_mjesecnaPotrosnja -= _mjesecnaPotrosnja * _popust;
	}
};

int pretragaPotrosnjeKlijenata(Osoba* niz[], int max) {
	//Funkcija treba da pronaðe sve one klijente koji su ostvarili mjeseènu potrošnju veću
	//od zadate. Ispisati podatke i vratiti ukupan broj pronaðenih klijenata.
	int n = 0;
	double potrosnja;

	cout << "Pretraga potrosnje klijenta\n";
	cin >> potrosnja;

	Klijent* klijent = nullptr;

	for (int i = 0; i < max; i++) {
		klijent = (Klijent*)niz[i];
		if (klijent != NULL && klijent->getPotrosnja() > potrosnja) {
			
		}
	}

	return n;
}


void pretragaVIPKlijenata(Osoba* niz[], int max) {
	//Pronaći sve VIP klijente, te im zaraèunati popust na kupljene artikle i ispisati
	//informacije o onima koji su ostvarili potrošnju veæu od 50 KM mjeseèno.
}



void generisiMailAdrese(Osoba* niz[], int max) {
	//Svim klijentima postaviti mail adresu u formatu: ime.prezime@firma.ba.
}



void pretragaKlijenataPoImenu(Osoba* niz[], int max) {
	//Omogućiti pretragu klijenata po imenu ili prezimenu (ispisati informacije
	//o svima koji sadrže uneseni tekst u dijelu imena ili prezimena.
}


void pretragaZaposlenika(Osoba* niz[], int max) {
	//Omogućiti pretragu zaposlenika na osnovu radnog mjesta koje definiše korisnik.
}


void main()
{
	//Testirati sve dostupne funkcionalnosti uz obaveznu provjeru globalnih funkcija

	system("pause>0");
}
