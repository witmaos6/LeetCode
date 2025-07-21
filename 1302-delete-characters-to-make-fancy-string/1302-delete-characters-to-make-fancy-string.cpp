class Solution {
public:
    string makeFancyString(string s)
    {
        string Fancy;
        char Prev = '-';
        int Count = 0;
        for(char& C : s)
        {
            if(Prev == C)
            {
                Count++;
                if(Count >= 3)
                    continue;
            }
            else
            {
                Prev = C;
                Count = 1;
            }
            Fancy += C;
        }
        return Fancy;
    }
};