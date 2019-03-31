//20. 有效的括号
//给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
//有效字符串需满足：
//左括号必须用相同类型的右括号闭合。
//左括号必须以正确的顺序闭合。
//注意空字符串可被认为是有效字符串。

//方法一：利用栈后进先出的原理，时间复杂度O(n),空间复杂度O(n)
class Solution {
public:
    bool isValid(string s) {
        stack<int> temp;    //新建一个栈用于左半边的括号
        for (int i=0; i<s.length(); i++)    //遍历整个字符串
        {
            if (s[i] == ')' || s[i] == ']' || s[i] == '}')  //如果当前的括号是右边的就去判断，否则就入栈
            {
                if (temp.size() == 0) return false; //一开始就是右边括号，则无效
                //栈顶是刚刚入栈的字符，可以判断当前的右括号是否和栈顶的括号匹配，不匹配则无效。
                if (temp.top() == '(' && s[i] != ')') return false; 
                if (temp.top() == '[' && s[i] != ']') return false;
                if (temp.top() == '{' && s[i] != '}') return false;
                temp.pop(); //如果括号是匹配的就把栈顶字符弹出，开始下一次验证
            }
            else
            {
                temp.push(s[i]);    //括号是左边的就入栈
            }    
        }
        return temp.size() == 0;    //最后返回这个栈是否是空的，空的表示有效，都匹配上了。
    }
};
