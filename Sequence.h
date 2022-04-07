//
//Created by Damian Bukowski
//

#ifndef LAB1_SEQUENCE_H
#define LAB1_SEQUENCE_H

#include <iostream>

template <typename Key, typename Info>
class Sequence{
    struct Node{
        Key key;
        Info info;
        Node* next;
        Node(const Key& key, const Info& vinfo, Node* vnext=nullptr):key(key), info(vinfo), next(vnext){}
    };
private:
    Node* head;
    unsigned int size;
    void copyall(const Sequence& x);
public:
    Sequence();
    Sequence(const Sequence &x);
    ~Sequence();
    Sequence& operator=(const Sequence &x);
    void display(std::ostream &out);
    void insertAtBeginning (const Key &vKey, const Info &vInfo);
    void insertAtEnd (const Key &vKey, const Info &vInfo);
    void deleteAtBeginning();
    void clear();
    bool pickUpBeginning(Sequence& y);
    unsigned int getSize() const {return size;}
    bool empty()const{return head==nullptr;}

    std::size_t produce (const Sequence<Key, Info>& seq1, int start1, int dl1,
                         const Sequence<Key, Info>& seq2, int start2, int dl2, int limit);
};

template<typename Key, typename Info>
Sequence<Key, Info>::Sequence(){
    head = nullptr;
}

template<typename Key, typename Info>
Sequence<Key, Info>::Sequence(const Sequence &x){
    copyall(x);
}

template<typename Key, typename Info>
Sequence<Key, Info>::~Sequence(){
    clear();
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::pickUpBeginning(Sequence &y){
    if(y.empty() == true){
        return false;
    } else {
        insertAtEnd(y.head->key, y.head->info);
        y.deleteAtBeginning();
        return true;
    }
}

template <typename Key, typename Info>
void Sequence<Key, Info>::insertAtEnd(const Key& vkey, const Info& vinfo){
    Node * curr = head;
    if(curr==nullptr){
        insertAtBeginning(vkey, vinfo);
    }else{
        while(curr->next){
            curr=curr->next;
        }
        Node * now = new Node(vkey, vinfo);
        curr->next = now;
    }
    size++;
}

template<typename Key, typename Info>
void Sequence<Key, Info>::deleteAtBeginning(){
    Node *curr = head;
    head = head->next;
    delete curr;
    size--;
}

template<typename Key, typename Info>
void Sequence<Key, Info>::copyall(const Sequence& x){
    Node * curr = head;
    Node * copy = x.head;
    if(head){
        while (curr->next){
            curr=curr->next;
        }
    }
    while(copy){
        Node *now = new Node(copy->key, copy->info);
        if(!now){throw "Error";}
        if(!head){head=now;}else{
            curr->next=now;
        }
        curr=now;
        copy=copy->next;
    }
    size=x.size+size;
}

template<typename Key, typename Info>
Sequence<Key, Info>& Sequence<Key, Info>::operator=(const Sequence &x){
    if(this != &x) {
        clear();
        copyall(x);
    }
    return *this;
}

template<typename Key, typename Info>
void Sequence<Key, Info>::clear(){
    Node *temp;
    while(head) {
        temp = head->next;
        delete head;
        head = temp;
    }
}

template <typename Key, typename Info>
void Sequence<Key,Info>::insertAtBeginning (const Key &vKey, const Info &vInfo){
    Node* temp = new Node(vKey, vInfo, head);
    head = temp;
}

template<typename Key, typename Info>
void Sequence<Key, Info>::display(std::ostream &out){
    Node *temp = head;
    while(temp != nullptr){
        out << temp->key << " " << temp->info << std::endl;
        temp = temp->next;
    }
}

template <typename Key, typename Info>
Sequence<Key, Info> produce (const Sequence<Key, Info>& seq1, int start1, int dl1,
                             const Sequence<Key, Info>& seq2, int start2, int dl2, int limit){
    Sequence<Key, Info> vseq1 = seq1;
    Sequence<Key, Info> vseq2 = seq2;

    while(start1 != 0){
        vseq1.deleteAtBeginning();
        start1--;
    }
    while(start2 != 0){
        vseq2.deleteAtBeginning();
        start2--;
    }
    Sequence<Key, Info> kekw; //I honestly don't remember why this is here and what it does. Serves me well for not commneting the code while writing
    while(limit != 0){
        if(vseq1.getSize() >= dl1 && vseq2.getSize() >= dl2){
            for(int i = 0; i < dl1; i++){
                if(kekw.pickUpBeginning(vseq1) == false){
                    return kekw;
                }
            }
            for (int j = 0; j < dl2; j++){
                if(kekw.pickUpBeginning(vseq2) == false){
                    return kekw;
                }
            }
        } else break;
        limit--;
    }
    return kekw;
}

#endif //LAB1_SEQUENCE_H
