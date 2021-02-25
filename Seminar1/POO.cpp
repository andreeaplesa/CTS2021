
//Modificarile pot fi vizualizate cautand cuvantul MODIFICARE in cod
#include<iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
#include<algorithm>
#include<string>
#include <fstream>

using namespace std;

void afisarea_meniului() {
	cout << endl << endl;
	cout << "Optiunile disponibile din meniu sunt urmatoarele:" << endl;
	cout << "1. Afisati un obiect din clasele create;" << endl;
	cout << "2. Afisati numele unuia dintre farmacisti;" << endl;
	cout << "3. Afisati numarul de ingrediente pentru un medicament;" << endl;
	cout << "4. Adaugati intr-o lista de ingrediente active ingredientul -Amina-;" << endl;
	cout << "5. Testati daca adresa -Calea Serban Voda, nr.61, Bucuresti- este una dintre adresele angajatilor noi;" << endl;
	cout << "6. Adaugati un nou salariu in cadrul unei farmacii;" << endl;
	cout << "7. Afisati farmacia premiata din anul 2018;" << endl;
	cout << "8. Afisati lista cu noii angajati ordonata;" << endl;
	cout << "9. Parasiti meniul." << endl << endl;
	cout << "Introduceti tasta dorita:" << endl;
}

void afisare_meniu_mic() {
	cout << endl;
	cout << "Clasele disponibile sunt:" << endl;
	cout << "1. Farmacist;" << endl;
	cout << "2. Farmacie;" << endl;
	cout << "3. Medicament;" << endl;
	cout << "4. Reveniti la meniul principal." << endl;
	cout << "Selectati clasa pentru care veti afisa obiectul:" << endl;
}

int k, k1;


class Farmacist {
private:
	//INAINTE
	/*char* nume;                  //Numele farmacistului  
	int nr_medicamente[7];       //Numar de medicamente vandute in fiecare zi a saptamanii
	int nr_zile;                 //Numar de zile lucrate
	int* nr_clienti;             //Numar de clienti
	const int id;                //Id-ul de identificare
	static int nr_farmacisti;    //Numar total de farmacisti
	*/

	//MODIFICARE: eliminarea comentariilor
	char* nume;                 
	int nr_medicamente[7];       
	int nr_zile;                 
	int* nr_clienti;             
	const int id;                
	static int nr_farmacisti;   

public:

	//Constructor fara parametrii

	Farmacist() :id(Farmacist::nr_farmacisti) {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		for (int i = 0; i < 7; i++) {
			this->nr_medicamente[i] = 0;
		}
		this->nr_zile = 0;
		this->nr_clienti = NULL;
		this->nr_farmacisti++;
	}

	//Constructor cu parametrii nume, nr_medicamente, nr_zile, nr_clienti

	Farmacist(char* numeF, int nr_medicamenteF[7], int nr_zileF, int* nr_clientiF) :id(Farmacist::nr_farmacisti) {
		if (numeF != NULL) {
			this->nume = new char[strlen(numeF) + 1];
			strcpy(this->nume, numeF);
		}
		for (int i = 0; i < 7; i++) {
			this->nr_medicamente[i] = nr_medicamenteF[i];
		}
		this->nr_zile = nr_zileF;

		if (nr_clientiF != NULL) {
			this->nr_clienti = new int[this->nr_zile];
			for (int i = 0; i < this->nr_zile; i++) {
				this->nr_clienti[i] = nr_clientiF[i];
			}
		}
		this->nr_farmacisti++;
	}

	//Constructor nou cu parametrii nr_zile, nr_clienti

	Farmacist(int nr_zileF2, int* nr_clientiF2) :id(Farmacist::nr_farmacisti) {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy(this->nume, "Anonim");
		for (int i = 0; i < 7; i++) {
			this->nr_medicamente[i] = 0;
		}
		this->nr_zile = nr_zileF2;
		if (nr_clientiF2 != NULL) {
			this->nr_clienti = new int[this->nr_zile];
			for (int i = 0; i < this->nr_zile; i++) {
				this->nr_clienti[i] = nr_clientiF2[i];
			}
		}
		this->nr_farmacisti++;
	}

	// Constructor de copiere

	Farmacist(const Farmacist& copie) :id(Farmacist::nr_farmacisti) {
		if (copie.nume != NULL) {
			this->nume = new char[strlen(copie.nume) + 1];
			strcpy(this->nume, copie.nume);
		}
		for (int i = 0; i < 7; i++) {
			this->nr_medicamente[i] = copie.nr_medicamente[i];
		}
		this->nr_zile = copie.nr_zile;

		if (copie.nr_clienti != NULL) {
			this->nr_clienti = new int[this->nr_zile];
			for (int i = 0; i < this->nr_zile; i++) {
				this->nr_clienti[i] = copie.nr_clienti[i];
			}
		}
		this->nr_farmacisti++;
	}

	//Operatorul =

	Farmacist& operator=(const Farmacist& copie2) {
		if (this->nume != NULL)
			delete this->nume;
		if (copie2.nume != NULL) {
			this->nume = new char[strlen(copie2.nume) + 1];
			strcpy(this->nume, copie2.nume);
		}
		for (int i = 0; i < 7; i++) {
			this->nr_medicamente[i] = copie2.nr_medicamente[i];
		}
		this->nr_zile = copie2.nr_zile;

		if (this->nr_clienti != NULL)
			delete[] this->nr_clienti;

		if (copie2.nr_clienti != NULL) {
			this->nr_clienti = new int[this->nr_zile];
			for (int i = 0; i < this->nr_zile; i++) {
				this->nr_clienti[i] = copie2.nr_clienti[i];
			}
		}

		return *this;
	}

	//Destructor

	~Farmacist() {
		cout << endl << "--Apel destructor!--" << endl;
		if (this->nume != NULL)
			delete[] this->nume;
		if (this->nr_clienti != NULL)
			delete[] this->nr_clienti;
	}



	//Afisare

	void afisare() {
		cout << endl << "Informatiile farmacistului:" << endl;
		cout << "Nume: " << this->nume << endl;
		cout << "Medicamente vandute pe zile:" << endl;
		for (int i = 0; i < 7; i++)
			cout << "   Numar medicamente vandute in ziua " << i + 1 << ": " << this->nr_medicamente[i] << endl;
		cout << "Numarul de zile muncite: " << this->nr_zile << endl;
		cout << "Clienti serviti: " << endl;
		for (int i = 0; i < this->nr_zile; i++)
			cout << "   Numar clienti serviti in ziua " << i + 1 << ":" << this->nr_clienti[i] << endl;
		cout << "Id farmacist: " << this->id << endl;
		cout << "Numar farmacisti: " << this->nr_farmacisti << endl << endl;
	}

	//Prelucare

	int cantitate_medicamente() {
		int s = 0;                          //Numarul de medicamente vandute
		for (int i = 0; i < 7; i++) {
			s = s + this->nr_medicamente[i];
		}
		return s;
	}


	//getteri si setteri

	char* getNume() {
		return this->nume;
	}

	void setNume(char* numeNou) {
		if (this->nume != NULL)
			delete[] this->nume;
		if (numeNou != NULL) {
			this->nume = new char[strlen(numeNou) + 1];
			strcpy(this->nume, numeNou);
		}
	}

	int getNr_medicamente(int i) {
		return this->nr_medicamente[i];
	}

	void setNr_medicamente(int nr_medicamenteNou[7]) {
		for (int i = 0; i < 7; i++) {
			if (nr_medicamenteNou[i] < 100)                    //Nu trebuie vandute mai mult de 100 de medicamente
				this->nr_medicamente[i] = nr_medicamenteNou[i];
		}
	}

	int getNr_zile() {
		return this->nr_zile;
	}

	//INAINTE
	/*void setNr_zile(int nr_zileNou) {
		if (nr_zileNou < 25) this->nr_zile = nr_zileNou;         //Nu trebuie lucrate mai mult de 25 de zile
	}*/

	//MODIFICARE: formatare cod
	void setNr_zile(int nr_zileNou) {
		if (nr_zileNou < 25)                                    //Nu trebuie lucrate mai mult de 25 de zile
		{
			this->nr_zile = nr_zileNou;
		}
	}

	int* getNr_clienti() {
		return this->nr_clienti;
	}

	void setNr_clienti(int* nr_clientiNou, int nr_zileNou) {
		if (nr_clienti != NULL)
			delete[] nr_clienti;
		if (nr_clientiNou != NULL) {
			this->nr_zile = nr_zileNou;
			this->nr_clienti = new int[this->nr_zile];
			for (int i = 0; i < this->nr_zile; i++)
				this->nr_clienti[i] = nr_clientiNou[i];
		}
	}

	int getId() {
		return this->id;
	}

	static int getNr_farmacisti() {
		return nr_farmacisti;
	}

	static void setNr_farmacisti(int nr_farmacistiNou) {
		Farmacist::nr_farmacisti = nr_farmacistiNou;
	}

	//Operator <<

	friend ostream& operator<<(ostream& out, Farmacist& f) {
		out << endl << "Informatiile farmacistului sunt:" << endl << "Nume: " << f.nume << endl;
		out << "Medicamente vandute pe zile:" << endl;
		for (int i = 0; i < 7; i++)
			out << "Numar medicamente vandute in ziua " << i + 1 << ": " << f.nr_medicamente[i] << endl;
		out << "Numar zile muncite: " << f.nr_zile << endl;
		cout << "Clienti serviti: " << endl;
		for (int i = 0; i < f.nr_zile; i++)
			out << "Numar clienti serviti: " << f.nr_clienti[i] << endl;
		out << "Id farmacist: " << f.id << endl;
		out << "Numar farmacisti: " << f.nr_farmacisti << endl << endl;
		return out;
	}


