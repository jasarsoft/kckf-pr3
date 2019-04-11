//
//#include <iostream>
//using namespace std;
//
//class Proizvod {
//private: char *Naziv;
//private: char *Proizvodjac;
//private: float Cijena;
//private: int Kolicina;
//
//public: void Unos()
//{
//	Naziv = new char[100];
//	Proizvodjac = new char[100];
//
//	cout << "unesite cijenu " << endl;
//	cin >> Cijena;
//	cout << "unesite kolicinu" << endl;
//	cin >> Kolicina;
//	cin.ignore();
//	cout << "unesit e naziv" << endl;
//	cin.getline(Naziv, 100);
//	cout << "unesite proizvodaca" << endl;
//	cin.getline(Proizvodjac, 100);
//
//
//
//}
//
//public: void Ispis() 
//{
//	cout << Naziv<<endl;
//	cout << Proizvodjac << endl;
//	cout << Cijena << endl;
//	cout << Kolicina << endl;
//}
//};
//
//
//void main() {
//
//	Proizvod pr1, pr2, pr3;
//	//Unijeti podatke o tri proizvoda, te ih ispisati.
//	pr1.Unos();
//	pr2.Unos();
//	pr3.Unos();
//	pr1.Ispis();
//	cout << "====================================" << endl;
//	pr2.Ispis();
//	cout << "====================================" << endl;
//
//	pr3.Ispis();
//	cout << "====================================" << endl;
//
//
//	system("pause>0");
//}
//


//#include <iostream>
//using namespace std;
//
//class Apartman {
//private: char *Naziv;
//private: char *Mjesto;
//private: float Cijena;
//private: int BrojKreveta;
//
//public: void Unos() {
//	Naziv = new char[100];
//	Mjesto = new char[100];
//
//	cout << "unesite broj kreveta" << endl;
//	cin >> BrojKreveta;
//	cout << "unesite cijenu" << endl;
//	cin >> Cijena;
//	cin.ignore();
//	cout << "unesite naziv" << endl;
//	cin.getline(Naziv, 100);
//	cout << "unesite mijesto" << endl;
//	cin.getline(Mjesto, 100);
//
//}
//
//public: void Info()
//{
//	cout << Naziv << endl;
//	cout << Mjesto << endl;
//	cout << Cijena << endl;
//	cout << BrojKreveta << endl;
//
//}
//
//public: float GetCijena() {
//	return Cijena;
//	//vraæa cijenu apartmana
//}
//
//public: bool IsFromMostar() {
//	if (strcmp(Mjesto,"Mostar")==0)
//	{
//		return true;
//	}
//	return false;
//	//funkcija koja vraæa informaciju da li je apartman iz Mostara
//}
//};
//
//float GetProsjecnaCijena(Apartman *niz, int vel) {
//	float suma = 0;
//	for (int i = 0; i < vel; i++)
//	{
//		suma += niz[i].GetCijena()/vel;
//	}
//	return suma;
//	//Funkcija koja raèuna prosjeènu cijenu apartmana
//}
//
//
//int GetBrojApartmanaInMostar(Apartman *niz, int vel) {
//	int brojac = 0;
//	for (int i = 0; i < vel; i++)
//	{
//		if (niz[i].IsFromMostar()==true)
//		{
//			brojac++;
//		}
//	}
//	return brojac;
//	//Funkcija koja vraæa koliko je apartmana iz Mostara
//}
//void GetNajjeftinijiApartman(Apartman niz[], int vel) 
//{
//	int najjeftiniji = INT32_MAX;	
//	for (int i = 0; i < vel; i++)
//	{
//		if ( niz[i].GetCijena() < najjeftiniji )
//		{
//			najjeftiniji = niz[i].GetCijena();
//		}
//	}
//}
//
//void main() {
//
//	int n;
//	cout << "Koliko apartmana želite dodati? ";
//	cin >> n;
//	cin.ignore();
//	Apartman *apartmani = new Apartman[n];
//
//	for (int i = 0; i < n; i++)
//		apartmani[i].Unos();
//
//	system("cls");
//
//	for (int i = 0; i < n; i++) {
//		apartmani[i].Info();
//		cout << "===========================================\n\n";
//	}
//
//
//	cout << "Prosjeèna cijena apartmana iznosi: " << GetProsjecnaCijena(apartmani, n) << " KM\n";
//	cout << "Broj apartmana u Mostaru: " << GetBrojApartmanaInMostar(apartmani, n) << endl;
//	GetNajjeftinijiApartman(apartmani, n);
//
//	system("pause>0");
//}

