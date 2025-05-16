class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups)
    {
        const int N = static_cast<int>(groups.size());
        vector<int> Memo(N, 1);
        vector<int> Parent(N, -1);

        int MaxInt = 0;

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(groups[i] != groups[j] && DiffByOneChar(words[i], words[j]) && Memo[i] < Memo[j] + 1)
                {
                    Memo[i] = Memo[j] + 1;
                    Parent[i] = j;
                }
            }
            MaxInt = max(MaxInt, Memo[i]);
        }

        vector<string> Result;
        for(int i = 0; i < N; i++)
        {
            if(MaxInt == Memo[i])
            {
                while(i != -1)
                {
                    Result.push_back(words[i]);
                    i = Parent[i];
                }
                break;
            }
        }
        reverse(Result.begin(), Result.end());
        return Result;
    }

private:
    bool DiffByOneChar(string& Word1, string& Word2)
    {
        if(Word1.size() != Word2.size())
            return false;

        int DiffCount = 0;
        const int N = static_cast<int>(Word1.size());
        for(int i = 0; i < N; i++)
        {
            DiffCount += (Word1[i] != Word2[i]);
        }
        return DiffCount == 1;
    }
};