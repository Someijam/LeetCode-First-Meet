/*
 * @lc app=leetcode.cn id=1105 lang=cpp
 * @lcpr version=21906
 *
 * [1105] 填充书架
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
    vector<vector<int> > books;
    int width;
    unordered_map<int,int> dict;
public:
    int recBooks(int tail)
    {
        if(tail==0)
        {
            return books[0][1];
        }
        if(dict.find(tail)!=dict.end())return dict[tail];
        int ans=0x3f3f3f3f;
        int thisLayerWidth=0;
        int thisLayerHeight=0;
        for(int i=tail;i>=0;i--)
        {
            thisLayerWidth+=books[i][0];
            if(thisLayerWidth>this->width)break;
            thisLayerHeight=max(thisLayerHeight,books[i][1]);
            int prevLayerHeight;
            if(i-1>=0)prevLayerHeight=recBooks(i-1);
            else prevLayerHeight=0;
            //再加上这一层的书[i,tail]的高度
            if(prevLayerHeight+thisLayerHeight<ans)ans=prevLayerHeight+thisLayerHeight;
        }
        // cout<<"Tail="<<tail<<", Height="<<ans<<endl;
        dict[tail]=ans;
        return ans;
    }
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        this->books=books;
        this->width=shelfWidth;
        return recBooks(books.size()-1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[1,3],[2,4],[3,2]]\n6\n
// @lcpr case=end

 */

