#include <iostream>
using namespace std;
class PolozeniPredmet {
public: char * _naziv;
public: int _ocjena;


		PolozeniPredmet(char ime[] = "ime", int ocjena = 0)
		{
			_naziv = new char[strlen(ime) + 1];
			strcpy_s(_naziv, strlen(ime) + 1, ime);

			_ocjena = _ocjena;

		}

		PolozeniPredmet(PolozeniPredmet &original) //kopije
		{
			_naziv = new char[strlen(original._naziv) + 1];
			strcpy_s(_naziv, strlen(original._naziv) + 1, original._naziv);
			_ocjena = original._ocjena;

		}

		~PolozeniPredmet() {
			delete[]_naziv;
			_naziv = nullptr;

		}


		//Napraviti
		//1. Defaultni konstruktor		//2. Konstruktor koji prima parametre:naziv i ocjena
		//3. Konstruktor kopije
		//4. Destruktor
		//5. Funkcije definisane ispod


		void Kopiraj(const PolozeniPredmet & original) {
			_naziv = new char[strlen(original._naziv) + 1];
			strcpy_s(_naziv, strlen(original._naziv) + 1, original._naziv);
			_ocjena = original._ocjena;

			//Kopira vrijednosti iz proslijeðenog objekta u trenutni


		};




		class KolekcijaPolozenih {
			PolozeniPredmet * _polozeni;
			int _trenutno;
			int _max;
		public:



			KolekcijaPolozenih(int max=4)
			{
				_trenutno = 0;
				_max = max;
				_polozeni = new PolozeniPredmet[max];
			}



			KolekcijaPolozenih(KolekcijaPolozenih&original)//kopije
			{
				_trenutno = original._trenutno;
				_max = original._max;
				_polozeni = new PolozeniPredmet[_max];

				for (int i = 0; i < _trenutno; i++)
				{
					_polozeni[i].Kopiraj(original._polozeni[i]);
				}
			}

			~KolekcijaPolozenih()
			{
				delete[] _polozeni;
			}
			//konstruktor, 
			//konstruktor kopije, 
			//destruktor 
			//potrebne funkcije

			void AddPolozeniPredmet(PolozeniPredmet & original) {
				for (int i = 0; i < _trenutno; i++)
				{
					if (strcmp(_polozeni[_trenutno]._naziv, original._naziv) == 0)
						return;
				}

				_polozeni[_trenutno].Kopiraj(original);
				_trenutno++;
				//Dodaje novi polozeni predmet u niz
				//Voditi raèuna da se ne moze dodavati isti predmet (istog naziva)

			}

			void ispis() 
			{
				cout<<
			}
		};



		void main()
		{


			system("pause>0");
		}