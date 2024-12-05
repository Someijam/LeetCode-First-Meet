// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=815 lang=cpp
 * @lcpr version=30204
 *
 * [815] 公交路线
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
class Solution
{
private:
    // stopInWhichLines[i]: 通过站点i的线路
    vector<vector<int>> stopInWhichLines=vector<vector<int>>(1000000);
    // connected[i][j]: =1 跨线连通; =inf 不连通
    vector<vector<int>> connected=vector<vector<int>>(500,vector<int>(500,0));
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if(source==target)return 0;
        for(int i=0;i<routes.size();i++)
        {
            for(auto it:routes[i])
            {
                stopInWhichLines[it].push_back(i);
            }
        }
        // cout<<"整理了所有通过站点i的线路"<<endl;
        for(auto it:stopInWhichLines)// 对于每一站 所经过它的线路
        {
            if(it.size()<=1)continue; //站点i只过一条线，pass
            // for(auto iit:it)printf("%d ",iit);
            // printf("\n");
            for(int i=0;i<it.size()-1;i++)
            {
                for(int j=i+1;j<it.size();j++)
                {
                    // printf("(%d,%d) ",i,j);
                    connected[it[i]][it[j]]=1;
                    connected[it[j]][it[i]]=1;
                }
                // printf("\n");
            }
        }
        // for(int i=0;i<5;i++)
        // {
        //     for(int j=0;j<5;j++)
        //     {
        //         printf("%d ",connected[i][j]);
        //     }
        //     printf("\n");
        // }
        // cout<<"整理了不同线路之间的连接"<<endl;
        // 最短路，满足 多起点->多终点 stopInWhichLines[source] -> stopInWhichLines[target] 
        // 相当于从 上海南站(1,3,15) 到 世纪大道(2,4,6,9) 最少换乘几次
        deque<pair<int,int>> bfs; // bfs<lineNo,depth>
        vector<int> viewedLines=vector<int>(500,0);
        int ans=-1;
        for(auto it:stopInWhichLines[source])
        {
            // printf("Ini:%d\n",it);
            bfs.push_back({it,1});
            viewedLines[it]=1;
        }
        while (bfs.empty()==false)
        {
            auto head=bfs.front(); // head<lineNo,depth>
            bfs.pop_front();
            // printf("Trav: %d\n",head.first);
            // viewedLines[head.first]=1;
            // 当前bfs到的线路是否属于stopInWhichLines[target]
            bool tillend=false;
            for(auto it:stopInWhichLines[target])
            {
                if(it==head.first)
                {
                    tillend=true;
                    ans=head.second;
                    break;
                }
            }
            if(tillend)break;
            for(int i=0;i<connected.size();i++)
            {
                if(connected[i][head.first]==1 && viewedLines[i]==0)
                {
                    bfs.push_back({i,head.second+1});
                    viewedLines[i]=1;
                }
            }
        }
        // cout<<"BFS结束"<<endl;
        return ans;
    }
};
// @lc code=end

/*
// @lcpr case=start
// [[1,2,7],[3,6,7]]\n1\n6\n
// @lcpr case=end

// @lcpr case=start
// [[7,12],[4,5,15],[6],[15,19],[9,12,13]]\n15\n12\n
// @lcpr case=end

 */
