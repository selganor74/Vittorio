#include <iostream>
using namespace std;

#define N 30
#define N_MATERIE 5

struct studente
{
    string sMatricola;
    string sNome;
    string sCognome;
    int votoMaterie[N_MATERIE];
};

studente registro[N];
int num_studenti = 0;

int print_menu()
{
    int scelta;
    cout << "Scegli una voce" << endl;
    cout << "  1.) Aggiungi uno studente." << endl;
    cout << "  0.) Esci." << endl;
    cout << endl;
    cout << "Scelta: ";
    cin >> scelta;

    return scelta;
}

void aggiungi_studente()
{
    studente nuovo;
    cout << "Aggiungi un nuovo Studente: " << endl << endl;
    cout << "  Nome     : ";
    cin  >> nuovo.sNome;
    cout << "  Cognome  : ";
    cin  >> nuovo.sCognome;
    cout << "  Matricola: ";
    cin  >> nuovo.sMatricola;
    
    for(int m = 0; m < N_MATERIE; m++) 
    {
        cout << "     Voto " << m + 1 << ": ";
        cin >> nuovo.votoMaterie[m];
    }

    registro[num_studenti] = nuovo;
    num_studenti++;
}

int main()
{
    int scelta;
    do
    {
        scelta = print_menu();
        switch (scelta)
        {
            case 1:
                aggiungi_studente();
                break;
        }
    } while (scelta != 0);

    return 0;
}