	//Operator >>

	friend istream& operator>>(istream& in, Farmacist& f) {
		cout << "Introduceti numele farmacistului:";
		char buffer[20];
		if (f.nume != NULL)
			delete[] f.nume;
		f.nume = new char[strlen(buffer) + 1];
		in >> buffer;
		strcpy(f.nume, buffer);
		cout << "Introduceti numarul de medicamente vandute pe zile:" << endl;
		for (int i = 0; i < 7; i++)
		{
			cout << "   Numarul de medicamente vandute in ziua " << i + 1 << " este: ";
			in >> f.nr_medicamente[i];
		}
		cout << "Introduceti numarul de zile muncite: ";
		in >> f.nr_zile;
		cout << "Introduceti numarul de clienti:" << endl;
		if (f.nr_clienti != NULL) {
			delete[] f.nr_clienti;
			f.nr_clienti = new int[f.nr_zile];
			for (int i = 0; i < f.nr_zile; i++)
			{
				cout << "Numarul de clienti serviti:";
				in >> f.nr_clienti[i];
			}
			cout << endl << endl;
		}
		return in;
	}

	//Operator pentru indexare

	int& operator[](int index) {
		if (index<0 || index>this->nr_zile)
		{
			cout << "Index in afara limitelor!";
			throw new exception("Exceptie!");
		}
		else
			return this->nr_clienti[index];
	}

	//Operator cast

	explicit operator int() {
		return this->nr_zile;
	}

	//Operator -

	Farmacist operator-(int valoare) {
		Farmacist copie = *this;
		if (valoare < copie.nr_zile)
			copie.nr_zile = copie.nr_zile - valoare;

		return copie;
	}

	//Operator *

	//INAINTE
	/*friend Farmacist operator*(int valoare, Farmacist& far) {
		Farmacist copie = far;
		for (int i = 0; i < 7; i++)
			copie.nr_medicamente[i] = 2 * copie.nr_medicamente[i];
		return copie;
	}*/

	//MODIFICARE: denumirea sugestiva a variabilelor
	//denumirea variabilei farmacist este modificata din far in farmacist

	friend Farmacist operator*(int valoare, Farmacist& farmacist) {
		Farmacist copie = farmacist;
		for (int i = 0; i < 7; i++)
			copie.nr_medicamente[i] = 2 * copie.nr_medicamente[i];
		return copie;
	}

	//Operator ++ prefixat

	Farmacist& operator++() {
		int* nr_clientiNou = new int[this->nr_zile + 1];
		for (int i = 0; i < this->nr_zile; i++)
			nr_clientiNou[i] = this->nr_clienti[i];
		nr_clientiNou[this->nr_zile] = 40;
		this->nr_zile++;
		if (this->nr_clienti != NULL)
			delete[] this->nr_clienti;
		this->nr_clienti = nr_clientiNou;
		return *this;
	}

	//Operator ++

	Farmacist operator++(int) {
		Farmacist copie = *this;
		int* nr_clientiNou = new int[this->nr_zile + 1];
		for (int i = 0; i < this->nr_zile; i++)
			nr_clientiNou[i] = this->nr_clienti[i];
		nr_clientiNou[this->nr_zile] = 40;
		this->nr_zile++;
		if (this->nr_clienti != NULL)
			delete[] this->nr_clienti;
		this->nr_clienti = nr_clientiNou;
		return copie;
	}

	//Operator !

	bool operator!() {
		if (this->nr_zile != 0)
			return false;
		else
			return true;
	}

	//Operator >=

	bool operator>=(Farmacist f) {
		if (this->id >= f.id)
			return true;
		else
			return false;
	}

	//Operator ==

	bool operator==(Farmacist f) {
		if (strcmp(this->nume, f.nume) == 0)
			return true;
		else
			return false;
	}

	//Operator +=

	Farmacist& operator+=(int valoare) {
		this->nr_zile += valoare;
		return *this;
	}

};

//Clasa abstracta

class Farmacist_Sef_de_Tura : public Farmacist {
private:
	unsigned int nr_subalterni;
	string tura;

public:
	Farmacist_Sef_de_Tura() :Farmacist() {
		this->nr_subalterni = 0;
		this->tura = "zi";
	}

	Farmacist_Sef_de_Tura(unsigned int nr_subalterniF, int turaF, char* numeF, int nr_medicamenteF[7], int nr_zileF, int* nr_clientiF) :Farmacist(numeF, nr_medicamenteF, nr_zileF, nr_clientiF) {
		this->nr_subalterni = nr_subalterniF;
		this->tura = turaF;
	}

	unsigned int getNr_subalterni() {
		return this->nr_subalterni;
	}

	void setNr_subalterni(unsigned int nr_subalterniF2) {
		this->nr_subalterni = nr_subalterniF2;
	}

	string getTura() {
		return this->tura;
	}

	void setTura(string turaF) {
		this->tura = turaF;
	}

	void schimbare_tura(string turaF) {  //Schimba tura de noapte in cea de zi si invers
		if (turaF == "zi")
			this->tura = "noapte";
		else
			this->tura = "zi";
	}

	void afisareFarmacist_Sef_de_Tura() {
		cout << endl << "Nume: " << this->getNume() << endl;
		cout << "Medicamentele vandute pe zile sunt:" << endl;
		for (int i = 0; i < 7; i++)
			cout << "Numar medicamente vandute in ziua " << i + 1 << ": " << this->getNr_medicamente(i) << endl;
		cout << "Numar zile muncite: " << this->getNr_zile() << endl;
		int* p = new int[this->getNr_zile()];
		p = this->getNr_clienti();
		cout << "Clientii sunt:" << endl;
		for (int i = 0; i < this->getNr_zile(); i++)
			cout << "Numar clienti serviti in ziua " << i + 1 << ": " << p[i] << endl;
		cout << "Id farmacist: " << this->getId() << endl;
		cout << "Numar subalteri: " << this->nr_subalterni << endl;
		cout << "Tura:" << this->tura << endl << endl;

	}

	virtual void contorizare() = 0;

	virtual ~Farmacist_Sef_de_Tura() {
		cout << endl << "Destructor Farmacist_Sef_de Tura." << endl;
	}
};

//Interfata

class Sarcini {
public: virtual void realizareRapoarte() = 0;
		virtual void gestionareFurnizori() = 0;
		virtual void acordareBonus() = 0;
};

//Clasa mostenitoare

class Farmacist_Manager : public Farmacist_Sef_de_Tura, public Sarcini {
public:
	virtual void contorizare()
	{
		cout << "Medicamente contorizate!" << endl;
	}
	virtual void realizareRapoarte() {
		cout << "Raport saptamanal realizat!" << endl;
	}
	virtual void gestionareFurnizori() {
		cout << "Contracte incheiate!" << endl;
	}
	virtual void acordareBonus() {
		cout << "Bonus acordat!" << endl;
	}
};

int Farmacist::nr_farmacisti = 0;

class Farmacie {
private:

	char* denumire;            //Denumirea farmaciei
	string adresa;             //Adresa la care se afla farmacia
	unsigned int program[7];   //Numarul de ore din fiecare zi a saptamanii in care farmacia e deschisa
	unsigned int nr_angajati;  //Numarul de angajati din farmacie
	float* salarii;            //Salariile angajatilor
	const int id_farmacie;     //Codul de identificare al farmaciei
	static int nr_farmacii;    //Numarul de farmacii

public:

	//Constructor fara parametrii

	Farmacie() :id_farmacie(Farmacie::nr_farmacii) {

		this->denumire = new char[strlen("Farmacie_necunoscuta") + 1];
		strcpy(this->denumire, "Farmacie_necunoscuta");
		this->adresa = "Adresa_necunoscuta";
		for (int i = 0; i < 7; i++) {
			this->program[i] = 0;
		}
		this->nr_angajati = 0;
		this->salarii = NULL;
		this->nr_farmacii++;
	}

	//Constructor cu parametrii denumire, adresa, nr_angajati, salarii

	Farmacie(char* denumireF, string adresaF, unsigned int programF[7], unsigned int nr_angajatiF, float* salariiF) :id_farmacie(Farmacie::nr_farmacii) {

		if (denumireF != NULL) {
			this->denumire = new char[strlen(denumireF) + 1];
			strcpy(this->denumire, denumireF);
		}
		this->adresa = adresaF;

		for (int i = 0; i < 7; i++) {
			this->program[i] = programF[i];
		}
		this->nr_angajati = nr_angajatiF;

		if (salariiF != NULL) {
			this->salarii = new float[this->nr_angajati];
			for (int i = 0; i < this->nr_angajati; i++) {
				this->salarii[i] = salariiF[i];
			}
		}

		this->nr_farmacii++;
	}

	//Constructor nou cu parametrii adresa, nr_angajati, salarii

	Farmacie(string adresaF2, unsigned int nr_angajatiF2, float* salariiF2) :id_farmacie(Farmacie::nr_farmacii) {
		this->denumire = new char[strlen("Farmacie_necunoscuta") + 1];
		strcpy(this->denumire, "Farmacie_necunoscuta");
		this->adresa = adresaF2;

		for (int i = 0; i < 7; i++) {     //Nu se lucreaza in weekend
			this->program[i] = 0;
		}
		this->nr_angajati = nr_angajatiF2;

		if (salariiF2 != NULL) {
			this->salarii = new float[this->nr_angajati];
			for (int i = 0; i < this->nr_angajati; i++) {
				this->salarii[i] = salariiF2[i];
			}
		}

		this->nr_farmacii++;
	}

	//Constructor de copiere

