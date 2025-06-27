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

void show_matrix(bid_matrix* obj_matrix){
    printf("\n\nStampa della matrice in corso...\n");
    tipo_inf** matrice = obj_matrix->matrix; 

    //stampa della matrice riga per riga
    for(int riga=0; riga<obj_matrix->rows; riga++){
        printf("\t");
        for(int colonna=0; colonna<obj_matrix->columns; colonna++){
            printf("%d\t", matrice[riga][colonna].value);
        }
 
        //terminata la stampa di una riga
        printf("\n");
    }

}

//inizializza una matrice di interi a 0     
void initialize_int_values(bid_matrix* obj_matrix){
    for(int riga=0; riga<obj_matrix->rows; riga++){
        for(int colonna=0; colonna<obj_matrix->columns; colonna++){
            obj_matrix->matrix[riga][colonna].value = 0;
            strcpy(obj_matrix->matrix[riga][colonna].descrizione, "");
        }
    }
}

void fill_matrix_rand(bid_matrix* obj_matrix, tipo_inf min, tipo_inf max){
    if(min.value > max.value){
        printf("\nMassimo e minimo scambiati per evitare ambiguita'\n");
        scambia_tipoInf(&min, &max); 
    }

    for(int riga=0; riga<obj_matrix->rows; riga++){
        for(int colonna=0; colonna<obj_matrix->columns; colonna++){
            obj_matrix->matrix[riga][colonna].value = min.value + (rand() % max.value);
        }
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


/** primitiva per la somma di matrici */
bid_matrix sum_matrix(bid_matrix matrix1, bid_matrix matrix2){
    /*printf("\nRows m1: %d", matrix1.rows);
    printf("\nRows m2: %d", matrix2.rows);
    printf("\nCOolumns m1: %d", matrix1.columns);
    printf("\nCOolumns m2: %d", matrix2.columns);*/

    //la somma viene effettuata solo per matrici delle stesse dimensioni
    if(matrix1.rows != matrix2.rows || matrix1.columns != matrix2.columns){
        bid_matrix obj_matrix = {
            .rows = 0, 
            .columns = 0, 
            .matrix = NULL
        };

        return obj_matrix;

    }

    bid_matrix sum = generate_matrix(matrix1.rows, matrix1.columns);
    initialize_int_values(&sum);

    //scorro entrambe le matrici
    //sum[i][j] = matrix1[i][j] + matrix2[i][j]
    for(int i=0; i<matrix1.rows; i++){
        for(int j=0; j<matrix2.columns; j++)
            sum.matrix[i][j].value = matrix1.matrix[i][j].value + matrix2.matrix[i][j].value;
    }

    return sum;
}

bid_matrix transpose(bid_matrix* ptr_matrix){
    //TRASPOSTA[I][J] = MATRIX[J][I]
    bid_matrix trasposta = generate_matrix(ptr_matrix->columns, ptr_matrix->rows);
    
    for(int i=0; i<ptr_matrix->rows; i++){
        for(int j=0; j<ptr_matrix->columns; j++)
            trasposta.matrix[j][i].value = ptr_matrix->matrix[i][j].value;
    }

    return trasposta;
}