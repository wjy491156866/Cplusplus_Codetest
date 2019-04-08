//344. 反转字符串
//编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 char[] 的形式给出。
//不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
//你可以假设数组中的所有字符都是 ASCII 码表中的可打印字符。

//方法一：直接交换
class Solution {
public:
    void reverseString(vector<char>& s) {
        for (int i=0; i<(s.size()/2); i++)  //直接交换首尾字符
        {
            char temp = s[i];
            s[i] = s[s.size()-1-i];
            s[s.size()-1-i] = temp;
        }
    }
};


//方法二：swap()交换函数
class Solution {
void reverseString(vector<char>& s) {
        int i=0,j=s.size()-1;
        while(i<j)
            swap(s[i++],s[j--]);
    }
};    
    
