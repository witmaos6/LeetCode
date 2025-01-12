class Solution {
public:
    bool canBeValid(string s, string locked)
    {
        const int N = static_cast<int>(s.size());
        if((N & 1) == 1)
            return false;

        int OpenCount = 0;
        for(int i = 0; i < N; i++)
        {
            if(s[i] == '(' || locked[i] == '0')
            {
                OpenCount++;
            }
            else
            {
                OpenCount--;
            }

            if(OpenCount < 0)
            {
                return false;
            }
        }

        int CloseCount = 0;
        for(int i = N - 1; i >= 0; i--)
        {
            if(s[i] == ')' || locked[i] == '0')
            {
                CloseCount++;
            }
            else
            {
                CloseCount--;
            }
            if(CloseCount < 0)
            {
                return false;
            }
        }

        return true;
    }
};