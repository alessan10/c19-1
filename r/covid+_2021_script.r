#leggo il file:
data = read.csv("/Users/andreacalabretta/Downloads/out.csv") 
#ordino in base ai mesi:
data.ordered = data[order(match(data$Mese, month.abb)),] 
#creo un subset con solo i positivi
data.positive = subset(data.ordered, Covid == "positivo", select = c(Id, Nome, Cognome, Age, ChatId, Covid, Anno, Mese, Giorno, Weekday, Country)) 

#prendo solo i positivi del 2021
data.positive.year21 = with(data.positive, data.positive[(Anno == "2021"),])
#estraggo i mesi del 2021 in un vettore
month.vector.21 = data.positive.year21$Mese 
#conto quante volte si ripete ciascun mese nel 2021
month.vector.21.counter = table(month.vector.21) 
jpeg("/Users/andreacalabretta/Documents/0.MAGISTRALE_INFO/8.APL/consegna/c19-1/r/covid+_2021_plot.jpg", width = 1124, height = 680)
barplot(month.vector.21.counter, ylab = "positivi", xlab="mesi 2021")
#dopo il comando per plottare ci vuole dev.off; senza di esso potremmo ottenere un plot parziale o addirittura nulla
dev.off()


