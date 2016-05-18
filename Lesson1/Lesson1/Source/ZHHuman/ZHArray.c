//
//  ZHArray.c
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 16.05.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include <assert.h>
#include <string.h>

#include "ZHArray.h"

//#define unless1(condition) \
//    if(!(condition))

#define unless(condition, value) \
    if(!(condition)) { \
    return value; \
    }

void __ZHArrayDeallocate(void *array) {
    /////
    /////delete all object
    __ZHObjectDeallocate(array);
}

ZHArray *ZHArrayCreateWithCapacity(uint64_t capacity) {
    ZHArray *array = ZHObjectCreateWithType(ZHArray);
    array->_capacity = capacity;
    return array;
}

uint64_t ZHArrayGetCount(ZHArray *array) {
    unless(array, 0); // ;?
    
    return array->_count;
}

uint64_t ZHArrayGetCapacity(ZHArray *array) {
    unless(array, 0);
    
    return array->_capacity;
}

void *ZHArrayGetObjectAtIndex(ZHArray *array, uint64_t index) {
    unless(array, NULL);
    unless(ZHArrayGetCount(array), NULL);
    if (index>ZHArrayGetCapacity(array)) {
        return NULL;
    }
    
    return array->_data[index];
}


