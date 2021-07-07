#leggo il file
data = read.csv("/Users/andreacalabretta/Downloads/out.csv")
#ordino in base ai mesi
data.ordered = data[order(match(data$Mese, month.abb)),]
#creo un subset con solo i positivi
data.positive = subset(data.ordered, Covid == "positivo", select = c(Id, Nome, Cognome, Age, ChatId, Covid, Anno, Mese, Giorno, Weekday, Country)) 

#prendo solo i positivi del 2020
data.positive.year20 = with(data.positive, data.positive[(Anno == "2020"),]) 
#estraggo i mesi del 2020 in un vettore
month.vector.20 = data.positive.year20$Mese 
#conto quante volte si ripete ciascun mese nel 2020
month.vector.20.counter = table(month.vector.20)
jpeg("/Users/andreacalabretta/Documents/0.MAGISTRALE_INFO/8.APL/consegna/c19-1/r/covid+_2020_plot.jpg", width = 1024, height = 768)
barplot(month.vector.20.counter, ylab = "positivi", xlab="mesi 2020")
dev.off()