	Farmacie(const Farmacie& copie) :id_farmacie(Farmacie::nr_farmacii) {

		if (copie.denumire != NULL) {
			this->denumire = new char[strlen(copie.denumire) + 1];
			strcpy(this->denumire, copie.denumire);
		}
		this->adresa = copie.adresa;

		for (int i = 0; i < 7; i++) {
			this->program[i] = copie.program[i];
		}
		this->nr_angajati = copie.nr_angajati;

		if (copie.salarii != NULL) {
			this->salarii = new float[this->nr_angajati];
			for (int i = 0; i < this->nr_angajati; i++) {
				this->salarii[i] = copie.salarii[i];
			}
		}
		this->nr_farmacii++;
	}

	//Operatorul =

	Farmacie& operator=(const Farmacie& copie2) {

		if (copie2.denumire != NULL) {
			this->denumire = new char[strlen(copie2.denumire) + 1];
			strcpy(this->denumire, copie2.denumire);
		}
		this->adresa = copie2.adresa;

		for (int i = 0; i < 7; i++) {
			this->program[i] = copie2.program[i];
		}
		this->nr_angajati = copie2.nr_angajati;

		if (copie2.salarii != NULL) {
			this->salarii = new float[this->nr_angajati];
			for (int i = 0; i < this->nr_angajati; i++) {
				this->salarii[i] = copie2.salarii[i];
			}
		}
		return *this;
	}

	//Destructor

	//INAINTE 
	/*~Farmacie() {
		cout << endl << "--Apel destructor--" << endl;
		if (this->denumire != NULL)
			delete[] this->denumire;

		if (this->salarii != NULL)
			delete[] this->salarii;

		this->nr_farmacii--;
	}*/

	//MODIFICARE: eliminare cod redundant, eliminare mesaj
	~Farmacie() {
		if (this->denumire != NULL)
			delete[] this->denumire;

		if (this->salarii != NULL)
			delete[] this->salarii;

		this->nr_farmacii--;
	}



	//Afisare

	void afisare() {
		cout << endl << "Farmacia are urmatoarele specificatii:" << endl;
		cout << "ID Farmacie: " << this->id_farmacie << endl;
		cout << "Denumire: " << this->denumire << endl;
		cout << "Adresa: " << this->adresa << endl;
		cout << "Program: " << endl;

		for (int i = 0; i < 7; i++) {
			cout << "   Ziua " << i + 1 << " din saptamana: " << this->program[i] << endl;
		}

		cout << "Numar de angajati: " << this->nr_angajati << endl;
		cout << "Salarii: " << endl;

		if (this->salarii != NULL) {
			cout << endl;
			for (int i = 0; i < this->nr_angajati; i++)
				cout << "   Angajatul " << i + 1 << " are un salariu de " << this->salarii[i] << " lei." << endl;
		}

		cout << "Numarul de farmacii: " << this->nr_farmacii << endl << endl;
	}

	//Prelucare: Se calculeaza numarul total de ore in care farmacia este deschisa

	unsigned int nr_ore_farmacie_deschisa() {
		unsigned int s = 0;
		for (int i = 0; i < 7; i++)
			s = s + this->program[i];
		return s;
	}

	//getteri si setteri(functii accesor)

	int getId_farmacie() {
		return this->id_farmacie;
	}

	char* getDenumire() {
		return this->denumire;
	}

	void setDenumire(char* denumireNoua) {
		if (this->denumire != NULL)
			delete[] this->denumire;

		if (denumireNoua != NULL) {
			this->denumire = new char[strlen(denumireNoua) + 1];
			strcpy(this->denumire, denumireNoua);
		}
	}

	string getAdresa() {
		return this->adresa;
	}

	void setAdresa(string adresaNoua) {
		if (adresaNoua != "")
			this->adresa = adresaNoua;
	}

	unsigned int getProgram(int i) {
		return this->program[i];
	}


	void setProgram(unsigned int programNou[7]) {
		if ((programNou[5] < 5) && (programNou[6] == 0)) //Conditia este ca sambata programul sa fie mai mic de 5 ore, iar duminica farmacia sa fie inchisa 
			for (int i = 0; i < 7; i++) {
				this->program[i] = programNou[i];
			}
	}

	unsigned int getNr_angajati() {
		return this->nr_angajati;
	}

	void setNr_angajati(unsigned int nr_angajatiNou) {
		if (nr_angajatiNou != 0)
			this->nr_angajati = nr_angajatiNou;
	}

	float* getSalarii() {
		return this->salarii;
	}

	void setSalarii(float* salariiNoi, unsigned int nr_angajatiNou) {
		if (this->salarii != NULL)
			delete[] this->salarii;

		if (salariiNoi != NULL) {
			this->nr_angajati = nr_angajatiNou;
			this->salarii = new float[this->nr_angajati];
			for (int i = 0; i < this->nr_angajati; i++)
				this->salarii[i] = salariiNoi[i];
		}
	}

	static int getNr_farmacii() {
		return nr_farmacii;
	}

	static void setNr_farmacii(int nr_farmaciiNou) {
		Farmacie::nr_farmacii = nr_farmaciiNou;
	}

	//Operatorul <<

	friend ostream& operator<<(ostream& out, Farmacie& f) {
		out << endl;
		out << "Id farmacie: " << f.id_farmacie << endl;
		out << "Denumire farmacie: " << f.denumire << endl;
		out << "Adresa farmacie: " << f.adresa << endl;
		out << "Programul este: " << endl;
		for (int i = 0; i < 7; i++) {
			out << "   Ziua " << i + 1 << " din saptamana: " << f.program[i] << endl;
		}
		out << "Numar angajati: " << f.nr_angajati << endl;

		out << "Salarii: " << endl;
		for (int i = 0; i < f.nr_angajati; i++) {
			out << "   Angajatul " << i + 1 << "are un salariu de " << f.salarii[i] << " lei." << endl;
		}
		out << "Numarul de farmacii: " << f.nr_farmacii << endl << endl;
		return out;
	}

	//Operatorul >>

	friend istream& operator>>(istream& in, Farmacie& f) {
		cout << endl;
		if (f.denumire != NULL)
			delete[] f.denumire;

		cout << "Introduceti denumirea farmaciei: ";
		char b[50];
		in >> b;
		f.denumire = new char[strlen(b) + 1];
		strcpy(f.denumire, b);

		cout << "Introduceti adresa farmaciei: ";
		in >> f.adresa;
		cout << "Introduceti programul farmaciei: " << endl;
		for (int i = 0; i < 7; i++) {
			cout << "   Pentru ziua " << i + 1 << " din saptamana: ";
			in >> f.program[i];
		}

		cout << "Introduceti numarul de angajati: ";
		in >> f.nr_angajati;
		cout << "Introduceti salariile angajatilor: " << endl;
		if (f.salarii != NULL)
			delete[] f.salarii;
		f.salarii = new float[f.nr_angajati];
		for (int i = 0; i < f.nr_angajati; i++) {
			cout << "   Angajatul " << i + 1 << " are un salariul: ";
			in >> f.salarii[i];
		}

		cout << endl << endl;
		return in;
	}

	//Supraincarcare operator indexare

	float& operator[](int index) {
		if (index<0 || index>this->nr_angajati) {
			cout << "Indexul a depasit limitele!" << endl;
			throw new exception("Exceptie!");
		}
		else
			return this->salarii[index];
	}

	//Supraincarcare operator cast

	explicit operator string() {
		return this->adresa;
	}

	//Supraincarcare operator pentru negatie

	bool operator!() {
		if (this->nr_angajati != NULL)
			return false;
		else
			return true;
	}

	//Supraincarcare operator ==

	bool operator==(Farmacie f1) {
		if (this->adresa == f1.adresa && this->nr_angajati == f1.nr_angajati)
			return true;
		else
			return false;
	}

	//Supraincarcare operator>=

	bool operator>=(Farmacie f2) {
		if (this->nr_angajati >= f2.nr_angajati)
			return true;
		else
			false;
	}

	//Supraincarcare operator +

	Farmacie operator+(int valoare) {
		Farmacie copie = *this;
		copie.nr_angajati = copie.nr_angajati + valoare;
		return copie;
	}

	//Supraincarcare operator *

	friend Farmacie operator *(int valoare, Farmacie f) {
		Farmacie copie = f;
		for (int i = 0; i < 7; i++) {
			copie.program[i] = copie.program[i] * valoare;
		}
		return copie;
	}

	//Supraincarcare operator++ prefixat

	Farmacie& operator++() {
		float* salariiNoi = new float[this->nr_angajati + 1];
		for (int i = 0; i < this->nr_angajati; i++)
			salariiNoi[i] = this->salarii[i];
		salariiNoi[this->nr_angajati] = 1000;
		this->nr_angajati++;
		if (this->salarii != NULL) {
			delete[] this->salarii;
		}
		this->salarii = salariiNoi;
		return *this;
	}

	//Supraincarcare operator++ sufixat

	Farmacie operator++(int) {
		Farmacie copie = *this;
		float* salariiNoi = new float[this->nr_angajati + 1];
		for (int i = 0; i < this->nr_angajati; i++) {
			salariiNoi[i] = this->salarii[i];
		}
		salariiNoi[this->nr_angajati] = 1000;
		this->nr_angajati++;
		if (this->salarii = NULL)
			delete[] this->salarii;
		this->salarii = salariiNoi;
		return copie;
	}
};

//Clasa abstracta

class Farmacie_Cabinet : public Farmacie {
private: int nr_compartimente;
		 int nr_doctori;
public:
	Farmacie_Cabinet() :Farmacie() {
		this->nr_compartimente = 0;
		this->nr_doctori = 0;
	}

