/*
 * @lc app=leetcode.cn id=1016 lang=cpp
 * @lcpr version=21907
 *
 * [1016] 子串能表示从 1 到 N 数字的二进制串
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
    string binToStr(int n)
    {
        if(n==0)return "0";
        string ans="";
        while (n>0)
        {
            ans.insert(0,1,char('0'+(n&1)));
            n=(n>>1);
        }
        return ans;
    }
    bool queryString(string s, int n) {
        for(int i=1;i<=n;i++)
        {
            if(s.find(binToStr(i))==string::npos)return false;
        }
        return true;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "0110"\n3\n
// @lcpr case=end

// @lcpr case=start
// "0110"\n4\n
// @lcpr case=end

 */

