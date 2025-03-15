#include <iostream>

using namespace std;

#define MAX_LIBRI 100

struct libro
{
    int id;
    string titolo;
    string data_pubblicazione;
    string autore_nome;
    string autore_cognome;
    string casa_editrice;
    float prezzo_di_vendita;
};

libro biblioteca[MAX_LIBRI];
int prossimo_id = 0;

void aggiungi_libro(libro da_aggiungere)
{
    da_aggiungere.id = prossimo_id;
    biblioteca[prossimo_id] = da_aggiungere;
    prossimo_id++;
}

void crea_dati_di_test()
{
    aggiungi_libro({1, "Il Nome della Rosa", "01/01/1980", "Umberto", "Eco", "Bompiani", 15.00});
    aggiungi_libro({2, "Cent'anni di solitudine", "01/01/1967", "Gabriel", "García Márquez", "Feltrinelli", 18.00});
    aggiungi_libro({3, "1984", "01/01/1949", "George", "Orwell", "Mondadori", 12.00});
    aggiungi_libro({4, "Delitto e castigo", "01/01/1866", "Fëdor", "Dostoevskij", "BUR Rizzoli", 10.00});
    aggiungi_libro({5, "Il Signore degli Anelli", "01/01/1954", "J.R.R.", "Tolkien", "Bompiani", 25.00});
    aggiungi_libro({6, "Orgoglio e pregiudizio", "01/01/1813", "Jane", "Austen", "Garzanti", 9.00});
    aggiungi_libro({7, "Se una notte d'inverno un viaggiatore", "01/01/1979", "Italo", "Calvino", "Einaudi", 14.00});
    aggiungi_libro({8, "La Divina Commedia", "01/01/1320", "Dante", "Alighieri", "Mondadori", 20.00});
    aggiungi_libro({9, "Harry Potter e la pietra filosofale", "01/01/1997", "J.K.", "Rowling", "Salani", 16.00});
    aggiungi_libro({10, "Il piccolo principe", "01/01/1943", "Antoine", "de Saint-Exupéry", "Bompiani", 11.00});
}

void mostra_menu()
{
    cout << endl
         << endl;
    cout << "MENU:" << endl;
    cout << "  1. Aggiungi un libro" << endl;
    cout << "  2. Modifica un libro dato il suo id" << endl;
    cout << "  3. Ricerca per prezzo di vendita" << endl;
    cout << "  4. Conta libri pubblicati per data pubblicazione" << endl;
    cout << "  0. Esci" << endl
         << endl;
}

int attendi_scelta()
{
    int scelta;
    cout << "Fai la tua scelta: ";
    cin >> scelta;
    return scelta;
}

void esegui_aggiungi_libro()
{
    libro da_aggiungere;
    cout << "Titolo: ";
    cin >> da_aggiungere.titolo;
    cout << "Autore, Nome: ";
    cin >> da_aggiungere.autore_nome;
    cout << "Autore, Cognome: ";
    cin >> da_aggiungere.autore_cognome;
    cout << "Data Pubblicazione [gg/mm/aaa]: ";
    cin >> da_aggiungere.data_pubblicazione;
    cout << "Prezzo di Vendita: ";
    cin >> da_aggiungere.prezzo_di_vendita;

    aggiungi_libro(da_aggiungere);
}

void esegui_modifica_libro()
{
    int id_da_modificare = 0;
    cout << "id da modificare: [0-" << prossimo_id - 1 << "]: ";
    cin >> id_da_modificare;

    libro da_modificare = biblioteca[id_da_modificare];

    cout << "Titolo [" << da_modificare.titolo << "]: ";
    cin >> da_modificare.titolo;

    cout << "Autore, Nome [" << da_modificare.autore_nome << "]: ";
    cin >> da_modificare.autore_nome;

    cout << "Autore, Cognome [" << da_modificare.autore_cognome << "]: ";
    cin >> da_modificare.autore_cognome;

    cout << "Data Pubblicazione [" << da_modificare.data_pubblicazione << "]: ";
    cin >> da_modificare.data_pubblicazione;

    cout << "Prezzo di Vendita [" << da_modificare.prezzo_di_vendita << "]: ";
    cin >> da_modificare.prezzo_di_vendita;
}

void mostra_libro(libro da_mostrare)
{
    cout << "----------------------------------------------------------------------" << endl;
    cout << "                id: " << da_mostrare.id << endl;
    cout << "            Titolo: " << da_mostrare.titolo << endl;
    cout << "            Autore: " << da_mostrare.autore_cognome << " " << da_mostrare.autore_nome << endl;
    cout << "Data Pubblicazione: " << da_mostrare.data_pubblicazione << endl;
    cout << "     Casa Editrice: " << da_mostrare.casa_editrice << endl;
    cout << " Prezzo di Vendita: " << da_mostrare.prezzo_di_vendita << endl;
}

void esegui_ricerca_per_prezzo()
{
    float prezzo_soglia;
    cout << "Ricerca libri con prezzo di vendita minore di: ";
    cin >> prezzo_soglia;

    for (int i = 0; i < prossimo_id; i++)
    {
        libro corrente = biblioteca[i];
        if (corrente.prezzo_di_vendita < prezzo_soglia)
        {
            mostra_libro(corrente);
        }
    }
}

void esegui_libri_per_anno_pubblicazione()
{
    int anno_limite;
    cout << "Conta libri con anno di pubblicazione maggiore o uguale a: ";
    cin >> anno_limite;

    int conteggio = 0;
    for (int i = 0; i < prossimo_id; i++)
    {
        libro corrente = biblioteca[i];
        int indice_inizio_anno = corrente.data_pubblicazione.length() - 4;
        string anno_stringa = corrente.data_pubblicazione.substr(indice_inizio_anno, 4);
        int anno = stoi(anno_stringa);

        if (anno >= anno_limite) 
        {
            conteggio++;
        }
    }
    cout << "Trovati " << conteggio << " libri pubblicati dal " << anno_limite << endl << endl;
}

void esegui_scelta(int scelta)
{
    switch (scelta)
    {
    case 0: // Esci
        cout << endl << "Arrivederci !" << endl << endl;
        break;

    case 1: // Aggiungi un libro
        esegui_aggiungi_libro();
        break;

    case 2: // Modifica un libro
        esegui_modifica_libro();
        break;

    case 3: // Ricerca per prezzo di vendita
        esegui_ricerca_per_prezzo();
        break;

    case 4: // Libri per anno pubblicazione
        esegui_libri_per_anno_pubblicazione();
        break;

    default:
        cout << "Opzione " << scelta << " non valida!" << endl;
    }
}

/*
Entry point dell'applicazione.
*/
int main()
{
    // Crea dei dati di test
    crea_dati_di_test();

    int scelta = -1;
    do
    {
        mostra_menu();
        scelta = attendi_scelta();
        esegui_scelta(scelta);
    } while (scelta != 0);
}