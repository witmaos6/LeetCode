class MyStack {
    queue<int> Q;
public:
    MyStack()
    {
        
    }
    
    void push(int x)
    {
        Q.push(x);
    }
    
    int pop()
    {
        size_t Size = Q.size();
        int Value = 0;
        
        while(Size > 1)
        {
            int X = Q.front();
            Q.pop();
            Q.push(X);
            
            Size--;
        }
        
        Value = Q.front();
        Q.pop();
        
        return Value;
    }
    
    int top()
    {
        return Q.back();
    }
    
    bool empty()
    {
        return Q.empty();
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