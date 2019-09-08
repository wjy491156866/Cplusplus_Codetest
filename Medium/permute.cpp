//46. 全排列
//给定一个没有重复数字的序列，返回其所有可能的全排列。

//方法一：递归法
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;        //二维容器
        helper(res,nums,0);   //递归函数从0位开始
        return res;
    }
    void helper(vector<vector<int> >& res,vector<int>& nums,int start){
        if(start>=nums.size()){   //如果遍历到最后的节点，把当前的数组压进容器
            res.push_back(nums);
            return;
        }
        for(int i=start;i<nums.size();i++){   //首先第start位和后面的几位轮询交换一遍
            swap(nums[i],nums[start]);  
            helper(res,nums,start+1);   //低轨调用在第start+1位和后面几位轮询交换一遍
            swap(nums[i],nums[start]);    //恢复原来的数组
        }
    }
    
};

