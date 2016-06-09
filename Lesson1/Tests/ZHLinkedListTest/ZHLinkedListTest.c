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
    
    ZHString *String1 = ZHStringCreate("Test1");
    ZHLinkedListAddObject(linkedList, String1);
    
    ZHString *String2 = ZHStringCreate("Test2");
    ZHLinkedListAddObject(linkedList, String2);
    
    ZHString *String3 = ZHStringCreate("Test3");
    ZHLinkedListAddObject(linkedList, String3);
    
    ZHString *String4 = ZHStringCreate("Test4");
    ZHLinkedListAddObject(linkedList, String4);
    
    ZHString *String5 = ZHStringCreate("Test5");
    ZHLinkedListAddObject(linkedList, String5);

    printf("LinkedListGetCount %llu  \n", ZHLinkedListGetCount(linkedList));
    
    ZHObject *first = ZHLinkedListGetFirstObject(linkedList);
    ZHObject *second = ZHLikedListGetPreviousObject (linkedList, String1);
    ZHObject *object = ZHLinkedListGetNextObject(linkedList, String1);
    
    printf("%s \n", (ZHLinkedListContainsObject(linkedList, String1))? "Yes" :"No");
    printf("%s \n", (ZHLinkedListContainsObject(linkedList, String2))? "Yes" :"No");
    printf("A the first object is equal to the previous two? %s \n",first == second ? "Yes" :"No, error" );
    printf("A the first object is equal to the previous two? %s \n",first == object ? "Yes" :"No, error" );
    puts("end Test");
    
    
    
}



