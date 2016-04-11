//
//  ZhPrintFunction.c
//  Less1
//
//  Created by Artem Zhavrotskiy on 05.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include <stdio.h>
#include "ZHPrintFunction.h"


//The function prints "Hello world"
void ZHPrintHello() {
    printf("Hello World \n");
}

//The function prints "hello" and transmitted it the string value
void ZHPrintHwWithParents(const char *text) {
    printf("Hello  %s \n", text);
}

//The function adds a blank line
void ZHAddBlankLine() {
    printf("\n");
}

//The function adds the number of  n++ rows

void ZHAddManyBlankLine(int NumOfIter ) {
    for (int iteration = 0; iteration < NumOfIter; iteration++ ) {
    ZHAddBlankLine();
    }
}

void ZHPrintCharValue(const char *text) {
    printf("%s\n", text);
}

void ZHPrintPostAndPrefIncrement() {
    int value  = 10;
    int value1  = 10;
    int result = 0;
    int result1 = 0;
    result = value++;
    result1 = ++value1;
    printf("%d %d \n", result , value);
    printf("%d %d \n", result1 , value1);
}
