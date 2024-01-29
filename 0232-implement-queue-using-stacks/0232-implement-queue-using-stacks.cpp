class MyQueue {
public:
    stack<int> FrontData;
    stack<int> SavingData;
    MyQueue()
    {
        
    }
    
    void push(int x)
    {
        while(!FrontData.empty()) 
        {
            SavingData.push(FrontData.top());
            FrontData.pop();
        }
        SavingData.push(x);
        while(!SavingData.empty()) 
        {
            FrontData.push(SavingData.top());
            SavingData.pop();
        }
    }
    
    int pop()
    {
        int CurrentData = FrontData.top();
        FrontData.pop();
        return CurrentData;
    }
    
    int peek()
    {
        return FrontData.top();
    }
    
    bool empty()
    {
        return FrontData.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */