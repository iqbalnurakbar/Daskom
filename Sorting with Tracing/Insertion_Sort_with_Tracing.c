/*
        Insertion Sort with Tracing in each looping
*/
#include<stdio.h>
#include<stdlib.h>

int a[100];
int i,j,n,temp;
void main (){
    system("cls");
    //Input Data
    printf("Banyak data : "); scanf("%d",&n);
    for (i=0;i<=n-1;i++){
        printf("Data ke-%d : ",i);
        scanf("%d",&a[i]);
    }
    //Sorting Process
    for (i=0;i<=n-1;i++){
        temp=a[i];
        j=i;
        while ((j>0) && (temp>a[j-1])){//Compare the data
            a[j]=a[j-1];
            j=j-1;
        }
        a[j]=temp; //swapping the elements
        printf("Putaran ke-%d: ", i);
        for(j=0;j<n;j++){//Loop to trace the sorting process
            printf("%d ", a[j]);
        }
        printf("\n");
    }
    //Output Data
    for (i=0;i<=n-1;i++){
        printf("%d",a[i]);
        printf(" ");
    }
}