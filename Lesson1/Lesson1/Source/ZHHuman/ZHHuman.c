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
        free(human->_name);
        human->_name = NULL;
        
        if (name) {
            human->_name = strdup(name);
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
    return (!human) ? ZHHumanGenderNotDefined : human->_gender;
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
    
    if (ZHHumanGetPartner(human) != human) {
        ZHObjectRelease(human->_partner);
        human->_partner = partner;
        ZHObjectRetain(partner);
    }
}

void ZHHumanSetWeakPartner(ZHHuman *human, ZHHuman *partner) {
    if (!human) {
        return;
    }
    
    if (ZHHumanGetPartner(human) != human) {
        human->_partner = partner;
    }
}

void ZHHumanSetSpouse(ZHHuman *human, ZHHuman *partner) {
    if (ZHHumanGetGender(human) != ZHHumanGenderNotDefined ) {
        return;
    }
    
    if (ZHHumanGetGender(human) == ZHHumanGenderMale) {
        ZHHumanSetStrongPartner(human, partner);
    } else {
        ZHHumanSetWeakPartner(human, partner);
    }
}
