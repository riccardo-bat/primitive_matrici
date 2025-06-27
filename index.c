#include "tipo_inf.h"
#include "matrix.h"

int main(){
    bid_matrix matrice = generate_matrix(5, 5); //matrice quadrata 5x5
    initialize_int_values(&matrice);
    bid_matrix matrice2 = generate_matrix(10, 5); 
    initialize_int_values(&matrice2);

    show_matrix(matrice);
    show_matrix(matrice2);

    //deallocazione della memoria
    free_matrix(&matrice2);
    free_matrix(&matrice);

    return 0;
}