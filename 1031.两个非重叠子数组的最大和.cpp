/*
 * @lc app=leetcode.cn id=1031 lang=cpp
 * @lcpr version=21907
 *
 * [1031] 两个非重叠子数组的最大和
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
private:
    vector<int> prefixSum;
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        prefixSum.push_back(0);
        int maxAns=0;
        for(int i=1;i<=nums.size();i++)prefixSum.push_back(prefixSum[i-1]+nums[i-1]);
        //左 右
        int maxFirst=0;
        int maxSum=0;
        for(int r=firstLen;r+secondLen<=nums.size();r++)
        {
            maxFirst=max(maxFirst,prefixSum[r]-prefixSum[r-firstLen]);
            maxSum=max(maxSum,maxFirst+prefixSum[r+secondLen]-prefixSum[r]);
        }
        //右 左
        int maxSecond=0;
        for(int l=secondLen;l+firstLen<=nums.size();l++)
        {
            maxSecond=max(maxSecond,prefixSum[l]-prefixSum[l-secondLen]);
            maxSum=max(maxSum,maxSecond+prefixSum[l+firstLen]-prefixSum[l]);
        }
        return maxSum;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [0,6,5,2,2,5,1,9,4]\n1\n2\n
// @lcpr case=end

// @lcpr case=start
// [3,8,1,3,2,1,8,9,0]\n3\n2\n
// @lcpr case=end

// @lcpr case=start
// [2,1,5,6,0,9,5,0,3,8]\n4\n3\n
// @lcpr case=end

 */

