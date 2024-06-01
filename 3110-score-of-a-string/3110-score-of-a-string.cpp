class Solution {
public:
    int scoreOfString(string s)
    {
        const int N = static_cast<int>(s.size());
        int Result = 0;
        
        for(int i = 1; i < N; i++)
        {
            Result += abs(s[i] - s[i - 1]);
        }
        
        return Result;
    }
};