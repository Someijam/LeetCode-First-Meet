// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=167 lang=cpp
 * @lcpr version=21909
 *
 * [167] 两数之和 II - 输入有序数组
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
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int r=numbers.size()-1;
        while (l<r)
        {
            if(numbers[l]+numbers[r]==target)
            {
                return {l+1,r+1};
            }
            else if(numbers[l]+numbers[r]>target) r--;
            else if(numbers[l]+numbers[r]<target) l++;
        }
        return {0,0};
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,7,11,15]\n9\n
// @lcpr case=end

// @lcpr case=start
// [2,3,4]\n6\n
// @lcpr case=end

// @lcpr case=start
// [-1,0]\n-1\n
// @lcpr case=end

 */

