class Solution {
    const int DistanceLowerAndUpper = 32;
public:
    string makeGood(string s)
    {
        stack<char> St;
        for(char C : s)
        {
            if(!St.empty() && abs(C - St.top()) == DistanceLowerAndUpper)
            {
                St.pop();
            }
            else
            {
                St.push(C);
            }
        }
        
        string Result;
        while(!St.empty())
        {
            Result += St.top();
            St.pop();
        }
        reverse(Result.begin(), Result.end());
        return Result;
    }
};