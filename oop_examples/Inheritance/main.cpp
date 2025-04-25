#include <iostream>
#include "student.h"
#include "teacher.h"
#include<vector>

using namespace std;

void all_say_hi(vector<Person> allperson) {
    for(auto p: allperson){
        p.introduce();
        // p.study()    // 會報錯
        // p.teacher() // 會報錯
    }
}

// 測試
int main() {
    Student s("Alice", 16, 1001);
    Teacher t("Bob", 35, "Math");

    s.introduce();  // 繼承自 Person
    s.study();      // 自己的方法

    t.introduce();  // 繼承自 Person
    t.teach();      // 自己的方法

    vector<Person> allperson = {};

    allperson.push_back(s);
    allperson.push_back(t);

    all_say_hi(allperson);

    return 0;
}
