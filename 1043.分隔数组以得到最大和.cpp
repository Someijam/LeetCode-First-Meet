// @lcpr-before-debug-begin




// @lcpr-before-debug-end

// @lcpr-div-debug-arg-start
// funName= maxSumAfterPartitioning
// paramTypes=["number[]","number"]
// @lcpr-div-debug-arg-end

/*
 * @lc app=leetcode.cn id=1043 lang=cpp
 *
 * [1043] 分隔数组以得到最大和
 */
#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

// @lc code=start
class Solution {
    //记忆搜索
private:
    vector<int> arr;
    unordered_map<int,int> recCache;
public:
    int tailRecurse(int tail,int k)//返回arr[0,tail]的答案
    {
        if(recCache.find(tail)!=recCache.end())return recCache[tail];//寻找记忆

        int maxAns=0;
        for(int i=1;i<=k;i++)
        {
            if(tail-i<0)break;
            int tempAns=i*(*max_element(begin(arr)+(tail-i),begin(arr)+tail));
            if(tail-i>0)tempAns+=tailRecurse(tail-i,k);
            if(tempAns>maxAns)maxAns=tempAns;
        }
        recCache[tail]=maxAns;
        return maxAns;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        this->arr=arr;
        return tailRecurse(arr.size(),k);
    }
};
// @lc code=end

