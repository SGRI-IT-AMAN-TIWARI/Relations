#include <stdio.h>
#include <conio.h>
#include<string.h>
#include "Relations.h"

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