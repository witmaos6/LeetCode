class Solution {
public:
    int numberOfSubstrings(string s)
    {
        vector<int> C1 = {0};
        int Count1 = 0;
        int Count0 = 0;
        int Result = 0;

        for(const char& C : s)
        {
            if(C == '1')
            {
                Count1++;
            }
            else if(C == '0')
            {
                Count0++;
            }

            if(C == '0')
            {
                C1.push_back(Count1);
            }
            Result += Count1 - C1[Count0];

            for(int C0 = Count0 - 1; C0 >= 0; C0--)
            {
                const int Num0 = Count0 - C0;
                if(Num0 * Num0 > Count1)
                    break;

                const int Right = Count1 - C1[C0];
                const int Left = Count1 - C1[C0 + 1];

                if(Right < Num0 * Num0)
                {
                    continue;
                }
                else
                {
                    Result += max(0, Right - max(Left, Num0 * Num0) + 1);
                }
            }
        }
        return Result;
    }
};