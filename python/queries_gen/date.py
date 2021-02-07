class Date: 
  
  def __init__(self, string, week): 
    # string = 2020-12-30
    # week = Wednesday
    self.year = string[0:4] # 2020
    self.month = string[5:7] # 12
    self.day = string[8:10] # 31
    self.weekDay = week[0:3] # Wed

  def toString(self):
    print("Year: ", self.year)
    print("Month: ", self.month)
    print("Day: ", self.day)
    print("Day of the week: ", self.weekDay)

    
