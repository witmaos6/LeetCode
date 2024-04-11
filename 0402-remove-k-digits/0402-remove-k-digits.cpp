class Solution {
public:
    string removeKdigits(string num, int k)
    {
        stack<char> Monotonic;
        for(char Digit : num)
        {
            while(!Monotonic.empty() && k > 0 && Monotonic.top() > Digit)
            {
                Monotonic.pop();
                k--;
            }
            Monotonic.push(Digit);
        }
        while(k > 0)
        {
            Monotonic.pop();
            k--;
        }
        
        string Result;
        while(!Monotonic.empty())
        {
            Result += Monotonic.top();
            Monotonic.pop();
        }
        while(!Result.empty() && Result.back() == '0')
        {
            Result.pop_back();
        }
        reverse(Result.begin(), Result.end());
        
        return Result.empty() ? "0" : Result;
    }
};