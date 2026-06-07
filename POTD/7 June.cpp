/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* f(int val, unordered_map<int,int>&left,unordered_map<int,int>&right) {
        TreeNode* head = new TreeNode(val);
        if(left.find(val)!=left.end()) head->left = f(left[val], left,right);
        if(right.find(val)!=right.end()) head->right = f(right[val], left,right);
        return head;
    }
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,int>left,right;
        unordered_set<int> st;
        for (auto& v : descriptions) {
            if(v[2]==1)left[v[0]]=v[1];
            else right[v[0]]=v[1];
            st.insert(v[1]);
        }
        TreeNode* head = new TreeNode();
        for (auto& v : descriptions) {
            if (st.find(v[0]) == st.end()) {
                return f(v[0], left,right);
            }
        }
        return nullptr;
    }
};