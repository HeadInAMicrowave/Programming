#include<iostream>
#include<vector>
#include<cmath>

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr){}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right){}
};

class Solution {
    private:
        std::vector<int> A;
    public:
        void walk(TreeNode* root){
            if (root == nullptr) return;

            A.push_back(root->val);

            walk(root->left);
            walk(root->right);
        }

        int maxAncestorDiff(TreeNode* root){
            this->walk(root);
            for(int i = 0; i < this->A.size(); i++){
                
            }
        }
};

int main(){
    using namespace std;

    TreeNode node8(13);
    TreeNode node7(7);
    TreeNode node6(4);
    TreeNode node5(14, &node8, nullptr);
    TreeNode node4(6, &node6, &node7);
    TreeNode node3(1);
    TreeNode node2(10, nullptr, &node5);
    TreeNode node1(3, &node3, &node4);
    TreeNode root(8, &node1, &node2);

    Solution sol;
    // sol.walk(&root);
    sol.maxAncestorDiff(&root);

    return 0;
}