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
    string pavadinimas[256];
    int kiekis[256];
    int nr; // kolekcionieriaus turimų skirtingų pašto ženklų numeris
};

void Neturintys(Kolekcionierius K[], Kolekcionierius Naujas[], int n, int &m, Zenklas zenklas);
bool ArTuri(Kolekcionierius k, Zenklas zenklas);

int main()
{

}

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
}
