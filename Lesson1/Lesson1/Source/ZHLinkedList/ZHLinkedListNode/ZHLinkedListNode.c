//
//  ZHLinkedListNode.c
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 24.05.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include <assert.h>


#include "ZHLinkedListNode.h"


void __ZHLinkedListNodeDeallocate(void *object) {
    ZHLinkedListNodeSetObject(object, NULL);
    ZHLinkedListNodeSetNextNode(object, NULL);
    
    __ZHObjectDeallocate(object);
}

ZHLinkedListNode *ZHLinkedListNodeCreateWithObject(void *object) {
    ZHLinkedListNode *result = ZHObjectCreateWithType(ZHLinkedListNode);
    ZHLinkedListNodeSetObject(result, object);
    
    return result;
}

ZHLinkedListNode *ZHLinkedListNodeGetNextNode(ZHLinkedListNode *node) {
    ZHReturnValueIfCondition(!node, NULL);
    
    return node->_nextNode;
}

void ZHLinkedListNodeSetNextNode(ZHLinkedListNode *node, ZHLinkedListNode *nextNode) {
    ZHReturnValueIfCondition(!node, ZHEmpty);
    
    ZHLinkedListNode *previousNode = node->_nextNode;
    
    if (node && nextNode != previousNode) {
        ZHObjectRelease(previousNode);
        
        node->_nextNode = ZHObjectRetain(nextNode);
    }
}

void *ZHLinkedListNodeGetObject(ZHLinkedListNode *node) {
    ZHReturnValueIfCondition(!node, NULL);
    
    return  node->_object;
}

void ZHLinkedListNodeSetObject(ZHLinkedListNode *node, void *object) {
    ZHReturnValueIfCondition(!node, ZHEmpty);
    
    ZHLinkedListNode *previousObject = node->_object;
    
    if (node && object != previousObject && node != object) {
        ZHObjectRelease(previousObject);
        
        node->_object = ZHObjectRetain(object);
    }
}
