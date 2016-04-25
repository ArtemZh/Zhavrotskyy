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
    uint8_t testChar = 5;
    ZHPrintBinaryOfInputbit(testChar);
    
    float testValue = 7.2;
    printf("\n");
    ZHPrintBinaryValueWithSizeAndEndianness(&testValue, sizeof(testValue), ZHBigEndian);
    printf("\n ZHPrintBinaryValueWithSizeAndEndianness \n");
    ZHPrintBinaryValueWithSize(&testValue, sizeof(testValue));
    printf("\n ZHPrintBinaryValueWithSize \n");
}

void ZHPrintBinaryOfInputbit(uint8_t charValue) {
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
        ZHPrintBinaryOfInputbit(((uint8_t *)value)[index]);
    }
}

void ZHPrintBinaryValueWithSize (void *value, size_t size) {
    ZHEndiannessFormat endianness = ZHBigEndian;
    ZHPrintBinaryValueWithSizeAndEndianness(value, sizeof(value), endianness);
}


//void ZHPrintBinaryValueWithSizeAndDependOfEndianness(uint8_t charValue, ZHEndianness endianness ) {
//    printf("{ ");
//    for (uint8_t i = 8; i > 0; i--) {
//        if (endianness == ZHProcessorBigEndian ) {
//            uint8_t printShiftValue = charValue >> (i -1 );
//            if (printShiftValue & 1) {
//                printf("1 ");
//            } else {
//                printf("0 ");
//            }
//        } else {
//            uint8_t printShiftValue = charValue >> (8-i);
//            if (printShiftValue & 1) {
//                printf("1 ");
//            } else {
//                printf("0 ");
//            }
//        }
//        
//    } printf("}\n");
//    printf("\n");
//}