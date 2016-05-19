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

//#define ZHReturnValueIfCondition1(condition) \
//    if(!(condition))

#define ZHReturnValueIfCondition(condition, value) \
    if ((condition)) { \
    return value; \
    }

static const uint64_t kZHArrayIndexNotFound = UINT64_MAX;

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
    ZHReturnValueIfCondition(!array, 0);
    
    return array->_count;
}

uint64_t ZHArrayGetCapacity(ZHArray *array) {
    ZHReturnValueIfCondition(!array, 0);
    
    return array->_capacity;
}

void *ZHArrayGetObjectAtIndex(ZHArray *array, uint64_t index) {
    ZHReturnValueIfCondition(array && ZHArrayGetCount(array), NULL);
    if (index>ZHArrayGetCapacity(array)) {
        return NULL;
    }
    
    return array->_data[index];
}


uint64_t __ZHArrayGetIndexOfObject(ZHArray *array, void *object) {
    ZHReturnValueIfCondition(!array && !object , 0);
    
    uint64_t count = ZHArrayGetCount(array);
    for (uint64_t index = 0; index < count; index += 1) {
        ZHReturnValueIfCondition(ZHArrayGetObjectAtIndex(array, index), index)
    }
    
    return kZHArrayIndexNotFound;
}

void ZHArrayCountSetValue(ZHArray *array, uint64_t value) {
    ZHReturnValueIfCondition(!array, ); /// can this be?
    
    array->_count += value;
}

void ZHArraySetObjectAtIndex(ZHArray *array, void *object, uint64_t index){
    ZHReturnValueIfCondition(!array, );
    
    ZHObject *oldObject = ZHArrayGetObjectAtIndex(array, index);
    if (oldObject != object) {
        ZHObjectRelease(array->_data[index]);
        array->_data[index] = object;
        ZHObjectRetain(object);
    }

}

void ZHArrayAddObject(ZHArray *array, void *object){
    ZHReturnValueIfCondition(!array, );
    
    uint64_t count = ZHArrayGetCount(array);
    ZHArraySetObjectAtIndex(array, object, count);
    ZHArrayCountSetValue(array, 1);
}


