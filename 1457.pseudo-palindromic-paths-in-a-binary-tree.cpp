/*
@lc app=leetcode.cn id=1457 lang=cpp
@lcpr version=30111
 *
[1457] 二叉树中的伪回文路径
 */


// @lcpr-template-start
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
using namespace std;
// @lcpr-template-end
// @lc code=start

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
    int pseudoPalindromicPaths (TreeNode* root) 
    {
        int cnt=0;
        stack<pair<TreeNode*,unsigned int> >treeTrav;// <node,flag>
        treeTrav.push({root,1<<(root->val)});
        while (treeTrav.empty()==false)
        {
            auto last=treeTrav.top();
            treeTrav.pop();
            if(last.first->left==nullptr&&last.first->right==nullptr&&__builtin_popcount(last.second)<=1)
            {
                // cout<<last.first->val<<" -> "<<bitset<10>(last.second)<<endl;
                cnt++;
            }
            if(last.first->left!=nullptr)
            {
                treeTrav.push({last.first->left,last.second^(1<<(last.first->left->val))});
            }
            if(last.first->right!=nullptr)
            {
                treeTrav.push({last.first->right,last.second^(1<<(last.first->right->val))});
            }
        }
        return cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,1,3,1,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [2,1,1,1,3,null,null,null,null,null,1]\n
// @lcpr case=end

// @lcpr case=start
// [9]\n
// @lcpr case=end

 */

