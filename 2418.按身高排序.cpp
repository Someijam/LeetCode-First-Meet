/*
 * @lc app=leetcode.cn id=2418 lang=cpp
 * @lcpr version=21907
 *
 * [2418] 按身高排序
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
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        vector<int> indexes;
        for(int i=0;i<names.size();i++)indexes.push_back(i);
        sort(indexes.begin(),indexes.end(),[&](int a,int b)->bool{return heights[a]>heights[b];});
        for(int i:indexes)ans.push_back(names[i]);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["Mary","John","Emma"]\n[180,165,170]\n
// @lcpr case=end

// @lcpr case=start
// ["Alice","Bob","Bob"]\n[155,185,150]\n
// @lcpr case=end

 */

