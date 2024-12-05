/*
 * @lc app=leetcode.cn id=997 lang=cpp
 * @lcpr version=30204
 *
 * [997] 找到小镇的法官
 */

// @lcpr-template-start
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
// @lcpr-template-end
// @lc code=start
class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> outDeg=vector<int>(n+1,0);
        vector<int> inDeg=vector<int>(n+1,0);
        for(auto it:trust)
        {
            outDeg[it[0]]++;
            inDeg[it[1]]++;
        }
        int ans=-1;
        for(int i=1;i<outDeg.size();i++)
        {
            if(outDeg[i]==0 && inDeg[i]==n-1)
            {
                ans=i;
            }
        }
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// 2\n[[1,2]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,3],[2,3]]\n
// @lcpr case=end

// @lcpr case=start
// 3\n[[1,3],[2,3],[3,1]]\n
// @lcpr case=end

 */
