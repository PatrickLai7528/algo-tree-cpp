#pragma once

#include<iostream>
#include "person.h"
using namespace std;

// 子類：Teacher
class Teacher : public Person {
    private:
        string subject;
    
    public:
        Teacher(string name, int age, string subject)
            : Person(name, age, "Teacher"), subject(subject) {}
    
        void teach() {
            cout << name << " is teaching " << subject << "." << endl;
        }
    };