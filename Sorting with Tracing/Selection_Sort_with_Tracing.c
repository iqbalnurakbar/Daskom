/*
        Selection Sort with Tracing in each looping
*/
#include <stdio.h>
#include <stdlib.h>

int a[100];
int i,j,n,min,temp;
void main (){
    system("cls");
    //Input Data
    printf("Banyak data : ");
    scanf("%d",&n);
    for (i=0;i<=n-1;i++){
        printf("Data ke-%d : ",i);
        scanf("%d",&a[i]);
    }
    //Sorting Process
    for (i=0;i<=n-2;i++){
        printf("Putaran ke-%d: ", i);
        for(j=0;j<n;j++){ //Loop to trace the sorting process
            printf("%d ", a[j]);
        }
        printf("\n");
        min=i;
        for (j=i;j<=n-1;j++){ //Loop to compare each elements
            if (a[j]<a[min]){ //Swapping the elements
                min=j;
                temp=a[min];
                a[min]=a[i];
                a[i]=temp;
            }
        }
    }
    //Output Data
    for (i=0;i<=n-1;i++){
        printf("%d",a[i]);
        printf(" ");
    }
}