//
//  ZHObject.c
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 28.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include <assert.h>

#include "ZHObject.h"

void *__ZHObjectCreate(size_t objectSize, ZHObjectDeallocator deallocateCallback) {
    assert(0 != objectSize);
    assert(NULL != deallocateCallback);
    
    ZHObject *object = calloc(1, objectSize);
    
    assert(NULL != object);
    
    object->_referenceCount = 1;
    object->_deallocator = deallocateCallback;
    
    return object;
}

void __ZHObjectDeallocate(void *object) {
    if (NULL != object) {
        free(object);
    }
}

void *ZHObjectRetain(void *object) {
    if (NULL != object) {
        ((ZHObject *)object)->_referenceCount++;
    }
    
    return object;
}

void ZHObjectRelease(void *object) {
    if (NULL != object) {
        uint64_t count = ((ZHObject *)object)->_referenceCount - 1;
        ((ZHObject *)object)->_referenceCount = count;
        
        if (0 == count) {
            ((ZHObject *)object)->_deallocator(object);
        }
    }
}

