/*
        Bubble Sort with Tracing in each looping
*/
#include <stdio.h>
#include<stdlib.h>

int a[100];
int i,j,k,n,temp;
void main(){
    system("cls");
    //Input Data
    printf("Banyak data : ");
    scanf("%d",&n);
    for (i=0;i<n;i++){
        printf("Data ke-%d : ",i+1);
        scanf("%d",&a[i]);
    }
    //Sorting Process
    for (i=0;i<n;i++){ //Loop to access each array elements
        printf("Putaran ke-%d: ", i);
        for (k=0;k<n;k++){ //Loop to trace the sorting process
            printf("%d ",a[k]);
        }
        for (j=0;j<n-i-1;j++){ //Loop to compare array elements
            if (a[j]>a[j+1]){ //Swapping elements if it are not in the intended order
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
        printf("\n");
    }
    printf("\n\n");
    //Output Data
    for (i=0;i<=n-1;i++){
        printf("%d ",a[i]);
    }
}