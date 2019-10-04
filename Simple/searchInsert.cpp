//35. 搜索插入位置
//给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。

//你可以假设数组中无重复元素。

//方法一：直接遍历
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for(int i=0; i<nums.size(); i++){   //从0下标开始遍历
            if(nums[i]>=target)  return i;    //如果当前的数比目标要大，就返回当前下标。
        }
        return nums.size();   //遍历结束都没有值比目标大，目标插入数组的最后，下标为数组的长度值。
    }
};

//方法二：二分法
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left=0, right=nums.size();  //左边界0，右边界比数组最大下标大1
        while(left<right){
            int mid = (left+right)/2; //求中间下标值
            if(nums[mid]>target){ 判断中间下标对应的数组值与目标比较
                right=mid;    //如果目标比中间值小，右边界减小
            }
            else if(nums[mid]<target){
                left = mid+1;   //如果目标比中间值大，则更新左边界
            }
            else
                return mid;   //如果相同，就返回中间下标
        }
        return left;    //遍历结束还没有对应的目标值，左边界就是目标可以插入的位置。
    }
};
