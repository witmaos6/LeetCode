class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words)
    {
        const int N = static_cast<int>(words.size());

        int Count = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                if(IsPrefix(words[i], words[j]) && IsSuffix(words[i], words[j]))
                {
                    Count++;
                }
            }
        }
        return Count;
    }

private:
    bool IsPrefix(const string& Word1, const string& Word2)
    {
        const int Word1Size = static_cast<int>(Word1.size());
        const int Word2Size = static_cast<int>(Word2.size());

        if(Word1Size > Word2Size)
            return false;

        for(int i = 0; i < Word1Size; i++)
        {
            if(Word1[i] != Word2[i])
                return false;
        }
        return true;
    }

    bool IsSuffix(const string& Word1, const string& Word2)
    {
        const int Word1Size = static_cast<int>(Word1.size());
        const int Word2Size = static_cast<int>(Word2.size());

        if(Word1Size > Word2Size)
            return false;

        int Index = Word2Size - 1;
        for(int i = Word1Size - 1; i >= 0; i--)
        {
            if(Word1[i] != Word2[Index])
                return false;

            Index--;
        }
        return true;
    }  
};