import sys
import random
import cperson as c
from faker import Faker

fake = Faker('en_US')


totale = sys.argv[1]

print("totale:", totale)

print(fake.name())

#p = c.Person()
#print(p.name)
flag = 1

covid = ('positivo','negativo')
print(covid[0])
for n in range(int(totale)): 
  flag = 1
  print(fake.date_between(start_date='-1y', end_date='today'))
  #p = c.Person(fake.name(), "-", covid[random.choice([0, 1])])




