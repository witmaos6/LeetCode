class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        stack<int> S;
        int i = 0;
        
        for(int& Push : pushed)
        {
            S.push(Push);
            
            while(!S.empty() && S.top() == popped[i])
            {
                S.pop();
                i++;
            }
        }
        
        return S.empty();
    }
};