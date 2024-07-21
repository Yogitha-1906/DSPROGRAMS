#include <stdio.h>
 
int main() {
    int terms, i;
    // Get the number of terms in the first polynomial
    printf("Enter the total number of terms in the polynomial: ");
    scanf("%d", &terms);
    // Declare arrays to store coefficients and exponents
    int coeff[terms], expo[terms];
    // Get the coefficients and exponents of the first polynomial
    printf("Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
    for (i = 0; i < terms; i++) {
        printf("Enter the Coefficient (%d): ", i + 1);
        scanf("%d", &coeff[i]);
        printf("Enter the exponent(%d): ", i + 1);
        scanf("%d", &expo[i]);
    }
    printf("\nFirst polynomial: ");
        for (i = 0; i < terms; i++) {
            printf("%d(x^%d)", coeff[i], expo[i]);
            if (i != terms - 1) {
                printf("+");
            }
        }
    printf("\n");
    // Get the number of terms in the second polynomial
    printf("\nEnter the total number of terms in the polynomial: ");
    scanf("%d", &terms);
    // Declare arrays to store coefficients and exponents of the second polynomial
    int coeff2[terms], expo2[terms];
    // Get the coefficients and exponents of the second polynomial
    printf("\n");
    printf("Enter the COEFFICIENT and EXPONENT in DESCENDING ORDER\n");
    for (i = 0; i < terms; i++) {
        printf("Enter the Coefficient (%d): ", i + 1);
        scanf("%d", &coeff2[i]);
        printf("Enter the exponent(%d): ", i + 1);
        scanf("%d", &expo2[i]);
    }
    // Add the corresponding coefficients of the two polynomials
    int result_coeff[terms], result_expo[terms];
    int j = 0, k = 0, m = 0;
    while (j < terms && k < terms) {
        // If the exponents are equal, add the coefficients and store in the result array
        if (expo[j] == expo2[k]) {
            result_coeff[m] = coeff[j] + coeff2[k];
            result_expo[m] = expo[j];
            j++;
            k++;
            m++;
        }
        else if (expo[j] > expo2[k]) {
            // If the first polynomial's exponent is greater, copy it to the result array
            result_coeff[m] = coeff[j];
            result_expo[m] = expo[j];
            j++;
            m++;
        }
        else {
            // If the second polynomial's exponent is greater, copy it to the result array
            result_coeff[m] = coeff2[k];
            result_expo[m] = expo2[k];
            k++;
            m++;
        }
    }
    // Copy the remaining terms from the larger polynomial (if any)
    while (j < terms) {
        result_coeff[m] = coeff[j];
        result_expo[m] = expo[j];
        j++;
        m++;
        }
        while (k < terms) {
            result_coeff[m] = coeff2[k];
            result_expo[m] = expo2[k];
            k++;
            m++;
        }
        // Print the first polynomial
        // Print the second polynomial
        printf("\nSecond polynomial: ");
        for (i = 0; i < terms; i++){
            printf("%d(x^%d)", coeff2[i], expo2[i]);
            if (i != terms - 1) {
                printf("+");
            }
        }
        // Print the resultant polynomial
        printf("\nResultant polynomial after addition: ");
        for (i = 0; i < m; i++) {
            printf("%d(x^%d)", result_coeff[i], result_expo[i]);
            if (i != m - 1){
            printf("+");
            }
        }
        return 0;
}
