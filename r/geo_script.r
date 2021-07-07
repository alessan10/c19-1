library(cartography)

#importo il dataframe
data = read.csv("C:/Users/alexm/Downloads/out.csv") 
#creo un subset con solo i positivi
data.positive.bycountry = subset(data, Covid == "positivo", select = c(Country, Covid)) 
#metto le country in un vettore
country.vector = data.positive.bycountry$Country 
#conto quanti sono i positivi per ogni country
country.vector.counter = table(country.vector) 
#trasformo in un dataframe la tabella dove ho conteggiato le country
new.df = as.data.frame.table(country.vector.counter) 
#creo il file jpeg
jpeg("D:/Alessandro/uniCT/Magistrale/Secondo_Anno/1_Advanced_Programming_Languages/Progetto_Esame/git_c19/c19/r/geo_plot.jpg", width = 1024, height = 768)
#plotto
choroLayer(spdf = nuts0.spdf, df = new.df, var = "Freq" , legend.pos = "right") 
title("Positive by Country")
dev.off()