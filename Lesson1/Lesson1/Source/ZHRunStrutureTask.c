//
//  ZHRunStrutureTask.c
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 21.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include "ZHRunStrutureTask.h"
#include "ZHMacrosOutputFunction.h"
#include "ZHStructuresTest.h"

void ZHStructureTask() {
    ZHMacrosTest(1, 'a');
    ZHPrintSizeOfStructure();
    ZHPrintBiraryOfInputValue(5);
    ZHPrintBiraryDependOfTypeProccesor(1, 0);
 
}


