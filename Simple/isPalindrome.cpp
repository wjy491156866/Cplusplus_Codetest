//9. 回文数
//判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

class Solution {
public:
    bool isPalindrome(int x) {
        int temp = x;   //设定标志位记录下x的原始值便于比较
        int rev = 0;    //反转数初始化
        if (x < 0)  //负数不是回文数
            return false;
        if (x >= 0 && x <=9)    //0-9为回文数
            return true;
        if (x > 9)  //当x大于9时需要反正
        {
            while(x != 0)   //整数反转算法不用考虑负数
            {
                int pop = x % 10;   //把个位数弹出
                x /= 10;    //去掉个位数
                if(rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7))  //考虑反转溢出 
                    return false;
                rev = rev * 10 + pop;   //把个位数从后面加入
            }
        }
        return rev == temp;     //对比反转后的数和前期的比较
    }
};
