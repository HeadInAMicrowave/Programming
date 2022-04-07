// Created by Damian Bukowski on 19.12.2020.
#ifndef LAB3_AVL_DICTIONARY_H
#define LAB3_AVL_DICTIONARY_H
#include <iostream>

template<typename Key, typename Info>
class Dictionary{
    struct node{
        Key vkey;
        Info vinfo;
        node* left;
        node* right;
        int height;
    };
    node* root;

    //useful methods and what not
    node* insert(const Key &vkey, const Info &vinfo, node* new_node);
    node* remove(const Key &vkey, node* temp);

    //rotations
    node* RightRotation(node* &temp);
    node* LeftRotation(node* &temp);
    void PrintInOrder(node* temp);
    void PrintPreOrder(node* temp);

    //utility function
    int getHeight(node* temp){
        if(temp == nullptr) return 0;
        return temp->height;
    };
    int getBalance(node* temp){
        if(temp == nullptr) return 0;
        return (getHeight(temp->left) - getHeight(temp->right));
    }
    int getMax(int a, int b){
        return (a > b) ? a : b;
    }
    void clear(node* &temp){
        if(temp == nullptr) return;
        clear(temp->left);
        clear(temp->right);
        delete temp;
        temp = nullptr;
    }
    node* minVal(node* temp){
        if(temp == nullptr) return nullptr;
        else if(temp->left == nullptr) return temp;
        else return minVal(temp->left);
    }

public:
    //constructor and destructor
    Dictionary(){ root = nullptr; };
    ~Dictionary(){ clear(root); };

    bool find(const Key &vkey);
    void insert(const Key& vkey, const Info& vinfo);
    void remove(const Key& vkey);
    void dispIn();
    void dispPre();

};

template<typename Key, typename Info>
bool Dictionary<Key, Info>::find(const Key &vkey){
    node* temp = root;

    while(temp){
        if(temp->vkey == vkey){
            return true;
        }

        if(vkey < temp->vkey){
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    return false;
}

template<typename Key, typename Info>
typename Dictionary<Key, Info>::node* Dictionary<Key, Info>::RightRotation(Dictionary<Key, Info>::node *&temp)
{
    node *new_temp = temp->left;
    node *careful = new_temp->right;

    new_temp->right = temp;
    temp->left = careful;

    temp->height = getMax(getHeight(temp->left),getHeight(temp->right)) + 1;

    new_temp->height = getMax(getHeight(new_temp->left), getHeight(new_temp->right)) + 1;

    return new_temp;
}

template<typename Key, typename Info>
typename Dictionary<Key, Info>::node* Dictionary<Key, Info>::LeftRotation(Dictionary<Key, Info>::node *&temp)
{
    node *new_temp = temp->right;
    node *careful = new_temp->left;

    new_temp->left = temp;
    temp->right = careful;

    temp->height = getMax(getHeight(temp->left), getHeight(temp->right)) + 1;
    new_temp->height = getMax(getHeight(new_temp->left), getHeight(new_temp->right)) + 1;

    return new_temp;
}

template<typename Key, typename Info>
void Dictionary<Key, Info>::insert(const Key& vkey, const Info& vinfo){
    root = insert(vkey,vinfo,root);
}

template<typename Key, typename Info>
typename Dictionary<Key, Info>::node* Dictionary<Key, Info>::insert(const Key &vkey, const Info &vinfo, node* new_node){
    if(new_node == nullptr){
        new_node = new node;
        new_node->vkey = vkey;
        new_node->vinfo = vinfo;
        new_node->height = 0;
        new_node->left = nullptr;
        new_node->right = nullptr;
        return new_node;
    }

    if(vkey < new_node->vkey){
        new_node->left = insert(vkey, vinfo, new_node->left);
    } else if (vkey > new_node->vkey){
        new_node->right = insert(vkey, vinfo, new_node->right);
    } else if (vkey == new_node->vkey) {
        new_node->vinfo = vinfo;

    }

    //updating height and implementing balance
    new_node->height = 1 + getMax(getHeight(new_node->left), getHeight(new_node->right));

    int balance = getBalance(new_node);

    //implementation of rotations
    if(balance > 1 && vkey < new_node->left->vkey) return RightRotation(new_node);

    if(balance < -1 && vkey < new_node->right->vkey){
        new_node->right = RightRotation(new_node->right);
        return LeftRotation(new_node);
    }
    return new_node;
}

template<typename Key, typename Info>
void Dictionary<Key, Info>::PrintInOrder(node *temp){
    if(temp == nullptr) return;
    PrintInOrder(temp->left);
    std::cout << temp->vkey << " " << temp->vinfo << " ";
    PrintInOrder(temp->right);
}

template<typename Key, typename Info>
void Dictionary<Key, Info>::PrintPreOrder(node *temp){
    if (temp != nullptr){
        std::cout << temp->vkey << " " << temp->vinfo << " ";
        PrintPreOrder(temp->left);
        PrintPreOrder(temp->right);
    }
}

template<typename Key, typename Info>
void Dictionary<Key, Info>::dispIn(){
    PrintInOrder(root);
    std::cout << std::endl;
}

template<typename Key, typename Info>
void Dictionary<Key, Info>::dispPre(){
    PrintPreOrder(root);
    std::cout << std::endl;
}

template<typename Key, typename Info>
void Dictionary<Key, Info>::remove(const Key& vkey){
    root = remove(vkey,root);
}

template<typename Key, typename Info>
typename Dictionary<Key, Info>::node* Dictionary<Key, Info>::remove(const Key& vkey, node *temp){
    if(temp == nullptr) return temp;
    if(vkey < temp->vkey) temp->left = remove(vkey, temp->left);
    else if(vkey > temp->vkey) temp->right = remove(vkey, temp->right);

    else{
        if((temp->left == nullptr) || (temp->right == nullptr)){
          node* t = temp->left ? temp->left : temp->right;

          if(t == nullptr){
              t = temp;
              temp = nullptr;
          } else {
              *temp = *t;
              delete t;
          }
        } else {
            node* t = minVal(temp->right);
            temp->vkey = t->vkey;
            temp->vinfo = t->vinfo;
            temp->right = remove(t->vkey, temp->right);
        }
    }
    if (temp == nullptr) return temp;

    temp->height = 1 + getMax(getHeight(temp->left), getHeight(temp->right));

    int balance = getBalance(temp);

    if(balance > 1 && getBalance(temp->left) >= 0) return RightRotation(temp);

    if (balance > 1 && getBalance(temp->left) < 0){
        temp->left = LeftRotation(temp->left);
        return RightRotation(temp);
    }

    if(balance < -1 && getBalance(temp->right) <= 0) return LeftRotation(temp);

    if(balance < -1 && getBalance(temp->right) > 0){
        temp->right = RightRotation(temp->right);
        return LeftRotation(temp);
    }
    return temp;
}

#endif //LAB3_AVL_DICTIONARY_H
