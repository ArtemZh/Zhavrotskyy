//
//  ZHStructuresTest.h
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 18.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#ifndef ZHStructuresTest_h
#define ZHStructuresTest_h

#include <stdio.h>
#include <stdbool.h>


typedef enum {
    ZHProcessorBigEndian       = 1,
    ZHProcessorLittleEndian    = 0
} ZHProcessorType;

struct ZHStructTypesVar {
    char valueChar;             //8
    int valueInt;               //4
    long valueLong;             //8
    short shortValue1;          //4
    short shortValue2;          //4
    short shortValue3;          //4
    long long valueLongLong;    //8
    float valueFloat;           //8
    double valueDouble;         //8
    long double valueLongDouble;//8
    union {
        struct boolStructure {
            bool boolValue1;
            bool boolValue2;
            bool boolValue3;
            bool boolValue4;
            bool boolValue5;
            bool boolValue6;
        } flags;
    };
};

struct ZHStructTypesVarOptimized {
    char valueChar;             //8
    long valueLong;             //8
    long long valueLongLong;    //8
    float valueFloat;           //8
    double valueDouble;         //8
    long double valueLongDouble;//8
    int valueInt;               //4
    short valueShort1;          //4
    short valueShort2;          //4
    short valueShort3;          //4
    union {
        struct boolStructure1 {
            bool boolValue1;
            bool boolValue2;
            bool boolValue3;
            bool boolValue4;
            bool boolValue5;
            bool boolValue6;
        } flags;
    };
};

typedef struct ZHStructTypesVar ZHStructTypesVar;
typedef struct ZHStructTypesVarOptimized ZHStructTypesVarOptimized;
void ZHPrintSizeOfStructure(void);

void ZHPrintBiraryOfInputValue(uint8_t charValue);
void ZHPrintBiraryDependOfTypeProccesor(uint8_t charValue, ZHProcessorType proc );


#define ZHMacrosStructureShiftOutput(typeValue) \
printf(#typeValue"= %lu \n", offsetof(ZHStructTypesVarOptimized, typeValue))

#endif /* ZHStructuresTest_h */
