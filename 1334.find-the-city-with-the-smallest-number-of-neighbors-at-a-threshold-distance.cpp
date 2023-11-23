// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1334 lang=cpp
 * @lcpr version=30109
 *
 * [1334] 阈值距离内邻居最少的城市
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
private:
    vector<vector<int> > graphMatrix;
    int pointNum;
    int inf=0x3f3f3f3f;
public:
    void updateMatrix()
    {
        for(int p=0;p<pointNum;p++)
        {
            for(int i=0;i<graphMatrix.size();i++)
            {
                for(int j=0;j<graphMatrix.size();j++)
                {
                    graphMatrix[i][j]=min(graphMatrix[i][j],graphMatrix[i][p]+graphMatrix[p][j]);
                    graphMatrix[j][i]=graphMatrix[i][j];
                }
            }
        }
        return;
    }
    int collectValidPoints(int p,int rlimit)
    {
        vector<int> validPoints;
        for(int i=0;i<pointNum;i++)
        {
            if(p==i)continue;
            if(graphMatrix[p][i]<=rlimit)
            {
                validPoints.push_back(i);
            }
        }
        // cout<<"City"<<p<<" -> [";
        // for(auto it:validPoints)cout<<it<<", ";
        // cout<<"]\n";
        return validPoints.size();
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        graphMatrix.resize(n);
        pointNum=n;
        for(auto &it:graphMatrix)it.resize(n,inf);
        for(auto it:edges)
        {
            graphMatrix[it[0]][it[1]]=it[2];
            graphMatrix[it[1]][it[0]]=it[2];
        }
        for(int i=0;i<n;i++)
        {
            graphMatrix[i][i]=0;
        }
        updateMatrix();
        // cout<<endl;
        // for(auto it:graphMatrix)
        // {
        //     cout<<"[";
        //     for(auto iit:it)cout<<iit<<", ";
        //     cout<<"]\n";
        // }
        int minAns=INT_MAX;
        int minPoint=0;
        for(int i=0;i<n;i++)
        {
            int tAns=collectValidPoints(i,distanceThreshold);
            if(tAns<=minAns)
            {
                minAns=tAns;
                minPoint=i;
            }
        }
        return minPoint;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=findTheCity
// paramTypes= ["number","number[][]","number"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// 4\n[[0,1,3],[1,2,1],[1,3,4],[2,3,1]]\n4\n
// @lcpr case=end

// @lcpr case=start
// 5\n[[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]]\n2\n
// @lcpr case=end

 */

