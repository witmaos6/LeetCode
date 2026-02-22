class Solution {
public:
    int binaryGap(int n)
    {
        vector<bool> Bitset;
        while(n > 0)
        {
            Bitset.push_back(n & 1);
            n >>= 1;
        }

        const int N = static_cast<int>(Bitset.size());
        int PreIndex = N - 1;
        int Result = 0;
        for(int i = N - 2; i >= 0; i--)
        {
            if(Bitset[i])
            {
                Result = max(Result, PreIndex - i);
                PreIndex = i;
            }
        }
        return Result;
    }
};