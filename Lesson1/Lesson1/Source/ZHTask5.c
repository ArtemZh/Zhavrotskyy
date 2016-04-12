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
//typedef enum {
//    embezzler,
//    fair,
//    angel,
//    dead
//} ZHDeputyEntity;

void ZHDeputySalary(ZHDeputyEntity entity, long salary, long revenueDeputat ) {
    
    
    
    if(revenueDeputat < salary * 12  ) {
        entity = angel;
    } else if (revenueDeputat < salary * 120) {
        entity = fair;
    } else if (revenueDeputat > salary * 1000 * 1000) {
        entity = embezzler;
    } else {
        entity = dead;
    }
    
    switch (entity) {
       // case ZHDeputyEntity[0]
        case embezzler:
            ZHPrintCharValue("Deputy embezzler");
            break;
        case fair:
            ZHPrintCharValue("Deputy fair");
            break;
        case angel:
            ZHPrintCharValue("Deputy angel");
            break;
        case dead:
        default:
            ZHPrintCharValue("Deputy dead");
            break;
    }
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
   // char text[5] = "Hello";
    //int textSize = sizeof(textArray);
    //printf("%d", textsize);
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
//    if (lastChar == '\n') printf("\n Length of String is %d \n", textSize);
//    else printf("\n String is not terminated \n");
    lastChar == '\n' ? printf("\n Length of String is %d \n", textSize):printf("\n String is not terminated \n");
}

//5.19



int ZHMamaPapa (int value) {
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

//void ZHTaskMamaPapa( int value) {
//    char str1[] = "Mama";
//    char str2[] = "Papa";
//    
//    printf("\n %s", str1);
//    
//    if (value % 3 == 0) {
//        if (value % 5 == 0) {
//            strcat(str1, str2);
//        } else {
//            if (value % 5 == 0) {
//                strcpy(str1, str2);
//            }
//        }
//    } else {
//        strchr(str1, value);
//    }
//    
//    ZHPrintCharValue(str1);
//}

/// sdelat cherez enum, add enum element

char  ZHTaskMamaPapa2(int value) {
    char str1[] = "Mama";
    char str2[] = "Papa";
    
    if (value % 3 == 0) {
        if (value % 5 == 0) {
            strcat(str1, str2);
        } else {
            return str1;
        }
    } else {
        if (value % 5 == 0) {
            strcpy(str1, str2);
        } else {
            strchr(str1, value);
        }
    } return str1;
}

