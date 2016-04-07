//
//  ZHRunAplication.h
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 07.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#ifndef ZHRunAplication_h
#define ZHRunAplication_h

#include "ZHPrintFunction.h"
#include "ZHPrintNumberFunction.h"
#include "ZHPrintDifferentTypesVariables.h"


#include <stdio.h>

#endif /* ZHRunAplication_h */

void ZHRunAplication (){
    
    ZHPrintHw();
    ZHPrintHwWithParents("Papa");
    ZHAddBlankLine();
    ZHAddMenyBlankLine (1);
    
    ZHPrintNubderIncreas();
    ZHAddMenyBlankLine (1);
    ZHPrintNubderDecreas();
    
    ZHPrintChar ("text");
    ZHPrintShort (1);
    ZHPrintInt (12);
    ZHPrintLong (12345678*12345678);
    ZHPrintLongLong (123456789*123456789);
    ZHPrintFloat (12345/12345);
    ZHPrintDouble (123456789/123456789);

}