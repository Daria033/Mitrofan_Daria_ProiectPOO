// proiectprimafaza.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Mitrofan Daria - Medical

#include <iostream>
using namespace std;

class Spital
{
public:
	const string adresa;
	string nume;
	int nrMedici;
	int nrSpecializari;
	string* numeSpecializari;
	bool areDepartamente;
	static int anInfiintare;


	Spital() :adresa("Brasov")
	{
		string nume[] = { "Ortopedie", "Chirurgie generala", "Reumatologie" };
		this->nume = "Spitalul de Urgenta 'Sfantul Constantin'";
		this->nrMedici = 90;
		this->nrSpecializari = 3;
		if (this->numeSpecializari != NULL)
		{
			delete[]this->numeSpecializari;
		}
		this->numeSpecializari = new string[nrSpecializari];
		for (int i = 0; i < nrSpecializari; i++)
		{
			this->numeSpecializari[i] = nume[i];
		}

		this->areDepartamente = true;
	}

	Spital(const string adresa, string nume, int nrMedici, int nrSpecializari, string* numeSpecializari, bool areDepartamente) :adresa(adresa)
	{
		this->nume = nume;
		this->nrMedici = nrMedici;
		this->nrSpecializari = nrSpecializari;
		if (this->numeSpecializari != NULL) {
			delete[]this->numeSpecializari;
		}
		this->numeSpecializari = new string[nrSpecializari];
		for (int i = 0; i < nrSpecializari; i++) {
			this->numeSpecializari[i] = numeSpecializari[i];
		}
		this->areDepartamente = areDepartamente;

	}

	Spital(string adresanoua, string nume) :adresa(adresanoua) {
		this->nume = nume;
	}

	~Spital()
	{
		if (this->numeSpecializari != NULL) {
			delete[]this->numeSpecializari;
		}
	}



	void afisare() {
		cout << "Spitalul " << nume << " se afla in orasul " << adresa << " si are un numar de " << nrMedici << " medici si " << nrSpecializari << " specializari: ";
		for (int i = 0; i < this->nrSpecializari; i++) {
			cout << numeSpecializari[i] << ", ";
		}
		cout << (areDepartamente ? " Spitalul are departamente. " : " Spitalul nu are departamente. ");
		cout << " Aceasta s-a infiintat in anul " << anInfiintare;
		cout << endl;
	}


}; int Spital::anInfiintare = 1923;




class Pacient {
public:
	const int id;
	string nume;
	int nrPacienti;
	int* varstePacienti;
	static int gradSeveritate;

	Pacient() :id(100) {
		this->nume = "Pacient";
		this->nrPacienti = 0;
		this->varstePacienti = NULL;
	}

	Pacient(int id, string nume, int nrPacienti, int* varstePacienti) :id(id), nume(nume), nrPacienti(nrPacienti) {
		if (nrPacienti != 0) {
			this->varstePacienti = new int[nrPacienti];
			for (int i = 0;i < nrPacienti;i++)
			{
				this->varstePacienti[i] = varstePacienti[i];
			}
		}
		else
		{
			this->varstePacienti = NULL;
		}
	}

	Pacient(int idnou, string nume) :id(idnou) {
		this->nume = nume;
		this->nrPacienti = 0;
		this->varstePacienti = NULL;
	}

	~Pacient() {
		if (this->varstePacienti != NULL) {
			delete[]this->varstePacienti;
		}
	}


	void afisare() {
		cout << id << " . " << " Numele: " << nume << " . " << "  Grad severitate: " << gradSeveritate << ". Nr pacienti " << nrPacienti << " , varste: ";
		if (varstePacienti != NULL)
		{
			for (int i = 0; i < nrPacienti; i++) {
				cout << varstePacienti[i] << " , ";
			}
		}
		else {
			cout << " - ";
		}
		cout << endl;
	}

};
int Pacient::gradSeveritate = 4;





class Medicamente {
public:
	const int id;
	string nume;
	float pret;
	string* substanteActive;
	static int nrMaximSubstante;

	Medicamente() : id(100) {
		this->nume = "Paracetamol";
		this->pret = 3.49;
		this->substanteActive = NULL;
	}

	Medicamente(int id, string nume, float pret, string* substanteActive) : id(id), nume(nume), pret(pret) {
		if (substanteActive != NULL) {
			this->substanteActive = new string[3];
			for (int i = 0; i < 3; i++) {
				this->substanteActive[i] = substanteActive[i];
			}
		}
		else {
			this->substanteActive = NULL;
		}
	}

	Medicamente(int idNou, string nume) : id(idNou) {
		this->nume = nume;
		this->pret = 0.0;
		this->substanteActive = NULL;
	}

	~Medicamente() {
		if (this->substanteActive != NULL) {
			delete[] this->substanteActive;
		}
	}

	void afisare() {
		cout << id << " . " << "Numele: " << nume << " . Pret: " << pret << ". Nr. maxim de substante active este:" << nrMaximSubstante << ". Substantele active pe care le contine medicamentul: ";
		if (substanteActive != NULL) {
			for (int i = 0; i < 2; i++) {
				cout << substanteActive[i] << " , ";
			}
		}
		else {
			cout << " - ";
		}
		cout << endl;
	}
};
int Medicamente::nrMaximSubstante = 5;



void main()
{
	string nume[] = { " Chirurgie cardiovasculara ", "Cardiologie","Pneumologie", "Endocrinologie" };
	Spital spital1;
	spital1.afisare();
	cout << endl;
	Spital spital2("Bucuresti", "de Urgenta 'Sfantul Pantelimon'", 140, 4, nume, true);
	spital2.afisare();
	cout << endl;
	Spital spital3("Iasi", "de Urgenta 'Sfantul Mihail'");
	spital3.afisare();
	cout << endl;



	int* varste;
	varste = new int[2];
	varste[0] = 4;
	varste[1] = 12;
	varste[2] = 32;

	Pacient pacient1;
	pacient1.afisare();
	Pacient pacient2(2, "Bogdan", 3, varste);
	pacient2.afisare();
	Pacient pacient3(7, "Andrei");
	pacient3.afisare();
	cout << endl;



	string* substante;
	substante = new string[3];
	substante[0] = "Amoxicilina";
	substante[1] = "Acid clavulanic";
	Medicamente medicament1;
	medicament1.afisare();
	Medicamente medicament2(200, "Augmentin", 21.68, substante);
	medicament2.afisare();
	Medicamente medicament3(300, "No-Spa");
	medicament3.afisare();

}
