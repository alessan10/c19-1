//Importiamo le librerie necessarie alla generazione i dati delle persone fittizie
const { fake } = require('faker');
var faker = require('faker');
var fs = require('fs');
const { exit } = require('process');

// scegliamo di generare contenuti in lingua inglese 
faker.locale = "en";

var str= "";

//genero date
for (var i=0; i<100; i++){
    var aux = faker.date.past().toString();
    aux = aux.substring(0, 15); //da 0 a 15 significa che non stampa la parte di stringa successiva GMT+01 eccetera
    str += aux +'\n';
}

//scriviamo le queries su file
fs.writeFile('generator_data.txt', str, function(err){
    if(err) { return console.log(err); } console.log('The file was saved');
  });
  