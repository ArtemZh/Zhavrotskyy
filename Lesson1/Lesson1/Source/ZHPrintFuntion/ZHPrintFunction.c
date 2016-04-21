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

void ZHPrintBlankLine() {
    printf("\n");
}

void ZHPrintBlankLines(int count) {
    for (int iteration = 0; iteration < count; iteration++ ) {
    ZHPrintBlankLine();
    }
}

void ZHPrintCharValue(const char *text) {
    printf("%s\n", text);
}

void ZHPrintPostAndPrefIncrement() {
    int value  = 10;
    int value1  = 10;
    printf("%d %d \n %d %d", value+1 , value, 1+value1 , value1 );
}
