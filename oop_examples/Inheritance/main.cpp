#include <iostream>
#include "student.h"
#include "teacher.h"
#include<vector>

using namespace std;

void all_say_hi(vector<Person*> allperson) {
    for(Person* p: allperson){ // for x in allPerson:
        p->introduce();
        if(p->getType() == "Teacher"){
            //cout << p->getName()<<endl;
           // Student s = static_cast<Student*>(p);
        }
        // p.study()    // 會報錯
        // p.teacher() // 會報錯
    }
}

// 測試
int main() {
    Student* s = new Student("Alice", 16, 1001);
    Teacher* t = new Teacher("Bob", 35, "Math");

    s->introduce();  // 繼承自 Person
    s->study();      // 自己的方法
    cout<<s->getType()<<endl;

    t->introduce();  // 繼承自 Person
    t->teach();      // 自己的方法
    cout<<t->getType()<<endl;

    vector<Person*> allperson = {};

    allperson.push_back(s);
    allperson.push_back(t);

    all_say_hi(allperson);

    return 0;
}
