library(lattice)

#leggo il file
data = read.csv("/Users/andreacalabretta/Downloads/out.csv")
#creo un subset con solo i positivi
#data.positive = subset(data, Covid == "positivo", select = c(Id, Nome, Cognome, Age, ChatId, Covid, Anno, Mese, Giorno, Weekday, Country)) 

#creo un subset con solo i positivi
data.positive = subset(data, Covid == "positivo", select = c(Id, Age, Covid)) 

#estraggo le eta' e le metto in un vettore
eta.vector = data.positive$Age 
#li ordino dal piu' piccolo al piu' grande
eta.vector.sorted = sort(eta.vector, decreasing = FALSE) 
#conto quante volte si ripete ciascun valore di eta'

eta.vector.counter = table(eta.vector.sorted) 
jpeg("/Users/andreacalabretta/Documents/0.MAGISTRALE_INFO/8.APL/consegna/c19-1/r/covid+_eta_plot.jpg", width = 1124, height = 680)
dotplot(eta.vector.counter~eta.vector.sorted, ylab = "positivi", xlab="eta'")
#dopo il comando per plottare ci vuole dev.off; senza di esso potremmo ottenere un plot parziale o addirittura nulla
dev.off()
