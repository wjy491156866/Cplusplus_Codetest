//7. 整数反转
//给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

class Solution {
public:
    int reverse(int x) {
        int rev = 0; 
        while (x != 0){ //如果整形数不是0
            int pop = x % 10; //把当前数的个位数取出
            x /= 10; //把个位数去掉
            //往前顶之前先判断是否有可能会溢出[-2147483648，2147483647]
            //最大的不能大于int的最大值，最小不能小于int的最小值
            if (rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN/10 && pop > 8)) return 0;
            //往前顶一位空出个位数，然后加上个位数
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
