#ifndef MATRIX_H
    #define MATRIX_H

    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    #include <string.h>
    #include "tipo_inf.h"

    //oggetto matrice
    typedef struct{ 
        int rows; 
        int columns; 
        tipo_inf** matrix; //puntatore alla matrice dinamica
    } bid_matrix; //matrici bidimensionali 

    //prototipi 
    bid_matrix generate_matrix(int rows, int columns);
    void initialize_int_values(bid_matrix* obj_matrix);
    void fill_matrix_rand(bid_matrix* obj_matrix, tipo_inf min, tipo_inf max);
    void show_matrix(bid_matrix* obj_matrix);
    void free_matrix(bid_matrix* obj_matrix);
    bid_matrix sum_matrix(bid_matrix matrix1, bid_matrix matrix2);
    bid_matrix transpose(bid_matrix* ptr_matrix);

#endif