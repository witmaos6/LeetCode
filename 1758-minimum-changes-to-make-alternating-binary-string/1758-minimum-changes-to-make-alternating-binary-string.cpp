class Solution {
public:
    int minOperations(string s)
    {
        const int N = static_cast<int>(s.size());
        if(N == 1)
            return 0;
        
        int Count1 = 0; // 0101...
        int Count2 = 0; // 1010...
        for(int i = 0; i < N; i++)
        {
            if((i & 1) == 0)
            {
                if(s[i] == '0')
                {
                    Count1++;
                }
                else if(s[i] == '1')
                {
                    Count2++;
                }
            }
            else
            {
                if(s[i] == '1')
                {
                    Count1++;
                }
                else if(s[i] == '0')
                {
                    Count2++;
                }
            }
        }
        return min((N - Count1), (N - Count2));
    }
};