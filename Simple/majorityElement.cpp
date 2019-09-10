//169. 求众数
//给定一个大小为 n 的数组，找到其中的众数。众数是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。
//你可以假设数组是非空的，并且给定的数组总是存在众数。


//方法一：计数法，总有一个数最多
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1;  //计数器count=1
		int major = nums[0];    //先以第0个为基准
		for (int i = 1; i < nums.size(); i++) { //第1个数开始比较
			if (major == nums[i])
				count++;    //遇到相同的就加1
			else {
				count--;    //遇到不同的就减1
				if (count == 0) {   //减到0就重新换个数开始计数
					major = nums[i + 1];
				}
			}
		}
		return major;   //返回众数
    }
};

//写法二：
//计数法，总有一个数最多
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;  //计数器count=0
		int major = nums[0];    //先以第0个为基准
		for (int i = 0; i < nums.size(); i++) { //第1个数开始比较
            if (count == 0) {   //减到0就重新换个数开始计数
                major = nums[i];
            }		
            if (major == nums[i])
				count++;    //遇到相同的就加1
			else {
				count--;    //遇到不同的就减1
				}
		}
		return major;   //返回众数
    }
};

