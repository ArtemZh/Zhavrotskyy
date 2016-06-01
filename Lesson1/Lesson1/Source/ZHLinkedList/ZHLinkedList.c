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


void __ZHLinkedListDeallocate(void *object) {
    ZHLinkedListSetCount(object, 0);
    
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
    
    void *previousObject = NULL;
    ZHLinkedListContext *context = ZHLinkedListContextCreateWithObject(object);
    ZHLinkedListNode *node = ZHLinkedListFindNodeWithContext(list, ZHLinkedListNodeContainsObject, context);
    if (node) {
        ZHLinkedListNode *node = context->previousNode;
        previousObject = ZHLinkedListNodeGetObject(node);
    }
    
    return previousObject;
}

void ZHLinkedListRemoveFirstObject(ZHLinkedList *list) {
    ZHLinkedListNode *firstNode = ZHLinkedListGetHead(list);
    ZHLinkedListNode *nextNode = ZHLinkedListNodeGetNextNode(firstNode);
    
    ZHLinkedListSetHead(list, nextNode);
    ZHLinkedListCountAddValue(list, -1);
}

void ZHLinkedListRemoveObject(ZHLinkedList *list, void *object) {
    ZHReturnValueIfCondition(!list, ZHEmpty);
    
    ZHLinkedListContext context = *ZHLinkedListContextCreateWithObject(object);
    ZHLinkedListNode *node = ZHLinkedListFindNodeWithContext(list, ZHLinkedListNodeContainsObject, &context);
    ZHLinkedListNode *head = ZHLinkedListGetHead(list);
    if (node) {
        if (node == head){
            ZHLinkedListSetHead(list, ZHLinkedListNodeGetNextNode(node));
        } else {
            ZHLinkedListNode *previousNode = context.previousNode;
            ZHLinkedListNode *nexNode =  ZHLinkedListNodeGetNextNode(node);
            ZHLinkedListNodeSetNextNode(previousNode, nexNode);
            ZHLinkedListCountAddValue(list, -1);
        }
    }
}

void ZHLinkedListRemoveAllObjects(ZHLinkedList *list) {
    ZHReturnValueIfCondition(!list, ZHEmpty);
    
    ZHLinkedListSetCount(list, 0);
}

bool ZHLinkedListIsEmpty(ZHLinkedList *list) {
    ZHReturnValueIfCondition(!list, 0);
    
    return !ZHLinkedListGetHead(list);
}

uint64_t ZHLinkedListGetMutationsCount(ZHLinkedList *list) {
    ZHReturnValueIfCondition(!list, 0);
    
    return list->_mutationsCount;
}

bool ZHLinkedListContainsObject(ZHLinkedList *list, void *object) {
    ZHReturnValueIfCondition(!list, 0);
    
    ZHLinkedListContext *context = ZHLinkedListContextCreateWithObject(object);
    ZHLinkedListNode *node = ZHLinkedListFindNodeWithContext(list, ZHLinkedListNodeContainsObject, context);
    
    return (bool)node;
}


void ZHLinkedListCountAddValue(ZHLinkedList *list, uint8_t value) {
    ZHReturnValueIfCondition(!list, ZHEmpty);
    
    list->count += value;
}

void ZHLinkedListSetCount(ZHLinkedList *list, uint64_t value) {
    ZHReturnValueIfCondition(!list, ZHEmpty);
    
    if (!value) {
        ZHLinkedListSetHead(list, NULL);
    }
    
    list->count = value;
    ZHLinkedListMutationsCountAddValue(list, +1);
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

ZHLinkedListNode *ZHLinkedListFindNodeWithContext(ZHLinkedList *list,
                                                    ZHLinkedListNodeComparisonFunction comparator,
                                                    ZHLinkedListContext *context) {
    ZHLinkedListNode *result = NULL;
    if (list) {
        ZHLinkedListEnumerator *enumerator = ZHLinkedListEnumeratorCreateWithList(list);
        while (ZHLinkedListEnumeratorIsValid(enumerator) && ZHLinkedListEnumeratorGetNextObject(enumerator))  {
            ZHLinkedListNode *node = ZHLinkedListEnumeratorGetNode(enumerator);
            
            if (ZHLinkedListNodeContainsObject(node, context)) {
                result = node;
                break;
            }
        }
        
        ZHObjectRelease(enumerator);
    }
    
    return result;
}

ZHLinkedListContext* ZHLinkedListContextCreateWithObject(void *object) {
    ZHLinkedListContext *context = calloc(1, sizeof(*context));
    context->object = object;
    
    return context;
}

ZHLinkedListContext *ZHLinkedListCreateContextFindNodeWithObject(ZHLinkedList *list, void *object) {
    ZHLinkedListContext *context = ZHLinkedListContextCreateWithObject(object);
    __unused ZHLinkedListNode *node = ZHLinkedListFindNodeWithContext(list, ZHLinkedListNodeContainsObject, context);
    
    return context;
}

bool ZHLinkedListNodeContainsObject(ZHLinkedListNode *node, ZHLinkedListContext *context) {
    bool result = false;
    if (node) {
        context->previousNode = context->node;
        context->node = node;
        
        void *object = ZHLinkedListNodeGetObject(node);
        if (context->object == object) {
            result = true;
        }
    }
    
    return result;
}

