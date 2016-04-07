//
//  ZhPrintFunction.c
//  Less1
//
//  Created by Artem Zhavrotskiy on 05.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include <stdio.h>
#include "ZHPrintFunction.h"


//The function prints "Hello world"
void ZHPrintHw (){
    printf("Hello World \n");
}

//The function prints "hello" and transmitted it the string value
void ZHPrintHwWithParents (const char *text){
    printf("Hello  %s \n", text);
}

//The function adds a blank line
void ZHAddBlankLine () {
    printf("\n");
}

//The function adds the number of  n++ rows

void ZHAddMenyBlankLine (int NumOfIter ) {
    for (int iteration = 0; iteration < NumOfIter; iteration++ );
    ZHAddBlankLine();
}