//
//  ZHObject.c
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 28.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include <assert.h>

#include "ZHObject.h"

void __ZHObjectDeallocate(void *object) {
    if (object) {
        free(object);
    }
}

void *__ZHObjectCreate(size_t objectSize, ZHObjectDeallocator deallocateCallback) {
    assert(deallocateCallback);
    
    ZHObject *object = calloc(1, objectSize);
    
    assert(object);
    
    object->_referenceCount = 1;
    object->_deallocator = deallocateCallback;
    
    return object;
}

void *ZHObjectRetain(void *object) {
    if (object) {
        ((ZHObject *)object)->_referenceCount+= 1;
    }
    
    return object;
}

void ZHObjectRelease(void *object) {
    if (object) {
        uint64_t count = ((ZHObject *)object)->_referenceCount - 1;
        ((ZHObject *)object)->_referenceCount = count;
        
        if (0 == count) {
            ((ZHObject *)object)->_deallocator(object);
        }
    }
}

