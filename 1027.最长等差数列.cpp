// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1027 lang=cpp
 * @lcpr version=21906
 *
 * [1027] 最长等差数列
 */
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
// @lc code=start
class Solution {
private:
    vector<int> arr;
    vector<vector<int> > dict;
    int maxD;
public:
    int recursive(int tailIndex,int d)//以尾巴结尾，公差为d的LAS
    {
        // cout<<"Current:tail="<<tailIndex<<", d="<<d<<endl;
        if(tailIndex==0)
            return 1;
        if(dict[tailIndex][d+maxD]!=0)//找到缓存
        {
            return dict[tailIndex][d+maxD];
        }
        //找到等差数列上一个人（如果有）的序号
        int lastAPElemIndex=-1;
        for(int i=tailIndex-1;i>=0;i--)
        {
            if(arr[i]==arr[tailIndex]-d)
            {
                lastAPElemIndex=i;
                break;
            }
        }
        //上一个人是arr[lastAPElemIndex]
        // int subLength=recursive(lastAPElemIndex,d);
        int subLength;
        if(lastAPElemIndex>=0)
        {
            int tempAns=recursive(lastAPElemIndex,d)+1;
            dict[tailIndex][d+maxD]=tempAns;
            cout<<"Queried tail="<<tailIndex<<", d="<<d<<endl;
            return tempAns;
        }
        else return 1;
    }
    int longestArithSeqLength(vector<int>& nums) {
        this->arr=nums;
        auto [minNum,maxNum]=minmax_element(nums.begin(),nums.end());
        maxD=*maxNum-*minNum;
        int maxLength=1;
        if(true)
        {
            vector<int> sampleTemp(2*maxD+1,0);
            vector<vector<int> > sampleDict(nums.size(),sampleTemp);
            dict=sampleDict;
        }
        //缓存，dict[tail][d+maxD]表示0-tail中公差为d的LAS元素数目
        for(int tail=nums.size()-1;tail>0;tail--)
        {
            for(int d=-maxD;d<=maxD;d++)
            {
                int tempAns=recursive(tail,d);
                // cout<<"When D="<<d<<", maxLenth="<<tempAns<<endl;
                if(tempAns>maxLength)maxLength=tempAns;
            }
        }
        return maxLength;
    }
    
};
// @lc code=end



/*
// @lcpr case=start
// [3,6,9,12]\n
// @lcpr case=end

// @lcpr case=start
// [9,4,7,2,10]\n
// @lcpr case=end

// @lcpr case=start
// [20,1,15,3,10,5,8]\n
// @lcpr case=end

 */

