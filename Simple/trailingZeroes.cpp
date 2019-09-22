//172. 阶乘后的零
//给定一个整数 n，返回 n! 结果尾数中零的数量。

//计算5的个数
class Solution {
public:
    int trailingZeroes(int n) {
        int count=0;
        while(n>=5){
            count += n/5;
            n /= 5;
        }
        return count;
    }
};

