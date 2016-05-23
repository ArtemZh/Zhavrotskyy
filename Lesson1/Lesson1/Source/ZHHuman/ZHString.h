//
//  ZHString.h
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 16.05.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#ifndef ZHString_h
#define ZHString_h

#include "ZHObject.h"

typedef struct ZHString ZHString;
struct ZHString {
    ZHObject _super;
    
    char *_value;
};

extern
void __ZHStringDeallocate(void *object);

extern
ZHString *ZHStringCreate(char *value);

extern
size_t ZHStringGetStringLength(char *string);

extern
ZHString *ZHStringCopy(ZHString *string);

extern
char *ZHStringGetString (ZHString *string);

#endif /* ZHString_h */
