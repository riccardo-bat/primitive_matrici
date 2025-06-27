#include "tipo_inf.h"

//funzioni 

tipo_inf create_object(int value, char* descrizione){
    tipo_inf obj_to_return = {
        .value = value, 
        strcpy(obj_to_return.descrizione, descrizione)
    };

    return obj_to_return;
}

void scambia_tipoInf(tipo_inf* value1, tipo_inf* value2){
    tipo_inf temp = *value1;
    *value1 = *value2;
    *value2 = temp; 
}