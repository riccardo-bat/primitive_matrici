//indica il tipo di dato memorizzato all'interno delle matrici
#ifndef TIPO_INF_H
    #define TIPO_INF_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    #define LENGTH_DESCRIZIONE 50
    
    typedef struct{
        int value;
        char descrizione[LENGTH_DESCRIZIONE];
    } tipo_inf; 

    //funzioni sugli oggetti di tipo tipo_inf
    tipo_inf create_object(int value, char* descrizione);
    void scambia_tipoInf(tipo_inf* value1, tipo_inf* value2);

#endif