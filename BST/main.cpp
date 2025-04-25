#include<iostream>
#include<string>
//#include "MyBST.h"
#include "BSTAns.h"

using namespace std;

int main(){
    IBST<int, string>* tree =  new BST<int, string>();
    tree->insert(10, "A");
    tree->insert(20, "B");
    tree->inOrder();        // 應該是排序好的
}