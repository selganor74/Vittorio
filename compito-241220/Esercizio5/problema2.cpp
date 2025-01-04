/*
    1. Simulazione input e output

    Esempio 1

        Percentuale di soglia = 95%

        Fascia oraria: 18
        Numero richieste Totali: 1000
        Numero richieste Errate:  100

        numero richieste corrette = Numero richieste Totali - Numero richieste Errate               =>  1000 - 100 = 900
        percentuale di successo   = ( numero richieste corrette / Numero richieste Totali ) * 100   =>  ( 900 / 1000 ) * 100 = 90%

        Nella fascia oraria 18:00 - 18:59 la pecentuale di successo è 90% ( < 95% ) KO 👎



    Esempio 2

        Percentuale di soglia = 95%

        Fascia oraria: 18
        Numero richieste Totali: 1000
        Numero richieste Errate:   10

        numero richieste corrette = Numero richieste Totali - Numero richieste Errate               =>  1000 - 10 = 990
        percentuale di successo   = ( numero richieste corrette / Numero richieste Totali ) * 100   =>  ( 990 / 1000 ) * 100 = 99%

        Nella fascia oraria 18:00 - 18:59 la pecentuale di successo è 99% ( >= 95% ) OK! 👍


    2. Algoritmo

    * Visualizza un messaggio di benvenuto e la percentuale di successo impostata come soglia
    * Richiedi la fascia oraria e controlla che sia un numero compreso tra 0 e 23
    * Richiedi il numero di richieste totali per la fascia oraria
    * Richiedi il numero di richieste ERRATE per la fascia oraria
    * Calcola la percentuale di successo
    * Se la percentuale di successo calcolata è minore della percentuale impostata come soglia
    *   allora visualizza le statistiche con un KO
    *   altrimenti visualizza le statistiche con un OK!


 */

#include <iostream>

using namespace std;

// conterrà la fascia oraria richiesta dall'utente.
// 0 (da mezzanotte alle una)
// 1 (dalle 1 alle 2)
// ...
// 23 (dalle 23 a mezzanotte)
int fascia_oraria = 0;

// il numero delle richieste fatte al server
float numero_di_richieste_per_fascia = 0;

// il numero delle risposte restituite con errori dal server
float num_richieste_non_esaudite_per_fascia = 0;

// la soglia minima di risposte corrette/risposte totali che il server deve rispettare
float percentuale_minima = 95.0;

int main()
{
    // Visualizzazione del messaggio di benvenuto
    cout << "Calcolo della percentuale di risposte corrette vs errate del Server Web" << endl
         << "Percentuale di soglia impostata " << percentuale_minima << "% " << endl
         << endl;

    // Ciclo infinito! Fino a quando l'utente non inserisce un valore nell'intervallo previsto, non si esce !
    while (true)
    {
        cout << "Fascia oraria da considerare [0-23]: ";
        cin >> fascia_oraria;

        // verifica che il dato inserito dall'utente sia tra quelli attesi ...
        if (fascia_oraria < 0 || fascia_oraria > 23)
        {
            // ... il dato inserito è fuori dall'intervallo previsto, stampiamo un messaggio
            cout << endl
                 << "La fascia inserita non è valida. Inserire un numero nell'intervallo [0-23]" << endl
                 << endl;
        }
        else
        {
            // ... il dato inserito è nell'intervallo previsto, possiamo andare avanti.
            break;
        }
    }

    // Stampiamo un messaggio per richiedere il numero di richieste ricevute dal server.
    cout << "Numero di richieste totali ricevute dal server: ";
    cin >> numero_di_richieste_per_fascia;

    // un ritorno a capo, per fare un po' di spazio
    cout << endl;

    // anche qui un ciclo infinito perché il numero di richieste non esaudite non può
    // essere maggiore del numero di richieste totali
    while (true)
    {
        // Stampiamo un messaggio per richiedere il numero di richieste ricevute dal server.
        cout << "Numero di richieste NON esaudite dal server [0-" << numero_di_richieste_per_fascia << "]: ";
        cin >> num_richieste_non_esaudite_per_fascia;

        // un ritorno a capo, per fare un po' di spazio
        cout << endl;

        // verifichiamo che il valore inserito dall'utente sia coerente ...
        if (num_richieste_non_esaudite_per_fascia > numero_di_richieste_per_fascia)
        {
            // ... il numero inserito è maggiore del numero di richieste totali. Chiediamo un nuovo valore.
            cout << "Il numero di richieste non esaudite non può essere maggiore del numero di richieste totali (" << numero_di_richieste_per_fascia << ")! " << endl
                 << endl;
        }
        else
        {
            // ... il numero inserito è coerente. possiamo uscire dal loop
            break;
        }
    }

    // abbiamo tutti i dati per calcolare la percentuale di risposte corrette del server:
    float percentuale_risposte_corrette = ((numero_di_richieste_per_fascia - num_richieste_non_esaudite_per_fascia) / numero_di_richieste_per_fascia) * 100;

    // e possiamo inviare allo schermo il risultato
    cout << "Dalle " << fascia_oraria << ":00 alle " << fascia_oraria << ":59 percentuale di successo: " << percentuale_risposte_corrette << "% ==> ";

    // e forniamo un giudizio sulla bontà del servizio svolto dal server ...
    if (percentuale_risposte_corrette >= percentuale_minima)
    {
        // ... se maggiore della soglia minima stampiamo un OK con una faccina sorridente
        cout << "OK! 👍";
    }
    else
    {
        // ... altrimenti una faccina triste
        cout << "KO 👎";
    }

    // un po' di spazio in verticale
    cout << endl
         << endl;

    return 0;
}