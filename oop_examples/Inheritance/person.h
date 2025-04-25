#pragma once

#include<string>
#include<iostream>

using namespace std;

// 父類：Person
class Person {
protected:
    string name;
    int age;
    string type;

public:
    Person(string name, int age, string type){
        this->age = age;
        this->name = name;
        this->type = type;
    }

    string getType(){
        return this->type;
    }

    string getName(){
        return this->name;
    }

    void introduce() {
        cout << "Hi, I am " << name << ", and I am " << age << " years old." << endl;
    }
};