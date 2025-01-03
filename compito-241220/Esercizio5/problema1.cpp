#include <iostream>

using namespace std;

// il numero da indovinare ! Il problema specifica di crearlo come "costante" 
const int da_indovinare = 13;

int main()
{
    // breve messaggio "introduttivo"
    cout << "Ho pensato ad un numero tra 1 e 20 (estremi compresi)..." << endl
         << "Prova ad indovinarlo !" << endl
         << endl;

    // conterrà il tentativo fatto dall'utente
    int tentativo = 0;

    // non strettamente richiesto dal problema. Serve a contare i tentativi fatti.
    int num_tentativi = 0;

    // il loop è "infinito"! Si potrà uscire (con un break) indovinando o inserendo 0. Oppure premendo CTRL+C !
    while(true)
    {
        // incrementiamo il numero di tentativi fatti.
        num_tentativi++;

        // stampa un messaggio per richiedere un nuovo tentativo.
        cout << "Fai il tuo tentativo [inserisci 0 o premi CTRL+C per smettere di giocare]: ";

        // legge il tentativo fatto dall'utente
        cin >> tentativo;

        // serve solo a fare un po' di spazio
        cout << endl;

        // se l'utente ha inserito 0 ...
        if (tentativo == 0)
        {
            // stampiamo un messaggio ed interrompiamo il loop
            cout << "Sarà per la prossima volta!" << endl
                 << endl
                 << "Ciao!" << endl
                 << endl;

            break;
        }

        // se l'utente ha indovinato ...
        if (tentativo == da_indovinare)
        {
            // stampiamo un messaggio ed interrompiamo il loop
            cout << "Bravo, hai indovinato in " << num_tentativi << " tentativo/i" << endl;
            break;
        }
        else
        {
            // l'utente non ha indovinato ...
            cout << "No, non hai indovinato! ";
            
            if (tentativo < da_indovinare)
            {
                // ... inserendo un valore troppo basso
                cout << "Il tuo tentativo è troppo basso!";
            }
            else
            {
                // ... inserendo un valore troppo alto
                cout << "Il tuo tentativo è troppo alto!";
            }

            // ritorno a capo per fare un po' di spazio nell'output
            cout << endl
                 << endl;
        }
    } // while

    return 0;
}