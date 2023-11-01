/*
 * @lc app=leetcode.cn id=415 lang=cpp
 * @lcpr version=21910
 *
 * [415] 字符串相加
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
class BigInt
{
public:
    string self;//逆序过的
    BigInt(string num);
    BigInt();
    string BigAdd(string n1,string n2)
    {
        string sum="";
        int cfNum=0;
        for(int i=0;i<min(n1.length(),n2.length());i++)
        {
            int s=n1[i]-'0'+n2[i]-'0';
            sum.push_back('0'+((s+cfNum)%10));
            cfNum=(cfNum+s)/10;
        }
        if(n1.length()<n2.length())swap(n1,n2);
        for(int i=n2.length();i<n1.length();i++)
        {
            int s=n1[i]-'0';
            sum.push_back('0'+((s+cfNum)%10));
            cfNum=(cfNum+s)/10;
        }
        if(cfNum!=0)sum.push_back('0'+cfNum);
        this->self=sum;
        return sum;
    }
    ~BigInt();
};

BigInt::BigInt(){this->self="";}
BigInt::BigInt(string num)
{
    for(int i=num.length()-1;i>=0;i--)
    {
        this->self.push_back(num[i]);
    }
}
BigInt::~BigInt()
{
}


class Solution {
public:
    string addStrings(string num1, string num2) {
        BigInt n1(num1);
        BigInt n2(num2);
        BigInt sum;
        sum.BigAdd(n1.self,n2.self);
        string ans="";
        // cout<<sum.self<<","<<sum.self.length()<<endl;
        for(int i=sum.self.length()-1;i>=0;i--)ans.push_back(sum.self[i]);
        return ans;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "11"\n"123"\n
// @lcpr case=end

// @lcpr case=start
// "456"\n"77"\n
// @lcpr case=end

// @lcpr case=start
// "0"\n"0"\n
// @lcpr case=end

 */

