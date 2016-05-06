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

//Задачи:
//1. Создать объектную структуру данных человек, имеющую поля имя, возраст, пол, количество детей, женат или нет, указатель на партнера, на родителей и на массив с детьми, где могло бы быть, максимум, 20 детей.
//Требования:
//- каждая из сущностей, будь то строка или массив, должны быть обернуты в свой объект, который, как минимум, умел бы выполнять подсчет ссылок и имел базовые аксессоры и тесты;
//- реализовать подсчет ссылок, геттеры и сеттеры для полей;
//- реализовать метод жениться, который бы устанавливал поле женат в true и указатель на партнера, с которым был брак;
//- реализовать метод развестись, который бы устанавливал поле женат и указатель на партнера;
//- реализовать метод произвести потомство, который бы создавал ребенка, устанавливал ему родителей, а у родителей добавлял бы ребенка;
//- создать тесты на все поведение человека.




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
