// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=187 lang=cpp
 * @lcpr version=30105
 *
 * [187] 重复的DNA序列
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
class Solution {
private:
    unordered_map<string,int> dict;
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        for(int i=0;i+9<s.length();i++)
        {
            if(dict.find(s.substr(i,10))!=dict.end())
            {
                dict[s.substr(i,10)]++;
            }
            else
            {
                dict[s.substr(i,10)]=1;
            }
        }
        vector<string> ans;
        for(auto it:dict)
        {
            if(it.second>1)ans.push_back(it.first);
        }
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"\n
// @lcpr case=end

// @lcpr case=start
// "AAAAAAAAAAAAA"\n
// @lcpr case=end

 */

