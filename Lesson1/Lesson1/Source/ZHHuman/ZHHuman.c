//
//  ZHHuman.c
//  Lesson1
//
//  Created by Artem Zhavrotskiy on 26.04.16.
//  Copyright © 2016 Artem Zhavrotskiy. All rights reserved.
//

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#include "ZHHuman.h"
#include "ZHObject.h"

#pragma mark -
#pragma mark Private declaration

static
void ZHHumanSetStrongPartner(ZHHuman *human, ZHHuman *partner);

static
void ZHHumanSetWeakPartner(ZHHuman *human, ZHHuman *partner);

static
uint8_t ZHHumanGetTrueIndexOfChild(ZHHuman *human, uint8_t index);

#pragma mark -
#pragma mark Public Implementations

void ZHHumanSetName(ZHHuman *human, char *name) {
    if (human) {
        if (human->_name != name ) {
            if (human->_name) {
                free(human->_name);
                human->_name = NULL;
            }
            
            if (name) {
                human->_name = strdup(name);
            }
        }
    }
    
}

char *ZHHumanGetName(ZHHuman *human) {
    return (!human) ? NULL : human->_name;
}

void ZHHumanSetAge(ZHHuman *human, uint8_t age) {
    if (!human) {
        return;
    }
    
    human->_age = age;
}

uint8_t ZHHumanGetAge(ZHHuman *human){
    return (!human) ? 0 : human->_age;
}

void ZHHumanSetGender(ZHHuman *human, ZHHumanGender gender) {
    if (!human) {
        return;
    }
    
    human->_gender = gender;
}

ZHHumanGender ZHHumanGetGender(ZHHuman *human) {
    return (!human) ? ZHHumanGenderUndefined : human->_gender;
}

ZHHuman *ZHHumanGetPartner(ZHHuman *human){
    return (!human) ? NULL : human->_partner;
}

ZHHuman *ZHHumanGetMother(ZHHuman *human){
    return (!human) ? NULL : human->_mother;
}

ZHHuman *ZHHumanGetFather(ZHHuman *human){
    return (!human) ? NULL : human->_partner;
}

uint32_t ZHHumanGetChildrenCount(ZHHuman *human) {
    return human->_childrenCount;
}

#pragma mark -
#pragma mark Private Implementations

void ZHHumanSetStrongPartner(ZHHuman *human, ZHHuman *partner) {
    if (human && human->_partner != human) {
        ZHObjectRelease(human->_partner);
        human->_partner = partner;
        ZHObjectRetain(partner);
    }
}

void ZHHumanSetWeakPartner(ZHHuman *human, ZHHuman *partner) {
    if (human && human->_partner != human) {
        human->_partner = partner;
    }
}

void ZHHumanSetPartner(ZHHuman *human, ZHHuman *partner) {
    if (ZHHumanGetGender(human) != ZHHumanGenderUndefined ) {
        return;
    }
    
    switch (ZHHumanGetGender(human)) {
        case ZHHumanGenderMale:
            ZHHumanSetStrongPartner(human, partner);
            break;
            
        case ZHHumanGenderFemale:
            ZHHumanSetWeakPartner(human, partner);
            break;
            
        default:
            break;
    }
}

void ZHHumanGetDivorced(ZHHuman *human) {
    ZHHuman *partner = ZHHumanGetPartner(human);
    ZHHumanSetPartner(human, NULL);
    ZHHumanSetPartner(partner, NULL);
}

bool ZHHumanCanGetMarried(ZHHuman *human, ZHHuman *partner) {
    return ZHHumanGetGender(human) != ZHHumanGetGender(partner);
}

void ZHHumanGetMarried(ZHHuman *human, ZHHuman *partner) {
    if (ZHHumanCanGetMarried(human, partner)) {
        return;
    }
    
    ZHHumanGetDivorced(partner);
    ZHHumanGetDivorced(human);
    
    ZHHumanSetPartner(human, partner);
    ZHHumanSetPartner(partner, human);
}

uint8_t ZHHumanGetChildCount(ZHHuman *human){
    return (!human) ? 0 : human->_childrenCount;
}

ZHHuman *__ZHHumanGetChildAtIndex(ZHHuman *human, uint8_t index){
    if (!human) {
        return NULL;
    }
    
    return human->_children[index];
}

ZHHuman *ZHHumanGetChildAtIndex(ZHHuman *human, uint8_t index) {
    uint8_t trueIndex = ZHHumanGetTrueIndexOfChild(human, index);
    return human->_children[trueIndex];
}

uint8_t __ZHHumanGetIndexOfChild(ZHHuman *human, ZHHuman *child) {
    for (uint8_t increment = 0; increment < kZHMaximumChildrenCount ; increment += 1) {
        if (__ZHHumanGetChildAtIndex(human, increment) == child) {
            return increment;
        }
    }
    
    return kZHIndexNotFound;
}

