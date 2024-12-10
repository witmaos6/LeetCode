class Solution {
public:
    int maximumLength(string s)
    {
        array<array<int, 51>, 26> Count = {0};
        
        const int N = static_cast<int>(s.size());
        
        int L = 0;
        int Result = -1;
        for(int R = 1; R <= N; R++)
        {
            while(R < N && s[R] == s[L])
            {
                R++;
            }
            for(int i = R - 1; i >= L; i--)
            {
                int Length = i - L + 1;
                int Index = s[L] - 'a';
                
                Count[Index][Length] += R - i;
                if(Count[Index][Length] >= 3 && Length > Result)
                {
                    Result = Length;
                }
            }
            
            L = R;
        }
        
        return Result;
    }
};