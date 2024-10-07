class Solution {
public:
    int minLength(string s)
    {
        stack<char> RemoveStr;
        
        for(char C : s)
        {
            if(RemoveStr.empty())
            {
                RemoveStr.push(C);
                continue;
            }
            
            if(RemoveStr.top() == 'A' && C == 'B')
            {
                RemoveStr.pop();
            }
            else if(RemoveStr.top() == 'C' && C == 'D')
            {
                RemoveStr.pop();
            }
            else 
            {
                RemoveStr.push(C);
            }
        }
        
        return static_cast<int>(RemoveStr.size());
    }
};