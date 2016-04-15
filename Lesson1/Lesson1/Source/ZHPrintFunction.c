//
//  ZhPrintFunction.c
//  Less1
//
//  Created by Artem Zhavrotskiy on 05.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include <stdio.h>
#include "ZHPrintFunction.h"



void ZHPrintHello() {
    printf("Hello World \n");
}

void ZHPrintHelloWorldWithParents(const char *text) {
    printf("Hello  %s \n", text);
}

void ZHPrintMama() {
    printf("Mama");
}

void ZHPrintPapa() {
    printf("Papa");
}

void ZHAddBlankLine() {
    printf("\n");
}

void ZHAddManyBlankLine(int countBlankLine ) {
    for (int iteration = 0; iteration < countBlankLine; iteration++ ) {
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
