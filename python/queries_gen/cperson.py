class Person:
  def __init__(self, name, chatid, covid, weekday, day, month, year):
    self.name = name
    self.chatid = chatid
    self.covid = covid
    self.day = day
    self.weekday = weekday
    self.month = month
    self.year = year
    

  def toString(self):
    print("Name : " + self.name)
    print("Chatid : " + self.chatid)
    print("Covid : " + self.covid)
    print("Weekday : " + self.weekday)
    print("Day : " + self.day)
    print("Month : " + self.month)
    print("Year : " + self.year)




d = Person("Deb", "-", "positivo", "Mon", "12","Jen", "2021")


d.toString()







