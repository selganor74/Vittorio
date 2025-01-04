#include <iostream>

using namespace std;

int main()
{
    int numero;
    do
    {
        cout << "Inserisci un numero inferiore a 10 per uscire." << endl;
        cin >> numero;
    } while (numero >= 10);
}

/*
    La riga 10 è commentata. Togliendo il commento, cosa scriveresti
    nel testo tra virgolette nell'istruzione cout? In altre parole
    cosa chiederesti all'utente di inserire, per uscire dal ciclo ?    
*/