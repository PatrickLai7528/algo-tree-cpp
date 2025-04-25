#include<iostream>
#include<string>
#include "AVL.h"

using namespace std;

void insert(IBST<int, string>* tree){
    tree->insert(10, "A");
    tree->insert(20, "B");
    tree->insert(30, "C");  // 應該觸發Ll旋轉
    //tree->insert(25, "D");  // 應該觸發RL旋轉
    tree->inOrder();        // 應該是排序好的
}

int main(){
    insert(new AVLTree<int, string>());
}