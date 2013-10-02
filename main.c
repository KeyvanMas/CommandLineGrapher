//
//  main.c
//  AlphaGraph
//
//  Created by KeyvanMas on 9/23/13.

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include "UserSide.h"

char array[kMaxLenght*10][kMaxWidth*10];

void SetBasePoint(void);
void PrintCoordination(void);
void Dot(float x , float y);
void Line(float slope , float y0) ;
void Emp(float x , float y);
void Circle(float  x , float y , float r) ;
void EmpCircle(float  x , float y , float r) ;

int main(int argc, const char * argv[])
{
    bool exit = false ;
    float x , y , sloup , radius ;
    do {
        SetBasePoint() ;
        switch (GetCommand()) {
            case 'l':
                GetLineSpec(&sloup , &y) ;
                Line(sloup, y);
                PrintCoordination() ;
                break;
            case 'd':
                GetCoordination(&x , &y ) ;
                Dot(x, y) ;
                PrintCoordination() ;
                break;
            case 'c' :
                GetCircle(&x, &y, &radius);
                Circle(x, y, radius);
                PrintCoordination() ;
                break ;
            case 'e' :
                GetCircle(&x, &y, &radius);
                EmpCircle(x, y, radius);
                PrintCoordination();
                break;
            case 'q' :
                exit = true ; 
                printf("\nBye... ") ;
                return 0; 
        }
    }while (!exit); 
    
}

void EmpCircle(float  x , float y , float r)
{
    float i , j ;
    for (i=iMin; i <= iMax; i+= 0.05) {
        for (j = jMin ; j <= jMax ; j+= 0.05) {
            if ( (pow(j-y, 2) -( (pow(r, 2) - pow(i-x, 2)))) < 0.1 ) {
                Dot(i, j);
            }
        }
    }
    r -=  0.1;
    for (i=iMin; i <= iMax; i+= 0.05) {
        for (j = jMin ; j <= jMax ; j+= 0.05) {
            if ( (pow(j-y, 2) -( (pow(r, 2) - pow(i-x, 2)))) < 0.1 ) {
                Emp(i, j);
            }
        }
    }
    
}

void Circle(float  x , float y , float r)
{
    float i , j ;
    for (i=iMin; i <= iMax; i+= 0.05) {
        
        for (j = jMin ; j <= jMax ; j+= 0.05) {
            if ( (pow(j-y, 2) -( (pow(r, 2) - pow(i-x, 2)))) < 0.1 ) {
                Dot(i, j); 
            }
        }
    }
    
}

void Line(float s , float y0)
{
    float i , j ;
    for (i = iMin; i <= iMax; i+= 0.05) {
      
        j = (s*i) + (y0);
        if (j <= jMax && j >= jMin) {
            Dot(i, j);
        }
        
    }
}

void Dot(float x ,float y)
{
    short i , j ;
    i = lbase + (x*10) ;
    j = wbase - (y*10) ;
    if (i > 0 && j>0) {
        array[i][j] = '*' ;
    }
}

void  Emp(float x , float y)
{
    short i , j ;
    i = lbase + (x*10) ;
    j = wbase - (y*10) ;
    if (i > 0 && j>0) {
        array[i][j] = '.' ;
        if (i == lbase)
            array[i][j] = '|' ;
        else if (j== wbase)
            array[i][j] = '-';
    }
}

void PrintCoordination(void)
{
    short j , i ;
    for (j = 0; j < kMaxWidth; j++) {
        for (i = 0; i < kMaxLenght; i++) {
            putchar(array[i][j]);
            putchar(' ');
        }
        putchar('\n');
    }
}

void SetBasePoint(void)
{
    short j , i ;
    for (j = 0; j < kMaxWidth; j++) {
        for (i = 0; i < kMaxLenght; i++) {
            if (i == lbase)
                array[i][j] = '|' ;
            else if (j== wbase)
                array[i][j] = '-' ;
            else 
                array[i][j] = '.' ;
        }
    }
    return ; 
}
