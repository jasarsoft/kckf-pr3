
#include<iostream>

using namespace std;

template<class T1>
class Kolekcija {
	T1 * _elementi1;
	int _trenutnoElemenata;
	/*1. potrebne funkcije
	2. operator+= :: omogucava dodavanje novog elementa u kolekciju. Osigurati automatsko prosiranje kolekcije,
	te onemoguciti ponavljanje elemenata. U zavisnosti od uspjesnosti operacije funkcija vraca true ili
	false.
	3. operator-= :: na osnovu parametra tipa T1 uklanja element iz kolekcije. Ukoliko je potrebno, prilikom
	uklanjanja elementa izvrsiti dealokaciju. Onemoguciti pojavljivanje neinicijaliziranih elemenata, te
	ocuvati redoslijed dodavanja elemenata. U zavisnosti od uspjesnosti operacije, funkcija vraca true ili
	false*/
public:
	Kolekcija() {
		_trenutnoElemenata = 0;
	}
	Kolekcija(Kolekcija &orig) {
		_trenutnoElemenata = orig._trenutnoElemenata;

		if (_trenutnoElemenata > 0) {
			_elementi1 = new T1[_trenutnoElemenata];

			for (int i = 0; i < _trenutnoElemenata; i++)
			{
				_elementi1[i] = orig._elementi1[i];
			}
		}
	}

	/*2. operator+= :: omogucava dodavanje novog elementa u kolekciju. Osigurati automatsko prosiranje kolekcije,
	te onemoguciti ponavljanje elemenata. U zavisnosti od uspjesnosti operacije funkcija vraca true ili
	false.*/
	//3. operator-= :: na osnovu parametra tipa T1 uklanja element iz kolekcije. Ukoliko je potrebno, prilikom
	//uklanjanja elementa izvrsiti dealokaciju. Onemoguciti pojavljivanje neinicijaliziranih elemenata, te
	//ocuvati redoslijed dodavanja elemenata. U zavisnosti od uspjesnosti operacije, funkcija vraca true ili
	//false*/

	int getTrenutno() {  }
	T1& getElement(int i) { }
	T1& operator[](int i) { }

	//operator <<
};


class Datum {
	int * _dan, *_mjesec, *_godina;
	//1. potrebne funkcije
	Datum(int dan = 0, int mjesec = 0, int godina = 0) {
		_dan = new int(dan);
		_mjesec = new int(mjesec);
		_godina = new int(godina);
	}

	Datum(Datum &datum) {
		_dan = new int(*datum._dan);
		_mjesec = new int(*datum._mjesec);
		_godina = new int(*datum._godina);
	}

	~Datum()
	{
		delete _dan, _mjesec, _godina;
	}

public:
	//operatori <<, <, >
};

class TelefonskiPrikljucak {
	Datum _datumPrikljucenja;
	char* _telefonskiBroj;//036 111 222
	bool _aktivan; //u slucaju da se broj više ne koristi
public:
	//1. potrebne funkcije	

	//operator =
	//operator <<
	//operator ==
	Datum getDatum() {
	}
};

class TelecomKorisnik {
	char * _imePrezimeKorisnika;
	Kolekcija<TelefonskiPrikljucak>  _telefonskiPrikljucci;
public:
	//potrebne funkcije
	/*	1. operator [] :: vraca pokazivac na objekat tipa TelefonskiPrikljucak kod koga je broj telefona
	identican onome koji je proslijedjen kao parametar. U slucaju da trazeni broj ne postoji funkcija
	vraca NULL.*/

	/*	2. AddTelefonskiPrikljucak :: dodaje podatke o novom telefonskom priljucku korisnika. Nije dozvoljeno
	dodati dva identicna telefonska broja. U zavisnosti od uspjesnosti operacije, funkcija vraca true ili false.*/

	/*3. RemoveTelefonskiPrikljucakByDatum :: na osnovu dva primljena parametra (tipa Datum) uklanja podatke o
	svim telefonskim prikljuccima koji su izvrseni u periodu izmedju ta dva datuma.
	Funkcija vraca broj uklonjenih prikljucaka.*/
	//operator ==

	//operator <<
};

void PretragaPoBroju(Kolekcija<TelecomKorisnik> BHTelecomKorisnici, char * trazeniBroj) {
	/*Funkcija treba da ispise podatke o korisniku prikljucka koji je vlasnik trazenog broja*/

}
void main() {
	TelecomKorisnik t1("Niko Nikiæ");
	TelecomKorisnik t2("Miro Miriæ");

	Datum d1(23, 6, 2016), d2(24, 6, 2016), d3(26, 7, 2016);

	TelefonskiPrikljucak tp1(d1, "061 234 345");
	TelefonskiPrikljucak tp2(d2, "768 567 356");
	TelefonskiPrikljucak tp3(d3, "897 653 848");

	cout << "Korisnik1: " << t1 << endl;
	cout << "Korisnik2: " << t2 << endl;

	t1.AddTelefonskiPrikljucak(tp1);
	t1.AddTelefonskiPrikljucak(tp2);

	t2.AddTelefonskiPrikljucak(tp3);

	cout << "Korisnik1: " << t1 << endl;
	cout << "Korisnik2: " << t2 << endl;

	t1.RemoveTelefonskiPrikljucakByDatum(d1, d2);

	cout << "Korisnik1: " << t1 << endl;

	char broj[] = "061 234 345";
	cout << t1[broj] << endl;
	Kolekcija<TelecomKorisnik> BHTelecom;
	BHTelecom += t1;

	PretragaPoBroju(BHTelecom, broj);

	system("pause>0");
}