	Farmacie_Cabinet(int nr_compartimenteF, int nr_doctoriF, char* denumireF, string adresaF, unsigned int programF[7], unsigned int nr_angajatiF, float* salariiF) :Farmacie(denumireF, adresaF, programF, nr_angajatiF, salariiF) {
		this->nr_compartimente = nr_compartimenteF;
		this->nr_doctori = nr_doctoriF;
	}

	int getNr_compartimente() {
		return this->nr_compartimente;
	}

	void setNr_compartimente(int nr_compartimenteNou) {
		this->nr_compartimente = nr_compartimenteNou;
	}

	int getNr_doctori() {
		return this->nr_doctori;
	}

	void setNr_doctori(int nr_doctoriNou) {
		this->nr_doctori = nr_doctoriNou;
	}

	//INAINTE
	void renovare() {
		this->nr_compartimente = this->nr_compartimente + 1;
	}
	//MODIFICARE: denumirea sugestiva a functiilor
	void adaugareCompartiment() {
		this->nr_compartimente = this->nr_compartimente + 1;
	}


	void afisareFarmacie_Cabinet() {
		cout << endl;
		cout << "Farmacia tip Cabinet are urmatoarele specificatii: " << endl;
		cout << "ID Farmacie tip Cabinet: " << this->getId_farmacie() << endl;
		cout << "Denumire: " << this->getDenumire() << endl;
		cout << "Adresa: " << this->getAdresa() << endl;
		cout << "Program: " << endl;

		for (int i = 0; i < 7; i++) {
			cout << "   Ziua " << i + 1 << " din saptamana: " << this->getProgram(i) << endl;
		}

		cout << "Numar de angajati: " << this->getNr_angajati() << endl;
		cout << "Salarii: " << endl;

		float* l = new float[this->getNr_angajati()];
		l = this->getSalarii();
		for (int i = 0; i < this->getNr_angajati(); i++)
			cout << "   Angajatul " << i + 1 << " are salariul de " << l[i] << " lei." << endl;
		cout << "Numar compartimente: " << this->nr_compartimente << endl;
		cout << "Numar doctori: " << this->nr_doctori << endl << endl;
	}

	virtual void conditiiMunca() = 0;
	virtual ~Farmacie_Cabinet() {
		cout << endl << "Destructor Farmacie_Cabinet!" << endl;
	}
};

//Interfata

class Operatiuni {
public: virtual void achitareChirie() = 0;
		virtual void consultatii() = 0;
};

//Clasa mostenitoare

class Farmacie_Cabinet_Veterinar : public Farmacie_Cabinet, public Operatiuni {
public:
	virtual void conditiiMunca() {
		cout << "Conditii indeplinite!" << endl;
	}
	virtual void achitareChirie() {
		cout << "Chirie achitata!" << endl;
	}

	virtual void consultatii() {
		cout << "Fiecare doctor a realizat cel putin o consultatie!" << endl;
	}
};

int Farmacie::nr_farmacii = 0;

class Medicament {
private:
	char* nume;                          //Numele medicamentului
	unsigned int doze[3];                //Dozele pe care pacientul trebuie sa le ia in functie de momentul zilei: Dimineata(0), Pranz(1), Seara(2)
	bool compensat;                      //Compensare 
	unsigned int nr_ingrediente;         //Numarul de ingrediente
	string* ingrediente;                 //Ingredientele medicamentului
	const unsigned int serie;            //Seria medicamentului
	static unsigned int nr_medicamente;  //Numar de medicamente

public:

	//Constructor fara parametrii

	Medicament() :serie(Medicament::nr_medicamente) {
		this->nume = new char[strlen("Medicament_necunoscut") + 1];
		strcpy(this->nume, "Medicament_necunoscut");
		this->compensat = false;
		for (int i = 0; i < 3; i++) {
			this->doze[i] = 0;
		}
		this->nr_ingrediente = 0;
		this->ingrediente = NULL;
		this->nr_medicamente++;

	}

	//Constructor cu parametrii nume, doze, compensat, nr_ingrediente, ingrediente

	Medicament(char* numeM, unsigned int dozeM[3], bool compensatM, unsigned int nr_ingredienteM, string* ingredienteM) :serie(Medicament::nr_medicamente) {
		if (numeM != NULL) {
			this->nume = new char[strlen(numeM) + 1];
			strcpy(this->nume, numeM);
		}
		this->compensat = compensatM;
		for (int i = 0; i < 3; i++) {
			this->doze[i] = dozeM[i];
		}
		this->nr_ingrediente = nr_ingredienteM;
		if (ingredienteM != NULL) {
			this->ingrediente = new string[this->nr_ingrediente];
			for (int i = 0; i < this->nr_ingrediente; i++) {
				this->ingrediente[i] = ingredienteM[i];
			}
		}
		this->nr_medicamente++;
	}

	//Constructor cu paramentri nr_ingrediente, ingrediente

	Medicament(unsigned int nr_ingredienteM2, string* ingredienteM2) :serie(Medicament::nr_medicamente) {
		this->nume = new char[strlen("Medicament_necunoscut") + 1];
		strcpy(this->nume, "Medicament_necunoscut");
		this->compensat = false;
		for (int i = 0; i < 3; i++) {
			this->doze[i] = 0;
		}
		this->nr_ingrediente = nr_ingredienteM2;
		if (ingredienteM2 != NULL) {
			this->ingrediente = new string[this->nr_ingrediente];
			for (int i = 0; i < this->nr_ingrediente; i++)
				this->ingrediente[i] = ingredienteM2[i];
		}
		this->nr_medicamente++;
	}

	//Constructor de copiere

	Medicament(const Medicament& copie) :serie(copie.serie) {
		if (copie.nume != NULL) {
			this->nume = new char[strlen(copie.nume) + 1];
			strcpy(this->nume, copie.nume);
		}
		this->compensat = copie.compensat;
		for (int i = 0; i < 3; i++) {
			this->doze[i] = copie.doze[i];
		}
		this->nr_ingrediente = copie.nr_ingrediente;
		if (copie.ingrediente != NULL) {
			this->ingrediente = new string[this->nr_ingrediente];
			for (int i = 0; i < this->nr_ingrediente; i++) {
				this->ingrediente[i] = copie.ingrediente[i];
			}
		}

		this->nr_medicamente++;
	}

	//Operatorul =

	Medicament& operator=(const Medicament& copie2) {
		if (this->nume != NULL)
			delete[] this->nume;

		if (copie2.nume != NULL) {
			this->nume = new char[strlen(copie2.nume) + 1];
			strcpy(this->nume, copie2.nume);
		}
		this->compensat = copie2.compensat;
		for (int i = 0; i < 3; i++) {
			this->doze[i] = copie2.doze[i];
		}
		this->nr_ingrediente = copie2.nr_ingrediente;

		if (this->ingrediente != NULL)
			delete[] this->ingrediente;

		if (copie2.ingrediente != NULL) {
			this->ingrediente = new string[this->nr_ingrediente];
			for (int i = 0; i < this->nr_ingrediente; i++) {
				this->ingrediente[i] = copie2.ingrediente[i];
			}
		}
		return *this;
	}

	//Destructor

	~Medicament() {
		cout << endl << "--Apel destructor--" << endl;
		if (this->nume != NULL)
			delete[] this->nume;
		if (this->ingrediente != NULL)
			delete[] this->ingrediente;
		this->nr_medicamente--;
	}

	//Afisare

	void afisare() {
		cout << endl;
		cout << "Informatiile despre medicament sunt:" << endl;
		cout << "Nume: " << this->nume << endl;
		cout << "Compensat? (0=Nu, 1=Da): " << this->compensat << endl;
		cout << "Dozele recomandate, in functie de momentul zilei (Dimineata 0, Pranz 1, Seara 2) sunt: " << endl;
		for (int i = 0; i < 3; i++) {
			cout << "   Pentru momentul " << i << " doza: " << this->doze[i] << endl;
		}
		cout << "Numar ingrediente: " << this->nr_ingrediente << endl;
		cout << "Ingredientele sunt:" << endl;
		for (int i = 0; i < this->nr_ingrediente; i++)
			cout << this->ingrediente[i] << endl;
		cout << "Serie: " << this->serie << endl;
		cout << "Numar medicamente: " << this->nr_medicamente << endl << endl;
	}

	//getteri si setteri

	char* getNume() {
		return this->nume;
	}

	void setNume(char* numeNou) {
		if (this->nume != NULL)
			delete[] nume;
		if (numeNou != NULL) {
			this->nume = new char[strlen(numeNou) + 1];
			strcpy(this->nume, numeNou);
		}

	}

	bool getCompensat() {
		return this->compensat;
	}

	void setCompensat(bool compensatNou) {
		if (compensatNou == false || compensatNou == true)
			this->compensat = compensatNou;
	}

	unsigned int getDoze(int i) {
		return this->doze[i];
	}

	void setDoze(unsigned int dozeNoi[3]) {
		for (int i = 0; i < 3; i++) {
			if (doze[i] < 4)                     //Doza maxima e de 3 comprimate
				this->doze[i] = dozeNoi[i];
		}
	}

	unsigned int getNr_ingrediente() {
		return this->nr_ingrediente;
	}

	void setNr_ingrediente(unsigned int nr_ingredienteNou) {
		if (nr_ingredienteNou < 6)                               //Numarul de ingrediente dintr-un anumit medicament trebuie sa fie maxim 5
			this->nr_ingrediente = nr_ingredienteNou;
	}

	string* getIngrediente() {
		return this->ingrediente;
	}

