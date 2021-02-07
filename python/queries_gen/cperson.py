import random

class Person:

  status = ('positivo', 'negativo') 

  def __init__(self, name, chatid, weekday, day, month, year):
    self.name = name
    self.chatid = chatid
    self.covid = self.status[random.choice([0, 1])]
    self.day = day
    self.weekday = weekday
    self.month = month
    self.year = year
    

  def toString(self):
    print("\n")
    print("Name : " + self.name)
    print("Chatid : " + self.chatid)
    print("Covid : " + self.covid)
    print("Weekday : " + self.weekday)
    print("Day : " + self.day)
    print("Month : " + self.month)
    print("Year : " + self.year)









