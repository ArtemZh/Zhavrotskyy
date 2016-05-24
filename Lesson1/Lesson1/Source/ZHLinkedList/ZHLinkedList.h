//
//  ZHLinkedList.h
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 24.05.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#ifndef ZHLinkedList_h
#define ZHLinkedList_h

#include <stdbool.h>

#include "ZHObject.h"

typedef struct ZHLinkedListEnumerator ZHLinkedListEnumerator;
typedef struct ZHLinkedListNode ZHLinkedListNode;

typedef struct ZHLinkedList ZHLinkedList ;
struct ZHLinkedList {
    ZHObject _super;
    
    ZHLinkedListNode *_head;
    uint64_t mutationCount;
    uint64_t count;
};


#endif /* ZHLinkedList_h */
