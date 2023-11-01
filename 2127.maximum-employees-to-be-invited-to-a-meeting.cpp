// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=2127 lang=cpp
 * @lcpr version=30104
 *
 * [2127] 参加会议的最多员工数
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
    // Idea: Miyamizu Mitsuha
    int n;
public:
    int maximumInvitations(vector<int>& favorite) 
    {
        //记录入度
        n=favorite.size();
        vector<int> inDeg(n,0);
        for(auto i:favorite)inDeg[i]++;

        //拓扑排序
        deque<int> topoQue;
        for(int i=0;i<inDeg.size();i++)
        {
            if(inDeg[i]==0)topoQue.push_back(i);
        }
        vector<int> maxChainLenthOf(n,0);
        while (topoQue.empty()==false)
        {
            int headPerson=topoQue.front();
            topoQue.pop_front();
            int headFavor=favorite[headPerson];
            maxChainLenthOf[headFavor]=max(maxChainLenthOf[headFavor],maxChainLenthOf[headPerson]+1);
            inDeg[headFavor]--;
            if(inDeg[headFavor]==0)
            {
                topoQue.push_back(headFavor);
            }
        }

        // for(auto i:maxChainLenthOf)cout<<i<<", ";
        // cout<<endl;
        // for(auto i:inDeg)cout<<i<<", ";
        // cout<<endl;

        //剩下的人里面，inDeg未被减至0的是属于环的元素
        //走环，找最长的环
        int maxCircLenth=0;
        int sumOfChains=0;
        for(int i=0;i<favorite.size();i++)
        {
            if(inDeg[i]==0)continue;
            int currentLength=1;
            int j=favorite[i];
            // cout<<"Circle: "<<i;
            while (j!=i)
            {
                // cout<<" -> "<<j;
                inDeg[j]=0;//走过人的不能再走了
                j=favorite[j];
                currentLength++;
            }
            // cout<<endl;
            if(currentLength==2)sumOfChains+=(2+maxChainLenthOf[i]+maxChainLenthOf[favorite[i]]);//两个人的环当成链
            if(currentLength>maxCircLenth)maxCircLenth=currentLength;//更新最长环
            
        }

        return max(maxCircLenth,sumOfChains);
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=maximumInvitations
// paramTypes= ["number[]"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// [2,2,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,0]\n
// @lcpr case=end

// @lcpr case=start
// [3,0,1,4,1]\n
// @lcpr case=end

 */

