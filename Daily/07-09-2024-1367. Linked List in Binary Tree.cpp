
// https://leetcode.com/problems/find-largest-value-in-each-tree-row/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, unordered_map<ListNode*, bool>> mp;
    bool traverse(ListNode*&head, ListNode* curr, TreeNode* root){
        if(root == NULL){
            if(curr == NULL){
                return true;
            }
            return false;
        }
        if(mp.find(root) !=mp.end()){
            if(mp[root].find(curr) != mp[root].end()){
                return mp[root][curr];
            }
        }
        if(curr == NULL){
            return true;
        }
        bool reStart = false;
        if(root->val == head->val){
            reStart = traverse(head,head->next,root->left) || traverse(head, head->next, root->right);
        }
        if(reStart)return  mp[root][curr] = true;

        if(root->val == curr->val){
            return mp[root][curr] = traverse(head, curr->next, root->left) || traverse(head, curr->next, root->right);
        }
        return mp[root][curr] = traverse(head, head, root->left) || traverse(head, head, root->right);
    }
    bool isSubPath(ListNode* head, TreeNode* root) {
        return traverse(head, head,root);
    }
};
