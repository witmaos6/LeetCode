class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries)
    {
        vector<int> PrefixSum = PrefixSumFromWords(words);

        vector<int> CountVowel;
        CountVowel.reserve(queries.size());
        for(vector<int>& Query : queries)
        {
            int Left = Query.front() + 1;
            int Right = Query.back() + 1;

            int Count = PrefixSum[Right] - PrefixSum[Left - 1];
            CountVowel.push_back(Count);
        }

        return CountVowel;
    }

private:
    vector<int> PrefixSumFromWords(vector<string>& Words)
    {
        const int N = static_cast<int>(Words.size());
        vector<int> PrefixSum(N + 1);

        for(int i = 1; i <= N; i++)
        {
            PrefixSum[i] = PrefixSum[i - 1];

            if(IsVowel(Words[i - 1].front()) && IsVowel(Words[i - 1].back()))
            {
                PrefixSum[i]++;
            }
        }
        return PrefixSum;
    }

    array<char, 5> Vowels = {'a','e','i','o','u'};
    bool IsVowel(const char C)
    {
        for(char& Vowel : Vowels)
        {
            if(Vowel == C)
                return true;
        }
        return false;
    }
};