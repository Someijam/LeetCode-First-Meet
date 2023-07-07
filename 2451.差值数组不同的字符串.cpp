/*
 * @lc app=leetcode.cn id=2451 lang=cpp
 * @lcpr version=21908
 *
 * [2451] 差值数组不同的字符串
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
    string oddString(vector<string>& words) {
        int ans;
        for(int pos=1;pos<words[0].length();pos++)
        {
            vector<int> diff;
            unordered_map<int,int> dict;
            int stdnum;
            for(int i=0;i<words.size();i++)
            {
                int tdiff=int(words[i][pos])-int(words[i][pos-1]);
                if(dict.find(tdiff)==dict.end())
                {
                    dict[tdiff]=0;
                }
                dict[tdiff]++;
                diff.push_back(tdiff);
            }
            for(auto it:dict)
            {
                if(it.second>1)stdnum=it.first;
            }
            for(int i=0;i<diff.size();i++)
            {
                if(diff[i]!=stdnum)
                {
                    ans=i;
                }
            }
        }
        return words[ans];
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["adc","wzy","abc"]\n
// @lcpr case=end

// @lcpr case=start
// ["aaa","bob","ccc","ddd"]\n
// @lcpr case=end

 */

