//557. 反转字符串中的单词 III
//给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。
//注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。

//方法一：利用string方法遍历，遇到空格停止，把之前的字符串做反转，每次停止设置标志位，下次从标志位之后的字符串反转。
class Solution {
public:
    string reverseWords(string s) {
        int len = s.length(), temp = 0;
        for (int i=0; i<len; i++)
        {
            if (s[i] == ' ' || i == len-1)
            {
                if (i == len-1) i++;
                for (int j=temp; j<(i+temp)/2; j++) //j下标等于(i-temp)/2+temp
                {
                    swap(s[j],s[i-1-j+temp]);   //每个单词内容交换，左边++，右边--
                }
                temp = i+1; //标志位移到下一个字符串
            }
        }
        return s;   //返回整体字符串
    }
};

/*
交换函数swap()
template <class T> void swap ( T& a, T& b )
{
  T c(a); a=b; b=c;
}
*/

