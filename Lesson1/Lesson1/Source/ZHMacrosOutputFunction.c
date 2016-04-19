//
//  ZHMacrosOutputFunction.c
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 14.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include "ZHMacrosOutputFunction.h"

ZHMacrosPrintValueWithType(int, d);
ZHMacrosPrintValueWithType(char, c);


void ZHMacrosTest(int intValue, char charValue) {
    ZHOutputValue(int, intValue);
    ZHOutputValue(char, charValue);
    ZHMacrosPrintSizeOfValue(int);
    ZHMacrosPrintSizeOfValue(char);
    ZHMacrosPrintSizeOfValue(long long);
    }
