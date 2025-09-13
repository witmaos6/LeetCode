class Solution {
    const string Vowels = "aeiou";
public:
    int maxFreqSum(string s)
    {
        vector<int> Table(26);
        for(char& C : s)
        {
            Table[C - 'a']++;
        }

        int MaxVowelFreq = 0;
        int MaxConsonantFreq = 0;
        for(int i = 0; i < 26; i++)
        {
            if(IsVowel(i))
            {
                MaxVowelFreq = max(MaxVowelFreq, Table[i]);
            }
            else
            {
                MaxConsonantFreq = max(MaxConsonantFreq, Table[i]);
            }
        }
        return MaxVowelFreq + MaxConsonantFreq;
    }
private:
    bool IsVowel(int i)
    {
        for(const char& C : Vowels)
        {
            if(C == 'a' + i)
                return true;
        }
        return false;
    }
};