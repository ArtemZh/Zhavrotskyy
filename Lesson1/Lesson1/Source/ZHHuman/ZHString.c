//
//  ZHString.c
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 16.05.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//
#include <string.h>
#include <assert.h>

#include "ZHString.h"

static
void ZHStringSetValue(ZHString *string, char *value);

void __ZHStringDeallocate(void *object) {
    ZHStringSetValue(object, NULL);
    __ZHObjectDeallocate(object);
}

ZHString *ZHStringCreate(char *value) {
    ZHString *string = ZHObjectCreateWithType(ZHString);
    ZHStringSetValue(string, value);
    
    return string;
}

void ZHStringSetValue(ZHString *string, char *value) {
    if (string && string->_value != value) {
            if (string->_value) {
                free(string->_value);
                string->_value = NULL;
            }
            
            if (value) {
                size_t fieldSize = strlen(value)+ 1;
                string->_value = malloc(fieldSize);
                memmove(string->_value, value, fieldSize); //strcpy
            }
    }
    
}

size_t ZHStringGetStringLength(char *string) {
    return (!string) ? 0 : strlen(string);
}

char *ZHStringGetString (ZHString *string) {
    return (!string) ? NULL : string->_value; ///?
}

ZHString *ZHStringCopy(ZHString *string) {
    if (!string) {
        return NULL;
    }
    
    char *charString = ZHStringGetString(string);
    
    return ZHStringCreate(charString);
}
