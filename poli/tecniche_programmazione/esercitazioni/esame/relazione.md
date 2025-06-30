## Relazione esame tecniche di programmazione - I appello del 30/06/2025

#### Cellini Marco 341045

### Funzione ```raggruppaBambini```

<!-- ```c
void raggruppaBambini(bambino b[], int n, int conteggi[10])
{
    int i, n_attivita;
    for (i = 0; i < n; i++)
    {
        n_attivita = b[i].n;
        if (n_attivita > 45)
            conteggi[9]++;
        else
            conteggi[n_attivita / 5]++;
    }
}
``` -->
Le uniche differenze da quanto consegnato nella prova sono:

 - ```viod``` errore di battitura che è stato corretto in ```void```. 

 - La variabile ```len``` non esiste, perché inizialmente al posto di ```int n``` avevo usato ```int len```, ma non l’ho sostituita nel resto del codice.

Eventuale piccola correzione, che però non influenza l'esecuzione della funzione, è la rimozione dell' ```=``` nella condizione ```n_attivita >= 45``` in quanto se ```n_attivita``` è uguale a 45 non si hanno problemi di indici facendo ```conteggi[n_attivita / 5]++;``` a differenza di valori maggiori di 45. 

**Spiegazione codice**
Al fine di raggruppare i bambini in base al numero di attività svolte ```n_attivita```, per evitare di sforare gli indici disponibili nel vettore ```conteggi``` se le attività svolte sono maggiori di 45 viene incrementato il conteggio all'indice 9. 
Viceversa gli altri conteggi vengono incrementati secondo l'indice ```n_attivita / 5``` che mediante la divisione intera divide perfettamente le attività tra $[0, 4]$ nel gruppo0, tra $[5, 9]$ nel gruppo1, ecc...

<!-- *** -->

### Funzione ```attivitaPreferite```

<!-- ```c
void attivitaPreferite(bambino b[], int n, attivita *preferite[])
{
    int i, j, max, n_attivita;
    for (i = 0; i < n; i++)
    {
        max = 0;
        n_attivita = b[i].n;
        for (j = 1; j < n_attivita; j++)
            if (b[i].elenco[j].ingressi > b[i].elenco[max].ingressi)
                max = j;
        preferite[i] = &b[i].elenco[max];
    }
}
``` -->

L'unica modifica rispetto a quanto consegnato all'esame è la correzzione di un errore di battitura :

 - la dichiarazione degli ```int``` iniziale era: ```int i, j max, n_attivita;``` mancava una ```,``` tra ```j``` e ```max```. 

Inoltre una minima ottimizzazione:
 
 - il ciclo interno da essere ```for (j = 0; j < n_attivita; j++)``` è diventato ```for (j = 1; j < n_attivita; j++)``` dato che, di default, il massimo viene impostato con l'indice 0 e non ha senso controllarlo perchè sicuramente non sarà maggiore di se stesso. 

**Spiegazione codice**
La funzione itera tra i bambini e per ogni bambino si setta un variabile ```max``` che rappresenta l'indice dove è presente il maggior numero di ingressi, iterando nella attività svolte [```b[i].elenco```] cerca l'attività svolta con il maggior numero di ingressi e se la trova sostituisce l'indice del massimo con quello nuovo. 
Trovata la "preferita" (quella con il numero di ingressi massimo) memorizza il puntatore all'attività all'indice i-esimo di ```preferite```. 

<!-- *** -->

### Funzione ```piuAttivi```

<!-- ```c
int piuAttivi(bambino b[], int n, int min, bambino *selezionati[])
{
    int i, n_attivita, selected = 0;
    for (i = 0; i < n; i++)
    {
        n_attivita = b[i].n;
        if (n_attivita >= min)
            selezionati[selected++] = &b[i];
    }
    return selected;
}
``` -->

In questa funzione non è stata fatta alcuna modifica rispetto alla consegna originale. 

**Spiegazione codice**
La funzione itera tra i bambini e per ogni bambino valuta la quantità di attivita svolte [```n_attivita```]e, se essa è maggiore o uguale alla soglia minima inserisce il puntatore al bambino i-esimo nella posizione ```selected```, inizializzato a 0 ed incrementato ad ogni inserimento. 
Infine la funzione ritorna il valore di ```selected``` che corrisponde a quanti bambini sono stati selezionati. 