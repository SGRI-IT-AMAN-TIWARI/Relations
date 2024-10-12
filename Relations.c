#include <stdio.h>
#include <conio.h>
#include<string.h>
#include "Relations.h"

void ZeroOneRepresentation(int cardinalNo, int R[20][20],char Name[10]){
    //Represents the Zero-One Matrics of Relation R having dimension cardinalNo*cardinalNo with name 'Name'
    int i,j;
    printf("%s\t",Name);
    for (i = 0; i < cardinalNo; i++)
    {
        for (j = 0; j < cardinalNo; j++)
        {
            printf("%d\t",R[i][j]);
        }
        printf("\n\t");
    }
    printf("\n");

}
void Store(int cardinalNo, int A[], int R[20][20])
{
    // Takes input from the User of Relation defined from set A to A with n(A) = cardinalNo
    int i, j, k;
    for (i = 0; i < cardinalNo; i++)
    {
        for (j = 0; j < cardinalNo; j++)
        {
            printf("( %d , %d ) belongs to Relation R? 1 for yes, 0 for No\t", A[i], A[j]);
            scanf("%d",&R[i][j]);
        }
    }
}
void CopyMatrixAtoB(int size ,int A[20][20] , int B[20][20]){
    // Copies Matrix from A to B having dimensions Size*size
    int i,j;
    for (i=0 ; i<size ; i++){
        for(j=0 ; j <size ; j++){
            B[i][j] = A[i][j];
        }
    }
}
int BooleanAddition (int a, int b){
    // Returns addition under Boolean Laws
    if(a==0 || a==1){
        if(b==0 || b==1){
            return a+b>=2?1:a+b;
        }else{
            printf("Invalid Boolean Operation");
            return 0;
        }
    }else{
        printf("Invalid Boolean Operation");
        return 0;
    }
}
int BooleanMultiplication (int a, int b){
    // Returns Multiplication under BOolean Laws
    if(a==0 || a==1){
        if(b==0 || b==1){
            return a*b;
        }else{
            printf("Invalid Boolean Operation");
            return 0;
        }
    }else{
        printf("Invalid Boolean Operation");
        return 0;
    }
}
void WarshallAlgorithm(int cardinalNo, int R[20][20], int Closure[20][20]){
    // Finds Transitive Closure of Relation R using Warshall Algorithm and Stores it in Closure
    int i,j,k;
    char name[10] = "W";
    CopyMatrixAtoB(cardinalNo,R,Closure);
    for(k=0;k<cardinalNo;k++){
        for(i=0;i<cardinalNo;i++){
            for(j=0;j<cardinalNo;j++){
                Closure[i][j] = BooleanAddition(Closure[i][j], BooleanMultiplication(Closure[i][k],Closure[k][j]));
            }
        }
        sprintf(name,"%d",k+1);
        ZeroOneRepresentation(cardinalNo,Closure,name);
    }
}

