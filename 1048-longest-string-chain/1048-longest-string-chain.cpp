class Solution {
    typedef pair<string, int> Freq;
public:
    int longestStrChain(vector<string>& words)
    {
        vector<vector<Freq>> LevelWords(17);
        for(string& Word : words)
        {
            LevelWords[Word.size()].push_back({Word, 1});
        }
        
        int Result = 1;
        for(int Level = 1; Level < 16; Level++)
        {
            for(Freq& NextLevel : LevelWords[Level + 1])
            {
                for(Freq& CurrLevel : LevelWords[Level])
                {
                    if(bIsChain(NextLevel.first, CurrLevel.first))
                    {
                        NextLevel.second = max(NextLevel.second, CurrLevel.second + 1);
                        Result = max(Result, NextLevel.second);
                    }
                }
            }
        }

        return Result;
    }
    
private:
    bool bIsChain(const string& Next, const string& Curr)
    {
        size_t NextLength = Next.size(), CurrLength = Curr.size();
        size_t i = 0, j = 0;

        while(i < NextLength && j < CurrLength)
        {
            if(Next[i] != Curr[j])
            {
                if(i != j)
                {
                    return false;
                }
                i++;
            }
            else
            {
                i++;
                j++;
            }
        }

        return true;
    }
};