class Solution {
    vector<char> Vowels = {'a','e','i','o','u'};
public:
    int maxVowels(string s, int k)
    {
        const int N = static_cast<int>(s.size());
        int Result = 0;
        int NrOfVowel = 0;
        int SubSize = 0;
        
        for(int i = 0; i <= N; i++)
        {
            if(SubSize < k)
            {
                if(bIsVowelLetter(s[i]))
                {
                    NrOfVowel++;
                }
                SubSize++;
            }
            else
            {
                if(bIsVowelLetter(s[i]))
                {
                    NrOfVowel++;
                }
                if(bIsVowelLetter(s[i - k]))
                {
                    NrOfVowel--;
                }
            }
            Result = max(Result, NrOfVowel);
        }
        
        return Result;
    }
    
private:
    bool bIsVowelLetter(char c)
    {
        for(char Vowel : Vowels)
        {
            if(Vowel == c)
            {
                return true;
            }
        }
        return false;
    }
};