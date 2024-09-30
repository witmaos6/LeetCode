class CustomStack {
    vector<int> Stack;
    int Index = 0;
public:
    CustomStack(int maxSize)
    {
        Stack.resize(maxSize);
    }
    
    void push(int x)
    {
        if(Index < static_cast<int>(Stack.size()))
        {
            Stack[Index] = x;
            ++Index;
        }
    }
    
    int pop()
    {
        if(Index == 0)
        {
            return -1;
        }
        
        int Value = Stack[--Index];
        return Value;
    }
    
    void increment(int k, int val)
    {
        int Range = min(k, static_cast<int>(Stack.size()));
        for(int i = 0; i < Range; ++i)
        {
            Stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */