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
    ZHProcessorBigEndian,
    ZHProcessorLittleEndian
} ZHEndianness;

struct ZHStructTypesVar {
    char valueChar;             //8
    int valueInt;               //4
    long valueLong;             //8
    short valueShort1;          //4
    short valueShort2;          //4
    short valueShort3;          //4
    long long valueLongLong;    //8
    float valueFloat;           //8
    double valueDouble;         //8
    long double valueLongDouble;//8
    union {
        struct boolStructure {
            bool valueBool1 :1;
            bool valueBool2 :1;
            bool valueBool3 :1;
            bool valueBool4 :1;
            bool valueBool5 :1;
            bool valueBool6 :1;
        } flags;
        char bitfild;
    };
};

struct ZHStructTypesVarOptimized {
    long long valueLongLong;    //8
    double valueDouble;         //8
    long double valueLongDouble;//8
    float valueFloat;           //4
    long valueLong;             //4
    int valueInt;               //4
    short valueShort1;          //4
    short valueShort2;          //4
    short valueShort3;          //4
    char valueChar;             //1
    union {
        struct boolStructure1 {
            bool valueBool1;
            bool valueBool2;
            bool valueBool3;
            bool valueBool4;
            bool valueBool5;
            bool valueBool6;
        } flags;
        char bitfild;
    };
};

typedef struct ZHStructTypesVar ZHStructTypesVar;
typedef struct ZHStructTypesVarOptimized ZHStructTypesVarOptimized;
void ZHPrintSizeOfStructure(void);

void ZHPrintBiraryOfInputValue(uint8_t charValue);
void ZHPrintBiraryDependOfTypeProccesor(uint8_t charValue, ZHEndianness endianness );


#define ZHMacrosStructureShiftOutput(typeValue) \
    printf(#typeValue"= %lu \n", offsetof(ZHStructTypesVarOptimized, typeValue))

#endif /* ZHStructuresTest_h */
