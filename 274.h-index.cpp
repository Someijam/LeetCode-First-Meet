// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=274 lang=cpp
 * @lcpr version=30104
 *
 * [274] H 指数
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
public:
    int hIndex(vector<int>& citations) 
    {
        sort(citations.begin(),citations.end(),[](int x,int y)->bool{return x>=y;});
        // 6,5,4 ,1,0
        // 前面的i个人都>=i -> 第i个人>=i -> a[i-1]>=i,max i
        int ans=0;
        for(int i=0;i<citations.size();i++)
        {
            if(citations[i]<i+1)
            {
                return i;
            }
        }
        return citations.size();
    }
};
// @lc code=end



/*
// @lcpr case=start
// [3,0,6,1,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,3,1]\n
// @lcpr case=end

 */

