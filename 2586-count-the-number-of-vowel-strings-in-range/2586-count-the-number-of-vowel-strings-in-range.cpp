class Solution {
    const vector<char> Vowels = {'a','e','i','o','u'};
public:
    int vowelStrings(vector<string>& words, int left, int right)
    {
        int Count = 0;
        for(int i = left; i <= right; i++)
        {
            if(bIsVowel(words[i].front()) && bIsVowel(words[i].back()))
            {
                Count++;
            }
        }
        return Count;
    }
    
private:
    bool bIsVowel(const char C)
    {
        for(const char Vowel : Vowels)
        {
            if(Vowel == C)
            {
                return true;
            }
        }
        return false;
    }
};