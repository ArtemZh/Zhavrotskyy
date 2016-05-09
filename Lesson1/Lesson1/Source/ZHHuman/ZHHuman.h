//
//  ZHHuman.h
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 26.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#ifndef ZHHuman_h
#define ZHHuman_h

#include <stdbool.h>
#include <stdio.h>

#include "ZHObject.h"

typedef enum {
    ZHHumanGenderUndefined,
    ZHHumanGenderMale,
    ZHHumanGenderFemale
} ZHHumanGender;

static const uint8_t kZHMaximumChildrenCount = 20;

typedef struct ZHHuman ZHHuman;
struct ZHHuman {
    uint64_t _referenceCount;
    
    char *_name;
    uint8_t _age;
    ZHHumanGender _gender;
    
    uint8_t _childrenCount;
    ZHHuman *_children[kZHMaximumChildrenCount];
    
    ZHHuman *_partner;
    ZHHuman *_mother;
    ZHHuman *_father;
};

extern
void ZHHumanSetName(ZHHuman *human, char *name);

extern
char *ZHHumanGetName(ZHHuman *human);

extern
void ZHHumanSetAge(ZHHuman *human, uint8_t age);

extern
uint8_t ZHHumanGetAge(ZHHuman *human);

extern
void ZHHumanSetGender(ZHHuman *human, ZHHumanGender gender);

extern
ZHHumanGender ZHHumanGetGender(ZHHuman *human);

extern
ZHHuman *ZHHumanGetPartner(ZHHuman *human);

extern
ZHHuman *ZHHumanGetMother(ZHHuman *human);

extern
ZHHuman *ZHHumanGetFather(ZHHuman *human);

extern
uint32_t ZHHumanGetChildrenCount(ZHHuman *human);




#endif /* ZHHuman_h */
