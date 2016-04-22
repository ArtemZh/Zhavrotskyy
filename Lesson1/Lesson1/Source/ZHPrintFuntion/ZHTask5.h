//
//  ZHTask5.h
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 10.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#ifndef ZHTask5_h
#define ZHTask5_h

#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#include "ZHPrintFunction.h"

typedef enum {
    ZHDeputyEmbezzler,
    ZHDeputyFair,
    ZHDeputyAngel,
    ZHDeputyDead
} ZHDeputyEntity;

typedef enum {
    ZHPassValueCondition,
    ZHMamaCondition,
    ZHPapaCondition,
    ZHMamaPapaCondition,
} ZHPrintParentsConditions;

void ZHCheckTrueOrFalse(bool value);
void ZHArray();
void ZHPrintString1( char * text, bool termination);
int ZHMamaPapa(int value);
bool ZHBoolOperations(int value1, int value2);
void ZHBoolResultLikeMamaPapa(bool result);
void ZHBoolResultLikeMamaPapa2(int value1, int value2);
void ZHPrintDeputyState(ZHDeputyEntity entity);
void ZHDeputySalary(long salary, long revenueDeputat);
ZHPrintParentsConditions ZHPrintParentsConditionAndValue(int value);
void ZHPrintVariablesSize();

void ZHPrintString(const char *string);
void ZHPrintStringWithLength(const char *string, unsigned long length);

#endif /* ZHTask5_h */
