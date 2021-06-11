data = read.csv("C:/Users/alexm/Downloads/out.csv") #leggo il file
data.ordered = data[order(match(data$Mese, month.abb)),] #ordino in base ai mesi
data.positive = subset(data.ordered, Covid == "positivo", select = c(Id, Nome, Cognome, Age, ChatId, Covid, Anno, Mese, Giorno, Weekday, Country)) #creo un subset con solo i positivi

#anno 2020
data.positive.year20 = with(data.positive, data.positive[(Anno == "2020"),]) #prendo solo i positivi del 2020
month.vector.20 = data.positive.year20$Mese #estraggo i mesi del 2020 in un vettore
month.vector.20.counter = table(month.vector.20) #conto quante volte si ripete ciascun mese nel 2020
jpeg("covid+_2020_plot.jpg", width = 1024, height = 768)
barplot(month.vector.20.counter, ylab = "positivi", xlab="mesi 2020")
dev.off()


#month.vector.20.trim = unique(month.vector.20) #tolgo i mesi ripetuti
#month.vector.21.trim = unique(month.vector.21) #tolgo i mesi ripetuti

#library(lattice) #mi serve se uso dotplot
#dotplot(month.vector.20.counter~month.vector.20.trim, ylab = "positivi", xlab="mesi 2020") #plotto il vettore  con i contatori(ASSE Y) e il vettore dei mesi(ASSE X)  
#dotplot(month.vector.21.counter~month.vector.21.trim, ylab = "positivi", xlab="mesi 2021") #plotto il vettore  con i contatori(ASSE Y) e il vettore dei mesi(ASSE X)  

#barplot(month.vector.20.counter~month.vector.20.trim, ylab = "positivi", xlab="mesi 2020") #uguale ma con istogramma 
#barplot(month.vector.21.counter~month.vector.21.trim, ylab = "positivi", xlab="mesi 2021") #uguale ma con istogramma  


#data.positive.year20[order(match(data.positive.year20$Mese, month.abb)),]
