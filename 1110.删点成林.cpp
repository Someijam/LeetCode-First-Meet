// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
@lc app=leetcode.cn id=1110 lang=cpp
@lcpr version=21908
 *
[1110] 删点成林
 */
using namespace std;
#include <algorithm>
#include <array>
#include <bitset>
#include <climits>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
// @lc code=start

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    
    void dfs(TreeNode*node,vector<TreeNode*> &v,vector<int>&cnt,int root){
        if(node==nullptr){
            return ;
        }
        if(cnt[node->val]==1){
            if(node->left){
                dfs(node->left,v,cnt,1);
            }
            if(node->right){
                dfs(node->right,v,cnt,1);
            }
            node=nullptr;
            return ;
        }
        if(node->left){
            dfs(node->left,v,cnt,0);
        }
        if(node->right){
            dfs(node->right,v,cnt,0);
        }
        if(root==1){
            v.push_back(node);
        }
        return ;
    }


    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
       vector<int>cnt(1001);
        for(int i=0;i<to_delete.size();i++){
            cnt[to_delete[i]]=1;
        }
        vector<TreeNode*>v;
        dfs(root,v,cnt,1);
        return v;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=[1,2,3,4,5,6,7]\n[3,5]\n
// paramTypes= ["number[]","number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [1,2,3,4,5,6,7]\n[3,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,4,null,3]\n[3]\n
// @lcpr case=end

 */

