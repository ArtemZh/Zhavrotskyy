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

extern
ZHArray *ZHArrayCreateWithCapacity(uint64_t capacity);

extern
void ZHArrayAddObject(ZHArray *array, void *object);

extern
uint64_t ZHArrayGetCount(ZHArray *array);

extern
uint64_t ZHArrayGetCapacity(ZHArray *array);

extern
void *ZHArrayGetObjectAtIndex(ZHArray *array, uint64_t index);

extern
uint64_t ZHArrayGetIndexOfObject(ZHArray *array, void *object);

extern
void ZHArraySetObjectAtIndex(ZHArray *array, void *object, uint64_t index);

#endif /* ZHArray_h */
