#pragma once

#include<string>
#include<iostream>

using namespace std;

// 父類：Person
class Person {
protected:
    string name;
    int age;

public:
    Person(string name, int age) : name(name), age(age) {}

    void introduce() {
        cout << "Hi, I am " << name << ", and I am " << age << " years old." << endl;
    }
};