#include<iostream>
using namespace std;

class Pregled {
public: char *Dijagnoza;
private: double cijenaPregleda;
public: void Unos()
{
	Dijagnoza = new char[100];
	cout << "unesite cijenu pregleda" << endl;
	cin >> cijenaPregleda;
	cin.ignore();
	cout << "unesite Dijagnozu" << endl;
	cin.getline(Dijagnoza, 100);
}
public: void Ispis() 
{
	cout << Dijagnoza << endl;
	cout << cijenaPregleda << endl;
}

public: void Dealociraj() 
{
	delete[] Dijagnoza;
	Dijagnoza = nullptr;
}

public: double GetCijenaPregleda()
{
	return cijenaPregleda;
}
};

class Pacijent {
private: char *imePrezime;
private: Pregled * preglediPacijenata[10];
private: int brojPregleda;
public:void Unos() 
{
	*preglediPacijenata = new Pregled[10];
	brojPregleda = 0;
	imePrezime = new char[100];

	cout << "unesi ime i prezime pacijenta " << endl;
	cin.getline(imePrezime, 100);

}
public: void Ispis()
{
	cout << imePrezime<<endl;
	for (int i = 0; i < brojPregleda; i++)
	{
		preglediPacijenata[i]->Ispis();
	}
	//Ispis osnovnih informacija o pacijentu, te o njegovim pregledima
}
public: void DodajPregled() {

	if (brojPregleda==10)
	{
		cout << "maksimalan broj pregleda koji mozet unijeti je 10" << endl;
	}
	preglediPacijenata[brojPregleda]->Unos();
	brojPregleda++;
	//Dodaje novi pregled za pacijenta
	//voditi racuna da pacijent moze imati maksimalno 10 pregleda
}
public: double GetUkupneTroskove() {
	double suma = 0;
	for (int i = 0; i < brojPregleda; i++)
	{
		suma += preglediPacijenata[i]->GetCijenaPregleda();
	}
	return suma / brojPregleda;
	//Funkcija vraæa ukupnu cijenu svih pregleda pacijenta
}

public:void Dealociraj() 
{
	delete[] imePrezime;
	imePrezime = nullptr;
	for (int i = 0; i < brojPregleda; i++)
	{
		preglediPacijenata[i]->Dealociraj();
		delete preglediPacijenata[i];
		preglediPacijenata[i]=nullptr;

	}
	
}

public: bool HasDijagnoza(char *dijagnoza) 
{
	for (int i = 0; i < brojPregleda; i++)
	{

		if (strcmp(preglediPacijenata[i]->Dijagnoza,dijagnoza)==0)
		{
			return true;
		}
	}
	return false;
}
};

void PretragaPoDijagnozi(Pacijent *pacijenti, int vel) {

	char *dijagnoza;
	dijagnoza = new char[100];
	cout << "unesite dijagnozu kojom zelite provjeravati " << endl;
	cin.getline(dijagnoza, 100);
	for (int i = 0; i < vel; i++)
	{
		if (pacijenti[i].HasDijagnoza(dijagnoza))
		{
			pacijenti[i].Ispis();
		}
	}
	//Vrši pretragu  pregleda svih pacijenata po dijagnozi
	//Ispisuje podatke pacijenta koji ima unesenu dijagnozu
	//Unutar funkcije tražiti od korisnika da unese dijagnozu koju pretražuje
	//te prema tome ispisati podatke pacijenata koji imaju unesenu dijagnozu
}

void main() {
	int vel;
	cout << "Unesite broj pacijenata koje zelite dodati:";
	cin >> vel;
	cin.ignore();
	Pacijent *pacijenti = new Pacijent[vel];

	for (int i = 0; i < vel; i++)
	{
		pacijenti[i].Unos();
		for (int j = 0; j < 2; j++)//za svakog pacijenta se dodaju po dva pregleda
			pacijenti[i].DodajPregled();
	}


	PretragaPoDijagnozi(pacijenti, vel);
	cout << "Ukupni troškovi: \n";
	for (int i = 0; i < vel; i++)
	{
		cout << i + 1 << ". pacijent: " << pacijenti[i].GetUkupneTroskove() << endl;
	}

	for (int i = 0; i < vel; i++)
	{
		pacijenti[i].Dealociraj();
	}

	delete[]pacijenti;
	pacijenti = NULL;
	system("pause>0");
}



