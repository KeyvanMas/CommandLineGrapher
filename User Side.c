//
//  User Side.c
//  AlphaGraph
//
//  Created by kaymas on 10/2/13.
//  Copyright (c) 2013 KeyvanMas. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h> 
#include <stdlib.h> 
#include "UserSide.h"

void GetLineSpec(float *s , float *y)
{
    char buffer[5] ; // to ignore a few extra spaces...

        printf("Slope = ");
        scanf("%s" , buffer );
        *s = atof(buffer);
    
    do{
        printf("y0 = ");
        scanf("%s" , buffer );
        *y = atof(buffer);
    }while (*y < jMin || *y > jMax) ;
}
void GetCoordination(float *x , float *y)
{
    char buffer[5] ; // to ignore a few extra spaces...
    do{
        printf("x = ");
        scanf("%s" , buffer );
        *x = atof(buffer);
    }while (*x < iMin || *x > iMax) ;
    do{
        printf("\ny = ");
        scanf("%s" , buffer );
        *y = atof(buffer);
    }while (*y < jMin || *y > jMax) ;

}
void GetCircle(float *x , float *y , float *r)
{
    char buffer[5] ; // to ignore a few extra spaces...
    do{
        printf("x = ");
        scanf("%s" , buffer );
        *x = atof(buffer);
    }while (*x < iMin || *x > iMax) ;
    do{
        printf("\ny = ");
        scanf("%s" , buffer );
        *y = atof(buffer);
    }while (*y < jMin || *y > jMax) ;
    do{
        printf("\nradius: = ");
        scanf("%s" , buffer );
        *r = atof(buffer);
    }while (r == 0) ;
    
    
}

char GetCommand(void)
{
    bool canReturn ; //is a bool var to determine whether the input command of the user is acceptable or not....
    char returner ;   // returner is a single character holder that return acceptable commands of the user
    do {
        printf("Enter Command: (l = line , d = dot , c = circle , e = empty circle , q = quit):\t");
        
        do {
            fgets(&returner, 2, stdin) ;//Getting only the first character of stdin. the only dangerous situation happens when user enters 'return (\n)'
        } while (returner == '\n' || returner == ' '); //in that case we use this do-while block to request a command again.
        
        StdShutUp(); //To shut remaining (extra/unwanted) input up!
        
        if (returner != 'l' && returner != 'd' && returner != 'c' && returner != 'e' && returner != 'q') // Check to determind validity of the command
            canReturn = false ;// command is not valid. so canReturn will be false and do-while block will be implemented again.
        else
            canReturn = true ;// command is valid. so pass the do-while
        
    } while (!canReturn); //While the user command is not valid, we tell him "Enter Command" and Check input again...
    return returner ;// returning valid user command.
}
void StdShutUp(void)
{
    // reading remaining stdin stream and returning back to the function that called StdShutUp() :
    char shutupper;
    do {
        shutupper =  getchar();
    } while (shutupper != '\n');
}
