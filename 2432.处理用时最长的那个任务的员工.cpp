/*
 * @lc app=leetcode.cn id=2432 lang=cpp
 * @lcpr version=21907
 *
 * [2432] 处理用时最长的那个任务的员工
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
    int hardestWorker(int n, vector<vector<int>>& logs) {
        int longgestTime=logs[0][1];
        int longgestId=logs[0][0];
        for(int i=1;i<logs.size();i++)
        {
            int currentTime=logs[i][1]-logs[i-1][1];
            int currentId=logs[i][0];
            if(currentTime>longgestTime)
            {
                longgestTime=currentTime;
                longgestId=currentId;
            }
            else if(currentTime==longgestTime)
            {
                if(currentId<longgestId)longgestId=currentId;
            }
        }
        return longgestId;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 10\n[[0,3],[2,5],[0,9],[1,15]]\n
// @lcpr case=end

// @lcpr case=start
// 26\n[[1,1],[3,7],[2,12],[7,17]]\n
// @lcpr case=end

// @lcpr case=start
// 2\n[[0,10],[1,20]]\n
// @lcpr case=end

 */

