//
//  ZHPrintDifferentTypesVariables.c
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 07.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include "ZHPrintTypesVariables.h"


void ZHPrintChar(char *text) {
    printf(" %s \n", text);
}

void ZHPrintShort(short shortValue) {
    printf(" %i \n", shortValue);
}

void ZHPrintInt(int intValue) {
    printf(" %i \n", intValue);
}
void ZHPrintLong(long longValue) {
    printf(" %li \n", longValue);
}

void ZHPrintLongLong(long longLongValue) {
    printf(" %li \n", longLongValue);
}

void ZHPrintFloat(float floatValue) {
    printf(" %f \n", floatValue);
}

void ZHPrintDouble(double dubleFloatValue) {
    printf(" %f \n", dubleFloatValue);
}

