var faker = require('faker');
var fs = require('fs');

var str= "";

for (var i=0;i<200; i++)
  str += faker.name.firstName() + ' ' + faker.name.lastName() + '\n';

fs.writeFile('test.txt', str, function(err){
  if(err) { return console.log(err); } console.log('The file was saved');
});