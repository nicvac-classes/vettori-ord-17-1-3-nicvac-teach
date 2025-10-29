#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>

using namespace std;


int main() {
    srand(time(0));
    
    int n, i, x, p, d;

    cout << "Inserire il numero di elementi da generare casualmente" << endl;
    cin >> n;
    vector<int> dispari(n);
    vector<int> pari(n);

    // Caricamento dei due vettori. Incremento p e d man mano che accodo gli elementi nel vettori Pari o Dispari.
    p = 0;
    d = 0;
    i = 0;
    while (i <= n - 1) {
        x = 1 + rand() % n;
        if (x % 2 == 0) {
            pari[p] = x;
            p = p + 1;
        } else {
            dispari[d] = x;
            d = d + 1;
        }
        i = i + 1;
    }

    // p e d qui sono le dimensioni di Pari e Dispari.
    cout << "Vettore Pari:" << endl;
    for (i = 0; i <= p - 1; i++) {
        cout << i << ": " << pari[i] << endl;
    }
    cout << "Vettore Dispari:" << endl;
    for (i = 0; i <= d - 1; i++) {
        cout << i << ": " << dispari[i] << endl;
    }

    // Ordinamento dei vettori
    int t;
    bool scambio;
    int j;

    scambio = true;
    i = 0;
    while (i <= p - 1 && scambio) {
        scambio = false;
        j = 0;
        while (j <= p - 2 - i) {
            if (pari[j] > pari[j + 1]) {
                scambio = true;
                t = pari[j];
                pari[j] = pari[j + 1];
                pari[j + 1] = t;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    scambio = true;
    i = 0;
    while (i <= d - 1 && scambio) {
        scambio = false;
        j = 0;
        while (j <= d - 2 - i) {
            if (dispari[j] > dispari[j + 1]) {
                scambio = true;
                t = dispari[j];
                dispari[j] = dispari[j + 1];
                dispari[j + 1] = t;
            }
            j = j + 1;
        }
        i = i + 1;
    }
    cout << "Vettore Pari Ordinato:" << endl;
    for (i = 0; i <= p - 1; i++) {
        cout << i << ": " << pari[i] << endl;
    }
    cout << "Vettore Dispari Ordinato:" << endl;
    for (i = 0; i <= d - 1; i++) {
        cout << i << ": " << dispari[i] << endl;
    }

    // Fondo i vettori usando il merge
    cout << "🏁🏁🏁🏁🏁 Merge 🏁🏁🏁🏁🏁" << endl;
    vector<int> v(n);
    int k;
    int i1, i2;

    k = 0;
    i1 = 0;
    i2 = 0;

    // Accodo gli elementi in V sapendo che V1 e V2 sono ordinati...
    while (i1 < p && i2 < d) {
        if (pari[i1] <= dispari[i2]) {
            v[k] = pari[i1];
            i1 = i1 + 1;
        } else {
            v[k] = dispari[i2];
            i2 = i2 + 1;
        }
        k = k + 1;
    }

    // Se ci sono ancora elementi di V1 da processare (e quindi non ci sono altri elementi di V2), li accodo in V.
    while (i1 < p) {
        v[k] = pari[i1];
        k = k + 1;
        i1 = i1 + 1;
    }

    // Se ci sono ancora elementi di V2 da processare (e quindi non ci sono altri elementi di V1), li accodo in V.
    while (i2 < d) {
        v[k] = dispari[i2];
        k = k + 1;
        i2 = i2 + 1;
    }
    cout << "Vettore Finale Ordinato:" << endl;
    for (i = 0; i <= k - 1; i++) {
        cout << i << ": " << v[i] << endl;
    }

    // Chiedo il valore da cercare, visualizzo l'indice del vettore.
    int valore, indice;

    do {
        cout << "Inserire l'elemento da cercare: " << endl;
        cin >> valore;
        int inizio, fine, medio;

        indice = -1;
        inizio = 0;
        fine = k - 1;
        while (inizio <= fine && indice == -1) {
            medio = inizio + (double) (fine - inizio) / 2;
            if (valore == v[medio]) {
                indice = medio;
            } else {
                if (valore > v[medio]) {
                    inizio = medio + 1;
                } else {
                    fine = medio - 1;
                }
            }
        }
        if (indice == -1) {
            cout << "L'elemento non esiste" << endl;
        }
    } while (indice == -1);
    cout << "Elemento " << valore << " trovato all'indice " << indice << endl;
    return 0;
}

