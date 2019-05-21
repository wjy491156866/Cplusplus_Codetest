//155. 最小栈
/*
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
*/


//方法一：双栈法
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;       //数据栈
    stack<int> min;     //最小值栈
    
    MinStack() {        //留空
        
    }
    
    void push(int x) {      //把x加入栈顶
        s.push(x);      //加入栈顶
        if(min.empty() || x<=min.top())    //如果最小栈是空的或者x小于或等于栈顶的数 
        {
            min.push(x);        //加入最小栈
        }
    }
    
    void pop() {        //删除栈顶元素
        if (s.top() == min.top())       //如果数据的头和最小栈的头相同
            min.pop();      //把最小栈的头删除
        s.pop();        //把数据栈的头删掉
    }
    
    int top() {     //获取栈顶元素
        return s.top();     //返回数据栈的头
    }
    
    int getMin() {      //检索栈中的最小元素
        return min.top();       //返回最小栈的头
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
