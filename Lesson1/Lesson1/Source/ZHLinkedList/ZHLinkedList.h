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
    uint64_t _mutationsCount;
    uint64_t count;
};


extern
void *ZHLinkedListGetFirstObject(ZHLinkedList *list);

extern
void *ZHLikedListGetPreviousObject(ZHLinkedList *list, void *object);


extern
void *ZHLinkedListGetNextObject(ZHLinkedList *list, void *object);


#endif /* ZHLinkedList_h */
