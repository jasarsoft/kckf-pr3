#include<iostream>
using namespace std;

//U programu implementirati nasljeðivanje izmeðu odgovarajuæih klasa
//Klasu deklarisati kao apstraktnu
class Osoba
	//proglasiti je apstraktnom
{
protected:
	char* _ime;
	char* _prezime;
	char* _adresa;
	char _telefon[15];
public:

	Osoba(const char ime[] = "////", const char prezime[] = "----", const char adresa[] = "----", const char telefon[15] = "111111111111111111")
	{
		_ime = new char[strlen(ime) + 1];
		strcpy_s(_ime, strlen(ime) + 1, ime);

		_prezime = new char[strlen(prezime) + 1];
		strcpy_s(_prezime, strlen(ime) + 1, prezime);

		_adresa = new char[strlen(adresa) + 1];
		strcpy_s(_adresa, strlen(adresa) + 1, adresa);

		strcpy_s(_telefon, 15, telefon);

	}

	~Osoba()
	{
		delete[] _ime;
		delete[] _prezime;
		delete[] _adresa;
		_ime = _prezime = _adresa = nullptr;
	}
	//Potrebne konstruktor i destruktor funkcije

	virtual void info() = 0;
	//Kreirati funkciju Info za ispis svih vrijednosti atributa klase

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


	//Kreirati funkciju za izmjenu mail adrese.

	void IzmijeniMail(char *novi) {
	}
	void setMail(char * Mail) {

	}
	char * GetMail() { }
	double getPotrosnja() {}
};

class Zaposlenik : public Osoba {
protected:
	char _radnoMjesto[30];
	int _godineStaza;
public:
	//Potrebne konstruktor i destruktor funkcije, konstruktor kopije

	char * GetRM() {
		//vraca radno mjesto zaposlenika
	}
};

class VIPKlijent :public Klijent
{
	double _popust;
	char* _parkingOznaka;
public:

	//Potrebne konstruktor i destruktor funkcije, kao i konstruktor kopije


	void SmanjiPotrosnju() {
		//Funkciju koja treba da izmijeni vrijednost mjeseène potrošnje na naèin da se 
		//uraèuna popust (prosjeèna potrošnja treba da se umanji)
	}
};

int pretragaPotrosnjeKlijenata(Osoba* niz[], int max) {
	//Funkcija treba da pronaðe sve one klijente koji su ostvarili mjeseènu potrošnju veću
	//od zadate. Ispisati podatke i vratiti ukupan broj pronaðenih klijenata.
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
