class Solution {
public:
    int balancedStringSplit(string s)
    {
        int N = static_cast<int>(s.size());
        int Result = 0;
        int LCount = 0;
        int RCount = 0;
        
        for(int i = 0; i < N; i++)
        {
            if(s[i] == 'L')
            {
                LCount++;
            }
            else if(s[i] == 'R')
            {
                RCount++;
            }
            
            if(LCount == RCount)
            {
                LCount = 0;
                RCount = 0;
                Result++;
            }
        }
        
        return Result;
    }
};