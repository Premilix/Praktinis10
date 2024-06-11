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
void Rikiuoti(Kolekcionierius X[], int m);
void PopuliariausiPastoZenklai(Zenklas Z[], Kolekcionierius K[], int zenkluSkaicius, int kolekcionieriuSkaicius, Zenklas Naujas[], int &k);
void PradiniaiIFaila(ofstream& out, Zenklas Z[], int zenkluSkaicius, Kolekcionierius K[], int kolekcionieriuSkaicius);
void RezultataiIFaila(ofstream& outX, Zenklas Z[], int zenkluSkaicius, Kolekcionierius K[], int kolekcionieriuSkaicius);

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
    PradiniaiIFaila(out, Z, zenkluSkaicius, K, kolekcionieriuSkaicius);
    RezultataiIFaila(outX, Z, zenkluSkaicius, K, kolekcionieriuSkaicius);
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
    out << "Pavadinimas          Metai      Kaina\n";
    for (int i = 0; i < zenkluSkaicius; ++i) {
        out << left << setw(20) << Z[i].pavadinimas << " ";
        out << left << setw(10) << Z[i].metai << " ";
        out << fixed << setprecision(1) << Z[i].kaina << "\n";
    }


    out << "\nD2 duomenys\n";
    out << "Vardas, pavardė      Kiekis\n";
    for (int i = 0; i < kolekcionieriuSkaicius; ++i) {
        out << left << setw(20) << K[i].varPav << " ";
        out << left << setw(20) << K[i].pavadinimas << " ";
        out << K[i].kiekis << "\n";
    }
}

void RezultataiIFaila(ofstream& outX, Zenklas Z[], int zenkluSkaicius, Kolekcionierius K[], int kolekcionieriuSkaicius){
    outX<<"Rezultatai:\n";
    outX<<"Populiariausi ženklai \n";
    PopuliariausiPastoZenklai(Z, K, zenkluSkaicius, kolekcionieriuSkaicius, outX);

    Kolekcionierius NeturinysPop[100];
    int neturintysPopCount = 0;
    Neturintys(K, NeturinysPop, kolekcionieriuSkaicius, neturintysPopCount, Z[1]);
    for (int i = 0; i < neturintysPopCount; i++) {
        outX << left << setw(20) << NeturinysPop[i].varPav << " ";
        outX << left << setw(20) << NeturinysPop[i].pavadinimas << " ";
        outX << NeturinysPop[i].kiekis << "\n";
    }

}

void Rikiuoti(Kolekcionierius X[], int m)
{
    int k;
    Kolekcionierius l;
    for (int i = 0; i < m - 1; i++)
    {
        k = i;
        l = X[i];
        for (int j = i + 1;j < m; j++)
        {
            if (X[j].varPav < l.varPav)
            {
                k = j;
                l = X[j];
            }
        }
        X[k] = X[i];
        X[i] = l;
    }
}

void PopuliariausiPastoZenklai(Zenklas Z[], Kolekcionierius K[], int zenkluSkaicius, int kolekcionieriuSkaicius, Zenklas Populiariausi[], int &k)
{
    int x[zenkluSkaicius]; // Kiekvieno zenklo kiekis
    int did = -1;
    for (int i = 0; i < zenkluSkaicius; i++)
    {
        x[i] = 0;
        for (int j = 0; j < kolekcionieriuSkaicius; j++)
        {
            if (K[j].pavadinimas == Z[i].pavadinimas) x[i] += K[j].kiekis;
        }

        if (x[i] > did) did = x[i];
    }
    k = 0;
    for (int i = 0; i < zenkluSkaicius; i++)
    {
        if (did == x[i])
        {
            Populiariausi[k] = Z[i];
            k++;
        }
    }
}

// funkcija, kuri suranda asmenis, neturinčius nurodyto pašto ženklo, ir surašo juos į naują sąrašą
void Neturintys(Kolekcionierius K[], Kolekcionierius Naujas[], int n, int &m, Zenklas zenklas) {
    m = 0;
    int temp = 0;
    Kolekcionierius Temp[100];

    // į laikiną masyvą surašo kolekcionierius, kurie turi pašto ženklą
    for (int i = 0; i < n; i++) {
        if (K[i].pavadinimas == zenklas.pavadinimas && K[i].kiekis != 0) {
            Temp[temp++] = K[i];
        }
    }

    // į naują masyvą surašo kolekcionierius, kurių nėra laikiname (turinčių ženklą) masyve
    for (int i = 0; i < n; i++) {
        bool yra = false;
        for (int j = 0; j < temp; j++) {
            if (K[i].varPav.compare(K[j].varPav) == 0) {
                yra = true;
                break;
            }
        }
        if (!yra) {
            Naujas[m++] = K[i];
        }
        
    }
}
