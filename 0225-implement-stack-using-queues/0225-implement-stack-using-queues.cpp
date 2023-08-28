class MyStack {
    queue<int> Q1;
    queue<int> Q2;
public:
    MyStack()
    {
        
    }
    
    void push(int x)
    {
        if(Q2.empty())
        {
            Q1.push(x);
        }
        else
        {
            Q2.push(x);
        }
    }
    
    int pop()
    {
        int Value = 0;
        if(Q1.empty())
        {
            while(Q2.size() > 1)
            {
                int X = Q2.front();
                Q2.pop();
                Q1.push(X);
            }
            Value = Q2.front();
            Q2.pop();
        }
        else
        {
            while(Q1.size() > 1)
            {
                int X = Q1.front();
                Q1.pop();
                Q2.push(X);
            }
            Value = Q1.front();
            Q1.pop();
        }
        
        return Value;
    }
    
    int top()
    {
        if(Q1.empty())
        {
            return Q2.back();
        }
        else
        {
            return Q1.back();
        }
    }
    
    bool empty()
    {
        return (Q1.empty() && Q2.empty());
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */