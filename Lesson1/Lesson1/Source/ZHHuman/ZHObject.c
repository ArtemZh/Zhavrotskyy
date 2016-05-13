//
//  ZHObject.c
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 28.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include <assert.h>

#include "ZHObject.h"

void __ZHObjectDeallocate(void *address) {
    if (address) {
        free(address);
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

void *ZHObjectRetain(void *address) {
    if (address) {
        ZHObject *object = address;
        object->_referenceCount+= 1;
    }
    
    return address;
}

void ZHObjectRelease(void *adderess) {
    if (adderess) {
        ZHObject *object = adderess;
         object->_referenceCount -= 1;
        
        if (0 == object->_referenceCount) {
            object->_deallocator(object);
        }
    }
}

uint64_t ZHObjectGetReferenceCount(void *object) {
    return object ? ((ZHObject*)object)->_referenceCount : 0;
}