	void setIngrediente(string* ingredienteNoi, unsigned int nr_ingredienteNou) {
		if (this->ingrediente != NULL)
			delete[] this->ingrediente;
		if (ingredienteNoi != NULL) {
			this->nr_ingrediente = nr_ingredienteNou;
			this->ingrediente = new string[this->nr_ingrediente];
			for (int i = 0; i < this->nr_ingrediente; i++)
				this->ingrediente[i] = ingredienteNoi[i];
		}

	}

	unsigned int getSerie() {
		return this->serie;
	}

	static unsigned int getNr_medicamente() {
		return nr_medicamente;
	}

	static void setNr_medicamente(unsigned int nr_medicamenteNou) {
		Medicament::nr_medicamente = nr_medicamenteNou;
	}

	// Prelucrare

	unsigned int nr_pastile() {
		unsigned int s = 0;
		for (int i = 0; i < 3; i++) {   //Numarul de pastile care trebuie luate intr-o zi
			s = s + this->doze[i];
		}
		return s;
	}

	//Operator <<
	friend ostream& operator<<(ostream& out, Medicament& m) {
		out << endl << "Informatiile despre medicament sunt: " << endl;
		out << "Nume: " << m.nume << endl;
		out << "Compensat? (0=Nu, 1=Da): " << m.compensat << endl;
		out << "Dozele recomdate, in functie de momentul zilei (Dimineata 0, Pranz 1, Seara 2) sunt: " << endl;
		for (int i = 0; i < 3; i++) {
			out << "Pentru momentul " << i << " doza: " << m.doze[i] << endl;
		}
		out << "Numar ingrediente: " << m.nr_ingrediente << endl;
		out << "Ingredientele sunt:" << endl;
		for (int i = 0; i < m.nr_ingrediente; i++)
			out << m.ingrediente[i] << endl;
		out << "Seria: " << m.serie << endl;
		out << "Numar medicamente: " << m.nr_medicamente << endl << endl;
		return out;
	}

	//Operator >>

	friend istream& operator>>(istream& in, Medicament& med) {
		if (med.nume != NULL)
			delete[] med.nume;
		char buff[50];
		cout << "Intorduceti numele medicamentului: ";
		in >> buff;
		med.nume = new char[strlen(buff) + 1];
		strcpy(med.nume, buff);

		cout << "E compensat? (1=da,0=nu) ";
		in >> med.compensat;
		cout << "Dozele recomdate, in functie de momentul zilei (Dimineata 0, Pranz 1, Seara 2) sunt: " << endl;
		for (int i = 0; i < 3; i++) {
			cout << "   Pentru momentul " << i << " doza este: ";
			in >> med.doze[i];
		}
		cout << endl;
		cout << "Introduceti numarul de ingrediente ale medicamentului: ";
		in >> med.nr_ingrediente;
		if (med.ingrediente != NULL)
			delete[] med.ingrediente;
		med.ingrediente = new string[med.nr_ingrediente];
		cout << "Ingredientele sunt:" << endl;
		for (int i = 0; i < med.nr_ingrediente; i++)
			in >> med.ingrediente[i];
		cout << endl;
		return in;
	}

	//Operator []

	string& operator[](int index) {
		if (index<0 || index>this->nr_ingrediente) {
			cout << "Indexul depaseste limitele!" << endl;
			throw new exception("Exceptie");
		}
		else
			return this->ingrediente[index];
	}

	//Operator cast

	operator unsigned int() {
		return this->nr_ingrediente;
	}

	//Operator -

	Medicament operator-(int valoare) {
		Medicament copie = *this;
		copie.nr_ingrediente = copie.nr_ingrediente - valoare;
		return copie;
	}

	//Operator +

	friend Medicament operator+(int valoare, Medicament& med) {
		Medicament copie = med;
		for (int i = 0; i < 3; i++)
			copie.doze[i] = valoare + copie.doze[i];
		return copie;
	}

	//Operator ++ prefixat

	Medicament& operator++() {
		string* ingredienteNoi = new string[this->nr_ingrediente + 1];
		for (int i = 0; i < this->nr_ingrediente; i++) {
			ingredienteNoi[i] = this->ingrediente[i];
		}
		ingredienteNoi[this->nr_ingrediente] = "Bicarbonat";
		this->nr_ingrediente++;
		if (this->ingrediente != NULL)
			delete[] this->ingrediente;
		this->ingrediente = ingredienteNoi;
		return *this;
	}

	//Operator ++ sufixat

	Medicament operator++(int) {
		Medicament copie = *this;
		string* ingredienteNoi = new string[this->nr_ingrediente + 1];
		for (int i = 0; i < this->nr_ingrediente; i++) {
			ingredienteNoi[i] = this->ingrediente[i];
		}
		ingredienteNoi[this->nr_ingrediente] = "Bicarbonat de sodiu";
		this->nr_ingrediente++;
		if (this->ingrediente != 0)
			delete[] this->ingrediente;
		this->ingrediente = ingredienteNoi;
		return copie;
	}

	//Operator ==

	bool operator==(Medicament m) {
		if (this->compensat == m.compensat && this->serie == m.serie)
			return true;
		else
			return false;
	}

	//Operator >=

	bool operator>=(Medicament m) {
		if (this->nr_ingrediente >= m.nr_ingrediente)
			return true;
		else
			return false;
	}

	//Operator !

	bool operator!() {
		if (this->compensat != NULL)
			return false;
		else
			return true;
	}
};

//Exemplificarea relatiei HAS A 

class Reteta {
private: int nrMedicamente;
		 Medicament** medicamente;
public: Reteta() {
	this->nrMedicamente = 0;
	this->medicamente = NULL;
}
		Reteta(int nrMedicamenteR, Medicament** medicamenteR) {
			this->nrMedicamente = nrMedicamenteR;
			this->medicamente = new Medicament*[this->nrMedicamente];
			for (int i = 0; i < this->nrMedicamente; i++) {
				this->medicamente[i] = medicamenteR[i];
			}
		}
		~Reteta() {
			if (this->medicamente != NULL)
				delete[] this->medicamente;
		}
		void afisare() {
			cout << "Reteta este formata din: " << endl;
			cout << "Medicamentele din cadrul retetei sunt in numar de: " << this->nrMedicamente << endl;
			for (int i = 0; i < this->nrMedicamente; i++) {
				cout << endl << "------------ Medicament " << i + 1 << "------------" << endl;
				this->medicamente[i]->afisare();

			}
			cout << endl << endl;
		}
};

unsigned int Medicament::nr_medicamente = 0;


int main()

