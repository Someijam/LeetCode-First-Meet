// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1048 lang=cpp
 * @lcpr version=21907
 *
 * [1048] 最长字符串链
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
    vector<string> sortedWds;
    unordered_map<string,int> dict;
    unordered_map<string,int> ansDict;
public:
    bool isPrev(string a,string b)
    {
        cout<<a<<", "<<b<<" :";
        if(b.length()-a.length()!=1)
        {
            cout<<"No."<<endl;
            return false;
        }
        int pos=0;
        while(a[pos]==b[pos]&&pos<a.length())
        {
            pos++;
        }
        //记住pos，从pos往后二者应该一致
        for(int i=pos;i<a.length();i++)
        {
            if(a[i]!=b[i+1])
            {
                cout<<"No."<<endl;
                return false;
            }
        }
        cout<<"Yes."<<endl;
        return true;
    }
    int maxLengthOfTail(string s)//以s结尾的最长序列长度
    {
        if(s.length()==1)
        {
            // cout<<"Tail="<<s<<":"<<1<<endl;
            return 1;
        }
        if(ansDict.find(s)!=ansDict.end())//命中缓存
        {
            return ansDict[s];
        }
        int maxLength=0;
        for(int rm=0;rm<s.length();rm++)
        {
            string rmmedStr=s.substr(0,rm-0)+s.substr(rm+1);
            if(dict.find(rmmedStr)==dict.end())continue;
            maxLength=max(maxLength,maxLengthOfTail(rmmedStr));
        }
        // cout<<"Tail="<<s<<":"<<maxLength+1<<endl;
        ansDict[s]=maxLength+1;
        return maxLength+1;
    }
    int longestStrChain(vector<string>& words) {
        sortedWds=words;
        for(auto s : words)dict[s]=1;
        sort(sortedWds.begin(),sortedWds.end(),[&](string a,string b) ->bool {return a.length()<b.length();});
        int maxLength=1;
        for(int i=1;i<sortedWds.size();i++)
        {
            maxLength=max(maxLength,maxLengthOfTail(sortedWds[sortedWds.size()-i]));
        }
        return maxLength;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["a","b","ba","bca","bda","bdca"]\n
// @lcpr case=end

// @lcpr case=start
// ["xbc","pcxbcf","xb","cxbc","pcxbc"]\n
// @lcpr case=end

// @lcpr case=start
// ["abcd","dbqca"]\n
// @lcpr case=end

 */

