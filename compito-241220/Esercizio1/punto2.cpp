/*

    L'algoritmo per questo programma:

    1 Visualizza un messaggio di benvenuto
    2 Richiedi il valore dell'estremo A (intero positivo o negativo)
    3 Richiedi il valore dell'estremo B (intero positivo o negativo) assicurandoti che sia maggiore o uguale ad A
    4 per ogni valore n compreso tra A e B
    5   Visualizza n

*/

#include <iostream>

using namespace std;

// gli estremi dell'intervallo
int A;
int B;

int main()
{
    // un messaggio di "benvenuto" che spieghi all'utente cosa fa il programma
    cout << endl
         << "Visualizza tutti i numeri interi in un intervallo [A, B] dove A e B possono essere positivi e/o negativi" << endl
         << endl;

    // richiesta dell'estremo A
    cout << "Inserisci l'estremo A: ";
    cin >> A;

    // loop infinito! finché l'utente non inserisce un numero "valido", non si esce!
    while (true)
    {
        // richiesta dell'estremo B
        cout << "Inserisci l'estremo B [ >= " << A << " ]: ";
        cin >> B;

        // verifica che l'estremo B sia maggiore o uguale ad A ...
        if (B >= A)
        {
            // ... ok possiamo uscire dal ciclo while
            break;
        }

        // altrimenti visualizziamo un errore ed il ciclo while si ripete
        cout << endl
             << "L'estremo B deve essere maggiore o uguale all'estremo A (" << A << ")." << endl
             << endl;
    }

    cout << endl;

    // ciclo tra gli estremi A e B
    for (int n = A; n <= B; n++)
    {
        cout << n;
        if (n != B)
            cout << ", ";
    }

    cout << endl
         << endl;

    return 0;
}