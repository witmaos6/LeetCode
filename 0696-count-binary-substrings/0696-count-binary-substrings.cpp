class Solution {
public:
    int countBinarySubstrings(string s)
    {
        vector<int> Counts;
        int Count = 0;
        char Prev = '-';
        for(char& C : s)
        {
            if(C == Prev)
            {
                Count++;
            }
            else
            {
                Counts.push_back(Count);
                Prev = C;
                Count = 1;
            }
        }
        Counts.push_back(Count);

        const int N = static_cast<int>(Counts.size());
        int Result = 0;
        for(int i = 1; i < N; i++)
        {
            int Num = Counts[i - 1];
            int Other = Counts[i];

            Result += min(Num, Other);
        }
        return Result;
    }
};