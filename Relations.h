// Relations.h
#ifndef RELATIONS_H
#define RELATIONS_H

void ZeroOneRepresentation(int cardinalNo, int R[20][20],char Name[10]);
void Store(int cardinalNo, int A[], int R[20][20]);
void CopyMatrixAtoB(int size ,int A[20][20] , int B[20][20]);
int BooleanAddition (int a, int b);
int BooleanMultiplication (int a, int b);
void WarshallAlgorithm(int cardinalNo, int R[20][20], int Closure[20][20]);


#endif // MY_FUNCTIONS_H