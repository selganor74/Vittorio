/*
    1. Simulazione input e output

    Esempio 1

        Calcolo della percentuale di risposte corrette vs errate del Server Web

        Dalle 0:00 alle 0:59 percentuale di successo: 95% ==> ok  3833 / 4031
        Dalle 1:00 alle 1:59 percentuale di successo: 93% ==> KO  7056 / 7545
        Dalle 2:00 alle 2:59 percentuale di successo: 93% ==> KO  5546 / 5908
        [...]
        Dalle 23:00 alle 23:59 percentuale di successo: 91% ==> KO  7825 / 8530

        numero richieste totali:        132447
        numero di richieste ok:         126644
        numero di richieste ko:         5803
        fasce orarie ok:                14
        percentuale giornaliera ok/tot: 95.6186 ok 

    2. Algoritmo

        * Visualizza un messaggio di benvenuto
        * Azzera l'accumulatore giornaliero delle richieste
        * Azzera l'accumulatore giornaliero delle richieste errate
        * Per ogni fascia oraria n da 0 a 23
            * Ottieni il numero delle richieste totali per fascia n usando la funzione "random"
            * Aggiungi all'accumulatore giornaliero delle richieste il numero delle richieste totali per fascia n
            * Ottieni il numero delle richieste ERRATE per fascia usando la funzione "random" ed accertandoti 
                che siano sempre minori delle richieste totali per fascia
            * Aggiungi all'accumulatore giornaliero delle richieste errate il numero delle richieste errate per fascia
            * Calcola la percentuale di successo per la fascia n
            * Se la percentuale di successo calcolata è minore della percentuale impostata come soglia
            *   allora visualizza le statistiche con un KO
            *   altrimenti visualizza le statistiche con un OK!
        * Calcola il numero giornaliero delle richieste ok
        * Calcola la percentuale giornaliera delle richieste
        * Visualizza l'insieme delle statistiche giornaliere
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

    // STATISTICHE: conterrà il numero di fasce orarie ok per il resoconto giornaliero
    int num_fasce_orarie_ok = 0;

    // STATISTICHE: conterrà il numero totale di richieste ricevute nel giorno
    float numero_richieste_giornaliere = 0;

    // STATISTICHE: conterrà il numero di richieste fallite nel giorno
    float numero_richieste_ko = 0;

    // STATISTICHE: percentuale giornaliera
    float percentuale_giornaliera = 0;

    // eseguiamo un ciclo per coprire tutte le fasce orarie di un giorno
    for (fascia_oraria = 0; fascia_oraria < 24; fascia_oraria++)
    {
        // usiamo la funzione random per sostituire l'input dell'utente
        numero_di_richieste_per_fascia = random(1, 10000);

        // STATISTICHE: aggiorna il numero di richieste giornaliere
        numero_richieste_giornaliere += numero_di_richieste_per_fascia;

        // usiamo la funzione random per sostituire l'input dell'utente.
        // per avere una distribuzione di KO e OK "visibile" limitiamo
        // il numero di richieste non esaudite ad un decimo di quelle effettive.
        num_richieste_non_esaudite_per_fascia = random(0, numero_di_richieste_per_fascia / 10);

        // STATISTICHE: aggiorna i valori totali giornalieri
        numero_richieste_ko += num_richieste_non_esaudite_per_fascia;

        // abbiamo tutti i dati per calcolare la percentuale di risposte corrette del server:
        int percentuale_risposte_corrette = ((numero_di_richieste_per_fascia - num_richieste_non_esaudite_per_fascia) / numero_di_richieste_per_fascia) * 100;

        // e possiamo inviare allo schermo il risultato
        cout << "Dalle " << fascia_oraria << ":00 alle " << fascia_oraria  << ":59 percentuale di successo: " << percentuale_risposte_corrette << "% ==> ";

        // e forniamo un giudizio sulla bontà del servizio svolto dal server ...
        if (percentuale_risposte_corrette >= percentuale_minima)
        {
            // ... se maggiore della soglia minima stampiamo un OK
            cout << "ok! 👍";

            // ed incrementiamo le fasce orarie ok
            num_fasce_orarie_ok++;
        }
        else
        {
            // ... altrimenti KO
            cout << "KO  👎";
        }

        // aggiungiamo all'output anche i numeri che concorrono al calcolo della percentuale.
        cout << " " << numero_di_richieste_per_fascia - num_richieste_non_esaudite_per_fascia << " / " << numero_di_richieste_per_fascia << endl;
    }

    float numero_richieste_ok = numero_richieste_giornaliere - numero_richieste_ko;
    percentuale_giornaliera = (numero_richieste_ok / numero_richieste_giornaliere) * 100;

    cout << endl
         << "numero richieste totali:        " << numero_richieste_giornaliere << endl
         << "numero di richieste ok:         " << numero_richieste_ok << endl
         << "numero di richieste ko:         " << numero_richieste_ko << endl
         << "fasce orarie ok:                " << num_fasce_orarie_ok << endl
         << "percentuale giornaliera ok/tot: " << percentuale_giornaliera;

    if (percentuale_giornaliera >= percentuale_minima)
    {
        // ... se maggiore della soglia minima stampiamo un OK
        cout << " ok! 👍";

        // ed incrementiamo le fasce orarie ok
        num_fasce_orarie_ok++;
    }
    else
    {
        // ... altrimenti KO
        cout << " KO  👎";
    }

    cout << endl
         << endl;

    return 0;
}
