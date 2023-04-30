#include <iostream>
#include <vector>


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* oddEvenList(ListNode* head) {
            
        }
};

int main(){
    // using namespace std;
    ListNode node5(15);
    ListNode node4(15, &node5);
    ListNode node3(15, &node4);
    ListNode node2(15, &node3);
    ListNode node1(15);

    Solution rozwiazanie;
}