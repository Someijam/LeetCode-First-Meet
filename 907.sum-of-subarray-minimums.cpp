/*
 * @lc app=leetcode.cn id=907 lang=cpp
 * @lcpr version=30111
 *
 * [907] 子数组的最小值之和
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
    int sumSubarrayMins(vector<int>& arr) 
    {
        long long ans=0;
        long long mod=1e9+7;
        int n=arr.size();
        vector<int> dp(n,0);
        dp[0]=arr[0];
        ans=0;
        stack<int> record;
        for(int i=0;i<n;i++)
        {
            while (record.empty()==false)
            {
                if(arr[record.top()]<arr[i])break;
                record.pop();
            }
            
            //是从i往左找比arr[i]小的人数
            int k;
            if(record.empty())k=i+1;
            else k=i-record.top();

            cout<<"i="<<i<<", k="<<k<<", i-k="<<i-k<<endl;
            if(i-k>=0)dp[i]=(dp[i-k]+k*arr[i])%mod;
            else dp[i]=(k*arr[i])%mod;
            ans=(ans+dp[i])%mod;
            record.push(i);
        }
        return ans;

    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,1,2,4]\n
// @lcpr case=end

// @lcpr case=start
// [11,81,94,43,3]\n
// @lcpr case=end

 */

