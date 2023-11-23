/*
 * @lc app=leetcode.cn id=2342 lang=cpp
 * @lcpr version=30109
 *
 * [2342] 数位和相等数对的最大和
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
    int possum(int a)
    {
        int sum=0;
        while (a>0)
        {
            sum+=a%10;
            a/=10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end(),[=](int a,int b)->bool
        {
            if(possum(a)!=possum(b))return possum(a)>possum(b);
            else return a>b;
        });
        int ans=-1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(possum(nums[i])==possum(nums[i+1]))
            {
                ans=max(ans,nums[i]+nums[i+1]);
            }
            else continue;
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [18,43,36,13,7]\n
// @lcpr case=end

// @lcpr case=start
// [10,12,19,14]\n
// @lcpr case=end

 */

