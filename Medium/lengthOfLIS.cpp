//300. 最长上升子序列
//给定一个无序的整数数组，找到其中最长上升子序列的长度。


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

