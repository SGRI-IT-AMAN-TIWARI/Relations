#include <stdio.h>
#include <conio.h>
#include<string.h>

void ZeroOneRepresentation(int cardinalNo, int R[20][20],char Name[10]){
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
    int i,j;
    for (i=0 ; i<size ; i++){
        for(j=0 ; j <size ; j++){
            B[i][j] = A[i][j];
        }
    }
}
int BooleanAddition (int a, int b){
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

void main()
{
    int n, A[20], R[20][20], Closure[20][20], option, i, j;
    printf("Enter No Of Elements\n");
    scanf("%d", &n);
    printf("Enter numbers\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }
    Store(n, A, R);
    ZeroOneRepresentation(n,R,"M[R] = ");
    WarshallAlgorithm(n,R,Closure);
    getch();
}