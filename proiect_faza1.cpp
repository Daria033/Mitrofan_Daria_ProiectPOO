// proiectprimafaza.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Mitrofan Daria - Medical

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
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
		/*if (this->numeSpecializari != NULL)
		{
			delete[]this->numeSpecializari;
		}*/
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

	//Constructor de copiere
	Spital(const Spital& s): adresa(s.adresa){
		this->nume = s.nume;
		this->nrMedici = s.nrMedici;
		this->nrSpecializari = s.nrSpecializari;

		/*if (this->numeSpecializari != NULL) {
			delete[] this->numeSpecializari;
		}*/

		if (this->nrSpecializari > 0) {
			this->numeSpecializari = new string[nrSpecializari];
			for (int i = 0; i < nrSpecializari; i++) {
				this->numeSpecializari[i] = s.numeSpecializari[i];
			}
		}
		else this->numeSpecializari = NULL;
		
		this->areDepartamente = s.areDepartamente;
	}

	//Getteri
	const string getAdresa() {
		return this->adresa;
	}
	string getNume() const{
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

	//Setteri
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

	//Functii prietene
	friend istream& operator>>(istream& in, Spital& spital);

	friend ostream& operator<<(ostream& out, const Spital& spital);
	

	/*const string adresa;
	string nume;
	int nrMedici;
	int nrSpecializari;
	string* numeSpecializari;
	bool areDepartamente;
	static int anInfiintare;*/


	void afisare() const {
		cout << "Spitalul " << nume << " se afla in orasul " << adresa << " si are un numar de " << nrMedici << " medici si " << nrSpecializari << " specializari: ";
		for (int i = 0; i < this->nrSpecializari; i++) {
			cout << numeSpecializari[i] << ", ";
		}
		cout << (areDepartamente ? " Spitalul are departamente. " : " Spitalul nu are departamente. ");
		cout << " Aceasta s-a infiintat in anul " << anInfiintare;
		cout << endl;
	}

	//Operatorul =
	//evitarea auto-asignarii
	Spital& operator=(const Spital& s) {
		if (this != &s) {
			this->nume = s.nume;
			this->nrMedici = s.nrMedici;
			this->nrSpecializari = s.nrSpecializari;
			
			if (this->numeSpecializari != NULL) {
				delete[]this->numeSpecializari;
			}
			if (this->nrSpecializari > 0) {
				this->numeSpecializari = new string[nrSpecializari];
			    for (int i = 0; i < nrSpecializari; i++) {
				     this->numeSpecializari[i] = s.numeSpecializari[i];
			    }
			}
			else this->numeSpecializari = NULL;
			
			this->areDepartamente = s.areDepartamente;
		}
		return *this;
	}


	//Operator de indexare
	Spital operator++() {
		this->nrMedici;
		return *this;
	}

	Spital operator++(int) {
		Spital aux = *this;
		this->nrMedici++;
		return aux;
	}




	//Operator +=
	Spital& operator+=(string nume) {
		string* numeSpecializari = new string[nrSpecializari + 1];
		for (int i = 0;i < nrSpecializari;i++) {
			numeSpecializari[i] = this->numeSpecializari[i];
		}
		numeSpecializari[nrSpecializari] = nume;
		nrSpecializari++;
		if (this->numeSpecializari != NULL) {
			delete[] this->numeSpecializari;
		}
		this->numeSpecializari = numeSpecializari;
		return *this;

	}

	//Activitate& operator +=(Activitate a) {
	//	this->durata += a.durata;
	//	return *this;
	//}

	Spital& operator+=(Spital s) {
		this->nrMedici += s.nrMedici;
		return *this;
	}

	//Operatorul cast
	operator int() {
		return this->nrMedici;
	}


	//Operatorul index
	string& operator[](int index) {
		if (index >= 0 && index < this->nrSpecializari) {
			return this->numeSpecializari[index];
		}
	}



	friend ifstream& operator>>(ifstream& in, Spital& spital);

	friend ofstream& operator<<(ofstream& out, const Spital& spital);


	

}; 
int Spital::anInfiintare = 1923;

//Operatorul >>
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
//ostream& operator<<(ostream& out, const Spital& spital) {
//	 Implementarea afișării obiectului Spital
//	out << "Spitalul " << spital.nume << " ... "; // Adăugați detaliile necesare
//	return out;
//}

