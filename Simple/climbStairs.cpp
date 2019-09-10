//70. 爬楼梯
//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
//每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
//注意：给定 n 是一个正整数。

class Solution {
public:
    int climbStairs(int n) {  //非递归方法，递归当n=44时，会显示超出时间限制
        vector<int> num;    //用数组形式来实现，规律是第n阶的次数等于第n-1阶的次数加上第n-2阶的次数
        num.push_back(1);   //1阶有一种
        num.push_back(2);   //在数组后尾加入，2阶有两种
        if (n == 1 || n == 2)
            return n;
        if (n > 2) 
            for(int i=2; i<n; i++) //把1~n阶都存下来了
            {
                num.push_back(num[i - 1] + num[i - 2]); //fn=fn-1 + fn-2
            }
        return num[n-1]; //找到第n阶的数              
    }
};


