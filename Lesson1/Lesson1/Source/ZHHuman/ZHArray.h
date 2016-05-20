//
//  ZHArray.h
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 16.05.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#ifndef ZHArray_h
#define ZHArray_h

#include <stdio.h>
#include <stdbool.h>

#include "ZHObject.h"

typedef struct ZHArray ZHArray;

struct ZHArray {
    ZHObject _super;
    
    void **_data;
    
    uint64_t _count;
    uint64_t _capacity;
};

uint64_t ZHArrayGetCount(ZHArray *array);
uint64_t ZHArrayGetCapacity(ZHArray *array);

void *ZHArrayGetObjectAtIndex(ZHArray *array, uint64_t index);

void ZHArrayResize(ZHArray *array);

void ZHArraySetCapacity(ZHArray *array, uint64_t newCapacity);

#endif /* ZHArray_h */
