//231. 2的幂
//给定一个整数，编写一个函数来判断它是否是 2 的幂次方。


//方法一：连除法
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 1) return true;  //如果是1正确
        if (n%2 == 1 || n <= 0) return false; //如果小于或等于0，或者不能整除2为错误
        while (true)
        {
            n = n/2;  //得到除以2之后的数
            if(n%2 && n == 1) return true;      //0&&0=0，0&&1=0，1&&0=0，1&&1=1；
            if(n%2 && n != 1) return false;
        }
    }
};
