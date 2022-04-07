//
// Created by Damian Bukowski on 22.10.2020.
//

#ifndef BST_FUNCTIONS_H
#define BST_FUNCTIONS_H

#include<stdio.h>
#include<iostream>

template<class T>
class BST{
    struct node{
        T value;
        struct node* right;
        struct node* left;
    };
private:
    struct node* root;
    int treeSize;
    void add(struct node** node, T val);
    bool lookup(struct node* node);
    void printPreOrder(struct node* node);
    void printInOrder(struct node* node);
    void printPostOrder(struct node* node);
    void deleteTree(struct node* node);
public:
    BST();
    ~BST();
    void add(T val);
    void printPreOrder();
    void printInOrder();
    void printPostOrder();
    int size();
    bool lookup(T val);
};

template<class T>
BST<T>::BST(){
    this->root = nullptr;
    this->treeSize = 0;
}

template<class T>
BST<T>::~BST(){
    deleteTree(this->root);
}

template<class T>
int BST<T>::size(){
    return this->treeSize;
}

template<class T>
void BST<T>::add(T val){
    add(&(this->root), val);
}

template<class T>
void BST<T>::add(struct node** node, T val){
    if(*node == nullptr){
        struct node* tmp = new struct node;
        tmp->value = val;
        tmp->left = nullptr;
        tmp->right = nullptr;
        *node = tmp;

        this->treeSize++;
    } else {
        if(val > (*node)->value){
            add(&(*node)->right, val);
        } else {
            add(&(*node)->left, val);
        }
    }
}

template<class T>
void BST<T>::printInOrder(){
    printInOrder(this->root);
    std::cout << std::endl;
}

template<class T>
void BST<T>::printInOrder(struct node* node){
    if(node != nullptr){
        printInOrder(node->left);
        std::cout << node->value << " ";
        printInOrder(node->right);
    }
}

template<class T>
void BST<T>::printPreOrder(){
    printPreOrder(this->root);
    std::cout << std::endl;
}

template<class T>
void BST<T>::printPreOrder(BST<T>::node *node){
    if(node !=nullptr){
        printPreOrder(node->left);
        std::cout << std::endl;
        printPreOrder(node->right);
    }
}

#endif //BST_FUNCTIONS_H
