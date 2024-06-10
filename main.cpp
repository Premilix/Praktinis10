#include <bits/stdc++.h>

// duomenu sukurimas (Haroldas)
// ivedimas is failo (Haroldas)
// pradiniai i faila (Motiejus)
// rezultatai i faila (Motiejus)
// populiariausių pašto ženklų sąrašo be pasikartojimų funkciją (Augustas)
// funkcija, kuri suranda asmenis, neturinčius nurodyto pašto ženklo, ir surašo juos į naują sąrašą. (Emilis)
// rikiavimas (Augustas)

using namespace std;

struct Zenklas
{
    string pavadinimas;
    int metai;
    double kaina;
};

struct Kolekcionierius
{
    string varPav;
    string pavadinimas;
    int kiekis;

};

void SkaitytiZenklus(ifstream& in, Zenklas Z[], int &zenkluSkaicius);
void SkaitytiKolekcionierius(ifstream& in, Kolekcionierius K[], int &kolekcionieriuSkaicius);
void Neturintys(Kolekcionierius K[], Kolekcionierius Naujas[], int n, int &m, Zenklas zenklas);
bool ArTuri(Kolekcionierius k, Zenklas zenklas);

int main()
{
    Zenklas Z[100];
    Kolekcionierius K[100];
    ifstream inZ("DuomenysZ.txt");
    ifstream inK("DuomenysK.txt");
    ofstream out("Pradiniai.txt");
    ofstream outX("Rezultatai.txt");

    int zenkluSkaicius;
    int kolekcionieriuSkaicius;

    SkaitytiZenklus(inZ, Z, zenkluSkaicius);
    SkaitytiKolekcionierius(inK, K, kolekcionieriuSkaicius);
}

void SkaitytiZenklus(ifstream& in, Zenklas Z[], int &zenkluSkaicius) {
    int n;
    in >> n;
    zenkluSkaicius = n;
    in.ignore();
    for (int i = 0; i < n; i++) {
        char pavadinimoLaukas[21];
        in.get(pavadinimoLaukas, 21);
        Z[i].pavadinimas = pavadinimoLaukas;
        in >> Z[i].metai >> Z[i].kaina;
        in.ignore();
    }
}

void SkaitytiKolekcionierius(ifstream& in, Kolekcionierius K[], int &kolekcionieriuSkaicius) {
    int n;
    in >> n;
    kolekcionieriuSkaicius = n;
    in.ignore();
    for (int i = 0; i < n; i++) {
        char vardoLaukas[21];
        in.get(vardoLaukas, 21);
        char zenkloLaukas[21];
        in.get(zenkloLaukas, 21);
        K[i].varPav = vardoLaukas;
        K[i].pavadinimas = zenkloLaukas;
        in >> K[i].kiekis;
        in.ignore();
    }
}
void PradiniaiIFaila(ofstream& out, Zenklas Z[], int zenkluSkaicius, Kolekcionierius K[], int kolekcionieriuSkaicius) {
    
    out << "Pradiniai duomenys\n";
    out << "D1 duomenys\n";
    out << "Pavadinimas             Metai Kaina\n";
    for (int i = 0; i < zenkluSkaicius; ++i) {
        out << left << setw(20) << Z[i].pavadinimas << " ";
        out << Z[i].metai << " " << fixed << setprecision(1) << Z[i].kaina << "\n";
    }

    
    out << "\nD2 duomenys\n";
    out << "Pavadinimas           Pavardė, vardas       Kiekis\n";
    for (int i = 0; i < kolekcionieriuSkaicius; ++i) {
        out << left << setw(20) << K[i].varPav << " ";
        out << left << setw(20) << K[i].pavadinimas << " ";
        out << K[i].kiekis << "\n";
    }
}
void RezultataiIFaila(ofstream& out, Zenklas Z[], int zenkluSkaicius, Kolekcionierius K[],Kolekcionierius Naujas[], int kolekcionieriuSkaicius){
    outX<<"Rezultatai:\n";
    outX<<"Populiariausi ženklai:\n";
    //nezinau kaip funkcija kuri iesko populiariausiu zenklu atrodo
    

    
}


/*
// funkcija, kuri suranda asmenis, neturinčius nurodyto pašto ženklo, ir surašo juos į naują sąrašą
void Neturintys(Kolekcionierius K[], Kolekcionierius Naujas[], int n, int &m, Zenklas zenklas) {
    m = 0;
    for (int i = 0; i < n; i++) {
        if (!ArTuri(K[i], zenklas)) {
            Naujas[m++] = K[i];
        }
    }
}

// funkcija, kuri tikrina, ar asmuo turi nurodytą pašto ženklą
bool ArTuri(Kolekcionierius k, Zenklas zenklas) {
    for (int i = 0; i < k.nr; i++) {
        if (k.pavadinimas[i] == zenklas.pavadinimas) return true;
    }
    return false;
} */
