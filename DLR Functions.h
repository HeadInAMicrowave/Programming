//
//Created by Damian Bukowski
//

#ifndef LAB2_DLR_FUNCTIONS_H
#define LAB2_DLR_FUNCTIONS_H

#include <iostream>

template<typename Key, typename Info>
class Ring{
private:
    struct Node{
        Key key;
        Info info;
        Node* next;
        Node* prev;
        Node(const Key& key, const Info& vinfo, Node* vnext, Node* vprev):key(key), info(vinfo), next(vnext), prev(vprev){}
        Node(const Key& vkey, const Info& vinfo) : key(vkey), info(vinfo), next(this), prev(this){};
    };
    void copy(const Ring<Key, Info>& x);
    Node* head;
    Node* tail;
public:

    class iterator{
    private:
        Node* itr;
        friend class Ring<Key, Info>;
    public:
        //constructors for interator
        iterator();
        iterator(Node* temp);

        //a few operators to test if the iterator works
        iterator& operator++(){
            itr = itr->next;
            return *this;
        }

        iterator& operator--(){
            itr = itr->prev;
            return *this;
        }

        bool operator==(const iterator& x){
            return itr==x.itr;
        }

        bool operator!=(const iterator& x){
            return itr!=x.itr;
        }

        Key operator*()const{
            return itr->key;
        }
    };
public:

    Ring();
    Ring(const Ring<Key, Info>& x);
    ~Ring();

    void add(const Key& vkey, const Info& vinfo); //method to add elements to the ring
    void show(std::ostream& out); //method to print the elements of the ring
    void clear(); //method to clear the ring
    bool remove(const iterator& x); //method to remove an element that the iterator is pointing to

    //methods to initiate the iterator
    iterator begin(){
        return iterator(head);
    }
    iterator end(){
        return iterator(tail);
    }
};

template<typename Key, typename Info>
Ring<Key, Info>::iterator::iterator(){
    itr = nullptr;
}

template<typename Key, typename Info>
Ring<Key, Info>::iterator::iterator(Node* temp){
    itr = temp;
}

template<typename Key, typename Info>
Ring<Key, Info>::Ring(){
    head = nullptr;
    tail = nullptr;
}

template<typename Key, typename Info>
Ring<Key, Info>::Ring(const Ring<Key, Info>& x){
    head = nullptr;
    tail = nullptr;
    copy(x);
}

template<typename Key, typename Info>
Ring<Key, Info>::~Ring(){
    clear();
}

template<typename Key, typename Info>
void Ring<Key, Info>::clear(){
    Node *temp = head;
    do{
        head = temp->next;
        delete temp;
    } while(temp->next != head);
    head = nullptr;
}

template<typename Key, typename Info>
void Ring<Key, Info>::add(const Key& vkey, const Info& vinfo){
    if(!head){
        Node* temp = new Node(vkey, vinfo);
        head = temp;
        tail = head;
    } else {
        Node* temp = new Node(vkey, vinfo, head, head->prev);
        head->prev->next = temp;
        head->prev = temp;
        head = temp;
    }
}

template<typename Key, typename Info>
void Ring<Key,Info>::copy(const Ring<Key,Info>& x){

    Node* xtr = x.head;
    Node* etr = this->head;
    if(etr!=nullptr){
        this->clearAll();
    }
    do{
        Node* new_ptr = new Node(xtr->key, xtr->info);
        new_ptr->next = nullptr;

        if(head == nullptr){
            head=new_ptr;
        }
        else{
            etr->next = new_ptr;
            new_ptr->prev = etr;
        }
        etr = new_ptr;
        xtr = xtr->next;
    }while(xtr != x.head);
    head->prev = etr;
    etr->next = head;
}

template<typename Key, typename Info>
void Ring<Key, Info>::show(std::ostream& out){
    Node *temp = head;
    do{
        out << "Key is: " << temp->key << ", and info is: " << temp->info << std::endl;
        temp = temp->next;
    }while(temp != head);
    out << std::endl;
}

template<typename Key, typename Info>
bool Ring<Key,Info>::remove(const iterator& x){
    if(x.itr == nullptr){
        return false;
    } else {
        if(head == x.itr) {
            if(head->next != head) {
                head = head->next;
            } else {
                delete head;
                head = nullptr;
                tail = nullptr;
                return true;
            }
        }
        x.itr->prev->next = x.itr->next;
        x.itr->next->prev = x.itr->prev;
        if(x.itr == tail){
            tail = tail->prev;
        }
        delete x.itr;
        return true;
    }
}

#endif //LAB2_DLR_FUNCTIONS_H
