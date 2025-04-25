#pragma once

#include <iostream>

template <typename Key, typename Value>
class IBST {
public:
    virtual ~IBST() {}

    // 資訊查詢
    virtual int size() const = 0;
    virtual bool isEmpty() const = 0;
    virtual bool contain(Key key) const = 0;
    virtual Value* search(Key key) const = 0;

    // 基本操作
    virtual void insert(Key key, Value value) = 0;
    virtual void remove(Key key) = 0;
    virtual void removeMin() = 0;
    virtual void removeMax() = 0;

    // 最值
    virtual Key minimum() const = 0;
    virtual Key maximum() const = 0;

    // 遍歷
    virtual void preOrder() const = 0;
    virtual void inOrder() const = 0;
    virtual void postOrder() const = 0;
    virtual void levelOrder() const = 0;
};

