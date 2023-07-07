/*
 * @lc app=leetcode.cn id=2178 lang=cpp
 * @lcpr version=21909
 *
 * [2178] 拆分成最多数目的正偶数之和
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
    vector<long long> ans;
public:
    vector<long long> maximumEvenSplit(long long finalSum) 
    {
        if(finalSum&1)return {};//尾巴是1的数是奇数
        for(long long t=2;;t+=2)
        {
            if(finalSum<t)//不够减了
            {
                ans[ans.size()-1]+=finalSum;
                break;
            }
            finalSum-=t;
            ans.push_back(t);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 12\n
// @lcpr case=end

// @lcpr case=start
// 7\n
// @lcpr case=end

// @lcpr case=start
// 28\n
// @lcpr case=end

 */

