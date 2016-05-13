//
//  ZHObject.h
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 28.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#ifndef ZHObject_h
#define ZHObject_h

#include <stdlib.h>
#include <stdio.h>

#define ZHObjectCreateWithType(type) \
    __ZHObjectCreate(sizeof(type), (ZHObjectDeallocator)__##type##Deallocate)


typedef void (*ZHObjectDeallocator)(void *object);

typedef struct {
    uint64_t _referenceCount;
    ZHObjectDeallocator _deallocator;
} ZHObject;


extern
void *__ZHObjectCreate(size_t objectSize, ZHObjectDeallocator deallocateCallback);

extern
void __ZHObjectDeallocate(void *object);

extern
void *ZHObjectRetain(void *object);

extern
void ZHObjectRelease(void *object);

extern
uint64_t ZHObjectGetReferenceCount(void *object);

#endif /* ZHObject_h */
