library(cartography)

#importo il dataframe:
data = read.csv("/Users/andreacalabretta/Downloads/out.csv") 
#creo un subset con solo i positivi:
data.positive.bycountry = subset(data, Covid == "positivo", select = c(Country, Covid)) 
#metto i countries in un vettore:
country.vector = data.positive.bycountry$Country 
#conto quanti sono i positivi totali per ogni country:
country.vector.counter = table(country.vector)
#trasformo in un dataframe la tabella dove ho conteggiato le country:
new.df = as.data.frame.table(country.vector.counter) 
#creo un'immagine jpeg 
jpeg("/Users/andreacalabretta/Documents/0.MAGISTRALE_INFO/8.APL/consegna/c19-1/r/geo_plot.jpg", width = 1024, height = 768)
#plotto il grafico dei dati che mando in ingresso
choroLayer(spdf = nuts0.spdf, df = new.df, var = "Freq" , legend.pos = "right")
title("Positive by Country")
dev.off()

