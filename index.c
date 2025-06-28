#include "tipo_inf.h"
#include "matrix.h"

int main(){
    srand(time(NULL));

    bid_matrix matrice = generate_matrix(5, 5); //matrice quadrata 5x5
    //initialize_int_values(&matrice);
    fill_matrix_rand(&matrice, create_object(5, ""), create_object(10, ""));

    bid_matrix matrice2 = generate_matrix(5, 10); 
    //initialize_int_values(&matrice2);
    fill_matrix_rand(&matrice2, create_object(10, ""), create_object(1, ""));

    bid_matrix matrice3 = generate_matrix(5, 5); 
    //initialize_int_values(&matrice3);
    fill_matrix_rand(&matrice3, create_object(100, ""), create_object(200, ""));

    show_matrix(&matrice);
    show_matrix(&matrice2);
    show_matrix(&matrice3);

    //test delle primitive
    /*bid_matrix sum = sum_matrix(&matrice, &matrice2);
    if(sum.matrix != NULL){
        printf("\nMATRICE + MATRICE2");
        show_matrix(&sum);
    } else
        printf("\n\nIMPOSSIBILE ESEGUIRE MATRICE + MATRICE2");

    sum = sum_matrix(&matrice, &matrice3);
    if(sum.matrix != NULL){
        printf("\nMATRICE + MATRICE3");
        show_matrix(&sum);
    } else
        printf("\n\nIMPOSSIBILE ESEGUIRE MATRICE + MATRICE3");*/


    //trasposta di matrice2
    /*bid_matrix trasposta_matrice2 = transpose(&matrice2);
    printf("\nTRASPOSTA MATRICE 2");
    show_matrix(&trasposta_matrice2);*/


    //moltiplicazione tra matrici
    /*bid_matrix mul = mul_matrix(&matrice, &matrice2);
    printf("Here2");
    if(mul.matrix == NULL){
        printf("\n\nNon è possibile effettuare matrice * matrice2");
    } else{
        printf("\nMATRICE * MATRICE2");
        show_matrix(&mul);
    }

    mul = mul_matrix(&matrice2, &matrice3);
    if(mul.matrix == NULL){
        printf("\n\nNon e' possibile effettuare matrice2 * matrice3");
    } else{
        printf("\nMATRICE2 * MATRICE3");
        show_matrix(&mul);
    }*/


    //verifico se la matrice è simmetrica
    if(is_matrix_simmetric(&matrice))
        printf("\n\nMatrice e' simmetrica");
    else 
        printf("\n\nMatrice NON e' simmetrica");

    if(is_matrix_simmetric(&matrice2))
        printf("\n\nMatrice2 e' simmetrica");
    else 
        printf("\n\nMatrice2 NON e' simmetrica");


    //deallocazione della memoria
    free_matrix(&matrice);
    free_matrix(&matrice2);
    free_matrix(&matrice3);

    printf("\n\n");
    return 0;
}