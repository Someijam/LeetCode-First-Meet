/*
 * @lc app=leetcode.cn id=152 lang=cpp
 * @lcpr version=30110
 *
 * [152] 乘积最大子数组
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
    int maxProduct(vector<int>& nums) 
    {
        vector<int> maxProEndsAt(nums.size(),0);
        vector<int> minProEndsAt(nums.size(),0);

        maxProEndsAt[0]=nums[0];
        minProEndsAt[0]=nums[0];

        for(int i=1;i<nums.size();i++)
        {
            maxProEndsAt[i]=max(minProEndsAt[i-1]*nums[i],max(maxProEndsAt[i-1]*nums[i],nums[i]));
            minProEndsAt[i]=min(maxProEndsAt[i-1]*nums[i],min(minProEndsAt[i-1]*nums[i],nums[i]));
        }

        return *max_element(maxProEndsAt.begin(),maxProEndsAt.end());
    }
    // dpMax[i]=max(dpMax[i-1]*nums[i],nums[i],dpMin[i-1]*nums[i])
    // dpMin[i]=min(dpMin[i-1]*nums[i],nums[i],dpMax[i-1]*nums[i])
};
// @lc code=end



/*
// @lcpr case=start
// [2,3,-2,4]\n
// @lcpr case=end

// @lcpr case=start
// [-2,0,-1]\n
// @lcpr case=end

 */

