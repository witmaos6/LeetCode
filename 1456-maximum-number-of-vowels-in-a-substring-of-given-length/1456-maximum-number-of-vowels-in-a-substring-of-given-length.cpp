class Solution {
    vector<char> Vowels = {'a','e','i','o','u'};
public:
    int maxVowels(string s, int k)
    {
        const int N = static_cast<int>(s.size());
        int CurrCount = SubInit(s, N, k);
        int Result = CurrCount;
        
        
        for(int i = k; i < N; i++)
        {
            if(bIsVowelLetter(s[i]))
            {
                CurrCount++;
            }
            if(bIsVowelLetter(s[i - k]))
            {
                CurrCount--;
            }
            Result = max(Result, CurrCount);
        }
        
        return Result;
    }
    
private:
    int SubInit(string& s, int N, int k)
    {
        int Init = 0;
        for(int i = 0; i < k; i++)
        {
            if(bIsVowelLetter(s[i]))
            {
                Init++;
            }
        }
        return Init;
    }
    
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