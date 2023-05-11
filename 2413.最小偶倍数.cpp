/*
 * @lc app=leetcode.cn id=2413 lang=cpp
 * @lcpr version=21906
 *
 * [2413] 最小偶倍数
 */
#include<iostream>
using namespace std;
// @lc code=start
class Solution {
public:
    int smallestEvenMultiple(int n) {
        int a=0,b=0,c=2,d=3,e=4,f=5,g=6,h=7,i=8,j=9,k=10,m=11;
        asm(
            "add %2,%0\n\t"
            "add %13,%1\n\t"
            :"=r"(a),"+r"(b),"+r"(c)
            :"r"(d),"r"(e),"r"(f),"r"(g),"r"(h),"r"(i),"r"(j),"r"(k),"r"(m)
        );//此处a为只写所以不可读,%12为b，%13为c，%14就超出调用范围了
        printf("a=%d,b=%d,c=%d,d=%d",a,b,c,d);
        return 0;
        // int a=n;
        // int b=n;
        // asm(
        //     "andl %0,$1\n\t"
        //     "jnz T\n\t"
        //     "jmp E\n\t"
        //     "T:    shl %1,$1\n\t"
        //     "E:   \n\t"
        //     :"+r" (a),"+r" (b)
        // );
        // return b;
        // return n<<(n&1);
    }
};
// @lc code=end



/*
// @lcpr case=start
// 5\n
// @lcpr case=end

// @lcpr case=start
// 6\n
// @lcpr case=end

 */

