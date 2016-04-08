//
//  ZHRunAplication.c
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 07.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include "ZHRunAplication.h"



void ZHRunAplication (){
    
    ZHPrintHw();
    ZHPrintHwWithParents("Papa");
    ZHAddBlankLine();
    ZHAddManyBlankLine(1);
    
    ZHPrintNumbderIncreasing();
    ZHAddManyBlankLine (1);
    ZHPrintNumbderDecreasing();
    
    ZHPrintChar ("text");
    ZHPrintShort (1);
    ZHPrintInt (12);
    ZHPrintLong (12345678 * 12345678);
    ZHPrintLongLong (123456789 * 123456789);
    ZHPrintFloat (12345 / 12345);
    ZHPrintDouble (123456789 / 123456789);
    
}
