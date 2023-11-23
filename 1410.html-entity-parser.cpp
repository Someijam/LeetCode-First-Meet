// @lcpr-before-debug-begin




// @lcpr-before-debug-end

/*
 * @lc app=leetcode.cn id=1410 lang=cpp
 * @lcpr version=30110
 *
 * [1410] HTML 实体解析器
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
    unordered_map<string,string> dict={{"&quot;","\""},{"&apos;","\'"},{"&amp;","&"},{"&gt;",">"},{"&lt;","<"},{"&frasl;","/"}};
public:
    string entityParser(string text) 
    {
        for(int i=0;i<text.length();i++)
        {
            for(int len=0;i+len<=text.length()&&len<8;len++)
            {
                if(dict.find(text.substr(i,len))!=dict.end())
                {
                    // cout<<dict[text.substr(i,len)]<<endl;
                    text.replace(i,len,dict[text.substr(i,len)],0,1);
                    break;
                }
            }
        }

        return text;
    }
};
// @lc code=end


// @lcpr-div-debug-arg-start
// funName=entityParser
// paramTypes= ["string"]
// @lcpr-div-debug-arg-end




/*
// @lcpr case=start
// "& is an HTML entity but &ambassador; is not."\n
// @lcpr case=end

// @lcpr case=start
// "and I quote: "...""\n
// @lcpr case=end

// @lcpr case=start
// "Stay home! Practice on Leetcode :)"\n
// @lcpr case=end

// @lcpr case=start
// "x > y && x < y is always false"\n
// @lcpr case=end

// @lcpr case=start
// "leetcode.com⁄problemset⁄all"\n
// @lcpr case=end

 */

