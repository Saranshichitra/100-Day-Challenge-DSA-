#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
int main() {
    int n1, n2, i;                             //Declaration
    scanf("%d", &n1);                          //Size of first array 
    int a1[n1];                                //declaration of first array
    for (i=0; i<n1; i++)
        scanf("%d", &a1[i]);                 //Entering elements of first array one by one
    scanf("%d", &n2);                          //Size of first array 
    int a2[n2];;                                //declaration of first array 
    for (i=0; i<n2; i++)
        scanf("%d", &a2[i]);                 //Entering elements of first array one by one
    int a3[n1+n2];                           //Array to merge
    for (i=0; i<n1; i++)
        a3[i] = a1[i];
    for (i=0; i<n2; i++)
        a3[n1+i] = a2[i];
    qsort(a3, n1 + n2, sizeof(int), compare);  //using qsort technique to sort the array
    for (i=0; i<n1+n2; i++)
        printf("%d ", a3[i]);                   //Printing the merged array

    return 0;
}
