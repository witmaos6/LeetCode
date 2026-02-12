class Solution {
    unordered_map<char, int> Table;
public:
    int longestBalanced(string s)
    {
        const int N = static_cast<int>(s.size());
        int Result = 0;

        for(int i = 0; i < N; i++)
        {
            Table.clear();
            for(int j = i; j < N; j++)
            {
                int FreqNum = ++Table[s[j]];

                if(IsBalanced(FreqNum))
                {
                    Result = max(Result, j - i + 1);
                }
            }
        }
        return Result;
    }

private:
    bool IsBalanced(int FreqNum)
    {
        for(auto& [C, Freq] : Table)
        {
            if(Freq != FreqNum)
            {
                return false;
            }
        }
        return true;
    }
};