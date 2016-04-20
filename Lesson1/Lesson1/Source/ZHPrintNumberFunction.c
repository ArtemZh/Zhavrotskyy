//
//  ZHPrintNumberFunction.c
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 07.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include <stdio.h>
#include "ZHPrintNumberFunction.h"

void ZHPrintIncreasingValue() {
    puts("1234567890");
}

void ZHPrintDecreasingValue() {
    puts("0987654321");
}

int  ZHIncrement(int value) {
    return value + 1;
}

int ZHDecrement(int value) {
    return value - 1;
}
