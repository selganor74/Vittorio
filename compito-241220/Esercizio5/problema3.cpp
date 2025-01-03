#include <iostream>

using namespace std;

// conterrà la fascia oraria richiesta dall'utente.
// 0 (da mezzanotte alle una)
// 1 (dalle 1 alle 2)
// ...
// 23 (dalle 23 a mezzanotte)
int fascia_oraria = 0;

// il numero delle richieste fatte al server
float numero_di_richieste = 0;

// il numero delle risposte restituite con errori dal server
float numero_di_richieste_non_esaudite = 0;

// la soglia minima di risposte corrette/risposte totali che il server deve rispettare
float percentuale_minima = 95.0;

/*
    La funzione random va dichiarata prima della funzione main
    altrimenti il compilatore "non la vede"!
*/
int random(int min, int max)
{
    // ottiene un numero casuale tra 0 e RAND_MAX
    int random_value = rand();
    // riadattiamo l'intervallo in base ai valori di min e max
    float range = max - min;
    int in_range = min + (random_value * range / RAND_MAX);

    // Restituiamo il valore calcolato
    return in_range;
}

int main()
{
    // inizializza il generatore di numeri casuali (va fatto una sola volta all'inizio del programma)
    srand(time(nullptr));

    cout << "Calcolo della percentuale di risposte corrette vs errate del Server Web" << endl
         << endl;

    // eseguiamo un ciclo per coprire tutte le fasce orarie di un giorno
    for (fascia_oraria = 0; fascia_oraria < 24; fascia_oraria++)
    {
        // usiamo la funzione random per sostituire l'input dell'utente
        numero_di_richieste = random(1, 10000);

        // usiamo la funzione random per sostituire l'input dell'utente.
        // per avere una distribuzione di KO e OK "visibile" limitiamo 
        // il numero di richieste non esaudite ad un decimo di quelle effettive. 
        numero_di_richieste_non_esaudite = random(0, numero_di_richieste/10);

        // abbiamo tutti i dati per calcolare la percentuale di risposte corrette del server:
        int percentuale_risposte_corrette = ((numero_di_richieste - numero_di_richieste_non_esaudite) / numero_di_richieste) * 100;

        // e possiamo inviare allo schermo il risultato
        cout << "Dalle " << fascia_oraria << ":00 alle " << fascia_oraria + 1 << ":00 percentuale di successo: " << percentuale_risposte_corrette << "% ==> ";

        // e forniamo un giudizio sulla bontà del servizio svolto dal server ...
        if (percentuale_risposte_corrette >= percentuale_minima)
        {
            // ... se maggiore della soglia minima stampiamo un OK
            cout << "ok ";
        }
        else
        {
            // ... altrimenti KO
            cout << "KO ";
        }

        // aggiungiamo all'output anche i numeri che concorrono al calcolo della percentuale.
        cout << " " << numero_di_richieste - numero_di_richieste_non_esaudite << " / " << numero_di_richieste << endl;
    }

    return 0;
}
