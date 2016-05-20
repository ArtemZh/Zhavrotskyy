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

#define ZHEmpty

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
    ZHReturnValueIfCondition(!array && !ZHArrayGetCount(array), NULL);
    if (index > ZHArrayGetCapacity(array)) {
        return NULL;
    }
    
    return array->_data[index];
}


uint64_t ZHArrayGetIndexOfObject(ZHArray *array, void *object) {
    ZHReturnValueIfCondition(!array && !object , 0);
    
    uint64_t count = ZHArrayGetCount(array);
    for (uint64_t index = 0; index < count; index += 1) {
        ZHReturnValueIfCondition(ZHArrayGetObjectAtIndex(array, index), index)
    }
    
    return kZHArrayIndexNotFound;
}

void ZHArrayCountSetValue(ZHArray *array, uint64_t value) {
    ZHReturnValueIfCondition(!array, ZHEmpty);
    
    array->_count += value;
    ZHArrayResize(array);
}

void ZHArraySetObjectAtIndex(ZHArray *array, void *object, uint64_t index){
    ZHReturnValueIfCondition(!array, ZHEmpty);
    
    ZHObject *oldObject = array->_data[index];
    if (oldObject != object) {
        ZHObjectRelease(array->_data[index]);
        array->_data[index] = object;
        ZHObjectRetain(object);
    }

}

void ZHArrayAddObject(ZHArray *array, void *object){
    ZHReturnValueIfCondition(!array, ZHEmpty);
    
    uint64_t count = ZHArrayGetCount(array);
    ZHArraySetObjectAtIndex(array, object, count);
    ZHArrayCountSetValue(array, 1);
}

void ZHArraySetCapacity(ZHArray *array, uint64_t newCapacity) {
    ZHReturnValueIfCondition(!array, ZHEmpty);
    uint64_t previousCapacity = ZHArrayGetCapacity(array);
    if (previousCapacity != newCapacity) {
        size_t size = newCapacity * sizeof(*array->_data);
        if (size && array->_data) {
            free(array->_data);
            array->_data = NULL;
        } else {
            array->_data = realloc(array->_data, size);
            
            if (previousCapacity < newCapacity) {
                for (uint64_t iterator = previousCapacity; iterator < newCapacity; iterator += 1) {
                    array->_data[iterator] = NULL;
                }
            }
        }
        
        array->_data = newCapacity;
    }
}

uint64_t ZHArrayPreferredCapacity(ZHArray *array) {
    ZHReturnValueIfCondition(!array, 0);
    
    uint64_t count = ZHArrayGetCount(array);
    uint64_t capacity = ZHArrayGetCapacity(array);
    
    
    if (capacity == count) {
        return capacity * 3 / 2;
    }
    
    if (capacity > count * 2) {
        return capacity * 3 / 4;
    }
    
    return capacity;
}

void ZHArrayResize(ZHArray *array) {
    if (ZHArrayGetCapacity(array) != ZHArrayPreferredCapacity(array)) {
        ZHArraySetCapacity(array, ZHArrayPreferredCapacity(array));
    }
}

void ZHArrayRemoveObjectAtIndex(ZHArray *array, uint64_t index) {
    ZHReturnValueIfCondition(!array, ZHEmpty);
    
    ZHArraySetObjectAtIndex(array, NULL, index);
    uint64_t count = ZHArrayGetCount(array);
    
    void **data = array->_data;
    if (index < (count)) {
        uint64_t elementsCount = count - (index + 1);
        memmove(&data[index], &data[index + 1], elementsCount * sizeof(*data));
    }
    
    ZHArrayCountSetValue(array, - 1);
}


void ZHArrayRemoveAllObject(ZHArray *array) {
    ZHReturnValueIfCondition(!array, ZHEmpty);
    
    uint64_t count = ZHArrayGetCount(array);
    for (uint64_t index=0; index < count; index +=1) {
        ZHArraySetObjectAtIndex(array, NULL, index);
        ZHArrayCountSetValue(array, - 1);
    }
}
