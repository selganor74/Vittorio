#include <iostream>

using namespace std;

const int da_indovinare = 13;

int main()
{
    cout << "Ho pensato ad un numero tra 1 e 20 (estremi compresi)..." << endl
         << "Prova ad indovinarlo !" << endl;

    int tentativo = 0;
    int num_tentativi = 0;
    do
    {
        num_tentativi++;
        cout << "Fai il tuo tentativo [0 per smettere di giocare]: ";
        cin >> tentativo;

        if (tentativo == 0)
        {
            cout << endl << "Sarà per la prossima volta! Ciao!" << endl;
            break;
        }

        if (tentativo == da_indovinare)
        {
            cout << "Bravo, hai indovinato in " << num_tentativi << " tentativo/i" << endl;
            break;
        }
        else
        {
            cout << "No, non hai indovinato! ";
            if (tentativo < da_indovinare)
            {
                cout << "Il tuo tentativo è troppo basso!";
            }
            else
            {
                cout << "Il tuo tentativo è troppo alto!";
            }
            cout << endl
                 << endl;
        }
    } while (true);

    return 0;
}