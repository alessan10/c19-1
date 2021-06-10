# Corso di Laurea Magistrale in Ingegneria Informatica - a.a. 2020/2021

## Progetto di Advanced Programming Languages 

## Titolo: Covid-19 Tracker 



## Documentazione



- ##### Introduzione

Questo progetto è una rivisitazione dell’app Immuni per il tracciamento dei contagi, con alcune differenze.
L’obiettivo è quello di migliorare l’efficacia del sistema di tracciamento diminuendo la discrepanza tra la realtà e il modello che la rappresenta, a scapito della privacy.
Come miglioriamo il servizio?
A differenza di Immuni, in cui il contagiato non ha l’obbligo di comunicare il proprio stato di malattia sull’App, in questo progetto la positività dell’utente viene comunicata direttamente dal centro sanitario che ha effettuato il tampone.In questo modo si può risalire più efficacemente alla lista di persone venute in contatto col soggetto positivo.In particolare, ogni centro sanitario rappresenta il client e tramite delle interazioni con il server è in grado di memorizzare nel database i dati relativi ai pazienti i cui tamponi si sono rivelati positivi. Allo stesso modo ogni centro sanitario è in grado di prelevare il numero di persone con cui il paziente positivo è entrato in contatto, per avere una stima accurata del numero di tamponi che dovrà effettuare nell’immediato futuro nella zona in cui opera.



- ##### Scelte implementative

###### Client: C++

Poiché i client possono utilizzare qualsiasi sistema operativo (Windows, Linux, MacOS), C++ ci garantisce una ragionevole portabilità per tutti questi sistemi.

###### Server: Golang

Essendo un’applicazione su larga scala, i server sono soggetti a una grande sollecitazione in termini di richieste ricevute; scegliamo Go in quanto ci permette di sfruttare tutti i core delle macchine su cui viene eseguito.

###### Statistiche: R

...

###### App mobile: C#

...

###### Database: NEO4J

Database non relazione nel quale  vengono memorizzati gli utenti e le loro interazioni.



- ##### Dettaglio sulle scelte implementative

