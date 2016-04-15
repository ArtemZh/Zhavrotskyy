//
//  ZhPrintFunction.h
//  Less1
//
//  Created by Artem Zhavrotskiy on 05.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#ifndef ZHPrintFunction_h
#define ZHPrintFunction_h

#include <stdio.h>

//The function prints "Hello world"
void ZHPrintHello();
//The function prints "hello" and transmitted it the string value
void ZHPrintHelloWorldWithParents(const char *text);
void ZHPrintMama();
void ZHPrintPapa();
//The function adds a blank line
void ZHAddBlankLine();
//The function adds the number of  n++ rows
void ZHAddManyBlankLine(int countBlankLine);
void ZHPrintPostAndPrefIncrement();
void ZHPrintCharValue(const char *text);

#endif /* ZHPrintFunction_h */
