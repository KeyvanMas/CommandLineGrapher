//
//  UserSide.h
//  AlphaGraph
//
//  Created by KeyvanMas on 10/2/13.
//

#ifndef AlphaGraph_UserSide_h
#define AlphaGraph_UserSide_h

#define kMaxLenght 130
#define kMaxWidth  90
#define lbase ((kMaxLenght - ((kMaxLenght - 1)/2)) - 1) // because all arrays starts at 0
#define wbase ( (kMaxWidth - ((kMaxWidth - 1)/2)) - 1 ) // because all arrays starts at 0
#define iMin -lbase
#define iMax ((kMaxLenght -1)/2)
#define jMin -wbase
#define jMax  ((kMaxWidth - 1)/2)

void GetCircle(float *x , float *y , float *r);

char GetCommand(void) ; 

void StdShutUp(void);

void GetCoordination(float *x , float *y);

void GetLineSpec(float *s , float *y);
#endif
