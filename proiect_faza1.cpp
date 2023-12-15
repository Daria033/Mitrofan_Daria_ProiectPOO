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

	//Getteri
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


ostream& operator<<(ostream& out, Spital& spital) {
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

	friend ostream& operator<<(ostream& out, Pacient& pacient);

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



};
int Pacient::gradSeveritate = 4;

ostream& operator<<(ostream& out, Pacient& pacient) {
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




};
int Medicamente::nrMaximSubstante = 5;



int main()
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

	//Getteri
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

	//Setteri
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

	//Functie globala
	
	//Spital spital6;
	//cin >> spital2;
	//cout << spital2;
	cout << endl;
	cout << endl;

	cout << "Operatorii: = , ++, cast, index." << endl;

	//operator =
	Spital spital6;
	spital6 = spital2;
	cout << spital6 << endl;
	cout << endl;
	cout << endl;

	//Operator de indexare
	cout << "Postincrementare: " << endl;
	Spital spital7;
	spital7 = spital2++;
	cout << spital2 << endl;
	cout << spital7 << endl;
	cout << endl;

	cout << "Preincrementare: " << endl;
	Spital spital8;
	spital8 = ++spital2;
	cout << spital2 << endl;
	cout << spital8 << endl;
	cout << endl;
	cout << endl;



	//operator cast
	cout << "Numarul de medici din Spitalul de Urgenta 'Sfantul Constantin' este:" << endl;
	int b = spital1;
	cout << b << endl;
	cout << endl;
	cout << endl;

	//operator index
	cout << spital1[1] << endl;
	spital1[0] = "Chirurgie generala";
	cout << endl;
	cout << endl;




    //PACIENTI
	cout << "Pacienti:" << endl;
	int varste[] = {14,21,32};
	Pacient pacient1;
	pacient1.afisare();
	Pacient pacient2(2, "Bogdan", 3, varste);
	pacient2.afisare();
	Pacient pacient3(7, "Andrei");
	pacient3.afisare();
	cout << endl;
	//Constructor de copiere
	Pacient pacient4 = pacient1;
	pacient4.afisare();
	cout << endl;

	//Getteri
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

	//Setteri
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
	cout << endl;
	
	cout << "Operatorii: = , --, cast, +=." << endl;

	//Operator =
	Pacient pacient6;
	pacient6 = pacient2;
	cout << pacient6.getId() << endl;
	cout << "Nume: " << pacient6.getNume() << endl;
	cout << "Nr. pacienti: " << pacient6.getNrPacienti() << endl;
	cout << "Varstele pacientilor: ";
	for (int i = 0;i < pacient6.getNrPacienti();i++) {
		cout << pacient6.getVarstePacienti()[i] << ", ";
	}
	cout << endl;
	cout << "Grad severitate: " << pacient6.getGrad() << endl;
	cout << endl;


	cout << endl;
	cout << endl;

	cout << pacient2 << endl;
	cout << endl;
	//Operator --
	Pacient pacient7;
	--pacient2;
	pacient7 = pacient2--;
	cout << pacient2;
	cout << endl;
	cout << endl;
	cout << pacient7;
	cout << endl;
	cout << endl;
	
	//operator cast
	cout << "Numarul de pacienti cu numele de Ana este:" << endl;
	int p = pacient5;
	cout << p << endl;
	cout << endl;
	cout << endl;

	cout << endl;
	// Utilizare operator +=
	pacient1 += pacient5;

	cout << "\nPacient 1 dupa adaugare:" << endl;
	pacient1.afisare();
	cout << endl;
	cout << endl;


	cout << endl;


	//MEDICAMENTE
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

	//Getteri
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
	
	//Setteri
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
	cout << endl;
	cout << endl;


	cout <<"Operatorii: = , +=, ==, de scadere."<< endl;

	//operator =
	Medicamente med6;
	med6 = medicament2;
	cout << med6.getId() << endl;
	cout << "Nume medicament: " << med6.getNume() << endl;
	cout << "Pret: " << med6.getPret() << endl;
	cout << "Nr substante active: " << med6.getNrSubstante() << endl;
	cout << "Substante active: ";
	for (int i = 0;i < med6.getNrSubstante();i++) {
		cout << med6.getSubstanteActive()[i] << ", ";
	}
	cout << endl;
	cout << "Nr. maxim de substante active: " << med6.getMaxSubstante() << endl;
	cout << endl;
	cout << endl;


	//Operator +=
	medicament2 += medicament3;

	cout << "Pretul dupa adunare: " << medicament2.getPret() << endl;

	cout << endl;
	cout << endl;
	//Operator ==
	if (medicament1 == medicament2) {
		cout << "Medicamentele sunt identice." << endl;
	}
	else {
		cout << "Medicamentele sunt diferite." << endl;
	}


	cout << endl;
	cout << endl;

	//Operator de scădere -
	Medicamente medicamentDiferenta = medicament1 - medicament2;
	cout << "Pretul diferentei: " << medicamentDiferenta.getPret() << endl;

}
