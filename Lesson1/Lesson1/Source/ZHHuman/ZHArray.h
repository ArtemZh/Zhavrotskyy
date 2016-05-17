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
    
    uint16_t _count;
    uint16_t _capacity;
};


#endif /* ZHArray_h */
