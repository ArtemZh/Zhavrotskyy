//
//  ZHLinkedListNode.h
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 24.05.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#ifndef ZHLinkedListNode_h
#define ZHLinkedListNode_h

#include <stdio.h>

#include "ZHObject.h"

typedef struct ZHLinkedListNode ZHLinkedListNode;
struct ZHLinkedListNode {
    ZHObject _super;
    
    ZHLinkedListNode *_nextNode;
    void *_object;
};

extern
ZHLinkedListNode *ZHLinkedListNodeCreateWithObject(void *object);

extern
ZHLinkedListNode *ZHLinkedListNodeGetNextNode(ZHLinkedListNode *node);

extern
void ZHLinkedListNodeSetNextNode(ZHLinkedListNode *node, ZHLinkedListNode *nextNode);

extern
void *ZHLinkedListNodeGetObject(ZHLinkedListNode *node);

extern
void ZHLinkedListNodeSetObject(ZHLinkedListNode *node, void *object);

extern
void __ZHLinkedListNodeDeallocate(void *object);

#endif /* ZHLinkedListNode_h */
