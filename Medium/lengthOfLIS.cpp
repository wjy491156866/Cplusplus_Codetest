//300. 最长上升子序列
//给定一个无序的整数数组，找到其中最长上升子序列的长度。

//方法一：动态规划贪心算法，找最小的与之前的替换。
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size(), count = 0;
        if(len<2)   return len;
        vector<int> res;
        res.push_back(nums[0]);
        for(int i=1; i<len; i++){
            if(nums[i]>res[count]){
                res.push_back(nums[i]);
                count++;
            }
            else{	// 35题 搜索插入的位置 二分搜索
                int left=0, right=count;
                while(left<right){
                    int mid=(left+right)>>1;        //相当于/2(无符号整型可以这么做)
                    if(res[mid]>=nums[i]){
                        right=mid;
                    }
                    else{
                        left=mid+1;
                    }
                }
                res[left]=nums[i];	//左边界为插入位置，直接替换
            }
        }
        return count+1;
    }
};


//方法二：lower_bound函数法
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int len = nums.size();
        if(len<=1)  return len;
	vector<int> res;
	for (int i = 0; i < len; ++i) {
		auto iter = lower_bound(res.begin(), res.end(), nums[i]);//寻找第一个不小于nums[i]的元素
			//只有在res后面放入元素才会更改结果
		if (iter == res.end()) {//如果是end，说明res中所有元素都小于nums[i],这个元素直接放入
			res.push_back(nums[i]);
		}
		else {
			//修改操作不会影响结果，把这个大的元素修改为小的元素是为了后面可能出现更长的上升子序列
			*iter = nums[i]; //更新
		}
	}
	return res.size();
    }
};

