#include "matrix.h"

bid_matrix generate_matrix(int rows, int columns){
    //creo l'array di puntatori che puntano alle righe della matrice
    tipo_inf** ptr_matrix = (tipo_inf**) malloc(rows * sizeof(tipo_inf*));
    if(ptr_matrix == NULL){
        printf("\n\tMalloc failed in generate_matrix");
        exit(1);
    }

    for(int i=0; i<rows; i++)
        ptr_matrix[i] = (tipo_inf*) malloc(columns * sizeof(tipo_inf));
        

    bid_matrix obj_matrix = {
        .rows = rows, 
        .columns = columns, 
        .matrix = ptr_matrix        
    }; 

    return obj_matrix;
}

void show_matrix(bid_matrix obj_matrix){
    printf("\n\nStampa della matrice in corso...\n");
    tipo_inf** matrice = obj_matrix.matrix; 

    //stampa della matrice riga per riga
    for(int riga=0; riga<obj_matrix.rows; riga++){
        printf("\t");
        for(int colonna=0; colonna<obj_matrix.columns; colonna++){
            printf("%d ", matrice[riga][colonna].value);
        }
 
        //terminata la stampa di una riga
        printf("\n");
    }

}

//inizializza una matrice di interi a 0     
void initialize_int_values(bid_matrix* obj_matrix){
    for(int riga=0; riga<obj_matrix->rows; riga++){
        for(int colonna=0; colonna<obj_matrix->columns; colonna++)
            obj_matrix->matrix[riga][colonna].value = 0;
    }
}

void free_matrix(bid_matrix* obj_matrix){
    //libero ogni riga
    for(int i=0; i<obj_matrix->rows; i++)
        free(obj_matrix->matrix[i]);

    //dealloco l'array di puntatori
    free(obj_matrix->matrix);
    obj_matrix->matrix = NULL;
}
