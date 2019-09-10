//14. 最长公共前缀
//编写一个函数来查找字符串数组中的最长公共前缀。
//如果不存在公共前缀，返回空字符串 ""。
//说明:
//所有输入只包含小写字母 a-z 。


//方法一：水平扫描法,时间复杂度O(S),S是所有字符串中字符数量的总和。空间复杂度O(1)。
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int vec_len = strs.size();  //vector的长度，有多少字符串
        if (vec_len == 0) return ""; //如果没有字符串就返回""
        string pre = strs[0];   //首先获取第一个字符串，把它当作比较的基准pre
        for (int i=1; i<vec_len; i++)   //开始和后面的字符串进行比较
        {
            while (strs[i].find(pre) != 0)  //在第i个字符串中找到与pre相同的字符才能再和下一个字符串对比
            {
                pre = pre.substr(0, pre.size()-1);  //取基准从0到pre数-1的字符串，相当于把pre最后一位去掉了
                if (pre.empty())    //如果pre边空了，相当于没有匹配上返回""
                    return "";
            }                
        }
        return pre;    //如果和所以字符串都匹配结束还没有返回"",就可以返回最大公共前缀
    }
};
