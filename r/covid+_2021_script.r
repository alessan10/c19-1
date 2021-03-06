#leggo il file
data = read.csv("C:/Users/alexm/Downloads/out.csv")
#ordino in base ai mesi
data.ordered = data[order(match(data$Mese, month.abb)),]
#creo un subset con solo i positivi
data.positive = subset(data.ordered, Covid == "positivo", select = c(Id, Nome, Cognome, Age, ChatId, Covid, Anno, Mese, Giorno, Weekday, Country)) 

#prendo solo i positivi del 2021
data.positive.year21 = with(data.positive, data.positive[(Anno == "2021"),]) 
#estraggo i mesi del 2021 in un vettore
month.vector.21 = data.positive.year21$Mese
#conto quante volte si ripete ciascun mese nel 2021
month.vector.21.counter = table(month.vector.21) 
#creo il file jpeg
jpeg("D:/Alessandro/uniCT/Magistrale/Secondo_Anno/1_Advanced_Programming_Languages/Progetto_Esame/git_c19/c19/r/covid+_2021_plot.jpg", width = 1024, height = 768)
#plotto
barplot(month.vector.21.counter, ylab = "positivi", xlab="mesi 2021")
dev.off()