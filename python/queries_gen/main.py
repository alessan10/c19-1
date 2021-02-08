import sys
import date 
import cperson 
from faker import Faker

fake = Faker('en_US') # we generate just american names

tot = sys.argv[1] # total number of fake people to generate

array = []

flag = 1

for n in range(int(tot)): 
  flag = 1
  fullDate = fake.date_between(start_date='-1y', end_date='today') #generate a random date between 365 days ago and today
  #print(str(fullDate))
  data = date.Date(str(fullDate), str(fake.day_of_week()))
  #data.toString()
  p = cperson.Person(fake.first_name(), fake.last_name(), "-", data.weekDay, data.day, data.month, data.year)
  p.toString()
  if ("'" in p.first_name or "'" in p.last_name) :
    flag =0
  if n == 0:
    string = 'CREATE'
  if flag == 1:
    string += '(' + p.first_name.lower() + "_"+ p.last_name.lower() + ':Cperson {name: "' + p.first_name + ' ' +p.last_name +'", chatid: "-", covid: "'+ p.covid+ '",year: "'+ p.year + '", month: "'+ p.month +'", day: "'+ p.day +'", weekday: "'+ p.weekday+ '"}),' + '\n'
    array.append(p.first_name.lower() + '_' + p.last_name.lower())


array2 = []
#Facciamo una copia dell'array dentro l'array3
array3 = array.copy()
print(array)
print(array3)





