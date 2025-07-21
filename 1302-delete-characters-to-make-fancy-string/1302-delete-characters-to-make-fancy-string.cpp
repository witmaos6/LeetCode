class Solution {
public:
    string makeFancyString(string s)
    {
        string Fancy;
        char Prev = '-';
        int Count = 0;
        const int N = static_cast<int>(s.size());
        for(int i = 0; i <= N; i++)
        {
            char C = s[i];
            if(Prev == C)
            {
                Count++;
            }
            else
            {
                if(Count >= 1)
                {
                    Fancy += Prev;
                    if(Count >= 2)
                    {
                        Fancy += Prev;
                    }
                }
                Prev = C;
                Count = 1;
            }
        }
        return Fancy;
    }
};