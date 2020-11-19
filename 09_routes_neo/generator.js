const { fake } = require('faker');
var faker = require('faker');
var fs = require('fs');
const { exit } = require('process');

faker.locale = "en";

var str= "";

var covid = [
  'positivo',
  'negativo'
]

var array = []

var totale = 100;
var flag = 1;

for (var i=0;i<totale; i++){  
  flag = 1;
  var firstname = faker.name.firstName();
  var lastName = faker.name.lastName();
  if (firstname.includes("'") || lastName.includes("'")) flag = 0 ;
  var random = Math.floor(Math.random()*2 +1) -1;
  if (i==0){
    str = 'CREATE ';
  } 
  if (flag == 1){
    str += '(' + firstname.toLowerCase() + "_" + lastName.toLowerCase() + ':CPerson {name: "'  + firstname + ' ' + lastName + '", chatid: "-", covid: "' + covid[random] + '"}),' +'\n';
    array.push(firstname.toLowerCase() + '_' + lastName.toLowerCase())
  }  
}

// fs.writeFile('test.txt', str, function(err){
//   if(err) { return console.log(err); } console.log('The file was saved');
// });

// for(var i = 0; i < array.length ; i++){     
//   console.log(array[i]) 
// }

// for(var i=0; i<20; i++){
//   var n = Math.floor(Math.random()*5 )+5;
//   console.log(n)
// }

// var group = Math.floor(Math.random()*5 )+5;
// for(var i = 0; i < array.length ; i++){
//   str += '(' + array[i] + ')-[:CONTACT]->(' + array[i++] + '),';
// }

//SEMIFUNZIONANTE
// var somma_rndn = 0;

// for (group = 0; somma_rndn < totale; ){
//   var indice = Math.floor(Math.random()*5 )+5;
//   console.log(indice);
//   for (var i= group; i<indice; i++)
//   str2 += '(' + array[group] + ')-[:CONTACT]->(' + array[i++] + '),'+ '\n';
//   group = indice;
//   console.log(str2);
//   somma_rndn += indice;
// }


// fs.writeFile('test.txt', str, function(err){
//   if(err) { return console.log(err); } console.log('The file was saved');
// });

var array2=[];
var array3=[];

for (var i of array){
  array3.push(i);
}



console.log("1Array1: \n")
for(var i = 0; i < array.length ; i++){     
  console.log(array[i]) 
}


label:
while (array.length >1) 
{
  if (array.length <2 ) continue label;

  var src = Math.floor(Math.random()*array.length +1) -1;
  console.log("src: ", src);

  var node = array.splice(src, 1);
  array2.push(node);
  var edges = Math.floor(Math.random()*5 )+5;
  console.log("edges: ", edges);

  for (var i = 0; i<edges; i++)
  {
    var dest = Math.floor(Math.random()*array.length +1) -1;
    if (array[dest] == undefined){
      break;
    }
    str += '(' + node + ')-[:CONTACT]->(' + array[dest] + '),'+ '\n';
    //console.log(str);
    var removed = array.splice(dest, 1);
    console.log("removed: ", removed );
    console.log("remaining: ", array.length);
  }
} 

console.log(str);



  for (i=0; i< array3.length; i++){
    for(j =0; j < array2.length; j++){
      if(array3[i] == array2[j] ) array3.splice(i, 1)
    }
  }


  console.log("Array1: \n")
  for(var i = 0; i < array.length ; i++){     
    console.log(array[i]) 
  }

  console.log("Array2: \n")
  for(var i = 0; i < array2.length ; i++){     
    console.log(array2[i]) 
  }

  console.log("Array3: \n")
  for(var i = 0; i < array3.length ; i++){     
    console.log(array3[i]) 
  }


  label2:
while (array3.length >1) 
{
  if (array3.length <2 ) continue label2;

  var src = Math.floor(Math.random()*array3.length +1) -1;
  console.log("src: ", src);

  var node = array3.splice(src, 1);
  //array.push(node);
  var edges = Math.floor(Math.random()*5 )+5;
  console.log("edges: ", edges);

  for (var i = 0; i<edges; i++)
  {
    var dest = Math.floor(Math.random()*array3.length +1) -1;
    if (array3[dest] == undefined){
      break;
    }
    str += '(' + node + ')-[:CONTACT]->(' + array3[dest] + '),'+ '\n';
    //console.log(str);
    var removed = array3.splice(dest, 1);
    console.log("removed: ", removed );
    console.log("remaining: ", array3.length);
  }
} 


str = str.substring(0, str.length - 2);

fs.writeFile('test.txt', str, function(err){
  if(err) { return console.log(err); } console.log('The file was saved');
});
