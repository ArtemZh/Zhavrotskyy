//
//  ZHLinkedListTest.c
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 06.06.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include <stdio.h>

#include "ZHLinkedList.h"
#include "ZHLinkedListEnumerator.h"
#include "ZHObject.h"
#include "ZHString.h"

#include "ZHLinkedListTest.h"

void ZHLinkedListTest() {
    ZHLinkedList *linkedList = ZHObjectCreateWithType(ZHLinkedList);
    
    ZHString *String1 = ZHStringCreate("Test");
    ZHLinkedListAddObject(linkedList, String1);
    
    ZHString *String2 = ZHStringCreate("Test");
    ZHLinkedListAddObject(linkedList, String2);
    
    ZHString *String3 = ZHStringCreate("Test");
    ZHLinkedListAddObject(linkedList, String3);
    
    ZHString *String4 = ZHStringCreate("Test");
    ZHLinkedListAddObject(linkedList, String4);
    
    ZHString *String5 = ZHStringCreate("Test");
    ZHLinkedListAddObject(linkedList, String5);

    printf("%llu \n", ZHLinkedListGetCount(linkedList));
    
    ZHObject *first = ZHLinkedListGetFirstObject(linkedList);
    ZHObject *second = ZHLikedListGetPreviousObject (linkedList, String2);
    printf(" %s \n",first == second ? "good" :" error" );
}



