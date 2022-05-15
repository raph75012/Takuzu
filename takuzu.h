#ifndef TAKUZU_TAKUZU_H
#define TAKUZU_TAKUZU_H
#define SIZE 8
#include <stdio.h>
#include<stdlib.h>

int** startgrid(int[8][8], int[8][8], int size);
int** move(int **, int);
int errorrowandcol(int**, int, int, int);
int testrow(int**, int, int, int);
int testcol(int**, int, int, int);
int errornbrow(int **, int, int);
int comparray(int[][8], int[][8], int);




#endif //TAKUZU_TAKUZU_H
