#include "tipo_inf.h"
#include "matrix.h"

int main(){
    srand(time(NULL));

    bid_matrix matrice = generate_matrix(5, 5); //matrice quadrata 5x5
    //initialize_int_values(&matrice);
    fill_matrix_rand(&matrice, create_object(5, ""), create_object(10, ""));
    bid_matrix matrice2 = generate_matrix(10, 5); 
    //initialize_int_values(&matrice2);
    fill_matrix_rand(&matrice2, create_object(10, ""), create_object(1, ""));

    show_matrix(matrice);
    show_matrix(matrice2);

    //deallocazione della memoria
    free_matrix(&matrice2);
    free_matrix(&matrice);

    return 0;
}