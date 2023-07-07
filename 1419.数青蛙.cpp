/*
 * @lc app=leetcode.cn id=1419 lang=cpp
 * @lcpr version=21907
 *
 * [1419] 数青蛙
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
unordered_map<char,int> crockOrder{{'c',1},{'r',2},{'o',3},{'a',4},{'k',5}};

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) 
    {
        string ans="";
        for(int i=0;i<croakOfFrogs.length();i++)
        {
            cout<<"Current char="<<croakOfFrogs[i]<<endl;
            bool shouldAskNewFrog=true;
            for(int j=0;j<ans.length();j++)
            {
                if(crockOrder[croakOfFrogs[i]]-crockOrder[ans[j]]==1)//这个青蛙可以叫下一声
                {
                    ans[j]=crockOrder[croakOfFrogs[i]];
                    shouldAskNewFrog=false;
                    break;
                }
            }
            if(shouldAskNewFrog)//现有的青蛙叫不出来
            {
                if(croakOfFrogs[i]!='c')return -1;//新青蛙必须从第一声开始叫
                ans.push_back('c');
            }
        }

        return ans.length();
    }
};
// @lc code=end



/*
// @lcpr case=start
// "croakcroak"\n
// @lcpr case=end

// @lcpr case=start
// "crcoakroak"\n
// @lcpr case=end

// @lcpr case=start
// "croakcrook"\n
// @lcpr case=end

 */

