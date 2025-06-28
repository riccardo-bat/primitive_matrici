#--------------------------------------
#Variabili 
#--------------------------------------

CC = gcc
CFLAGS = -Wall

#--------------------------------------
#Regole
#--------------------------------------

#comando di default - linking di ogni file oggetto
esame: index.o tipo_inf.o matrix.o
	$(CC) $(CFLAGS) -o $@ $^
	del /F *.o *.out *.gch

#regole per la fase di traduzione
index.o: index.c tipo_inf.h matrix.h
	$(CC) $(CFLAGS) -c $^

tipo_inf.o: tipo_inf.c tipo_inf.h
	$(CC) $(CFLAGS) -c $^

matrix.o: matrix.c tipo_inf.h matrix.h
	$(CC) $(CFLAGS) -c $^


#pulizia del file
clean_exe: 
	del /F *.exe 

clean_all:
	del /F *.o *.out *.exe *.gch


.PHONY: clean_exe clean_all