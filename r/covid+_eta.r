library(lattice)

data = read.csv("/Users/andreacalabretta/Downloads/out.csv") #leggo il file
#data.positive = subset(data, Covid == "positivo", select = c(Id, Nome, Cognome, Age, ChatId, Covid, Anno, Mese, Giorno, Weekday, Country)) #creo un subset con solo i positivi
data.positive = subset(data, Covid == "positivo", select = c(Id, Age, Covid)) #creo un subset con solo i positivi

eta.vector = data.positive$Age #estraggo le et? e le mettoin un vettore
eta.vector.sorted = sort(eta.vector, decreasing = FALSE) #li ordino dal pi? piccolo al pi? grande
eta.vector.counter = table(eta.vector.sorted) #conto quante volte si ripete ciascun valore di et?

jpeg("/Users/andreacalabretta/Documents/0.MAGISTRALE_INFO/8.APL/consegna/c19-1/r/covid+_eta_plot.jpg", width = 1024, height = 768)
dotplot(eta.vector.counter~eta.vector.sorted, ylab = "positivi", xlab="et?")
dev.off()
#SISTEMALO!