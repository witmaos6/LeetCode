class Solution {
public:
    bool isValid(string s)
    {
        int N = static_cast<int>(s.size());
        if(N % 3 != 0)
        {
            return false;
        }
        
        stack<char> Stack;
        
        for(char word : s)
        {
            if(word == 'a' || word == 'b')
            {
                Stack.push(word);
            }
            else if(word == 'c')
            {
                int Count = 2;
                string Sub;
                while(!Stack.empty() && Count > 0)
                {
                    Sub += Stack.top();
                    Stack.pop();
                    Count--;
                }
                if(Sub != "ba")
                {
                    return false;
                }
            }
        }

        return Stack.empty();
    }
};