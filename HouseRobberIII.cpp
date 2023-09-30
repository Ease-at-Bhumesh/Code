#include<bits/stdc++.h>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
unordered_map<TreeNode*,int>m;
int solve(TreeNode* root){
    if(m[root]) return m[root]; 
    if(root==nullptr) return 0;
    int val=root->val;
    if(root->left!=nullptr) val+=solve(root->left->left)+solve(root->left->right);
    if(root->right!=nullptr) val+=solve(root->right->left)+solve(root->right->right);
    return m[root]=max(val,solve(root->left)+solve(root->right));
}
int main(){
    TreeNode p4(0);
    TreeNode p5(1);
    TreeNode p7(1);
    TreeNode p8(2);
    TreeNode p9(1);
    TreeNode p6(3,&p8,&p9);
    TreeNode p2(4,&p7,&p6);
    TreeNode p3(5,&p4,&p5);
    TreeNode p1(3,&p2,&p3);
    cout<<solve(&p1);
    return 0;
}