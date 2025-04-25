#pragma once

#include<iostream>
#include "person.h"

using namespace std;

// 子類：Student
class Student : public Person {
    private:
        int studentID;
    
    public:
        Student(string name, int age, int studentID)
            : Person(name, age, "Student"), studentID(studentID) {}
    
        void study() {
            cout << name << " is studying." << endl;
        }
    };