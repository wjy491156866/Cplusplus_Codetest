//53. 最大子序和
//给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
//进阶:
//如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。


//方法一：遍历累加法，尽可能减少负数的个数，时间复杂度为O(n) 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int temp = nums[0]; //定义一个标志位
        for (int i=1; i<nums.size(); i++)
        {
            if(nums[i-1] > 0)   //如果前一位是大于0的
            {
                nums[i] += nums[i-1];   //当前位数，等于当前和前一位相加，不断地更新当前位置的数
            }
            temp = (temp >= nums[i]) ? temp : nums[i];  //当前位和标志位比较取较大的做标志位
        }
        return temp;    //返回标志位
    }
};