ostream& operator<<(ostream& out, const Spital& spital) {
	out << "Spitalul " << spital.nume << " are " << spital.nrMedici << " de medici si " << spital.nrSpecializari << " specializari. Acestea sunt: ";
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


ifstream& operator>>(ifstream& in, Spital& spital) {
    in >> spital.nume;
	in >> spital.nrMedici;
	 in >> spital.nrSpecializari;
	if (spital.numeSpecializari) {
		delete[]spital.numeSpecializari;
	}
	spital.numeSpecializari = new string[spital.nrSpecializari];
	
	for (int i = 0; i < spital.nrSpecializari; i++) {
		in >> spital.numeSpecializari[i];
	}
 
	return in;
}

ofstream& operator<<(ofstream& out, const Spital& spital) {
	out << spital.nume << endl;
	out << spital.nrMedici << endl;
	out << spital.nrSpecializari << endl;
	if (spital.nrSpecializari != NULL) {
		for (int i = 0;i < spital.nrSpecializari;i++) {
			out << spital.numeSpecializari[i] << endl;
		}
	}

	return out;
}




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

	//Constructor de copiere
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

	//Getteri
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

	//Setteri
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

	void afisare() const {
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

	//Operator =
	Pacient& operator=(const Pacient& p) {
		if (this != &p) {
			this->nume = p.nume;
			this->nrPacienti = p.nrPacienti;
			if (nrPacienti != 0) {
				this->varstePacienti = new int[nrPacienti];
				for (int i = 0;i < nrPacienti;i++)
				{
					this->varstePacienti[i] = p.varstePacienti[i];
				}
			}
			
		}
		else {
			this->varstePacienti = NULL;
	    }
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Pacient& pacient);

	//Operator --

	Pacient& operator--() {
		if (this->nrPacienti > 0) {
			this->nrPacienti = this->nrPacienti - 1;
		}
		return *this;
	}
	Pacient& operator--(int n) {
		Pacient aux = *this;
		if (this->nrPacienti > 0) {
			this->nrPacienti = this->nrPacienti - 1;
		}
		return aux;
	}

	//OPerator cast
	operator int() {
		return this->nrPacienti;
	}

	//Operator+=
	Pacient& operator+=(const Pacient& p) {
		int* varsteNoi = new int[this->nrPacienti + p.nrPacienti];

		// Copiem varstele existente
		for (int i = 0; i < this->nrPacienti; ++i) {
			varsteNoi[i] = this->varstePacienti[i];
		}

		// Adăugăm varstele pacientului p
		for (int i = 0; i < p.nrPacienti; ++i) {
			varsteNoi[this->nrPacienti + i] = p.varstePacienti[i];
		}

		delete[] this->varstePacienti;  // Eliberăm memoria veche
		this->varstePacienti = varsteNoi;
		this->nrPacienti += p.nrPacienti;

		return *this;
	}

	friend istream& operator>>(istream& in, Pacient& pacient);
		
	friend ifstream& operator>>(ifstream& in, Pacient& pacient);
	friend ofstream& operator<<(ofstream& out, const Pacient& pacient);

};
int Pacient::gradSeveritate = 4;



istream& operator>>(istream& in, Pacient& pacient) {
	cout << "Numele pacientului: ";
	in >> pacient.nume;
	cout << endl << "Nr. pacienti: ";
	in >> pacient.nrPacienti;

	if (pacient.varstePacienti != NULL) {
		delete[] pacient.varstePacienti;
	}
	pacient.varstePacienti = new int[pacient.nrPacienti];
	for (int i=0;i < pacient.nrPacienti;i++) {
		cout << endl << "Varstele pacientilor: ";
		in >> pacient.varstePacienti[i];
	}
	return in;
}

ostream& operator<<(ostream& out, const Pacient& pacient) {
	out << "Pacientii cu numele: " << pacient.nume <<endl<< "Nr. de pacienti este de: " << pacient.nrPacienti << endl << "Varstele pacientilor sunt: ";
	if (pacient.nrPacienti != NULL) {
		for (int i = 0;i < pacient.nrPacienti;i++) {
			out << pacient.varstePacienti[i] << ", ";
		}
	}
	else {
		out << " - ";
	}

	return out;
}



ifstream& operator>>(ifstream& in, Pacient& pacient) {
	in >> pacient.nume;
	in >> pacient.nrPacienti;

	if (pacient.varstePacienti != NULL) {
		delete[] pacient.varstePacienti;
	}
	pacient.varstePacienti = new int[pacient.nrPacienti];
	for (int i = 0;i < pacient.nrPacienti;i++) {
		in >> pacient.varstePacienti[i];
	}
	return in;
}

ofstream& operator<<(ofstream& out, const Pacient& pacient) {
	out << pacient.nume << endl;
	out << pacient.nrPacienti << endl;
	if (pacient.nrPacienti != NULL) {
		for (int i = 0;i < pacient.nrPacienti;i++) {
			out << pacient.varstePacienti[i];
		}
	}

	return out;
}





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

	//Constructor de copiere
	Medicamente(const Medicamente& m) :id(m.id) {
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

	//Getteri
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

	//Setteri
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

	void afisare() const {
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

	//Operator =
	Medicamente& operator=(const Medicamente& m) {
		if (this != &m) {
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

		}
		else {
			this->substanteActive = NULL;
		}
		return *this;
	}

	
	
	//Operator +=
	Medicamente& operator+=(const Medicamente& m) {
		this->pret += m.pret;
		return *this;
	}

	//Operator ==
	bool operator==(const Medicamente& m) const {
		if (this->id != m.id || this->nume != m.nume || this->pret != m.pret || this->nrSubstante != m.nrSubstante) {
			return false;
		}

		// Comparam elementele din vectorul substanteActive
		for (int i = 0; i < this->nrSubstante; ++i) {
			if (this->substanteActive[i] != m.substanteActive[i]) {
				return false;
			}
		}

		return true;
	}

	//Operator de scădere -
	Medicamente operator-(const Medicamente& m) const {
		Medicamente diferenta = *this;
		diferenta.pret -= m.pret;
		return diferenta;
	}

	friend ostream& operator<<(ostream& out, const Medicamente& medicament);

	friend istream& operator>>(istream& in, Medicamente& medicament);




	//void scrieInFisierBinar(fstream& f) {
	//	//		f.write((char*)&this->RAM, sizeof(int));
	//	//		int lungime = strlen(this->tipCPU);
	//	//		f.write((char*)&lungime, sizeof(int));
	//	//		for (int i = 0; i < lungime; i++) {
	//	//			f.write((char*)&this->tipCPU[i], sizeof(char));
	//	//		}
	//	//		f.write((char*)&this->rezolutieEcran, sizeof(float));
	//	//		f.write((char*)&this->cameraWeb, sizeof(bool));
	//	//	}
	//	//

	//void scrieInFisierBinar(fstream& f) {
	//	f.write((char*)&this->nume, sizeof(string));
	//	f.write((char*)&this->pret, sizeof(float));
	//	f.write((char*)&this->nrSubstante, sizeof(int));


	//	int lungime = strlen(this->substanteActive.c_str());
	//	for (int i = 0;i < lungime;i++) {
	//		f.write((char*)&this->substanteActive[i], sizeof(string));
	//	}


	//}

		/*const int id;
string nume;
float pret;
int nrSubstante;
string* substanteActive;
static int nrMaximSubstante;*/

	void serializare(string numeFisier) {
		ofstream fisierBinar(numeFisier, ios::out, ios::binary);
		int lungimeNume = this->nume.size();
		fisierBinar.write((char*)&lungimeNume, sizeof(lungimeNume));
		fisierBinar.write(this->nume.c_str(), lungimeNume + 1);

		fisierBinar.write((char*)&this->pret, sizeof(pret));
		fisierBinar.write((char*)&this->nrSubstante, sizeof(nrSubstante));

		for (int i = 0;i < this->nrSubstante;i++) {
			int lungimeSubstanteActive = this->substanteActive[i].size();
			fisierBinar.write((char*)&lungimeSubstanteActive, sizeof(lungimeSubstanteActive));
			fisierBinar.write(this->substanteActive[i].c_str(), lungimeSubstanteActive + 1);

		}
		fisierBinar.close();
	
	
	}


	void deserializare(string numeFisier) {
		ifstream fisierBinar(numeFisier, ios::in, ios::binary);
		if (fisierBinar.is_open()) {
			if (this->substanteActive != NULL) {
				delete[] this->substanteActive;
		    }
			int lungimeNume = 0;
			fisierBinar.read((char*)&lungimeNume, sizeof(lungimeNume));
			char* aux = new char[lungimeNume + 1];
			fisierBinar.read(aux, lungimeNume + 1);
			this->nume = aux;
			delete[]aux;

			fisierBinar.read((char*)&this->pret, sizeof(pret));
			fisierBinar.read((char*)&this->nrSubstante, sizeof(nrSubstante));

			this->substanteActive = new string[this->nrSubstante];
			for (int i = 0;i < this->nrSubstante;i++) {
				int lungimeSubstanteActive = 0;
				fisierBinar.read((char*)&lungimeSubstanteActive, sizeof(lungimeSubstanteActive));
				char* aux1 = new char[lungimeSubstanteActive + 1];
				fisierBinar.read(aux1, lungimeSubstanteActive + 1);
				this->substanteActive[i] = aux1;
				delete[]aux1;
			}
		}
		else {
			cout << "Fisierul binar nu a fost gasit.";
		}
		

	}





};
int Medicamente::nrMaximSubstante = 5;


 istream& operator>>(istream& in, Medicamente& medicament) {
	cout << "Medicamentul: ";
	in >> medicament.nume;
	cout << endl << "Pretul medicamentului: ";
	in >> medicament.pret;
	cout << endl << "Nr. substante active: ";
	in >> medicament.nrSubstante;
	if (medicament.substanteActive != NULL) {
		delete[] medicament.substanteActive;
	}
	medicament.substanteActive = new string[medicament.nrSubstante];
	for (int i=0;i < medicament.nrSubstante;i++) {
		cout << endl << "Nume substante active: ";
		in >> medicament.substanteActive[i];
	}
	return in;
}

ostream& operator<<(ostream& out, const Medicamente& medicament) {
	out << "Medicamentul: " << medicament.nume << endl << "Pretul este: " << medicament.pret << endl << "Nr. de substante active: ";
	if (medicament.nrSubstante != NULL) {
		for (int i = 0;i < medicament.nrSubstante;i++) {
			out << medicament.substanteActive[i] << ", ";
		}
	}
	else {
		out << " - ";
	}

	return out;
}





class SectieSpital {
private:
	const Spital& spital;
	string numeSectie;
	int nrMediciSectie;

public:
	// Constructor
	SectieSpital(const Spital& spital, const string& numeSectie, int nrMediciSectie)
		: spital(spital), numeSectie(numeSectie), nrMediciSectie(nrMediciSectie) {}

	// Getteri
	Spital getSpital() const {
		return spital;
	}

	string getNumeSectie() const {
		return numeSectie;
	}

	int getNrMediciSectie() const {
		return nrMediciSectie;
	}

	// Setteri
	void setNumeSectie(const string& nume) {
		numeSectie = nume;
	}

	void setNrMediciSectie(int nrMedici) {
		nrMediciSectie = nrMedici;
	}

	
	void afisareDetalii() const {
    cout << "Sectia " << numeSectie << " din cadrul spitalului " << spital.getNume()
         << " are " << nrMediciSectie << " medici." << endl;
}


	// Operatori
	// Operatorul =
	SectieSpital& operator=(const SectieSpital& other) {
		if (this != &other) {
			numeSectie = other.numeSectie;
			nrMediciSectie = other.nrMediciSectie;
		}
		return *this;
	}


	// Operatorul de incrementare prefixat (++sectie)
	SectieSpital& operator++() {
		++nrMediciSectie;
		return *this;
	}

	// Operatorul de incrementare sufixat (sectie++)
	SectieSpital operator++(int) {
		SectieSpital temp = *this;
		++nrMediciSectie;
		return temp;
	}

	// Operatorul <<
	friend ostream& operator<<(ostream& out, const SectieSpital& sectie) {
		out << "Sectia " << sectie.numeSectie << " din cadrul spitalului " << sectie.spital.getNume()
			<< " are " << sectie.nrMediciSectie << " medici.";
		return out;
	}


	/*const Spital& spital;
	string numeSectie;
	int nrMediciSectie;*/


	void serializare(string numeFisier) {
		ofstream fisierBinar(numeFisier, ios::out, ios::binary);
		int lungimeNumeSectie = this->numeSectie.size();
		fisierBinar.write((char*)&lungimeNumeSectie, sizeof(lungimeNumeSectie));
		fisierBinar.write(this->numeSectie.c_str(), lungimeNumeSectie + 1);

		fisierBinar.write((char*)&this->nrMediciSectie, sizeof(nrMediciSectie));

		fisierBinar.close();
	}


	void deserializare(string numeFisier) {
		ifstream fisierBinar(numeFisier, ios::in, ios::binary);
		if (fisierBinar.is_open()) {
			int lungimeNumeSectie = 0;
			fisierBinar.read((char*)&lungimeNumeSectie, sizeof(lungimeNumeSectie));
			char* aux = new char[lungimeNumeSectie + 1];
			fisierBinar.read(aux, lungimeNumeSectie + 1);
			this->numeSectie = aux;
			delete[]aux;

			fisierBinar.read((char*)&this->nrMediciSectie, sizeof(nrMediciSectie));
		}
		else {
			cout << "Fisierul binar nu a fost gasit.";
		}

	}

};





int main()
{   


	//Clasa Spital
	//Fisiere text

	Spital spital1;
	
	cin >> spital1;
	ofstream afisare("spitale.txt", ios::out);
	afisare << spital1;
	afisare.close();


	Spital spital2;
	ifstream citire("spitale.txt", ios::in);
	citire >> spital2;
	cout << spital2;
	citire.close();


	cout << endl;

	//Clasa Pacient 
	//Fisiere text
	Pacient pacient1;

	cin >> pacient1;
	ofstream f("pacienti.txt", ios::out);
	f << pacient1;
	f.close();


	Pacient pacient2;
	ifstream g("pacienti.txt", ios::in);
	g >> pacient2;
	cout << pacient2;
	g.close();



	//Clasa Medicamente
	//Fisiere binare
	Medicamente med1;
	Medicamente medBinar;
	med1.serializare("fisierBinar.bin");
	medBinar.deserializare("fisierBinar.bin");
	cout << medBinar << endl;



}
