//
// Created by AILEE on 2022/3/23.
//

#include "Person.h"

Person::Person() :
    m_age(0),
    m_name("No Name"){

}

void Person::setName(std::string name) {
    this->m_name = name;
}

void Person::setAge(int age) {
    this->m_age = age;
}

std::string Person::getName() {
    return this->m_name;
}

int Person::getAge() {
    return this->m_age;
}
