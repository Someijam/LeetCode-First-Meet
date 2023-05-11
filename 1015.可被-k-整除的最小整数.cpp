/*
 * @lc app=leetcode.cn id=1015 lang=cpp
 * @lcpr version=21907
 *
 * [1015] 可被 K 整除的最小整数
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
    unordered_map<int,bool> dict;
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0||k%5==0)return -1;
        int cnt=1;
        int lastr=1%k;
        dict[lastr]=true;
        if(lastr==0)return cnt;
        while(1)
        {
            lastr=(10*lastr+1)%k;
            if(dict[lastr]==true)return -1;
            dict[lastr]=true;
            cnt++;
            if(lastr==0)return cnt;
        }
        return -1;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 1\n
// @lcpr case=end

// @lcpr case=start
// 2\n
// @lcpr case=end

// @lcpr case=start
// 3\n
// @lcpr case=end

 */

