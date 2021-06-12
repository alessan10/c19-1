library(lattice)

data = read.csv("C:/Users/alexm/Downloads/out.csv") #leggo il file
#data.positive = subset(data, Covid == "positivo", select = c(Id, Nome, Cognome, Age, ChatId, Covid, Anno, Mese, Giorno, Weekday, Country)) #creo un subset con solo i positivi
data.positive = subset(data, Covid == "positivo", select = c(Id, Age, Covid)) #creo un subset con solo i positivi

eta.vector = data.positive$Age #estraggo le età e le mettoin un vettore
eta.vector.sorted = sort(eta.vector, decreasing = FALSE) #li ordino dal più piccolo al più grande
eta.vector.counter = table(eta.vector.sorted) #conto quante volte si ripete ciascun valore di età

jpeg("covid+_eta_plot.jpg", width = 1024, height = 768)
dotplot(eta.vector.counter~eta.vector.sorted, ylab = "positivi", xlab="età")
dev.off()
#SISTEMALO!