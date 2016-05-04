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
    ZHBigEndian,
    ZHLittleEndian
} ZHEndiannessType;

void ZHPrintBinaryTest();

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
        struct {
            bool valueBool1 :1;
            bool valueBool2 :1;
            bool valueBool3 :1;
            bool valueBool4 :1;
            bool valueBool5 :1;
            bool valueBool6 :1;
        } flags;
        char bitfield;
    };
};

struct ZHStructTypesVarOptimized {
    long long valueLongLong;    //8
    double valueDouble;         //8
    long double valueLongDouble;//8
    float valueFloat;           //4
    long valueLong;             //4
    int valueInt;               //4
    short valueShort1;          //2
    short valueShort2;          //2
    short valueShort3;          //2
    char valueChar;             //1
    union {
        struct {
            bool valueBool1 :1;
            bool valueBool2 :1;
            bool valueBool3 :1;
            bool valueBool4 :1;
            bool valueBool5 :1;
            bool valueBool6 :1;
        } flags;
        char bitfield;
    };
};

typedef struct ZHStructTypesVar ZHStructTypesVar;
typedef struct ZHStructTypesVarOptimized ZHStructTypesVarOptimized;
void ZHPrintSizeOfStructure(void);

void ZHPrintBinaryByte(uint8_t charValue);
void ZHPrintBinaryValueWithSizeAndEndianness(void *value, size_t size, ZHEndiannessType endianness );
void ZHPrintBinaryValueWithSize(void *value, size_t size);


#define ZHMacrosStructureShiftOutput(typeValue) \
    printf(#typeValue"= %lu \n", offsetof(ZHStructTypesVarOptimized, typeValue))

#endif /* ZHStructuresTest_h */
