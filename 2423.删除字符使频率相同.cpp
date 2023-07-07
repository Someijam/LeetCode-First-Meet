/*
 * @lc app=leetcode.cn id=2423 lang=cpp
 * @lcpr version=21907
 *
 * [2423] 删除字符使频率相同
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
    bool isEquFreq(string s)
    {
        cout<<s<<endl;
        unordered_map<char,int> freqList;//<char, freq>
        for(auto ch : s)
        {
            if(freqList.find(ch)!=freqList.end())//找到了
            {
                freqList[ch]++;
            }
            else 
            {
                freqList[ch]=1;
            }
        }
        // for(auto it : freqList)cout<<it.first<<","<<it.second<<endl;
        int lastFreq=freqList.begin()->second;
        for(auto it=freqList.begin();it!=freqList.end();++it)
        {
            if(it->second!=lastFreq)
            {
                return false;
            }
        }
        return true;
    }
public:
    bool equalFrequency(string word) {
        for(int i=0;i<word.length();i++)
        {
            string testStr=word.substr(0,i)+word.substr(i+1);
            if(isEquFreq(testStr))//有相等的情况
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcc"\n
// @lcpr case=end

// @lcpr case=start
// "aazz"\n
// @lcpr case=end

 */

