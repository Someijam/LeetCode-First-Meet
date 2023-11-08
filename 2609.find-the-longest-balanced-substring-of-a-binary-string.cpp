/*
 * @lc app=leetcode.cn id=2609 lang=cpp
 * @lcpr version=30106
 *
 * [2609] 最长平衡子字符串
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
    int findTheLongestBalancedSubstring(string s) 
    {
        int ans=0;
        for(int i=0;i<s.length();)
        {
            //找连续的0和1
            int lenthof0=0;
            int lenthof1=0;
            for(int j=i;s[j]=='0';j++)
            {
                lenthof0++;
                i=j+1;
            }
            for(int j=i;s[j]=='1';j++)
            {
                lenthof1++;
                i=j+1;
            }
            ans=max(ans,2*min(lenthof0,lenthof1));

        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "01000111"\n
// @lcpr case=end

// @lcpr case=start
// "00111"\n
// @lcpr case=end

// @lcpr case=start
// "111"\n
// @lcpr case=end

 */

