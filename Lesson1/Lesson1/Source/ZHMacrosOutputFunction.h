//
//  ZHMacrosOutputFunction.h
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 14.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#ifndef ZHMacrosOutputFunction_h
#define ZHMacrosOutputFunction_h

#include <stdio.h>

// texts
#define ZHMacrosPrintString(text, text1, text2) \
    printf("Output Strings " #text" "#text1" "#text2"\n");

// macros printing value
#define ZHMacrosPrintValueWithType(type, qualifier) \
    void ZHOutput_ ##type(type value) { \
    printf(#type " value = %" #qualifier "\n", value); \
}

// macros call function
#define ZHOutputValue(type, value) \
    ZHOutput_##type(value)

// macros Print sizeOf Value
#define ZHMacrosPrintSizeOfValue(type) \
    do { \
    type value; \
    printf("Size of "#type" value = %lu \n", sizeof(value)); \
} while (0);

void ZHOutput_int(int value);
void ZHOutput_char(char value);
void ZHMacrosTest(int intValue, char charValue);

#endif /* ZHMacrosOutputFunction_h */
