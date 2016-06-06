//
//  ZHArrayTests.c
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 23.05.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include <stdio.h>

#include "ZHArrayTests.h"
#include "ZHArray.h"
#include "ZHObject.h"
#include "ZHString.h"
#include "ZHHuman.h"

static const int ZHObjectCount = 11;
static const int ZHObjectCountRemove = 7;

void ZHArrayTests() {
    puts("Start");
    
    ZHArray *array = ZHArrayCreateWithCapacity(10);
    ZHString *string =  ZHStringCreate("Test");
    
    printf(" New Array capacity %llu \n", ZHArrayGetCapacity(array));
    printf(" New Array object count %llu \n", ZHArrayGetCount(array));
   // printf(" object \n", ZHArrayGetObjectAtIndex(array, 1));
    
   // ZHArraySetObjectAtIndex(array, string, 0);
    for (int index = 0; index < ZHObjectCount ; index += 1) {
        ZHArrayAddObject(array, string);
        printf("capacity =%llu, count =%llu \n", ZHArrayGetCapacity(array), ZHArrayGetCount(array));
    }
    ZHObjectRetain(array);
    printf("Array Reference Count %llu \n", ZHObjectGetReferenceCount(array));
    ZHObjectRelease(array);
    printf("Array Reference Count %llu \n", ZHObjectGetReferenceCount(array));
    
    for (int index = 0; index < ZHObjectCountRemove; index += 1) {
        ZHArrayRemoveObjectAtIndex(array, index);
        printf("capacity =%llu, count =%llu\n", ZHArrayGetCapacity(array), ZHArrayGetCount(array));
    }
    //ZHArrayRemoveAllObject(array);
    ZHObjectRelease(array);
    printf("capacity =%llu, count =%llu after releas \n", ZHArrayGetCapacity(array), ZHArrayGetCount(array));
    
    printf("Array Reference Count %llu \n", ZHObjectGetReferenceCount(array));
}
