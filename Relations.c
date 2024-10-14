#include <stdio.h>
#include <conio.h>
#include <string.h>
#include<math.h>
#include "Relations.h"
#define MAX_SET_ELEMENTS 10
#define MAX_CHAR_IN_NAME 10
#define MAX_DIMENSION_OF_ZERO_ONE_MATRIX 20

void ZeroOneRepresentation(int cardinalNo, int R[MAX_DIMENSION_OF_ZERO_ONE_MATRIX][MAX_DIMENSION_OF_ZERO_ONE_MATRIX], char Name[MAX_CHAR_IN_NAME])
{
    // Represents the Zero-One Matrics of Relation R having dimension cardinalNo*cardinalNo with name 'Name'
    int i, j;
    printf("%s\t", Name);
    for (i = 0; i < cardinalNo; i++)
    {
        for (j = 0; j < cardinalNo; j++)
        {
            printf("%d\t", R[i][j]);
        }
        printf("\n\t");
    }
    printf("\n");
}
void Store(int cardinalNo, int A[MAX_SET_ELEMENTS], int R[MAX_DIMENSION_OF_ZERO_ONE_MATRIX][MAX_DIMENSION_OF_ZERO_ONE_MATRIX])
{
    // Takes input from the User of Relation defined from set A to A with n(A) = cardinalNo
    int i, j, k;
    for (i = 0; i < cardinalNo; i++)
    {
        for (j = 0; j < cardinalNo; j++)
        {
            printf("( %d , %d ) belongs to Relation R? 1 for yes, 0 for No\t", A[i], A[j]);
            scanf("%d", &R[i][j]);
        }
    }
}
void CopyMatrixAtoB(int size, int A[MAX_DIMENSION_OF_ZERO_ONE_MATRIX][MAX_DIMENSION_OF_ZERO_ONE_MATRIX], int B[MAX_DIMENSION_OF_ZERO_ONE_MATRIX][MAX_DIMENSION_OF_ZERO_ONE_MATRIX])
{
    // Copies Matrix from A to B having dimensions Size*size
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < size; j++)
        {
            B[i][j] = A[i][j];
        }
    }
}
int BooleanAddition(int a, int b)
{
    // Returns addition under Boolean Laws
    if (a == 0 || a == 1)
    {
        if (b == 0 || b == 1)
        {
            return a + b >= 2 ? 1 : a + b;
        }
        else
        {
            printf("Invalid Boolean Operation");
            return 0;
        }
    }
    else
    {
        printf("Invalid Boolean Operation");
        return 0;
    }
}
int BooleanMultiplication(int a, int b)
{
    // Returns Multiplication under BOolean Laws
    if (a == 0 || a == 1)
    {
        if (b == 0 || b == 1)
        {
            return a * b;
        }
        else
        {
            printf("Invalid Boolean Operation");
            return 0;
        }
    }
    else
    {
        printf("Invalid Boolean Operation");
        return 0;
    }
}
void WarshallAlgorithm(int cardinalNo, int R[MAX_DIMENSION_OF_ZERO_ONE_MATRIX][MAX_DIMENSION_OF_ZERO_ONE_MATRIX], int Closure[MAX_DIMENSION_OF_ZERO_ONE_MATRIX][MAX_DIMENSION_OF_ZERO_ONE_MATRIX])
{
    // Finds Transitive Closure of Relation R using Warshall Algorithm and Stores it in Closure
    int i, j, k;
    char name[10] = "W";
    CopyMatrixAtoB(cardinalNo, R, Closure);
    for (k = 0; k < cardinalNo; k++)
    {
        for (i = 0; i < cardinalNo; i++)
        {
            for (j = 0; j < cardinalNo; j++)
            {
                Closure[i][j] = BooleanAddition(Closure[i][j], BooleanMultiplication(Closure[i][k], Closure[k][j]));
            }
        }
        sprintf(name, "%d", k + 1);
        ZeroOneRepresentation(cardinalNo, Closure, name);
    }
}
void Union(int nA, int A[MAX_SET_ELEMENTS], int nB, int B[MAX_SET_ELEMENTS], int Result[2 * MAX_SET_ELEMENTS])
{
    int i, j, k = 0;
    for (i = 0; i < nA; i++)
    {
        Result[k++] = A[i];
    }
    for (j = 0; j < nB;)
    {
        for (i = 0; i < nA; i++)
        {
            if (B[j] == A[i])
            {
                i = 0;
                j++;
            }
        }
        Result[k++] = B[j++];
    }
    printf("\n The Union of given set is\n {");
    for (i = 0; i < k; i++)
    {
        printf("%d", Result[i]);
        if (i != k - 1)
        {
            printf(",\t");
        }
    }
    printf("}");
}
void Intersection(int nA, int A[MAX_SET_ELEMENTS], int nB, int B[MAX_SET_ELEMENTS], int Result[2 * MAX_SET_ELEMENTS])
{
    int i, j, k = 0;
    for (i = 0; i < nA; i++)
    {
        for (j = 0; j < nB; j++)
        {
            if (A[i] == B[j])
            {
                Result[k++] = B[j];
            }
        }
    }
    printf("\n The Intersection of given set is\n {");
    for (i = 0; i < k; i++)
    {
        printf("%d", Result[i]);
        if (i != k - 1)
        {
            printf(",\t");
        }
    }
    printf("}");
}
int belongsTo(int a ,int cardinalNo, int A[MAX_SET_ELEMENTS]){
    int i ;
    for(int i = 0 ; i< cardinalNo ; i++){
        if(A[i]==a){
            printf("\n%d belongs to the given Set\t",a);
            return 1;
        }
    }
    printf("\n%d does not belong to the given set\t",a);
    return 0 ;
}
int F(int n){
    if(n==0) return 1;
    else return n*F(n-1);
}
int P(int n, int r){
    return F(n) / F(n-r);
}
int C (int n , int r){
    return F(n)/(F(n-r)*F(r));
}
int S(int m , int n){
    int i, ans=0;
    for(i=n ; i>=1 ; i--){
        ans += pow(-1,n-i)*C(n,i)*pow(i,m);
    }
    return ans/F(n);
}
int B(int n){
    int i , ans =0 ;
    for(i=1 ; i<=n ; i++){
        ans += S(n,i);
    }
    return ans ;
}