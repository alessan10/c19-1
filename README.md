# Corso di Laurea Magistrale in Ingegneria Informatica - a.a. 2020/2021

## Progetto di Advanced Programming Languages 

## Titolo: Covid-19 Tracker 

## Studenti: 

- ## 	Andrea Calabretta (matricola: 1000008923)

- ## 	Alessandro Mauro (matricola: 1000009156) 



## Documentazione

- ##### Indice

  - 1. Introduzione
    2. Scelte Implementative
    3. Come avviare il progetto

  

- ##### 1. Introduzione

Questo progetto è una rivisitazione dell’app Immuni per il tracciamento dei contagi, con alcune differenze.
L’obiettivo è quello di migliorare l’efficacia del sistema di tracciamento diminuendo la discrepanza tra la realtà e il modello che la rappresenta, a scapito della privacy.
L'idea di fondo è la seguente: a differenza di Immuni, in cui il contagiato non ha l’obbligo di comunicare il proprio stato di malattia sull’App, in questo progetto la positività dell’utente viene comunicata direttamente dal centro sanitario che ha effettuato il tampone. In questo modo si può risalire più efficacemente alla lista di persone venute in contatto col soggetto positivo. In particolare, ogni centro sanitario rappresenta il client e tramite delle interazioni con il server è in grado di memorizzare nel database i dati relativi ai pazienti i cui tamponi si sono rivelati positivi. Allo stesso modo ogni centro sanitario è in grado di prelevare il numero di persone con cui il paziente positivo è entrato in contatto, per avere una stima accurata del numero di tamponi che dovrà effettuare in futuro e dell'andamento globale della pandemia.



- ##### 2. Scelte implementative

![img](https://github.com/andrea-calabretta/c19/blob/main/z.CONSEGNA/documentazione/Diagram.jpg)

Come evidenziato dalla precedente immagine, abbiamo deciso di utilizzare le seguenti tecnologie:

###### Client: C++

Poiché i client possono utilizzare qualsiasi sistema operativo (Windows, Linux, MacOS), C++ ci garantisce una ragionevole portabilità per tutti questi sistemi.

In dettaglio, abbiamo sfruttato le potenzialità dell'ambiente di sviluppo QTCreator per la realizzazione di un client dotato di interfaccia utente grafica che si adatta ai differenti sistemi operativi (Windows, Linux, MacOS) a partire da un unico codice sorgente. Mette inoltre a disposizione tutti gli elementi grafici necessari compresi metodi e funzioni per ottenere 

###### Server: Golang

Essendo un’applicazione su larga scala, i server sono soggetti a una grande sollecitazione in termini di richieste ricevute; scegliamo Go in quanto ci permette di sfruttare tutti i core delle macchine su cui viene eseguito. Il backend si occupa di eseguire le operazioni CRUD sugli utenti oltre a legarli mediante apposite relazioni pseudocasuali. Comunica con il frontend tramite protocollo HTTP e inviando opportuni codici di errore nel caso in cui le richieste non vadano a buon fine. 

###### Statistiche: R

Il linguaggio R ci consente di produrre statistiche in maniera efficiente e di facile lettura. Gli script, uno per ogni statistica, vengono lanciati dal client e producono un'immagine contenente la statistica richiesta. Questa immagine verrà poi invocata all'interno di una specifica area della view del client.
In particolare, le statistiche sono utili a visualizzare:

- il numero dei positivi in base alla nazione di appartenenza;
- l'andamento dei positivi in un dato anno;
- l'andamento dei positivi in base all'età.

###### App mobile: C#

...

###### Database: NEO4J

Database noSQL nel quale vengono memorizzati gli utenti e le loro interazioni. La scelta di un "graph database" ci permette di memorizzare efficientemente le relazioni tra i pazienti evitando replicazioni di dati. Per popolare inizialmente il database abbiamo implementato un algoritmo JavaScript che genera un numero di soggetti fittizi con i relativi campi (nome, cognome, ecc.) da inserire nel DB.



- ##### 3. Come avviare il progetto

  - Scaricare e avviare Neo4J Desktop, creare un Database e nominarlo “c19”, al suo interno definire: Utente : neo4j - Password: c19

  - Supponendo di aver già installato node.js, popolare il database eseguendo sul terminale il comando all’interno della cartella neo4j_js :
    *<u>node generator.js <**N**></u>*
    dove <**N**> è uguale al numero di pazienti che si vogliono generare.
    Per ottenere dati verosimili, è consigliato un valore compreso tra 100 e 300 (per valori superiori a 300 i nomi e i cognomi fittizi potrebbero ripetersi).

    Verrà prodotto un file di testo “queries_neo4j.txt” che conterrà le queries da incollare all’interno di Neo4J Browser.
    Il grafo così generato avrà un aspetto simile a quello della figura sottostante, i cui nodi sono persone fittizie e gli archi sono le interazioni tra di esse, generate tramite un algoritmo pseudorandom: 

    ![img](https://lh5.googleusercontent.com/bKmIuutiC_l5zs4xwevsgFwbdSc_RAHKR9RhLOPk6IOnlkDbn0iJyGur-zmcpeLUXeu8o5NU1C4IUWy-IHMZU3HNKjloJHZ7hCiJVyFyrWnUDSbHOykFw5Na420DtCh7tvHazR1v)
    
  - Avviare il server Go digitando sul terminale il comando: *<u>go run server.go</u>*
    Dopo aver consentito l'accesso richiesto dal firewall, sarà possibile visualizzare sul terminale il messaggio “SERVER UP" qualora la procedura sia andata a buon fine.
    A questo punto è possibile avviare il client oppure registrarsi al database tramite bot Telegram. 
    Vediamo nel dettaglio entrambe le opzioni:
    - Avviare il client simulando l’azienda ospedaliera che ha accesso al database generale in modo tale da poter visualizzare la situazione dei contagi e vedere le interazioni tra gli utenti.
    - Avviare l’app Telegram sul proprio smartphone e cercare il bot denominato “Covid-19 Tracking Bot”, per registrarsi o per ricevere notifiche push in caso di contatto con un positivo.
  - 



