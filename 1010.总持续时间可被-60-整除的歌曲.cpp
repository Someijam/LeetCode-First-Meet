/*
 * @lc app=leetcode.cn id=1010 lang=cpp
 * @lcpr version=21907
 *
 * [1010] 总持续时间可被 60 整除的歌曲
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
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnt=0;
        for(int i=0;i<time.size()-1;i++)
        {
            for(int j=i+1;j<time.size();j++)
            {
                if((time[i]+time[j])%60==0)cnt++;
            }
        }
        return cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [30,20,150,100,40]\n
// @lcpr case=end

// @lcpr case=start
// [60,60,60]\n
// @lcpr case=end

 */

