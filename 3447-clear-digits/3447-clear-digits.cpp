class Solution {
public:
    string clearDigits(string s)
    {
        stack<char> Stack;

        for(char& C : s)
        {
            if(isdigit(C))
            {
                if(!Stack.empty())
                {
                    Stack.pop();
                }
            }
            else
            {
                Stack.push(C);
            }
        }

        string Result;
        while(!Stack.empty())
        {
            Result += Stack.top();
            Stack.pop();
        }

        reverse(Result.begin(), Result.end());
        return Result;
    }
};