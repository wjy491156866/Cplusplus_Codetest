//507. 完美数
//对于一个 正整数，如果它和除了它自身以外的所有正因子之和相等，我们称它为“完美数”。
//给定一个 整数 n， 如果他是完美数，返回 True，否则返回 False
//28 = 1 + 2 + 4 + 7 + 14
//输入的数字 n 不会超过 100,000,000. (1e8)



class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num % 2 != 0) return false;    //不能被2整除不是完美数
        int tmp = 1;
        for(int i = 2; i < num / i; i++){   //不重复考虑被除的因子
            if(num % i == 0){   //如果能整除就相加
                tmp += i + num / i;
            }
        }
        return tmp == num;    //最后判断
    }
};
