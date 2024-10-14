#include <stdio.h>
#include <conio.h>
#include<string.h>
#include "Relations.h"

void main()
{
    int m ,n,b ;
    // int nA,nB, A[20], B[20] , Result[40], R[20][20], Closure[20][20], option, i, j;
    // printf("Enter No Of Elements in Set A\n");
    // scanf("%d", &nA);
    // printf("Enter numbers\n");
    // for (i = 0; i < nA; i++)
    // {
    //     scanf("%d", &A[i]);
    // }
    // printf("Enter No Of Elements in Set B\n");
    // scanf("%d", &nB);
    // printf("Enter numbers\n");
    // for (i = 0; i < nB; i++)
    // {
    //     scanf("%d", &B[i]);
    // }
    // Union(nA, A ,nB ,B, Result);
    // Intersection(nA, A ,nB ,B, Result);
    // printf("%d",belongsTo(7,nA,A));
    // Store(n, A, R);
    // ZeroOneRepresentation(n,R,"M[R] = ");
    // WarshallAlgorithm(n,R,Closure);
    printf("Enter m\n");
    scanf("%d",&m);
    printf("\nEnter n\n");
    scanf("%d",&n);
    printf("\nS(%d,%d) = %d\n",m,n,S(m,n));
    // printf("\nEnter no for Bell No\n");
    // scanf("%d",&n);
    for (int n = 0 ; n<=10 ; n++) printf("B(%d) = %d\n",n , B(n));
    getch();
}