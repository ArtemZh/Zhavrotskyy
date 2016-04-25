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

void ZHPrintBinaryTest() {
    printf("Start test\n");
    uint8_t testChar = 5;
    ZHPrintBinaryByte(testChar);
    
    uint16_t testValue = 1;
    printf("\n ZHPrintBinaryValueWithSizeAndEndianness \n");
    ZHPrintBinaryValueWithSizeAndEndianness(&testValue, sizeof(testValue), ZHBigEndian);
    printf("\n");
    uint16_t testValue1 = 1;
    printf("\n ZHPrintBinaryValueWithSize \n");
    ZHPrintBinaryValueWithSize(&testValue1, sizeof(testValue1));
}

void ZHPrintBinaryByte(uint8_t charValue) {
    const uint8_t bitCount = 8;
    printf("{ ");
    for (uint8_t i = 0; i < bitCount; i++) {
        size_t bit = charValue >> (bitCount - i - 1);
        printf("%lu ", bit & 1);
    }
    
    printf("}");
    printf("\n");
}

ZHEndiannessFormat ZHEndianness() {
    uint16_t value = 1;
    
    return (((char *)&value)[0]) ? ZHBigEndian : ZHLittleEndian;
}


void ZHPrintBinaryValueWithSizeAndEndianness(void *value, size_t size, ZHEndiannessFormat endianness ) {
    for (size_t i = 0; i < size; i++) {
        uint8_t index = endianness ? i : size - i - 1;
        ZHPrintBinaryByte(((uint8_t *)value)[index]);
    }
}

void ZHPrintBinaryValueWithSize (void *value, size_t size) {
    ZHEndiannessFormat endianness = ZHEndianness();
    ZHPrintBinaryValueWithSizeAndEndianness(value, sizeof(value), endianness);
}