{       //----------------------------CLASA------------FARMACIST-----------------FAZA_1-------------------------------------- 


	cout << " ----------------------------CLASA------------FARMACIST-----------CONSTRUCTORI----------OPERATII------" << endl;
	Farmacist fr1;
	fr1.afisare();

	char buffer[50];
	cout << "Intorduceti numele farmacistului:";
	cin >> buffer;
	char* numeF = new char[strlen(buffer) + 1];
	strcpy(numeF, buffer);

	int nr_medicamenteF[7];

	cout << "Introduceti numarul de medicamente vandute in fiecare zi a saptamanii:" << endl;
	for (int i = 0; i < 7; i++) {
		cout << "Pentru ziua " << i + 1 << " :";
		cin >> nr_medicamenteF[i];
	}

	int nr_zileF;
	cout << "Introduceti numarul de zile lucrate: ";
	cin >> nr_zileF;

	cout << "Introduceti numarul de clienti din fiecare zi:" << endl;
	int* nr_clientiF = new int[nr_zileF];
	for (int i = 0; i < nr_zileF; i++) {
		cout << "Pentru ziua " << i + 1 << " :";
		cin >> nr_clientiF[i];
	}
	cout << endl;
	Farmacist fr2(numeF, nr_medicamenteF, nr_zileF, nr_clientiF);
	fr2.afisare();

	int nr_zileF2 = 4;

	cout << "Introduceti numarul de clienti din fiecare zi:" << endl;
	int* nr_clientiF2 = new int[nr_zileF2];
	for (int i = 0; i < nr_zileF2; i++) {
		cout << "Pentru ziua " << i + 1 << " :";
		cin >> nr_clientiF2[i];
	}

	Farmacist fr3(nr_zileF2, nr_clientiF2);
	fr3.afisare();

	Farmacist fr4(fr2);
	fr4.afisare();

	Farmacist fr5 = fr4;
	fr5.afisare();

	char buf[50];
	cout << "Intorduceti numele nou al farmacistului care avea numele anterior " << fr2.getNume() << ":";
	cin >> buf;
	char* numeNou = new char[strlen(buf) + 1];
	strcpy(numeNou, buf);

	fr2.setNume(numeNou);

	cout << "Numele nou al farmacistului este: " << fr2.getNume() << endl << endl;

	int nr_medicamenteNou[7];
	cout << "Introduceti numarul de medicamente vandute in fiecare zi a saptamanii de catre " << fr3.getNume() << ":";
	for (int i = 0; i < 7; i++) {
		cout << "Pentru ziua " << i + 1 << " :";
		cin >> nr_medicamenteNou[i];
	}
	cout << endl;

	cout << "Noile numere de medicamente vandute in fiecare zi a saptamanii de catre " << fr3.getNume() << " sunt:" << endl;
	fr3.setNr_medicamente(nr_medicamenteNou);
	for (int i = 0; i < 7; i++)
		cout << fr3.getNr_medicamente(i) << endl;

	cout << endl;
	int nr_zileNou;
	cout << "Introduceti numarul de zile lucrate de catre " << fr4.getNume() << ":";
	cin >> nr_zileNou;

	fr4.setNr_zile(nr_zileNou);

	cout << "Noul numar de zile lucrate de catre " << fr4.getNume() << " este " << fr4.getNr_zile() << endl << endl;

	cout << "Introduceti numarul nou de clienti din fiecare zi pentru farmacistul " << fr3.getNume() << ":";

	int* nr_clientiNou = new int[nr_zileNou];
	for (int i = 0; i < nr_zileNou; i++) {
		cout << "Pentru ziua " << i + 1 << " :";
		cin >> nr_clientiNou[i];
	}

	cout << " Noile numere de clienti serviti sunt: " << endl;
	fr3.setNr_clienti(nr_clientiNou, nr_zileNou);

	int*p = new int[fr3.getNr_zile()];
	p = fr3.getNr_clienti();

	for (int i = 0; i < fr3.getNr_zile(); i++)
		cout << p[i] << endl;

	cout << endl;
	cout << "Id-ul farmacistului " << fr5.getNume() << " este " << fr5.getId() << endl << endl;

	int nr_farmacistiNou;
	cout << "Introduceti numarul de farmacisti:";
	cin >> nr_farmacistiNou;
	fr5.setNr_farmacisti(nr_farmacistiNou);
	cout << "Noul numar de farmacisti este: " << fr5.getNr_farmacisti() << endl << endl;

	cout << "Cantitatea de medicamnete vandute de catre " << fr4.getNume() << " este " << fr4.cantitate_medicamente() << endl << endl;

	cout << "Informatiile despre farmacistul " << fr5.getNume() << ":" << endl;
	cout << fr5;

	Farmacist fr6 = fr2;

	int zi;
	cout << "Introduceti ziua de lucru:";
	cin >> zi;
	try {
		cout << "Numarul de clienti din ziua de lucru numarul " << zi << " a farmacistului " << fr4.getNume() << " este " << fr4[zi] << endl << endl;
	}
	catch (exception* e)
	{
		cout << e->what() << endl;
		cout << "Exceptie prinsa 1" << endl << endl;
	}
	catch (...)
	{
		cout << "Exceptie prinsa 2" << endl << endl;
	}

	cout << "Numarul de zile lucrate de catre farmacistul " << fr4.getNume() << " este " << int(fr4) << endl << endl;

	cout << "Scadeti din numarul de zile lucrate de catre farmacistul " << fr2.getNume() << " 2 zile" << endl << endl;

	fr2 = fr2 - 2;
	cout << "Numarul actual de zile este " << fr2.getNr_zile() << endl << endl;

	cout << "Sa se dubleze numarul de medicamente vandute al farmacistului " << fr2.getNume() << endl;

	fr2 = 2 * fr2;

	cout << "Noile numere de medicamente vandute in fiecare zi a saptamanii de catre " << fr2.getNume() << " sunt:" << endl;

	for (int i = 0; i < 7; i++)
		cout << fr2.getNr_medicamente(i) << endl;

	cout << endl;

	cout << "Sa se adauge o noua zi de lucru(aceasta va avea 40 de clienti) pentru farmacistul " << fr6.getNume() << endl;

	fr6++;
	fr6.afisare();


	cout << "Sa se adauge o noua zi de lucru (aceasta va avea 40 de clienti) pentru farmacistul " << fr5.getNume() << endl;

	++fr5;
	cout << fr5;


	if (!fr2)
		cout << "Farmacistul " << fr2.getNume() << " are un numar de zile lucrate egal cu 0" << endl << endl;
	else
		cout << "Farmacistul " << fr2.getNume() << " are un numar de zile lucrate diferit de 0" << endl << endl;

	cout << "Sunt farmacistii " << fr5.getNume() << " si " << fr6.getNume() << " aceiasi?" << endl;

	if (fr5 == fr6)
		cout << "Este vorba de acelasi farmacist!" << endl << endl;
	else
		cout << "Farmacisti diferiti!" << endl << endl;

	cout << "Ce farmcist are id-ul mai mare dintre " << fr5.getNume() << " si " << fr6.getNume() << " ?" << endl;

	if (fr5 >= fr6)
		cout << fr5.getNume() << " cu id " << fr5.getId() << endl << endl;
	else
		cout << fr6.getNume() << " cu id " << fr6.getId() << endl << endl;

	cout << "Mariti cu 5 numarul de zile lucrate ale farmacistului " << fr5.getNume() << endl;
	fr5 += 5;
	cout << "Acesta a devenit " << fr5.getNr_zile() << endl << endl;



	//-------------------------CLASA------------------------FARMACIST-------FAZA_2-----------------------------


	cout << "-------------------------CLASA------------------------FARMACIST---------MOSTENIRE-----------" << endl;
	Farmacist fa;
	Farmacist_Manager farm;
	farm.contorizare();
	farm.realizareRapoarte();
	farm.gestionareFurnizori();
	farm.acordareBonus();

	Farmacist* fa2 = new Farmacist_Manager();
	Farmacist_Manager farm2;
	farm2.afisareFarmacist_Sef_de_Tura();

	farm2.setNr_subalterni(5);
	farm2.getNr_subalterni();
	cout << endl;

	farm.schimbare_tura("zi");
	farm.getTura();
	cout << endl;

	//-------------------------------CLASA------------FARMACIE----------------------FAZA_1-----------------------------

	cout << "-------------------------------CLASA------------FARMACIE--------------CONSTRUCTORI--------OPERATII------------" << endl;
	Farmacie f1;
	f1.afisare();

	char* denumireF = new char[strlen("Catena") + 1];
	strcpy(denumireF, "Catena");
	string adresaF = "Bulevardul Timisoara, nr.31, Bucuresti";
	cout << "Introduceti numarul de ore lucrate in farmacia " << f1.getDenumire() << " :" << endl;
	unsigned int programF[7];
	for (int i = 0; i < 7; i++) {
		cout << "   Numar de ore lucrate in ziua " << i + 1 << " din saptamana: ";
		cin >> programF[i];
	}

	unsigned int nr_angajatiF = 6;
	float* salariiF = new float[nr_angajatiF];
	for (int i = 0; i < nr_angajatiF; i++)
		salariiF[i] = 1000 + i * 4;

	Farmacie f2(denumireF, adresaF, programF, nr_angajatiF, salariiF);
	f2.afisare();

	string adresaF2 = "Strada Sarii, nr.7, Bucuresti";
	unsigned int nr_angajatiF2 = 4;
	float* salariiF2 = new float[nr_angajatiF2];
	for (int i = 0; i < nr_angajatiF2; i++)
		salariiF2[i] = 1000 + i * 10;

	Farmacie f3(adresaF2, nr_angajatiF2, salariiF2);
	f3.afisare();

	Farmacie f4(f2);
	f4.afisare();

	Farmacie f5 = f3;
	f5.afisare();

	cout << "Farmacia " << f1.getDenumire() << " functioneaza " << f1.nr_ore_farmacie_deschisa() << " ore." << endl << endl;


	cout << "Id-ul farmaciei " << f2.getDenumire() << " este " << f2.getId_farmacie() << " ." << endl << endl;

	char* denumireNoua = new char[strlen("Ana") + 1];
	strcpy(denumireNoua, "Ana");

	f1.setDenumire(denumireNoua);
	cout << "Noua denumire a farmaciei cu id-ul " << f1.getId_farmacie() << " este " << f1.getDenumire() << " ." << endl << endl;

	string adresaNoua = "Calea Teilor, nr.80, Bucuresti";
	f1.setAdresa(adresaNoua);
	cout << "Noua adresa a farmaciei " << f1.getDenumire() << " este " << f1.getAdresa() << " ." << endl << endl;

	cout << "Introduceti un nou program pentru farmacia " << f4.getDenumire() << " :" << endl;
	unsigned int programNou[7];
	for (int i = 0; i < 7; i++) {
		cout << "   Numar de ore lucrate in ziua " << i + 1 << " din saptamana: ";
		cin >> programNou[i];
	}
	cout << endl;

	f4.setProgram(programNou);

	cout << "Programul actual al farmaciei " << f4.getDenumire() << " este:" << endl;
	for (int i = 0; i < 7; i++)
		cout << "   Ziua " << i + 1 << " din saptamana: " << f4.getProgram(i) << endl;

	cout << endl;

	unsigned int nr_angajatiNou = 3;

	f1.setNr_angajati(nr_angajatiNou);
	cout << "Farmacia " << f1.getDenumire() << " are un numar actual de " << f1.getNr_angajati() << " angajati." << endl << endl;

	cout << "Introduceti noile salarii pentru angajatii din farmacia " << f1.getDenumire() << " :" << endl;
	float* salariiNoi = new float[nr_angajatiNou];
	for (int i = 0; i < nr_angajatiNou; i++)
	{
		cout << "   Salariul angajatului " << i + 1 << " este: ";
		cin >> salariiNoi[i];
	}

	f1.setSalarii(salariiNoi, nr_angajatiNou);


	float* sal = new float[f1.getNr_angajati()];

	sal = f1.getSalarii();

	cout << "Salariile actuale ale farmaciei " << f1.getDenumire() << " sunt:" << endl;

	for (int i = 0; i < f1.getNr_angajati(); i++)
		cout << "   Salariul angajatului " << i + 1 << " este " << sal[i] << endl;

	cout << endl;
	int nr_farmaciiNou = 4;
	f4.setNr_farmacii(nr_farmaciiNou);

	cout << "Numarul farmaciilor este: " << f4.getNr_farmacii() << endl << endl;

	cout << f2;

	Farmacie f6;
	cin >> f6;

	f6.afisare();

	int nr;
	cout << "Introduceti numarul unui angajat stiind ca numaratoarea in baza de date incepede de la 0:";
	cin >> nr;
	try {
		cout << "Salariul angajatului " << nr + 1 << " este " << f2[nr] << endl << endl;
	}
	catch (exception* e) {
		cout << e->what() << endl;
		cout << "Exceptie prinsa 1" << endl << endl;
	}
	catch (...) {
		cout << "Exceptie prinsa 2" << endl << endl;
	}

	cout << "Adresa farmaciei " << f2.getDenumire() << " este " << string(f2) << " ." << endl << endl;

	if (!f2)
		cout << "Farmacia " << f2.getDenumire() << " nu are angajati!" << endl << endl;
	else
		cout << "Farmacia " << f2.getDenumire() << " are angajati!" << endl << endl;

	cout << "Sunt farmaciile " << f5.getDenumire() << " si " << f3.getDenumire() << " identice?" << endl;

	if (f5 == f3)
		cout << "Farmaciile coincid!" << endl << endl;
	else
		cout << "Farmaciile sunt diferite!" << endl << endl;

	cout << "Ce farmacie are mai multi angajati dintre " << f2.getDenumire() << " si " << f3.getDenumire() << " ?" << endl;


	if (f2 >= f3)
		cout << "Farmacia " << f2.getDenumire() << " are mai multi angajati." << endl << endl;
	else
		cout << "Farmacia " << f3.getDenumire() << " are mai multi angajati." << endl << endl;

	cout << "Adaugati la numarul de angajati ai farmaciei " << f3.getDenumire() << " 3 angajati" << endl;

	f3 = f3 + 3;
	cout << "Numar actual de angajati: " << f3.getNr_angajati() << endl << endl;

	cout << "Sa se dubleze programul de lucru al farmaciei " << f2.getDenumire() << endl;

	f2 = 2 * f2;

	cout << "Programul actual al farmaciei " << f2.getDenumire() << " este:" << endl;
	for (int i = 0; i < 7; i++)
		cout << "   Ziua " << i + 1 << " din saptamana: " << f2.getProgram(i) << endl;

	cout << endl;

	cout << "Sa se adauge un nou salariu pentru farmacia " << f2.getDenumire() << endl;

	++f2;
	f2.afisare();

	cout << "Sa se adauge un nou salariu pentru farmacia " << f4.getDenumire() << endl;

	f4++;
	f4.afisare();

	//--------------------CLASA--------------------------FARMACIE-----------------FAZA_2-----------------------------------------


	cout << "--------------------CLASA--------------------------FARMACIE-----------------MOSTENIRE------------------------" << endl;
	Farmacie farma;
	Farmacie_Cabinet_Veterinar farma2;
	farma2.conditiiMunca();
	farma2.consultatii();
	farma2.achitareChirie();

	Farmacie* farma3 = new Farmacie_Cabinet_Veterinar();

	farma3->afisare();

	farma2.afisareFarmacie_Cabinet();
	cout << "Numarul de doctori devine 3:" << endl;
	farma2.setNr_doctori(3);
	cout << "Numar doctori: " << farma2.getNr_doctori() << endl << endl;
	cout << "Numarul de compartimente creste cu 1:" << endl;
	farma2.renovare();
	cout << "Numar compartimente: " << farma2.getNr_compartimente() << endl << endl;

	//----------------------------CLASA----------------------FARMACIE--------------------------FAZA_3------------------------

	cout << "--------------------CLASA--------------------------FARMACIE-----------------TIPURI_STL------------------------------" << endl;

	cout << endl << "-----------STL---------lista-----------" << endl << endl;
	list<unsigned int> lista;
	lista.push_front(f1.getNr_angajati());
	lista.push_front(f2.getNr_angajati());
	lista.push_back(f4.getNr_angajati());
	lista.push_front(f3.getNr_angajati());
	lista.push_back(f5.getNr_angajati());
	cout << "Lista cu numarul de angajati din farmacie este: " << endl;
	list<unsigned int>::iterator it2;
	for (it2 = lista.begin(); it2 != lista.end(); it2++) {
		cout << *it2 << endl;
	}

	cout << endl << "Lista sortata este:" << endl;
	lista.sort();
	for (it2 = lista.begin(); it2 != lista.end(); it2++) {
		cout << *it2 << endl;
	}

	cout << endl << "Lista dupa eliminarea primei valori este: " << endl;
	lista.pop_front();
	for (it2 = lista.begin(); it2 != lista.end(); it2++) {
		cout << *it2 << endl;
	}

	cout << endl << "Lista inversata este: " << endl;
	lista.reverse();
	for (it2 = lista.begin(); it2 != lista.end(); it2++) {
		cout << *it2 << endl;
	}

	cout << endl << "Lista dupa eliminarea ultimei valori este: " << endl;
	lista.pop_back();
	for (it2 = lista.begin(); it2 != lista.end(); it2++) {
		cout << *it2 << endl;
	}

	cout << endl << "-----------STL---------set-----------" << endl << endl;
	set<string> adrese;
	adrese.insert(f2.getAdresa());
	adrese.insert(f3.getAdresa());
	adrese.insert(f5.getAdresa());
	adrese.insert("Calea Serban Voada, nr.61, Bucuresti");
	cout << "Adresele angajatilor noi sunt: " << endl;
	set<string>::iterator it3;
	for (it3 = adrese.begin(); it3 != adrese.end(); it3++) {
		cout << *it3 << endl;
	}
	cout << endl;
	it3 = adrese.find("Calea Serban Voada, nr.61, Bucuresti");
	if (it3 != adrese.end())
		cout << " Adresa Calea Serban Voada, nr.61, Bucuresti a fost gasita!" << endl;
	else
		cout << " Adresa Calea Serban Voada, nr.61, Bucuresti nu a fost gasita!" << endl;

	cout << endl << "-----------STL---------map-----------" << endl << endl;
	map<int, Farmacie> farmaciiPremiate;
	farmaciiPremiate.insert(make_pair(2010, f2));
	farmaciiPremiate.insert(make_pair(2012, f5));
	farmaciiPremiate.insert(make_pair(2016, f4));
	farmaciiPremiate.insert(make_pair(2018, f6));
	map<int, Farmacie>::iterator itfP;
	for (itfP = farmaciiPremiate.begin(); itfP != farmaciiPremiate.end(); itfP++) {
		cout << "Farmacia anului " << itfP->first << " este " << itfP->second << endl;
	}
	int val;
	cout << endl << "Introduceti o valoare din lista: 2010, 2012, 2016, 2018: ";
	cin >> val;
	cout << "Farmacia premiata in anul " << val << " este " << farmaciiPremiate[val] << endl;

	//-------------------------------CLASA---------------------------MEDICAMENT--------------------FAZA_1-----------------------------

	cout << "-------------------------------CLASA---------------------------MEDICAMENT---------------CONSTRUCTORI-------------OPERATII-------------" << endl;

	Medicament m1;
	m1.afisare();
	cout << endl;

	char* numeM = new char[strlen("Algozone") + 1];
	strcpy(numeM, "Algozone");
	bool compensatM = false;
	unsigned int dozeM[3];
	cout << "Introduceti dozele in functei de momentul zile (Dimineata 0, Pranz 1, Seara 2): " << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Doza din momentul " << i << " al zilei: ";
		cin >> dozeM[i];
	}

	unsigned int nr_ingredienteM = 6;
	string* ingredienteM = new string[nr_ingredienteM];
	cout << "Introduceti ingredientele medicamentului:";
	cin.ignore();
	for (int i = 0; i < nr_ingredienteM; i++) {
		char buffer[50];
		cin.getline(buffer, 50);
		ingredienteM[i] = buffer;
	}

	Medicament m2(numeM, dozeM, compensatM, nr_ingredienteM, ingredienteM);
	m2.afisare();


	unsigned int nr_ingredienteM2;
	cout << "Introduceti numarul de ingrediente:";
	cin >> nr_ingredienteM2;
	string* ingredienteM2 = new string[nr_ingredienteM2];
	cout << "Ingredientele medicamentului:";
	cin.ignore();
	for (int i = 0; i < nr_ingredienteM2; i++) {
		char buffer[50];
		cin.getline(buffer, 50);
		ingredienteM2[i] = buffer;
	}

	cout << endl;

	Medicament m3(nr_ingredienteM2, ingredienteM2);
	m3.afisare();

	Medicament m4(m3);
	m4.afisare();

	Medicament m5 = m2;
	m5.afisare();

	char buff[50];
	cout << "Intorduceti numele nou al medicamentului care avea numele anterior " << m2.getNume() << ":";
	cin >> buff;
	char* numeNou1 = new char[strlen(buff) + 1];
	strcpy(numeNou1, buff);

	m2.setNume(numeNou1);

	cout << "Numele nou al medicamentului este: ";
	cout << m2.getNume() << endl << endl;

	bool compensatNou;
	cout << "Introduceti noul tip (compensat=1;necompensat=0) al medicamentului " << m3.getNume() << " :" << endl;
	cin >> compensatNou;

	m3.setCompensat(compensatNou);

	cout << "Tipul (compensat=1;necompensat=0) medicamentului " << m3.getNume() << " este " << m3.getCompensat() << endl << endl;

	cout << "Introduceti noi doze pentru medicamentul " << m4.getNume() << " :" << endl;

	unsigned int dozeNoi[3];
	for (int i = 0; i < 3; i++) {
		cout << "Doza din momentul " << i << " al zilei: ";
		cin >> dozeNoi[i];
	}

	m4.setDoze(dozeNoi);

	cout << "Noile doze sunt:" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "Doza din momentul " << i << " al zilei: ";
		cout << m4.getDoze(i) << endl;
	}

	unsigned int nr_ingredienteNou;
	cout << endl << "Introduceti numarul nou de ingrediente din medicamentul " << m4.getNume() << " :";
	cin >> nr_ingredienteNou;
	m4.setNr_ingrediente(nr_ingredienteNou);

	cout << "Numarul nou de ingrediente este: " << m4.getNr_ingrediente() << endl << endl;

	string* ingredienteNoi = new string[nr_ingredienteNou];
	cout << "Introduceti noile ingrediente ale medicamentului " << m4.getNume() << " :";
	cin.ignore();
	for (int i = 0; i < nr_ingredienteNou; i++) {
		char buffer[50];
		cin.getline(buffer, 50);
		ingredienteNoi[i] = buffer;
	}

	m4.setIngrediente(ingredienteNoi, nr_ingredienteNou);

	cout << "Ingredientele sunt:" << endl;

	string* k = new string[m4.getNr_ingrediente()];
	k = m4.getIngrediente();
	for (int i = 0; i < m4.getNr_ingrediente(); i++)
		cout << k[i] << endl;
	cout << endl;


	cout << "Stabiliti noul numar de medicamente pentru medicamentul cu seria " << m3.getSerie() << " ca fiind 7";

	m3.setNr_medicamente(7);
	cout << "Numarul nou de medicamente este:" << m3.getNr_medicamente() << endl << endl;

	cout << "Numarul de pastile care trebuie luate intr-o zi din medicamentul " << m2.getNume() << " este: " << m2.nr_pastile() << endl << endl;

	cout << m2;

	cin >> m3;
	m3.afisare();


	try {
		cout << "Ingredientul cu numarul 2 din medicamentul " << m2.getNume() << " este: " << m2[2] << endl;
	}
	catch (exception* e) {
		cout << e->what() << endl;
		cout << "Exceptie prinsa 1" << endl << endl;
	}
	catch (...) {
		cout << "Exceptie prinsa 2" << endl << endl;
	}

	cout << "Numarul de ingrediente din medicamentul " << m2.getNume() << " este:" << int(m2) << endl << endl;

	cout << "Sa se adauge un nou ingredient la medicamentul " << m3.getNume() << endl;
	m3++;
	m3.afisare();

	cout << "Sa se adauge un nou ingredient la medicamentul " << m4.getNume() << endl;
	++m4;
	m4.afisare();

	cout << "Medicamentele " << m3.getNume() << " si " << m3.getNume() << " coincid?" << endl;

	if (m4 == m3)
		cout << "Medicamentele coincid!" << endl << endl;
	else
		cout << "Medicamentele sunt diferite!" << endl << endl;

	cout << "Ce medicament dintre " << m2.getNume() << " si " << m1.getNume() << " are mai multe ingrediente?" << endl;

	if (m3 >= m2)
		cout << "Medicamentul " << m3.getNume() << " are mai multe ingrediente." << endl << endl;
	else
		cout << "Medicamentul " << m2.getNume() << " are mai multe ingrediente." << endl << endl;

	if (!m2)
		cout << "Medicamentul " << m2.getNume() << " nu e compensat!" << endl << endl;
	else
		cout << "Medicamentul " << m2.getNume() << " e compensat!" << endl << endl;


	cout << "Scadeti cu 2 numarul de ingrediente al medicamentului " << m4.getNume() << endl;

	m4 = m4 - 2;
	m4.afisare();

	cout << "Adaugati 1 la dozele ce trebuie luate din medicamentul " << m2.getNume() << endl;

	m2 = 1 + m2;

	m2.afisare();

	//-------------------------CLASA-------------------MEDICAMENT------------------------------FAZA_2----------------------------

	cout << "-------------------------------CLASA---------------------------MEDICAMENT-------------INCLUDEREA---------------------" << endl;

	cout << endl << endl << "------------------------------" << endl;

	Medicament* medicamente[4] = { &m1,&m2, &m3, &m4 };

	Reteta r(4, medicamente);
	r.afisare();

	//-------------------------CLASA-----------------MEDICAMENT--------------------------------FAZA 3-------------------------------


	cout << "-------------------------------CLASA---------------------------MEDICAMENT---------------STL------------------------------------" << endl;

	cout << endl << "--------------STL-----------vector------" << endl;
	vector<string>ingredienteActive;
	ingredienteActive.push_back(m2[2]);
	ingredienteActive.push_back(m3[1]);
	ingredienteActive.push_back(m4[0]);
	cout << "Ingredientele active sunt:" << endl;
	for (int i = 0; i < ingredienteActive.size(); i++) {
		cout << ingredienteActive[i] << endl;
	}

	//sortare

	sort(ingredienteActive.begin(), ingredienteActive.end());
	cout << endl << "--Interatorul 1--" << endl;
	vector<string>::iterator it;
	for (it = ingredienteActive.begin(); it != ingredienteActive.end(); it++) {
		cout << *it << endl;
	}
	cout << endl << "--Iteratorul 2--" << endl;
	ingredienteActive.pop_back();
	for (it = ingredienteActive.begin(); it != ingredienteActive.end(); it++) {
		cout << *it << endl;
	}
	cout << endl << "--Iteratorul 3--" << endl;
	ingredienteActive.pop_back();
	for (it = ingredienteActive.begin(); it != ingredienteActive.end(); it++) {
		cout << *it << endl;
	}

	//------------------------------------CLASA----------------------MEDICAMENT------------------FAZA_3-------- CITIRE/SCRIERE DIN/IN FISIER TEXT/BINAR

	cout << "-------------------------------CLASA---------------------------MEDICAMENT---------------CITIRE/SCRIERE DIN/IN FISIER TEXT/BINAR" << endl;

	//Scriere intr-un fisier text

	ofstream fileWrite;
	fileWrite.open("raport.txt", ios::out);
	Medicament m6(numeM, dozeM, compensatM, nr_ingredienteM, ingredienteM);
	fileWrite << m6;
	fileWrite.close();

	//Scriere intr-un fisier binar

	ofstream fileWriteBin;
	fileWriteBin.open("raport1.dat", ios::binary | ios::out);
	fileWriteBin << m6;
	fileWriteBin.close();

	//Citire dintr-un fisier text; Este nevoie de un fisier nou pentru ca valorile sa fie corecte

	ifstream fileRead;
	fileRead.open("raport.txt", ios::in);
	Medicament m7;
	fileRead >> m7;
	cout << "Medicamentul din prospect este: " << endl << m7 << endl;
	fileRead.close();

	//Citire dintr-un fisier binar; Este nevoie de un fisier nou pentru ca valorile sa fie corecte

	ifstream fileReadBin;
	fileReadBin.open("raport1.dat", ios::binary | ios::in);
	Medicament m8;
	fileReadBin >> m8;
	cout << "Medicamentul din prospect este: " << endl << m8 << endl;
	fileReadBin.close();

	//-------------------------------------------CLASA---------------------MEDICAMENT----------------FAZA_3-----------MENIU----------------------- 

	cout << "--------------------------------------MENIU-----------------------------------------------------------------" << endl;

	k = 0;
	afisarea_meniului();
	int i;
	cin >> i;
	while (k == 0)
	{
		switch (i) {
		case 1: k1 = 0;
			afisare_meniu_mic();
			int j;
			cin >> j;
			cout << endl;
			while (k1 == 0) {
				switch (j) {
				case 1:fr2.afisare();
					afisare_meniu_mic();
					cin >> j;
					cout << endl;
					break;
				case 2:f4.afisare();
					afisare_meniu_mic();
					cin >> j;
					cout << endl;
					break;
				case 3:m2.afisare();
					afisare_meniu_mic();
					cin >> j;
					cout << endl;
				case 4:k1++;
					break;
				default:cout << "Nu exista aceasta optiune. Incercati din nou." << endl;
					afisare_meniu_mic();
					cin >> j;
					cout << endl;
				}
			}
			afisarea_meniului();
			cin >> i;
			cout << endl;
			break;
		case 2: cout << fr4.getNume();
			afisarea_meniului();
			cin >> i;
			cout << endl;
			break;
		case 3:cout << m3.getNr_ingrediente();
			afisarea_meniului();
			cin >> i;
			cout << endl;
			break;
		case 4:ingredienteActive.push_back("Amina");
			cout << "Ingredientele active sunt:" << endl;
			for (int i = 0; i < ingredienteActive.size(); i++) {
				cout << ingredienteActive[i] << endl;
			}
			afisarea_meniului();
			cin >> i;
			cout << endl;
			break;
		case 5:it3 = adrese.find("Calea Serban Voada, nr.61, Bucuresti");
			if (it3 != adrese.end())
				cout << " Adresa Calea Serban Voada, nr.61, Bucuresti a fost gasita!" << endl;
			else
				cout << " Adresa Calea Serban Voada, nr.61, Bucuresti nu a fost gasita!" << endl;
			afisarea_meniului();
			cin >> i;
			cout << endl;
			break;
		case 6:++f2;
			f2.afisare();
			afisarea_meniului();
			cin >> i;
			break;
			cout << endl;
		case 7:cout << "Farmacia premiata in anul 2018 este " << farmaciiPremiate[2018] << endl;
			afisarea_meniului();
			cin >> i;
			cout << endl;
			break;
		case 8:cout << endl << "Lista sortata este:" << endl;
			lista.sort();
			for (it2 = lista.begin(); it2 != lista.end(); it2++) {
				cout << *it2 << endl;
			}
			afisarea_meniului();
			cin >> i;
			cout << endl;
			break;
		case 9:k++;
			break;
		default:cout << "Optiunea aceasta nu exista! Mai incercati: ";
			afisarea_meniului();
			cin >> i;
			cout << endl;
		}
	}
	cout << endl;
	cout << "--------------------------------Multumim. La revedere!-------------------------";
	return 0;
}



