//
//  ZHLinkedListEnumerator.h
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 24.05.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#ifndef ZHLinkedListEnumerator_h
#define ZHLinkedListEnumerator_h

#include <stdbool.h>

#include "ZHObject.h"

typedef struct ZHLinkedList ZHLinkedList;
typedef struct ZHLinkedListNode ZHLinkedListNode;

typedef struct ZHLinkedListEnumerator ZHLinkedListEnumerator;
struct ZHLinkedListEnumerator {
    ZHObject _super;
    
    ZHLinkedList *_list;
    ZHLinkedListNode *_node;
    uint64_t _mutationsCount;
    bool _isValid;
};

extern
ZHLinkedListEnumerator *ZHLinkedListEnumeratorCreateWithList(ZHLinkedList *list);

extern
void *ZHLinkedListEnumeratorGetNextObject(ZHLinkedListEnumerator *enumerator);

extern
bool ZHLinkedListEnumeratorIsValid(ZHLinkedListEnumerator *enumerator);

extern
void __ZHLinkedListEnumeratorDeallocate(void* object);

extern
ZHLinkedListNode *ZHLinkedListEnumeratorGetNode(ZHLinkedListEnumerator *enumerator);

#endif /* ZHLinkedListEnumerator_h */
