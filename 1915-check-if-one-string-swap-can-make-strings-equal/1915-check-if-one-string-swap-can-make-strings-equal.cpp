class Solution {
public:
    bool areAlmostEqual(string s1, string s2)
    {
        const int N = static_cast<int>(s1.size());

        int Count = 0;
        int Index1 = -1;
        int Index2 = -1;

        for(int i = 0; i < N; i++)
        {
            if(s1[i] != s2[i])
            {
                Count++;
                if(Index1 == -1)
                {
                    Index1 = i;
                }
                else if(Index2 == -1)
                {
                    Index2 = i;
                }
                else
                {
                    return false;
                }
            }
        }

        if(Count == 0)
        {
            return true;
        }
        if(Count == 2 && s1[Index1] == s2[Index2] && s1[Index2] == s2[Index1])
        {
            return true;
        }
        return false;
    }
};