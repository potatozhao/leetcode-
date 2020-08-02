/*
60. 第k个排列
难度
中等

290





给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。

按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：

"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。

说明：

给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。
示例 1:

输入: n = 3, k = 3
输出: "213"
示例 2:

输入: n = 4, k = 9
输出: "2314"
*/


class Solution {
public:
    vector<int> f;
    string getPermutation(int n, int k) {
        string ret;
        string s = string("123456789").substr(0,n);
        // 首先填充阶乘数组
        f = vector<int>(n+1,1);
        for(int i = 1; i< n; i++){
            f[i+1] = f[i]*(i+1);
        }
        f[0]=0;
        // 开始除法方案;
        --k;
        while(k>0){
            size_t t = k/f[n-1];
            ret.push_back(s[t]);
            s.erase(s.begin()+t);
            k %= f[n-1];
            n--;
        }
        ret = ret + s;
        return ret;
    }
};


/*
考虑到我们的目标仅仅是找到第k个排列，有没有办法不用列举中间的排列，直接根据输入信息和排列规律直接找到第k个排列？

在n个数字的排列中，根据手动排列的习惯，先固定第一个位置的数字，还剩下最多(n-1)!种排列，再由放到第一个位置的数字原先的位置i(从左往右第i个)的不同，表示跳过了i(n-1)种排列。要找到第k个排列，先由i = k/(n-1)得出应该移到第一个位置的数字索引，并由k = k%(n - 1)更新k.*

这样，我们可以从左往右遍历原先字符串的最小排列，每一次找到应该放在左边第一个位置的数字，将其添加到结果字符串中，并从原字符串中删除，然后对剩下的字符串重复这一操作，直到k==0。此外由于字符串最初的状态就是第１个排列，所以要将输入的k先减一。

作者：fu-guang
链接：https://leetcode-cn.com/problems/permutation-sequence/solution/c-ji-bai-100-3-xing-dai-ma-shi-xian-by-fu-guang/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。





class Solution {
    static const vector<int> fac;
public:
    string getPermutation(int n, int k) {
        string res;
        string s = string("123456789").substr(0, n);
        --k;
        while(k > 0)
        {
            size_t i = k/fac[n - 1];
            res.push_back(s[i]);
            s.erase(s.begin() + i);
            k %= fac[n - 1];
            --n;
        }
        return res + s;
    }
};
const vector<int> Solution::fac = {0,1,2,6,24,120,720,5040,40320,362880,3628800};

作者：fu-guang
链接：https://leetcode-cn.com/problems/permutation-sequence/solution/c-ji-bai-100-3-xing-dai-ma-shi-xian-by-fu-guang/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
