/*
 * @lc app=leetcode.cn id=2475 lang=cpp
 * @lcpr version=21909
 *
 * [2475] 数组中不等三元组的数目
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
    vector<int> arr;
    int cnt=0;
public:
    int unequalTriplets(vector<int>& nums) {
        this->arr=nums;
        // sort(arr.begin(),arr.end());
        for(int i=0;i+2<arr.size();i++)
        {
            for(int j=i+1;j+1<arr.size();j++)
            {
                if(arr[j]==arr[i])continue;
                for(int k=j+1;k<arr.size();k++)
                {
                    if(arr[k]==arr[j]||arr[k]==arr[i])continue;   
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [4,4,2,4,3]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,1,1]\n
// @lcpr case=end

 */

