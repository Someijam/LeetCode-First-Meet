/*
 * @lc app=leetcode.cn id=318 lang=cpp
 * @lcpr version=30105
 *
 * [318] 最大单词长度乘积
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
    int maxProduct(vector<string>& words) 
    {
        vector<bitset<26> > wordLettersUsed;
        bitset<26> commomLetters("11111111111111111111111111");
        for(auto si:words)
        {
            bitset<26> tempStatus(0);
            for(auto ci:si)
            {
                tempStatus[ci-'a']=1;
            }
            wordLettersUsed.push_back(tempStatus);
            // cout<<tempStatus<<endl;
            commomLetters&=tempStatus;
        }
        // cout<<commomLetters<<endl;
        //有人是1说明所有人都有这个字母，不存在符合要求的两个人
        if(commomLetters.any())return 0;

        size_t maxRes=0;

        for(int i=0;i<words.size()-1;i++)
        {
            for(int j=i+1;j<words.size();j++)
            {
                if((wordLettersUsed[i]&wordLettersUsed[j]).any())continue;
                maxRes=max(maxRes,words[i].length()*words[j].length());
            }
        }

        return maxRes;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["abcw","baz","foo","bar","xtfn","abcdef"]\n
// @lcpr case=end

// @lcpr case=start
// ["a","ab","abc","d","cd","bcd","abcd"]\n
// @lcpr case=end

// @lcpr case=start
// ["a","aa","aaa","aaaa"]\n
// @lcpr case=end

 */

