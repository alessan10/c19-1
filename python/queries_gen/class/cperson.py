class Cperson:
  def __init__(self, name, chatid, covid, weekday, day, month, year):
    self.name = name
    self.chatid = chatid
    self.covid = covid
    self.weekday = weekday
    self.day = day
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
