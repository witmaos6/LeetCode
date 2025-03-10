class Solution {
public:
    long long countOfSubstrings(string word, int k)
    {
        return LeastK(word, k) - LeastK(word, k + 1);
    }

private:
    long long LeastK(const string& Word, const int K)
    {
        const int N = static_cast<int>(Word.size());
        long long Result = 0;
        int Consonants = 0;
        unordered_map<char, int> VowelCount;
        int Left = 0;

        for(int Right = 0; Right < N; Right++)
        {
            if(IsVowel(Word[Right]))
            {
                VowelCount[Word[Right]]++;
            }
            else
            {
                Consonants++;
            }

            while(VowelCount.size() == 5 && Consonants >= K)
            {
                Result += N - Right;
                if(IsVowel(Word[Left]))
                {
                    VowelCount[Word[Left]]--;
                    if(VowelCount[Word[Left]] == 0)
                    {
                        VowelCount.erase(Word[Left]);
                    }
                }
                else
                {
                    Consonants--;
                }
                Left++;
            }
        }
        return Result;
    }

    array<char, 5> Vowels = {'a','e','i','o','u'};
    bool IsVowel(const char C)
    {
        for(char& Vowel : Vowels)
        {
            if(C == Vowel)
                return true;
        }
        return false;
    }
};