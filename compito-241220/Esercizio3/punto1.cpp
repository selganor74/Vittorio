#include <iostream>

using namespace std;

int main()
{
    int numero;
    do
    {
        // cout << "___________________________________" << endl;
        cin >> numero;
    } while (numero >= 10);
}

/*
    Cosa fa il frammento di programma scritto qui sopra?
    
    Il programma continua a richiedere un valore di input
    fino a quando il valore inserito è maggiore di 10.
    Inserendo un valore inferiore a 10, il programma si ferma.
*/