//47. 全排列 II
//给定一个可包含重复数字的序列，返回所有不重复的全排列。


//方法一：递归法
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        backtrack(nums,res,0);    //从0开始递归
        return res;
    }
    void swap(int &a,int &b){   //交换函数
        int temp=a;
        a=b;
        b=temp;
    }
    bool canswap(vector<int>& nums, int cur, int end){    //判断是否可换
        for(int i=cur;i<end;i++){   //从左边界往右边界遍历有相同的情况就不进行交换
            if(nums[i]==nums[end])
                return false;
        }
        return true;
    }
    void backtrack(vector<int>& nums,vector<vector<int>> &res,int cur){
        if(cur==nums.size()){   //如果遍历到最后的节点，把当前的数组压进容器
            res.push_back(nums);
        }
        for(int j=cur;j<nums.size();j++){   //首先第cur位和后面的几位轮询交换一遍
            if(canswap(nums,cur,j)){    //先判断是否可以换
                swap(nums[cur],nums[j]);
                backtrack(nums,res,cur+1);    //递归调用在第cur+1位和后面几位轮询交换一遍
                swap(nums[cur],nums[j]);    //恢复原来的数组
            }
            
        }
    }
};
