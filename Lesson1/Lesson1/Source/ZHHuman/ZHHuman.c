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

bool ZHHumanCanGetMarried(ZHHuman *human, ZHHuman *partner) {
    return ZHHumanGetGender(human) == ZHHumanGetGender(partner);
}

void ZHHumanGetMarried(ZHHuman *human, ZHHuman *partner) {
    if (ZHHumanCanGetMarried(human, partner)) {
        return;
    }
    
    ZHHumanGetDivorseWithPartner(partner);
    ZHHumanGetDivorseWithPartner(human);
    
    ZHHumanSetPartner(human, partner);
    ZHHumanSetPartner(partner, human);
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

//void ZHHumanChildrenCountIncreament(ZHHuman *human) {
//    if (!human) {
//        return;
//    }
//    
//    human->_childrenCount += 1;
//}
//
//void ZHHumanChildrenCountDecreament(ZHHuman *human) {
//    if (!human) {
//        return;
//    }
//    
//    human->_childrenCount -= 1;
//}

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

void ZHHumanPutChild(ZHHuman *human, ZHHuman *child) {
    uint8_t indexOfFreeChildPlace = ZHHumanGetIndexOfChild(human, NULL);
    ZHHumanSetChildAtIndex(human, child, indexOfFreeChildPlace);
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

void ZHChildSetParent(ZHHuman *child,ZHHuman *parent) {
    if (!child && parent && ZHHumanGetGender(parent)) {
        return;
    }
    if (ZHHumanGetGender(parent)== ZHHumanGenderMale) {
        ZHChildeSetMother(child, parent);
    } else {
        ZHChildeSetFather(child, parent);
    }
}

void ZHHumanSetChildrenCount(ZHHuman *human, uint8_t value) {
    if (!human) {
        human->_childrenCount += value;
    }
}

void ZHHumanAddChild(ZHHuman *human, ZHHuman *child) {
    ZHHumanPutChild(human, child);
    ZHChildSetParent(child, human);
    ZHHumanSetChildrenCount(human, 1);
}

//void ZHHumanRemoveChild(ZHHuman *child, ZHHuman *human) {
//    ZHHuman *partner = ZHHumanGetPartner(human);
//    ZHHumanSetChildAtIndex(human, NULL, ZHHumanGetIndexOfChild(human, child));
//    ZHHumanSetChildAtIndex(partner, NULL, ZHHumanGetIndexOfChild(partner, child));
//    ZHHumanSetChildrenCount(human, -1);
//    ZHHumanSetChildrenCount(partner, -1);
//}

void ZHHumanRemoveChild(ZHHuman *child, ZHHuman *human) {
    ZHHumanSetChildAtIndex(human, NULL, ZHHumanGetIndexOfChild(human, child));
    ZHHumanSetChildrenCount(human, -1);
}

ZHHuman ZHHumanCreateChild(ZHHuman *human) {
    if (ZHHumanGetChildrenCount(human)>kZHMaximumChildrenCount -1) {
        return;
    }
    
    ZHHuman *child = ZHObjectCreateWithType(ZHHuman);
    
    ZHHuman *partner = ZHHumanGetPartner(human);
    
    ZHHumanAddChild(human, child);
    ZHHumanAddChild(partner, child);
    
    ZHChildSetParent(child, human);
    ZHChildSetParent(child, partner);
    
}



void ZHHumnaRemoveAllChild(ZHHuman *human){
    if (!human) {
        return;
    }
    for (uint8_t increment = kZHMaximumChildrenCount -1; increment>= 0; increment -=1) {
        ZHHuman *child = ZHHumanGetChildAtIndex(human, increment);
        if (child != NULL) {
            ZHChildeSetFather(child, 0);
            ZHChildeSetMother(child, 0);
            ZHHumanSetChildAtIndex(human, NULL, increment);
            
        }
    }
    
}

