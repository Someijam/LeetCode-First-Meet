/*
 * @lc app=leetcode.cn id=2103 lang=cpp
 * @lcpr version=30104
 *
 * [2103] 环和杆
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
    int countPoints(string rings) 
    {
        int n=rings.length();
        vector<int> redCnt(10,0);
        vector<int> greenCnt(10,0);
        vector<int> blueCnt(10,0);
        for(int i=0;i<n;i+=2)
        {
            switch (rings[i])
            {
            case 'R':
                redCnt[atoi(rings.substr(i+1,1).c_str())]++;
                break;
            case 'G':
                greenCnt[atoi(rings.substr(i+1,1).c_str())]++;
                break;
            case 'B':
                blueCnt[atoi(rings.substr(i+1,1).c_str())]++;
                break;
            default:
                cout<<"Exception:"<<rings[i]<<rings[i+1]<<endl;
                break;
            }
        }
        // for(auto it:redCnt)cout<<it<<", ";
        // cout<<endl;
        // for(auto it:greenCnt)cout<<it<<", ";
        // cout<<endl;
        // for(auto it:blueCnt)cout<<it<<", ";
        // cout<<endl;
        int cnt=0;
        for(int i=0;i<10;i++)
        {
            if(redCnt[i]>0&&greenCnt[i]>0&&blueCnt[i]>0)cnt++;
        }
        return cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "B0B6G0R6R0R6G9"\n
// @lcpr case=end

// @lcpr case=start
// "B0R0G0R9R0B0G0"\n
// @lcpr case=end

// @lcpr case=start
// "G4"\n
// @lcpr case=end

 */