uint8_t ZHHumanGetIndexOfChild(ZHHuman *human, ZHHuman *child) {
    uint8_t trueIndex = 0;
    uint8_t index = __ZHHumanGetIndexOfChild(human, child);
    for (uint8_t increment = 0; increment < kZHMaximumChildrenCount ; increment += 1) {
        if (__ZHHumanGetChildAtIndex(human, increment) != NULL) {
            trueIndex += 1;
            if (trueIndex == index) {
                break;
            }
        }
    }
    
    return  trueIndex;
}



void __ZHHumanSetChildAtIndex(ZHHuman *human, ZHHuman *child, uint8_t index) {
    if (!human || human->_children[index] != child) {
        return;
    }
    
    ZHObjectRelease(human->_children[index]);
    human->_children[index] = child;
    ZHObjectRetain(child);
    
}

void ZHHumanSetChildAtIndex(ZHHuman *human, ZHHuman *child, uint8_t index) {
    uint8_t trueIndex = ZHHumanGetTrueIndexOfChild(human, index);
    __ZHHumanSetChildAtIndex(human, child, trueIndex);
}

uint8_t ZHHumanGetTrueIndexOfChild(ZHHuman *human, uint8_t index) {
    uint8_t trueIndex = 0;
    for (uint8_t increment = 0; trueIndex != index ||increment < kZHMaximumChildrenCount ; increment += 1) {
        if (__ZHHumanGetChildAtIndex(human, increment)) {
            trueIndex += 1;
        }
    }
    
    return trueIndex;
}

void ZHHumanAppendChild(ZHHuman *human, ZHHuman *child) {
    uint8_t index = __ZHHumanGetIndexOfChild(human, NULL);
    __ZHHumanSetChildAtIndex(human, child, index);
}

void ZHChildeSetFather(ZHHuman *child, ZHHuman *father) {
    if (!child && father) {
        return;
    }
    
    if (child->_father != father) {
        child->_father = father;
    }
}

void ZHChildeSetMother(ZHHuman *child, ZHHuman *mother) {
    if (!child && mother) {
        return;
    }
    
    if (child->_mother != mother) {
        child->_mother = mother;
    }
}

void ZHHumanSetParent(ZHHuman *human,ZHHuman *parent, ZHHumanGender parentGender) {
    if (ZHHumanGenderUndefined) {
        return;
    }
    if (ZHHumanGetGender(parent)== ZHHumanGenderMale) {
        ZHChildeSetMother(human, parent);
    } else {
        ZHChildeSetFather(human, parent);
    }
}

void ZHHumanSetChildrenCount(ZHHuman *human, uint8_t value) {
    if (!human) {
        human->_childrenCount += value;
    }
}

void ZHHumanAddChild(ZHHuman *human, ZHHuman *child) {
    ZHHumanAppendChild(human, child);
    ZHHumanSetParent(child, human, ZHHumanGetGender(human));
    ZHHumanSetChildrenCount(human, 1);
}

//void ZHHumanRemoveChild(ZHHuman *child, ZHHuman *human) {
//    ZHHuman *partner = ZHHumanGetPartner(human);
//    __ZHHumanSetChildAtIndex(human, NULL, __ZHHumanGetIndexOfChild(human, child));
//    __ZHHumanSetChildAtIndex(partner, NULL, __ZHHumanGetIndexOfChild(partner, child));
//    ZHHumanSetChildrenCount(human, -1);
//    ZHHumanSetChildrenCount(partner, -1);
//}

void ZHHumanRemoveChild(ZHHuman *child, ZHHuman *human) {
    __ZHHumanSetChildAtIndex(human, NULL, __ZHHumanGetIndexOfChild(human, child));
    ZHHumanSetChildrenCount(human, -1);
}

void ZHHumanRemoveAllChild(ZHHuman *human){
    if (!human) {
        return;
    }
    
    for (uint8_t increment = 0; increment < kZHMaximumChildrenCount; increment += 1) {
        ZHHuman *child = __ZHHumanGetChildAtIndex(human, kZHMaximumChildrenCount - increment);
        if (child != NULL) {
        ZHHumanSetParent(child, human, ZHHumanGetGender(human));
        __ZHHumanSetChildAtIndex(human, NULL, kZHMaximumChildrenCount - increment);
            
        }
    }
}

void __ZHHumanDeallocate(void *human) {
    ZHHumanGetDivorced(human);
    ZHChildeSetMother(human, NULL);
    ZHChildeSetFather(human, NULL);
    ZHHumanRemoveAllChild(human);
    
    __ZHHumanDeallocate(human);
}

ZHHuman *ZHHumanCreateChild(ZHHuman *human) {
    if (ZHHumanGetChildrenCount(human)>kZHMaximumChildrenCount -1) {
        return NULL;
    }
    
    ZHHuman *child = ZHObjectCreateWithType(ZHHuman);
    
    ZHHuman *partner = ZHHumanGetPartner(human);
    
    ZHHumanAddChild(human, child);
    ZHHumanAddChild(partner, child);
    
    ZHHumanSetParent(child, human, ZHHumanGetGender(human));
    ZHHumanSetParent(child, partner, ZHHumanGetGender(partner));
    
    return child;
    
}

ZHHuman *ZHCreatHuman(void) {
    ZHHuman *human = ZHObjectCreateWithType(ZHHuman);
    
    return human;
}
