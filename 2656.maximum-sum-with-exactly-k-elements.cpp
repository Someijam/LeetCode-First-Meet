/*
 * @lc app=leetcode.cn id=2656 lang=cpp
 * @lcpr version=30109
 *
 * [2656] K 个元素的最大和
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
    int maximizeSum(vector<int>& nums, int k) 
    {
        auto s=max_element(nums.begin(),nums.end());
        return ((*s+*s+k-1)*k)/2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,2,3,4,5]\n3\n
// @lcpr case=end

// @lcpr case=start
// [5,5,5]\n2\n
// @lcpr case=end

 */

