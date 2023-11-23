/*
 * @lc app=leetcode.cn id=53 lang=cpp
 * @lcpr version=30109
 *
 * [53] 最大子数组和
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
class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
        int ans=nums[0];
        int trav=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            trav=max(trav+nums[i],nums[i]);
            ans=max(ans,trav);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [-2,1,-3,4,-1,2,1,-5,4]\n
// @lcpr case=end

// @lcpr case=start
// [1]\n
// @lcpr case=end

// @lcpr case=start
// [5,4,-1,7,8]\n
// @lcpr case=end

 */

