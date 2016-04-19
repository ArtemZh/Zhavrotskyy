//
//  ZHTask5.c
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 10.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include "ZHTask5.h"

#include <stdbool.h>
#include <stdio.h>

#include "ZHPrintFunction.h"
#include "ZHPrintTypesVariables.h"

// 5.1
// true && true = true;
// true && false = false;
// false && true = false;
// false && false = false;
// true || true = true;
// true || false = true;
// false || true = true;
// false || false = false;

// 5.2
void ZHCheckTrueOrFalse(bool value) {
    //char * returnString ;
    value ? printf("True \n") : printf("False \n");
    //value ? strcpy(returnString, "true")  : strcpy(returnString, "false");
    //returnString;
}

// 5.3
bool ZHBoolOperations(int value1, int value2) {
    bool boolResult = value1 < value2;
    boolResult = value1 > value2;
    boolResult = value1 == value2;
    boolResult = value1 <= value2;
    boolResult = value1 >= value2;
    ZHCheckTrueOrFalse(boolResult);
    
    return boolResult;
}

//5.4
void ZHBoolResultLikeMamaPapa(bool result) {
   result ? ZHPrintCharValue("Mama") : ZHPrintCharValue("Papa");
}

// 5.5
void ZHBoolResultLikeMamaPapa2(int value1, int value2) {
    if(value1 < value2) {
        puts("Mama");
    } else {
        puts("Papa");
    }
}

//5.8
void ZHPrintDeputyState(ZHDeputyEntity entity) {
    
    switch (entity) {
        case DeputyEmbezzler:
            ZHPrintCharValue("Deputy embezzler");
            break;
            
        case DeputyFair:
            ZHPrintCharValue("Deputy fair");
            break;
            
        case DeputyAngel:
            ZHPrintCharValue("Deputy angel");
            break;
            
        case DeputyDead:
        default:
            ZHPrintCharValue("Deputy dead");
            break;
    }
}

void ZHDeputySalary(long salary, long revenueDeputat ) {
    ZHDeputyEntity entity = 0;
    if(revenueDeputat < salary * 12  ) {
        entity = DeputyDead;
    } else if (revenueDeputat < salary * 120) {
        entity = DeputyAngel;
    } else if (revenueDeputat < salary * 1000 * 1000) {
        entity = DeputyFair;
    } else {
        entity = DeputyEmbezzler;
    }
    ZHPrintDeputyState(entity);
        
}

// 5.10
void ZHArray() {
    int testArray[5] = {1, 2, 3, 4, 5};
    int testArray2[5];
    testArray2[0] = 1;
    testArray2[1] = 2;
    testArray2[2] = 3;
    testArray2[3] = 4;
    testArray2[4] = 5;
    
    
    int sizeArray = sizeof(testArray)/sizeof(testArray[0]);
    for ( int iterator = 0; iterator < sizeArray; iterator++) {
        printf("%d    %d\n", testArray[iterator], testArray2[iterator]);
    }
   
}
//5.12
void ZHPrintString(char * textArray, bool termination) {
    int textSize = (int)strlen(textArray);
    printf("%d \n", textSize);
    for ( int iterator = 0; iterator < textSize; iterator++) {
        printf("%c", textArray[iterator]);
    }
    termination ? printf("\n"):printf("");
}

// 5.13
void ZHGetString(char * textArray) {
    int textSize = (int)strlen(textArray);
    char lastChar = textArray[textSize - 1];
    lastChar == '\n' ? printf("\n Length of String is %d \n", textSize):printf("\n String is not terminated \n");
}

//5.19
int ZHMamaPapa(int value) {
    char * outPutStrung = "";
    int status = 0;
    if (value % 15 == 0) {
        outPutStrung = "MamaPapa\n";
        status = 15;
    }
    else if (value % 3 == 0) {
        outPutStrung = "Mama\n";
        status = 3;
    }
    else if (value % 5 == 0) {
        outPutStrung = "Papa\n";
        status = 5;
    }
    else {
        outPutStrung = "";
        status = -1;
    }
    printf("%s", outPutStrung );
    return status;
}
void ZHPrintVariablesSize() {
}

ZHPrintParentsConditions ZHPrintParentsConditionAndValue(int value) {
    ZHPrintParentsConditions printCondition = ZHPassValueCondition;
    if (0 == value % 3) {
        printCondition += ZHMamaCondition;
        ZHPrintMama();
    }
    
    if (0 == value % 5) {
        printCondition += ZHPapaCondition;
        ZHPrintPapa();
    }
    
    if (printCondition == 0) {
        ZHPrintInt(value);
    }
    
    return printCondition;
}
