//5. 最长回文子串
//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。



class Solution {
public:
    string longestPalindrome(string str) {
        int len = str.size();
        if (len<2) return str;
        int s = 0, e = 0;
        int dp[len] = {0, };
        for(int j = 0; j < len; ++j){
            for(int i = 0; i < j; ++i){
                if(!(dp[i] = dp[i + 1] || str[i] != str[j]) && (e - s) <= (j - i)) 
                    s = i, e = j;
            }
        }
        return str.substr(s, e - s + 1);
    }
};
