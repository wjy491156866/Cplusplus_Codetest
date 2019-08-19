//217. 存在重复元素
//给定一个整数数组，判断是否存在重复元素。
//如果任何值在数组中出现至少两次，函数返回 true。如果数组中每个元素都不相同，则返回 false。

//方法一：排序比较
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return false;
        sort(nums.begin(),nums.end());    //排序
        for(int i=0; i<len-1; i++)    //遍历数组
        {
            if(nums[i] == nums[i+1])    //前后比较，相同就返回true
                return true;
        }
        return false;   //遍历结束没有相同返回false
    }
};

//方法二：set方法
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end());    //set不允许两个元素有相同键值
        if(s.size() != nums.size())
            return true;
        return false;
    }
};


//方法三：map方法
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> nums1;
        for(int i = 0;i<nums.size();i++)
        {
            nums1[nums[i]]++;
            if(nums1[nums[i]] == 2)
                return true;
        }        
        return false;
    }
};



