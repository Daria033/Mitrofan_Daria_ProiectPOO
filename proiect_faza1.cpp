// proiectprimafaza.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Mitrofan Daria - Medical

#include <iostream>
using namespace std;

class Spital
{
private:
	const string adresa;
	string nume;
	int nrMedici;
	int nrSpecializari;
	string* numeSpecializari;
	bool areDepartamente;
	static int anInfiintare;
public:

	Spital() :adresa("Brasov")
	{
		string nume[] = { "Ortopedie", "Chirurgie generala", "Reumatologie" };
		this->nume = "de Urgenta 'Sfantul Constantin'";
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

	Spital(const Spital& s): adresa(adresa){
		this->nume = s.nume;
		this->nrMedici = s.nrMedici;
		this->nrSpecializari = s.nrSpecializari;
		if (this->numeSpecializari != NULL) {
			delete[]this->numeSpecializari;
		}
		this->numeSpecializari = new string[nrSpecializari];
		for (int i = 0; i < nrSpecializari; i++) {
			this->numeSpecializari[i] = s.numeSpecializari[i];
		}
		this->areDepartamente = s.areDepartamente;
	}

	const string getAdresa() {
		return this->adresa;
	}
	string getNume() {
		return this->nume;
	}
	int getNrMedici() {
		return this->nrMedici;
	}
	int getNrSpecializari() {
		return nrSpecializari;
	}
	string* getNumeSpecializari() {
		return numeSpecializari;
	}
	bool getAreDepartament() {
		return this->areDepartamente;
	}
	static int getInfiintare() {
		return Spital::anInfiintare;
	}


	void setNume(string nume) {
		this->nume = nume;
	}
	void setNrMedici(int nrMedici) {
		this->nrMedici = nrMedici;
	}
	void setSpecializari(int nrSpecializari, string* numeSpecializari) {
		if (nrSpecializari > 0) {
			this->nrSpecializari = nrSpecializari;
			if (this->numeSpecializari != NULL) {
				delete[] this->numeSpecializari;
			}
			this->numeSpecializari = new string[nrSpecializari];
			for (int i = 0;i < nrSpecializari;i++) {
				this->numeSpecializari[i] = numeSpecializari[i];
			}
		}
	}
	static void setInfiintare(int anInfiintare) {
		Spital::anInfiintare = anInfiintare;
	}


	friend istream& operator>>(istream& in, Spital& spital);

	friend ostream& operator<<(ostream& out, Spital& spital);
	

	/*const string adresa;
	string nume;
	int nrMedici;
	int nrSpecializari;
	string* numeSpecializari;
	bool areDepartamente;
	static int anInfiintare;*/


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

istream& operator>>(istream& in, Spital& spital) {
	cout << "Spitalul "; in >> spital.nume; 
	//cout << " Orasul in care se afla spitalul este: "; in >> spital.adresa;
	cout << "Nr. medici: "; in >> spital.nrMedici;
	cout << "Nr. de specializari: "; in >> spital.nrSpecializari;
	if (spital.numeSpecializari) {
		delete[]spital.numeSpecializari;
	}
	spital.numeSpecializari = new string[spital.nrSpecializari];
	cout << "Specializarile sunt: ";
	for (int i = 0; i < spital.nrSpecializari; i++) {
		in >> spital.numeSpecializari[i];
	}
	cout << " Aceasta s-a infiintat in anul: "; in >> spital.anInfiintare;
	cout << endl;
	return in;
}

ostream& operator<<(ostream& out, Spital& spital) {
	out << "Spitalul " << spital.nume << " are " << spital.nrMedici << " de medici si " << spital.nrSpecializari << " specializari. Acestea sunt: " << spital.numeSpecializari;
	if (spital.nrSpecializari != NULL) {
		for (int i = 0;i < spital.nrSpecializari;i++) {
			out << spital.numeSpecializari[i] << ", ";
		}
	}
	else {
		out << " - ";
	}
	
	return out;
}

//
//out << "Orasul " << oras.nume << " are suprafata de " << oras.suprafata << " si populatia de " << oras.populatie << ". Varste locuitori: " << oras.varsteLocuitori;
//if (oras.populatie != NULL) {
//	for (int i = 0;i < oras.populatie;i++) {
//		out << oras.varsteLocuitori[i] << ", ";
//	}
//}
//else {
//	out << "-";
//}
//out << endl;
//return out;
//}



class Pacient {
private:
	const int id;
	string nume;
	int nrPacienti;
	int* varstePacienti;
	static int gradSeveritate;
public:
	Pacient() :id(100) {
		this->nume = "Anonim";
		this->nrPacienti = 0;
		this->varstePacienti = NULL;
	}

	Pacient(int id, string nume, int nrPacienti, int* varstePacienti) :id(id) {
		this->nume = nume;
		this->nrPacienti = nrPacienti;
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

	Pacient(const Pacient& p) :id(p.id) {
		this->nume = p.nume;
		this->nrPacienti = p.nrPacienti;
		if (nrPacienti != 0) {
			this->varstePacienti = new int[nrPacienti];
			for (int i = 0;i < nrPacienti;i++)
			{
				this->varstePacienti[i] = p.varstePacienti[i];
			}
		}
		else
		{
			this->varstePacienti = NULL;
		}

	}

	const int getId() {
		return this->id;
	}
	string getNume() {
		return this->nume;
	}
	int getNrPacienti() {
		return this->nrPacienti;
	}
	int* getVarstePacienti() {
		return this->varstePacienti;
	}
	static int getGrad() {
		return Pacient::gradSeveritate;
	}

	void setNume(string nume) {
		this->nume = nume;
	}
	void setPacienti(int nrPacienti, int* varstePacienti) {
		if (nrPacienti > 0) {
			this->nrPacienti = nrPacienti;
			if (this->varstePacienti != NULL) {
				delete[] this->varstePacienti;
			}
			this->varstePacienti = new int[nrPacienti];
			for (int i = 0;i < nrPacienti;i++) {
				this->varstePacienti[i] = varstePacienti[i];
			}
		}
	}
	static void setGrad(int gradSeveritate) {
		Pacient::gradSeveritate = gradSeveritate;

	}

	/*const int id;
	string nume;
	int nrPacienti;
	int* varstePacienti;
	static int gradSeveritate;*/

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
private:
	const int id;
	string nume;
	float pret;
	int nrSubstante;
	string* substanteActive;
	static int nrMaximSubstante;
public:
	Medicamente() : id(100) {
		this->nume = "Necunoscut";
		this->pret = 0;
		this->nrSubstante = 0;
		this->substanteActive = NULL;
	}

	Medicamente(int id, string nume, float pret, int nrSubstante, string* substanteActive) : id(id) {
		this->nume = nume;
		this->pret = pret;
		this->nrSubstante = nrSubstante;
		this->substanteActive = substanteActive;
		if (nrSubstante != 0) {
			this->substanteActive = new string[nrSubstante];
			for (int i = 0; i < nrSubstante; i++) {
				this->substanteActive[i] = substanteActive[i];
			}
		}
		else {
			this->substanteActive = NULL;
		}
	}


	Medicamente(int idNou, string nume) : id(idNou) {
		this->nume = nume;
		this->pret = 3.49;
		this->nrSubstante = 0;
		this->substanteActive = NULL;
	}

	~Medicamente() {
		if (this->substanteActive != NULL) {
			delete[] this->substanteActive;
		}
	}

	Medicamente(const Medicamente& m) :id(id) {
		this->nume = m.nume;
		this->pret = m.pret;
		this->nrSubstante = m.nrSubstante;
		this->substanteActive = m.substanteActive;
		if (nrSubstante != 0) {
			this->substanteActive = new string[nrSubstante];
			for (int i = 0; i < nrSubstante; i++) {
				this->substanteActive[i] = m.substanteActive[i];
			}
		}
		else {
			this->substanteActive = NULL;
		}

	}

	const int getId() {
		return this->id;
	}
	string getNume() {
		return this->nume;
	}
	float getPret() {
		return this->pret;
	}
	int getNrSubstante() {
		return this->nrSubstante;
	}
	string* getSubstanteActive() {
		return this->substanteActive;
	}
	static int getMaxSubstante() {
		return Medicamente::nrMaximSubstante;
	}


	void setNume(string nume) {
		this->nume = nume;
	}
	void setPret(float pret) {
		this->pret = pret;
	}
	void setSubstante(int nrSubstante, string* substanteActive) {
		if (nrSubstante > 0) {
			this->nrSubstante = nrSubstante;
			if (this->substanteActive != NULL) {
				delete[] this->substanteActive;
			}
			this->substanteActive = new string[nrSubstante];
			for (int i = 0;i < nrSubstante;i++) {
				this->substanteActive[i] = substanteActive[i];
			}
		}
	}
	static void setMaxSubstante(int nrMaximSubstante) {
		Medicamente::nrMaximSubstante = nrMaximSubstante;
	}

	/*const int id;
	string nume;
	float pret;
	int nrSubstante;
	string* substanteActive;
	static int nrMaximSubstante;*/

	void afisare() {
		cout << id << " . " << "Nume medicament: " << nume << " . Pret: " << pret << "."<<endl<< "Nr.maxim de substante active este : " << nrMaximSubstante << "." << " Nr. substante:" << nrSubstante << ". Substantele active pe care le contine medicamentul : ";
		if (substanteActive != NULL) {
			for (int i = 0; i < this->nrSubstante; i++) {
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
{   //Spital
	cout << "Spitale:" << endl;
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

	Spital spital4 = spital1;
	spital4.afisare();
	cout << endl;

	Spital spital5;
	cout << spital5.getAdresa() << endl;
	cout << "Spitalul " << spital5.getNume() << endl;
	cout << "Nr. medici: " << spital5.getNrMedici() << endl;
	cout << "Nr. specializari: " << spital5.getNrSpecializari() << endl;
	cout << "Specializari: ";
	for (int i=0;i < spital5.getNrSpecializari();i++) {
		cout << spital5.getNumeSpecializari()[i] << ", ";
	}
	cout << endl;
	cout << "Anul de infiintare este: " << spital5.getInfiintare() << endl;
	cout << endl;

	string numeNoi[] = { "Cardiologie", "Ortopedie" };
	spital5.setNume("Spitalul Clinic Municipal de Urgenta");
	spital5.setNrMedici(67);
	spital5.setSpecializari(2, numeNoi);
	spital5.setInfiintare(1928);
	cout << spital5.getNume() << endl;
	cout << "Nr. medici: " << spital5.getNrMedici() << endl;
	cout << "Nr. specializari: " << spital5.getNrSpecializari() << endl;
	cout << "Specializari: ";
	for (int i = 0;i < spital5.getNrSpecializari();i++) {
		cout << spital5.getNumeSpecializari()[i] << ", ";
	}
	cout << endl;
	cout << "Anul de infiintare este: " << spital5.getInfiintare() << endl;
	cout << endl;
	cout << endl;

	//Spital spital6;
	cin >> spital2;
	cout << spital2;
	cout << endl;
	cout << endl;



    //Pacienti
	cout << "Pacienti:" << endl;
	int varste[] = {14,21,32};
	Pacient pacient1;
	pacient1.afisare();
	Pacient pacient2(2, "Bogdan", 3, varste);
	pacient2.afisare();
	Pacient pacient3(7, "Andrei");
	pacient3.afisare();
	cout << endl;
	Pacient pacient4 = pacient1;
	pacient4.afisare();
	cout << endl;

	Pacient pacient5;
	cout << pacient5.getId() << endl;
	cout << "Nume: " << pacient5.getNume() << endl;
	cout << "Nr. pacienti: " << pacient5.getNrPacienti() << endl;
	cout << "Varstele pacientilor: -";
	for (int i = 0;i < pacient5.getNrPacienti();i++) {
		cout << pacient5.getVarstePacienti()[i] << endl;
	}
	cout << endl;
	cout << "Grad severitate: " << pacient5.getGrad() << endl;
	cout << endl;

	int varsteNoi[] = { 22,41 };
	pacient5.setNume("Ana");
	pacient5.setPacienti(2, varsteNoi);
	pacient5.setGrad(3);
	cout << "Nume: " << pacient5.getNume() << endl;
	cout << "Nr. pacienti: " << pacient5.getNrPacienti() << endl;
	cout << "Varstele pacientilor: ";
	for (int i = 0;i < pacient5.getNrPacienti();i++) {
		cout << pacient5.getVarstePacienti()[i] <<  ", ";
	}
	cout << endl;
	cout << "Grad severitate: " << pacient5.getGrad() << endl;
	cout << endl;


	//Medicamente
	cout << "Medicamente:" << endl;
	string substante[] = {"Amoxicilina","Acid clavulanic"};
	Medicamente medicament1;
	medicament1.afisare();
	cout << endl;
	Medicamente medicament2(200, "Augmentin", 21.68, 2, substante);
	medicament2.afisare();
	cout << endl;
	Medicamente medicament3(300, "Paracetamol");
	medicament3.afisare();
	cout << endl;
	Medicamente medicament4 = medicament2;
	medicament4.afisare();
	cout << endl;
	cout << endl;

	Medicamente med5;
	cout << med5.getId() << endl;
	cout << "Nume medicament: " << med5.getNume() << endl;
	cout << "Pret: " << med5.getPret() << endl;
	cout << "Nr substante active: " << med5.getNrSubstante() << endl;
	cout << "Substante active: -";
	for (int i = 0;i < med5.getNrSubstante();i++) {
		cout << med5.getSubstanteActive()[i] << endl;
	}
	cout << endl;
	cout << "Nr. maxim de substante active: " << med5.getMaxSubstante() << endl;
	cout << endl;
	
	string substanteNoi[] = { "Clorhidratul de drotaverina" };
	med5.setNume("No-Spa");
	med5.setPret(15.98);
	med5.setSubstante(1, substanteNoi);
	cout << "Nume medicament: " << med5.getNume() << endl;
	cout << "Pret: " << med5.getPret() << endl;
	cout << "Nr substante active: " << med5.getNrSubstante() << endl;
	cout << "Substanta activa: ";
	for (int i = 0;i < med5.getNrSubstante();i++) {
		cout << med5.getSubstanteActive()[i] << endl;
	}
}
