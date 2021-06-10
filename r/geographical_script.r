library(cartography)

# Load data
#data(nuts2006)

# Build a choropleth
#choroLayer(spdf = nuts0.spdf, df = nuts0.df, var = "death_2008" , legend.pos = "right")
#title("Population in 2008")

#my version
data = read.csv("C:/Users/alexm/Downloads/out.csv") #importo il dataframe
data.positive.bycountry = subset(data, Covid == "positivo", select = c(Country, Covid)) #creo un subset con solo i positivi
country.vector = data.positive.bycountry$Country #metto le country in un vettore
country.vector.counter = table(country.vector) #conto quante sono
new.df = as.data.frame.table(country.vector.counter) #trasformo in un dataframe la tabella dove ho conteggiato le country
choroLayer(spdf = nuts0.spdf, df = new.df, var = "Freq" , legend.pos = "right") #plotto
title("Positive by Country")