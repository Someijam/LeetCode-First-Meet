/*
 * @lc app=leetcode.cn id=2106 lang=cpp
 * @lcpr version=21907
 *
 * [2106] 摘水果
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
    vector<int> prefixSum;
public:
    int totalFruitSumInRange(int l,int r)
    {
        //valid rec:[0,fruits[last][0]]
        if(l>=int(prefixSum.size()))return 0;
        r=min(r,int(prefixSum.size()-1));
        if(l<1)return prefixSum[r];
        return prefixSum[r]-prefixSum[l-1];
    }
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) 
    {
        int lastSum=0;
        for(int i=0;i<fruits[0][0];i++)prefixSum.push_back(0);
        for(int i=0;i+1<fruits.size();i++)
        {
            for(int j=fruits[i][0];j<fruits[i+1][0];j++)
            {
                prefixSum.push_back(fruits[i][1]+lastSum);
            }
            lastSum+=fruits[i][1];
        }
        prefixSum.push_back(lastSum+fruits[fruits.size()-1][1]);

        // for(int i=0;i<prefixSum.size();i++)cout<<prefixSum[i]<<" ";
        // cout<<endl;

        int ans=0;
        for(int i=0;i<=k/2;i++)
        {
            // cout<<"Test:("<<startPos-(k-2*i)<<","<<startPos+i<<")"<<endl;
            int temp=totalFruitSumInRange(startPos-(k-2*i),startPos+i);
            // cout<<"Range("<<startPos-(k-2*i)<<","<<startPos+i<<")="<<temp<<endl;
            if(temp>ans)
            {
                ans=temp;
            }
            // cout<<"Test:("<<startPos-i<<","<<startPos+(k-2*i)<<")"<<endl;
            temp=totalFruitSumInRange(startPos-i,startPos+(k-2*i));
            // cout<<"Range("<<startPos-i<<","<<startPos+(k-2*i)<<")="<<temp<<endl;
            if(temp>ans)
            {
                ans=temp;
            }
        }
        // cout<<"Ans="<<totalFruitSumInRange(-21,86)<<endl;
        return ans;
    }
    // [[0,15],[3,56],[4,98],[5,81],[7,16],[8,77],[9,89],[12,82],[13,49],[14,59],[17,40],[18,83],[19,35],[20,31],[21,44],[22,92],[25,84],[26,42],[29,4],[33,78],[35,83],[36,3],[37,71],[41,24],[44,81],[45,35],[46,81],[48,81],[50,85],[52,32],[53,93],[54,89],[55,82],[56,60],[59,52],[62,79],[63,90],[64,41],[66,15],[68,43],[69,32],[70,51],[71,79],[75,39],[76,21],[78,16],[79,44],[80,73],[81,95],[83,95],[85,11],[87,80],[88,2],[90,89],[99,35],[100,95]]\n86\n107
};
// @lc code=end



/*
// @lcpr case=start
// [[2,8],[6,3],[8,6]]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]]\n5\n4\n
// @lcpr case=end

// @lcpr case=start
// [[0,3],[6,4],[8,5]]\n3\n2\n
// @lcpr case=end

 */

