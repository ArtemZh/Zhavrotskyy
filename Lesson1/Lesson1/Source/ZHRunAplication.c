//
//  ZHRunAplication.c
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 07.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include "ZHRunAplication.h"
#include "ZHPrintFunction.h"
#include "ZHPrintNumberFunction.h"
#include "ZHPrintTypesVariables.h"
#include "ZHTask5.h"
#include "ZHMacrosOutputFunction.h"
#include "ZHStructuresTest.h"

void ZHRunAplication() {
    ZHPrintHello();
    ZHPrintHelloWorldWithParents("Papa");
    ZHPrintBlankLine();
    ZHPrintBlankLines(1);
    
    ZHPrintNumberIncreasing();
    ZHPrintBlankLines(1);
    ZHPrintNumberDecreasing();
    
    ZHPrintChar("text");
    ZHPrintShort(1);
    ZHPrintInt(12);
    ZHPrintLong(12345678 * 12345678);
    ZHPrintLongLong(123456789 * 123456789);
    ZHPrintFloat(12345 / 12345);
    ZHPrintDouble(123456789 / 123456789);
    
    printf("ZHIncrement = %d, ZHDecrement = %d \n", ZHIncrement(99), ZHDecrement(101));
    
    ZHPrintPostAndPrefIncrement();
    
    ZHCheckTrueOrFalse(true);
    ZHBoolOperations(2, 5);
    ZHBoolResultLikeMamaPapa(true);
    ZHBoolResultLikeMamaPapa2(2, 5);
    
    ZHArray();
    ZHPrintString("aaaa",true);
    ZHPrintString("bbbbb",false);
    ZHGetString("123458");
    ZHGetString("12345\n");
    
    ZHDeputySalary( 1, 144444444440);
    ZHPrintParentsConditionAndValue (14);
    
    printf("\n");
    
    ZHMacrosTest(1, 'a');
    ZHPrintSizeOfStructure();
    ZHPrintBiraryOfInputValue(5);
    ZHPrintBiraryDependOfTypeProccesor(1, 0);
   
    
    
}
