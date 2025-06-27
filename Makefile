#--------------------------------------
#Variabili 
#--------------------------------------

CC = gcc
CFLAGS = -Wall

#--------------------------------------
#Regole
#--------------------------------------

#comando di default - linking di ogni file oggetto
esame: index.o tipo_inf.o 
	$(CC) $(CFLAGS) -o $@ $^

#regole per la fase di traduzione
index.o: index.c tipo_inf.h
	$(CC) $(CFLAGS) -c $^

tipo_inf.o: tipo_inf.c tipo_inf.h
	$(CC) $(CFLAGS) -c $^


#pulizia del file
clean: 
	del /F *.o *.out *.exe *.gch

.PHONY: clean