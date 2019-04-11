#include<iostream>
using namespace std;

class Osoba {
protected: char *imePrezime;
protected: char *JMBG;

public:
	//defualtni konstruktor, koji puni samo 'testnim' vrijednostima atribute
	//konstruktor koji prima imePrezime, JMBG
	//konstruktor kopije
	//destruktor
	char *GetIme() 
	{
		return imePrezime;
	}
	char *GetJMBG() 
	{
		return JMBG;
	}

	Osoba(const char _imeprezime[] =  "-----" , const char jmbgg []="////")
	{
		imePrezime = new char[strlen(_imeprezime) + 1];
		JMBG = new char[strlen(jmbgg) + 1];

		strcpy_s(imePrezime, strlen(_imeprezime) + 1, _imeprezime);
		strcpy_s(JMBG, strlen(jmbgg) + 1, jmbgg);
	}
	Osoba( Osoba &original)
	{

		imePrezime = new char[strlen(original.imePrezime) + 1];
		JMBG = new char[strlen(original.JMBG) + 1];

		strcpy_s(imePrezime, strlen(original.imePrezime) + 1, original.imePrezime);
		strcpy_s(JMBG, strlen(original.JMBG) + 1, original.JMBG);
		
	}
	
	void Info() 
	{
		cout << GetIme << endl;
		cout << GetJMBG << endl;

	}


	~Osoba() 
	{
		delete[]imePrezime ;
		delete[] JMBG;
	}
};

class Zaposlenik : public Osoba {//neka Zaposlenik bude izvedena klasa od klase Osoba
protected: int godineRadnogStaza;
public:

	Zaposlenik(const char _imeprezime[] = "-----", const char jmbgg[] = "////",int _godineRadnogStaza=0)
		:Osoba (_imeprezime,jmbgg)
	{
		godineRadnogStaza = _godineRadnogStaza;
	}

	Zaposlenik(Zaposlenik &original)
	{
		Osoba(original.GetIme, original.GetJMBG);
		godineRadnogStaza = original.godineRadnogStaza;

	}
	//defualtni konstruktor, koji puni samo 'testnim' vrijednostima atribute
	//konstruktor koji prima imePrezime, JMBG
	//konstruktor kopije

	void Info() 
	{
		Osoba::Info();
		cout << "God staza: " << godineRadnogStaza << endl;
	}
};

void main() {


	system("pause>0");
}

