//
//  ZHLinkedList.c
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 24.05.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include <string.h>
#include <assert.h>

#include "ZHArray.h"
#include "ZHLinkedList.h"
#include "ZHLinkedListEnumerator.h"
#include "ZHLinkedListNode.h"
#include "ZHLinkedListPrivate.h"

static
void ZHLinkedListCountAddValue(ZHLinkedList *list, uint8_t value);

static
void ZHLinkedListSetCount(ZHLinkedList *list, uint64_t value);


void __ZHlinkedListDeallocate(void *object) {
    //delete all
    
    __ZHObjectDeallocate(object);
}

ZHLinkedListEnumerator *ZHLinkedListCreateEnumeratorFromList(ZHLinkedList *list) {
    return ZHLinkedListCreateEnumeratorFromList(list);
}

void *ZHLinkedListGetFirstObject(ZHLinkedList *list) {
    ZHLinkedListNode *node = ZHLinkedListGetHead(list);
    
    return ZHLinkedListNodeGetObject(node);
}

void *ZHLinkedListGetNextObject(ZHLinkedList *list, void *object) {
    ZHReturnValueIfCondition(!list, NULL);
    
    void *nextObject = NULL;
    ZHLinkedListNode *node = ZHLinkedListGetHead(list);
    while (ZHLinkedListNodeGetNextNode(node)) {
        void *curentObject = ZHLinkedListNodeGetObject(node);
        if (object == curentObject) {
            nextObject = ZHLinkedListNodeGetObject(ZHLinkedListNodeGetNextNode(node));
            break;
        }
        
        node = ZHLinkedListNodeGetNextNode(node);
    };
    
    return nextObject;
    
}

void *ZHLikedListGetPreviousObject(ZHLinkedList *list, void *object) {
    ZHReturnValueIfCondition(!list, NULL);
    
    void *previosObject = NULL;
    ZHLinkedListContext *context = ZHLinkedListContextCreateWithObject(object);
    ZHLinkedListNode *node = ZHLinkedListFindNodeWithContext(list, ZHLinkedListNodeContainsObject, context);
    if (node) {
        ZHLinkedListNode *node = context->previousNode;
        previosObject = ZHLinkedListNodeGetObject(node);
    }
    
    return previosObject;
}


void ZHLinkedListSetCount(ZHLinkedList *list, uint64_t value) {
    ZHReturnValueIfCondition(!list, ZHEmpty);
    
    if (!value) {
        ZHLinkedListSetHead(list, NULL);
    }
    
    list->count = value;
    ZHLinkedListMutationsCountAddValue(list, +1);
}

void ZHLinkedListCountAddValue(ZHLinkedList *list, uint8_t value) {
    ZHReturnValueIfCondition(!list, ZHEmpty);
    
    list->count += value;
}

void ZHLinkedListSetHead(ZHLinkedList *list, ZHLinkedListNode *head) {
    ZHReturnValueIfCondition(!list, ZHEmpty);
    
    ZHObjectRetainSetter(list, _head, head);
}

ZHLinkedListNode *ZHLinkedListGetHead(ZHLinkedList *list) {
    ZHReturnValueIfCondition(!list, NULL);
    
    return list->_head;
}

void ZHLinkedListSetMutationsCount(ZHLinkedList *list, uint64_t count) {
    ZHObjectAssignSetter(list, _mutationsCount, count);
}

void ZHLinkedListMutationsCountAddValue(ZHLinkedList *list, uint64_t value) {
    uint64_t count = ZHLinkedListGetMutationsCount(list);
    ZHLinkedListSetMutationsCount(list, count += value);
}













