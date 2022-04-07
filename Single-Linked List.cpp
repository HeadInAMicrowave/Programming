#include <iostream>
using namespace std;

template<typename Key, typename Info>
class Sequence{
private:
    struct Node{
        Key key;
        Info info;
        Node *next;
        Node(const Key& k, const Info& inf, Node *vnext=nullptr):key(k), info(inf), next(vnext){}
    };
    Node *head;

public:
    Sequence();
    ~Sequence();
    Sequence(const Sequence<Key, Info>&);
    Sequence<Key, Info>& operator=(const Sequence<Key, Info>);

    void insertAtBeginning(const Key& k, const Info& inf);
    void insertAtEnd(const Key& k, const Info& inf);
    bool insertAfter(const Key& k, const Info& inf, const Key& where, int occurrence = 1);
    bool find(const Key& k, int occurrence = 1);
};

template<typename Key, typename Info>
void Sequence<Key, Info>::insertAtBeginning(const Key &k, const Info &inf){
    Node* newNode = new Node(this->Key, this->Info, this->head);
    head = newNode;
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::find(const Key& k, int occurrence){ //TODO finish this
    Node* curr;
}

template<typename Key, typename Info>
void Sequence<Key, Info>::insertAtEnd(const Key &k, const Info &inf){
    Node* curr;
    if(curr==nullptr){
        insertAtBeginning(k, inf);
    } else {
        while(curr->next){
            curr = curr->next;
        }
        Node* now = new Node(k, inf);
        curr->next = now;
    }
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::insertAfter(const Key& k, const Info& inf, const Key& where, int occurrence){
    Node* curr = head;
    Node* prev = head;

    if(find(k, occurrence)==true){
        Node* now = new Node(k, inf, curr->next);
        curr->next = now;
    }
}

