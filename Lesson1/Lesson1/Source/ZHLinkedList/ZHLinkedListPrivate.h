//
//  ZHLinkedListPrivate.h
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 25.05.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#ifndef ZHLinkedListPrivate_h
#define ZHLinkedListPrivate_h

#include "ZHLinkedList.h"

typedef struct ZHLinkedListContext ZHLinkedListContext;
struct ZHLinkedListContext {
    void *previousNode;
    void *node;
    void *object;
};

typedef bool (*ZHLinkedListNodeComparisonFunction)(ZHLinkedListNode *node, ZHLinkedListContext *context);

extern
void ZHLinkedListSetHead(ZHLinkedList *list, ZHLinkedListNode *head);

extern
ZHLinkedListNode *ZHLinkedListGetHead(ZHLinkedList *list);

extern
uint64_t ZHLinkedListGetMutationsCount(ZHLinkedList *list);

extern
void ZHLinkedListSetMutationsCount(ZHLinkedList *list, uint64_t count);

extern
void ZHLinkedListMutationsCountAddValue(ZHLinkedList *list, uint64_t value);

extern
ZHLinkedListNode *ZHLinkedListFindNodeWithContext(ZHLinkedList *list,
                                                    ZHLinkedListNodeComparisonFunction comparator,
                                                    ZHLinkedListContext *context);

extern
bool ZHLinkedListNodeContainsObject(ZHLinkedListNode *node, ZHLinkedListContext *context);

ZHLinkedListContext *ZHLinkedListContextCreateWithObject(void *object);


#endif /* ZHLinkedListPrivate_h */
