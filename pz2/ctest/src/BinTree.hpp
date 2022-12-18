#pragma once

#include <iostream>

using namespace std;

template <typename T>
class BinTree {
private:
    T data;
    BinTree* lNode;
    BinTree* rNode;
public:
    BinTree(): data(0), lNode(nullptr), rNode(nullptr) {}
    explicit BinTree(T val): lNode(nullptr), rNode(nullptr) {
        this->data = val;
    }

    inline T getData() const { return this->data; }

    BinTree* Insert(BinTree* rootPtr, T data);
    bool Search(BinTree* rootPtr, T data);
    BinTree* Delete(BinTree* rootPtr, T data);
    BinTree<T>* FindMin(BinTree* rootPtr);
    BinTree<T>* FindMax(BinTree* rootPtr);

    void print(BinTree* rootPtr, int flag);
    bool is_empty(BinTree* rootPtr);
    void Terminate(BinTree* rootPtr);
};

template <typename T>
BinTree<T>* BinTree<T>::Insert(BinTree<T>* rootPtr, T data) {
    if(rootPtr == nullptr) {
        rootPtr = new BinTree<T>(data);
        return rootPtr;
    }

    if(data < rootPtr->data) {
        rootPtr->lNode = Insert(rootPtr->lNode, data);
    } else {
        rootPtr->rNode = Insert(rootPtr->rNode, data);
    }

    return rootPtr;
};

template <typename T>
bool BinTree<T>::Search(BinTree<T>* rootPtr, T data) {
    if(rootPtr == nullptr) return false;
    else if(rootPtr->data == data) return true;
    else if (data < rootPtr->data) return Search(rootPtr->lNode, data);
    else return Search(rootPtr->rNode, data);
}

template <typename T>
BinTree<T>* BinTree<T>::Delete(BinTree<T>* rootPtr, T data) {
    if(rootPtr == nullptr) return nullptr;
    else if(data < rootPtr->data) rootPtr->lNode = Delete(rootPtr->lNode, data);
    else if(data > rootPtr->data) rootPtr->rNode = Delete(rootPtr->rNode, data);
    else {
        if(rootPtr->lNode == nullptr && rootPtr->rNode == nullptr)  {
            delete rootPtr;
            rootPtr = nullptr;
        }
        else if(rootPtr->lNode == nullptr) {
            BinTree<T>* temp = rootPtr;
            rootPtr = rootPtr->rNode;
            delete temp;
        }
        else if(rootPtr->rNode == nullptr) {
            BinTree<T>* temp = rootPtr;
            rootPtr = rootPtr->lNode;
            delete temp;
        }
        else {
            BinTree<T>* temp = FindMin(rootPtr->rNode);
            rootPtr->data = temp->data;
            rootPtr->rNode = Delete(rootPtr->rNode, temp->data);
        }
    }
    return rootPtr;
}

template <typename T>
BinTree<T>* BinTree<T>::FindMin(BinTree<T>* rootPtr) {
    if(rootPtr == nullptr) return 0;
    else if(rootPtr->lNode == nullptr) return rootPtr;
    else return FindMin(rootPtr->lNode);
}

template <typename T>
BinTree<T>* BinTree<T>::FindMax(BinTree<T>* rootPtr) {
    if(rootPtr == nullptr) return 0;
    else if(rootPtr->rNode == nullptr) return rootPtr;
    else return FindMax(rootPtr->rNode);
}

template<typename T>
void BinTree<T>::print(BinTree<T>* rootPtr, int flag) {
    if(rootPtr == nullptr) return;

    switch(flag) {
        case 0:
            print(rootPtr->lNode, 0);
            cout << rootPtr->data << " ";
            print(rootPtr->rNode, 0);
            break;
        case 1:
            cout << rootPtr->data << " "; 
            print(rootPtr->lNode, 1);
            print(rootPtr->rNode, 1);
            break;
        case -1:
            cout << rootPtr->data << " "; 
            print(rootPtr->rNode, -1);
            print(rootPtr->lNode, -1);
        default:
            break;
    }
}

template<typename T>
bool BinTree<T>::is_empty(BinTree<T>* rootPtr) {
    if(rootPtr == nullptr) return true;
    else return false;
}

template<typename T>
void BinTree<T>::Terminate(BinTree<T>* rootPtr) {
    if(rootPtr != nullptr) {
        Terminate(rootPtr->lNode);
        Terminate(rootPtr->rNode);
        delete rootPtr;
        rootPtr = nullptr;
    }
}