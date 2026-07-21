class Solution {
public:
    int maxActiveSectionsAfterTrade(string s)
    {
        int Ones = 0;
        for(char& C : s)
        {
            if(C == '1')
                Ones++;
        }

        s = "1" + s + "1";
        const int N = s.size();
        int i = 0;
        int Result = Ones;

        while(i < N && s[i] == '1')
            i++;

        int C10 = 0;
        while(i < N && s[i] == '0')
        {
            C10++;
            i++;
        }

        while(i < N)
        {
            int C11 = 0;
            while(i < N && s[i] == '1')
            {
                C11++;
                i++;
            }

            if(C11 == 0)
                break;
            
            int C20 = 0;
            while(i < N && s[i] == '0')
            {
                C20++;
                i++;
            }

            if(C20 == 0)
                break;

            Result = max(Result, Ones + C10 + C20);
            C10 = C20;
        }
        return Result;
    }
};