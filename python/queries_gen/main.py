import sys
import date 
import cperson 
from faker import Faker

fake = Faker('en_US') # we generate just american names

tot = sys.argv[1] # total number of fake people to generate

flag = 1

for n in range(int(tot)): 
  flag = 1
  fullDate = fake.date_between(start_date='-1y', end_date='today') #generate a random date between 365 days ago and today
  #print(str(fullDate))
  data = date.Date(str(fullDate), str(fake.day_of_week()))
  #data.toString()
  p = cperson.Person(fake.name(), "-", data.weekDay, data.day, data.month, data.year)
  p.toString()





