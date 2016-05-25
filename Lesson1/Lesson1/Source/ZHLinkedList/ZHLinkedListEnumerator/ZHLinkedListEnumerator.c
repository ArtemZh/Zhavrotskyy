//
//  ZHLinkedListEnumerator.c
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 24.05.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include <assert.h>

#include "ZHLinkedListEnumerator.h"
#include "ZHLinkedList.h"
#include "ZHLinkedListNode.h"
#include "ZHLinkedListPrivate.h"
#include "ZHObject.h"

static
void ZHLinkedListEnumeratorSetList(ZHLinkedListEnumerator *enumerator, ZHLinkedList *list);

static
ZHLinkedList *ZHLinkedListEnumeratorGetList(ZHLinkedListEnumerator *enumerator);

static
void ZHLinkedListEnumeratorSetNode(ZHLinkedListEnumerator *enumerator, ZHLinkedListNode *node);

static
void ZHLinkedListEnumeratorSetMutationsCount(ZHLinkedListEnumerator *enumerator, uint64_t mutationsCount);

static
uint64_t ZHLinkedListEnumeratorGetMutationsCount(ZHLinkedListEnumerator *enumerator);

static
void ZHLinkedListEnumeratorSetValid(ZHLinkedListEnumerator *enumerator, bool isValid);

static
bool ZHLinkedListEnumeratorMutationsValidate(ZHLinkedListEnumerator *enumerator);

void __ZHLinkedListEnumeratorDeallocate(void* object) {
    ZHLinkedListEnumeratorSetNode(object, NULL);
    ZHLinkedListEnumeratorSetList(object, NULL);
    
    __ZHObjectDeallocate(object);
}

ZHLinkedListEnumerator *ZHLinkedListEnumeratorCreateWithList(ZHLinkedList *list) {
    ZHReturnValueIfCondition(!list, NULL);
    
    ZHLinkedListEnumerator * enumerator = ZHObjectCreateWithType(ZHLinkedListEnumerator);
    ZHLinkedListEnumeratorSetList(enumerator, list);
    ZHLinkedListEnumeratorSetMutationsCount(enumerator, ZHLinkedListGetMutationsCount(list));
    ZHLinkedListEnumeratorSetValid(enumerator, true);
    
    return enumerator;
}

void *ZHLinkedListEnumeratorGetNextObject(ZHLinkedListEnumerator *enumerator) {
    ZHReturnValueIfCondition(!enumerator, NULL);
    
    if (ZHLinkedListEnumeratorMutationsValidate(enumerator)) {
        ZHLinkedListNode *node = ZHLinkedListEnumeratorGetNode(enumerator);
        ZHLinkedList *list = ZHLinkedListEnumeratorGetList(enumerator);
        if (!node) {
            node = ZHLinkedListGetHead(list);
        } else {
            node = ZHLinkedListNodeGetNextNode(node);
        }
        
        ZHLinkedListEnumeratorSetNode(enumerator, node);
        if(!node) {
            ZHLinkedListEnumeratorSetValid(enumerator, false);
            
            return NULL;
        }
        
        return ZHLinkedListNodeGetObject(node);
    }
    
    return NULL;
}

bool ZHLinkedListEnumeratorIsValid(ZHLinkedListEnumerator *enumerator) {
    ZHReturnValueIfCondition(!enumerator, 0);
    
    return enumerator->_isValid;
}

void ZHLinkedListEnumeratorSetList(ZHLinkedListEnumerator *enumerator, ZHLinkedList *list) {
    ZHObjectRetainSetter(enumerator, _list, list);
}

ZHLinkedList *ZHLinkedListEnumeratorGetList(ZHLinkedListEnumerator *enumerator) {
    ZHReturnValueIfCondition(enumerator, 0);
    
    return enumerator->_list;
}

void ZHLinkedListEnumeratorSetNode(ZHLinkedListEnumerator *enumerator, ZHLinkedListNode *node) {
    ZHObjectRetainSetter(enumerator, _node, node);
}

ZHLinkedListNode *ZHLinkedListEnumeratorGetNode(ZHLinkedListEnumerator *enumerator) {
    ZHReturnValueIfCondition(!enumerator, 0);
    
    return enumerator->_node;
}

void ZHLinkedListEnumeratorSetMutationsCount(ZHLinkedListEnumerator *enumerator, uint64_t mutationsCount) {
    ZHObjectAssignSetter(enumerator, _mutationsCount, mutationsCount)
}

uint64_t ZHLinkedListEnumeratorGetMutationsCount(ZHLinkedListEnumerator *enumerator) {
    ZHReturnValueIfCondition(!enumerator, 0);
    
    return enumerator->_mutationsCount;
}

void ZHLinkedListEnumeratorSetValid(ZHLinkedListEnumerator *enumerator, bool isValid) {
    if (enumerator) {
        enumerator->_isValid = isValid;
    }
}

bool ZHLinkedListEnumeratorMutationsValidate(ZHLinkedListEnumerator *enumerator) {
    if (ZHLinkedListEnumeratorIsValid(enumerator)) {
        ZHLinkedList *list = ZHLinkedListEnumeratorGetList(enumerator);
        assert(ZHLinkedListGetMutationsCount(list) == ZHLinkedListEnumeratorGetMutationsCount(enumerator));
        
        return true;
    }
    
    return false;
}
