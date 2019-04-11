//476. 数字的补数
//给定一个正整数，输出它的补数。补数是对该数的二进制表示取反。
//注意:
//1.给定的整数保证在32位带符号整数的范围内。
//2.你可以假定二进制数不包含前导零位。

//方法1：按位异或法
class Solution {
public:
    int findComplement(int num) {
        int temp = num, c = 0;
        while (temp > 0)
        {
            temp >>= 1; //x>>n表示x转换的二进制右移n位，即把最右边一位的n删掉,x>>=1等价于x=x>>1
            c = (c << 1) + 1; //左移与右移运算相反，构造c=0111…,           
        }
        return num ^ c; //异或：相同为0，不同为1，0^0=0， 1^0=1， 0^1=1， 1^1=0 
    }
};
//& 与：有0则0； | 或：有1则1；

//方法二：计算二进制取反
class Solution {
public:
    int findComplement(int num) {
        vector<int> temp;
        while(num>0)    //计算当前数字的二进制表示
        {
            temp.push_back(num%2);  //将除以2的余数加到vector的最后面
            num /=2;    //取除以2之后的整数
        }
        int sum = 0,j=0;    
        for(int i=0;i<temp.size();i++)
        {
            temp[i] = temp[i]>0?0:1;    //把0和1取反
            sum = sum+temp[i]*pow(2,j); //二进制转十进制的式子
            j++;    //幂次
        }
        return sum;
    }
};

