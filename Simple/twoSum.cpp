//1. 两数之和
//给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int N, f, l;
        N = nums.size(); //获取vector大小
        for (int i=0; i<N-1; i++) //设定外层遍历 
            for (int j=i+1; j<N; j++) //设定内层遍历
            {
                if (nums[j] == target - nums[i]) //判断是否满足条件
                {
                    f = i; //记录头元素
                    l = j; //记录尾元素
                    break;
                }
            }
        return vector<int>{f,l};        //下标输出
    }
};

