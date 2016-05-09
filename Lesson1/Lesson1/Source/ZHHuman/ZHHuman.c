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



#pragma mark -
#pragma mark Public Implementations


void ZHHumanSetName(ZHHuman *human, char *name) {
    if (human && human->_name) {
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
    if (!human) {
        return;
    }
    
    if (human->_partner != human) {
        ZHObjectRelease(human->_partner);
        human->_partner = partner;
        ZHObjectRetain(partner);
    }
}

void ZHHumanSetWeakPartner(ZHHuman *human, ZHHuman *partner) {
    if (!human) {
        return;
    }
    
    if (human->_partner != human) {
        human->_partner = partner;
    }
}

void ZHHumanSetPartner(ZHHuman *human, ZHHuman *partner) {
    if (ZHHumanGetGender(human) != ZHHumanGenderUndefined ) {
        return;
    }
    
    if (ZHHumanGetGender(human) == ZHHumanGenderMale) {
        ZHHumanSetStrongPartner(human, partner);
    } else {
        ZHHumanSetWeakPartner(human, partner);
    }
}

void ZHHumanGetDivorseWithPartner(ZHHuman *human) {
    ZHHuman *partner = ZHHumanGetPartner(human);
    ZHHumanSetPartner(human, NULL);
    ZHHumanSetPartner(partner, NULL);
}

void ZHHumanGetMarried(ZHHuman *human, ZHHuman *partner) {
    if (ZHHumanGetGender(human) == ZHHumanGetGender(partner)) {
        return;
    }
    
    if (ZHHumanGetPartner(human) != ZHHumanGetPartner(partner)) {
        return;
    }
    
    ZHHumanSetPartner(human, partner);
}

uint8_t ZHHumanGetCountOfChildren(ZHHuman *human){
    return human->_childrenCount;
}

ZHHuman *ZHHumanGetChildAtIndex(ZHHuman *human, uint8_t index){
 return human->_children[index];
}

uint8_t ZHHumanGetIndexOfChild(ZHHuman *human, ZHHuman *child) {
    for (uint8_t increment = 0; increment < kZHMaximumChildrenCount ; increment +=1) {
        if (ZHHumanGetChildAtIndex(human, increment) == child) {
            return increment;
            break;
        }
    }
    return kZHIndexNotFound;
}

void ZHHumanChildrenCountIncrement(ZHHuman *human, uint8_t count) {
    if (!human) {
        return;
    }
    
    human->_childrenCount += count;
}

void ZHHumanSetChildAtIndex(ZHHuman *human, ZHHuman *child, uint8_t index) {
    if (!human) {
        return;
    }
    if (ZHHumanGetChildAtIndex(human, index) != child) {
        ZHObjectRelease(human->_children[index]);
        human->_children[index] = child;
        ZHObjectRetain(child);
    }
}

void ZHHumanAddChild(ZHHuman *human, ZHHuman *child) {
    uint8_t indexOfFreeChildPlace = ZHHumanGetIndexOfChild(human, NULL);
    ZHHumanSetChildAtIndex(human, child, indexOfFreeChildPlace);
}


