//136. 只出现一次的数字
//给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
//说明：
//你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();    //获取容器长度
        int single = 0; //初始化
        for (int i=0; i<n; i++)
        {
            //a^a=0;  0^a=a;  a^b=b^a;
            single ^=nums[i];   //如果这个数异或不到自己最后结果还是本身               
        }
        return single;  //返回没有重复的数
    }
};
