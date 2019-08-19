//238. 除自身以外数组的乘积
//给定长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
//输入: [1,2,3,4]
//输出: [24,12,8,6]
//说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
//进阶：
//你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）

//左右同时乘
//一共有Cn,n-1种情况，相当有n种情况。
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        int left=1, right=1;    //往左和往右乘的系数
        vector<int> res(len,1);   //n种情况
        for(int i=0; i<len; i++)
        {
            res[i] = res[i] * left;
            left = left * nums[i];
            res[len-1-i] = res[len-1-i] * right;
            right = right * nums[len-1-i];
        }
        return res;
    }
};


