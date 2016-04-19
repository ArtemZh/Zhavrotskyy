//
//  ZHStructuresTest.c
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 18.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include "ZHStructuresTest.h"


void ZHPrintSizeOfStructure(void) {
    printf("Size of structure ZHStructTypesVar - %lu \n",sizeof(ZHStructTypesVar));
    printf("Size of structure ZHStructTypesVarOptimized - %lu \n",sizeof(ZHStructTypesVarOptimized));
}

void ZHPrintBiraryOfInputValue(uint8_t charValue) {
    const uint8_t bitCount = 8;
    ZHEndianness endianness;
    printf("{ ");
    for (uint8_t i = 0; i < bitCount; i++) {
        uint8_t index = endianness ? i : bitCount - (i+1);
    }
    
    printf("}\n");
    printf("\n");
}

void ZHPrintBiraryDependOfTypeProccesor(uint8_t charValue, ZHEndianness endianness ) {
    printf("{ ");
    for (uint8_t i = 8; i > 0; i--) {
        if (endianness == ZHProcessorBigEndian ) {
            uint8_t printShiftValue = charValue >> (i -1 );
            if (printShiftValue & 1) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        } else {
            uint8_t printShiftValue = charValue >> (8-i);
            if (printShiftValue & 1) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        
    } printf("}\n");
    printf("\n");
}