//11. 盛最多水的容器
//给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//说明：你不能倾斜容器，且 n 的值至少为 2。

//双指针法
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();    //数组长度
        if (len < 2) return 0;  //数组不能小于2
        int i = 0, j = len-1, area = 0; //头指针和尾指针以及面积大小
        while (i < j) //头指针要小于尾指针
        {
            int temp = min(height[i],height[j]) * (j - i);  //计算面积，两个数最小的值乘以两个数的位置差
            area = max(area,temp);  //面积取遍历面积最大的一个
            (height[i] > height[j]) ? j-- : i++;    //为了保证面积最大，尽可能保留数值大的不移动   
        }
        return area;  //返回最大面积值
    }
};

