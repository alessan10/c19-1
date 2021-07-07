library(lattice)

#leggo il file
data = read.csv("C:/Users/alexm/Downloads/out.csv") 
#creo un subset con solo i positivi
data.positive = subset(data, Covid == "positivo", select = c(Id, Age, Covid)) 
#estraggo le età e le mettoin un vettore
eta.vector = data.positive$Age 
#li ordino dal più piccolo al più grande
eta.vector.sorted = sort(eta.vector, decreasing = FALSE) 
#conto quante volte si ripete ciascun valore di età
eta.vector.counter = table(eta.vector.sorted) 
#creo il file jpeg
jpeg("D:/Alessandro/uniCT/Magistrale/Secondo_Anno/1_Advanced_Programming_Languages/Progetto_Esame/git_c19/c19/r/covid+_eta_plot.jpg", width = 1024, height = 768)
#plotto
dotplot(eta.vector.counter~eta.vector.sorted, ylab = "positivi", xlab="età")
dev.off()