import random

class Person:

  status = ('positivo', 'negativo') 

  def __init__(self, first_name, last_name, chatid, weekday, day, month, year):
    self.first_name = first_name
    self.last_name = last_name
    self.chatid = chatid
    self.covid = self.status[random.choice([0, 1])]
    self.day = day
    self.weekday = weekday
    self.month = month
    self.year = year
    

  def toString(self):
    print("\n")
    print("First name : " + self.first_name)
    print("Last name : " + self.last_name)
    print("Chatid : " + self.chatid)
    print("Covid : " + self.covid)
    print("Weekday : " + self.weekday)
    print("Day : " + self.day)
    print("Month : " + self.month)
    print("Year : " + self.year)









