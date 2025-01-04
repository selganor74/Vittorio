#include <iostream>

using namespace std;

int main()
{
    int numero;
    while(numero >= 10)
    {
        // cout << "________________________________________________" << endl;
        cin >> numero;
    };
}

/*
    Se modifico il programma passando dal do...while() al while() in questo modo.
    
    Il programma resta identico?   NO

    Fornisci una breve spiegazione:

    Usando while() invece di do...while() Il controllo sul valore del numero viene 
    eseguito all'inizio del ciclo. Se il controllo fallisce il ciclo non viene MAI
    eseguito. Usando do...while() invece, il ciclo viene eseguito almeno una volta.
    
    Inoltre la variabile numero non viene inizializzata, pertanto conterrà un valore
    non determinato. Il risultato del primo controllo del while() non è prevedibile.
*/