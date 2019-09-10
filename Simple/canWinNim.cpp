//292. Nim游戏
//你和你的朋友，两个人一起玩 Nim游戏：桌子上有一堆石头，每次你们轮流拿掉 1 - 3 块石头。 拿掉最后一块石头的人就是获胜者。你作为先手。
//你们是聪明人，每一步都是最优解。 编写一个函数，来判断你是否可以在给定石头数量的情况下赢得游戏。

class Solution {
public:
    bool canWinNim(int n) {
        return n%4 != 0;      //如果堆中石头的数量n不能被4整除，那么你总是可以赢得Nim游戏的胜利。 
    }
};


