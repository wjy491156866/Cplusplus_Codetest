//3. 无重复字符的最长子串
//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

//方法一：双指针滑动窗口法
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size(), max = 0, temp = 0;    //字符串长度，最长字符串数，右边界下标
        for(int i=0; i<len; i++)    //慢指针，递进且固定右边界
        {
            for (int j=temp; j<i; j++)    //快指针，从左边界开始递进到右边界
            {
                if(s[j] == s[i])    //如果从右边界递进的过程中有与左边界重复项
                {
                    temp = j+1;   //左边界更新并跳出循环
                    break;
                }
            }
            if(i-temp+1 > max)    //判断此时两个边界的长度与max的大小。
                max = i-temp+1;
        }
        return max;   //返回最大个数
        
    }
};

