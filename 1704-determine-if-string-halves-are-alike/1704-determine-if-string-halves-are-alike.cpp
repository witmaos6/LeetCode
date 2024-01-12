class Solution {
    const array<char, 10> Vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
public:
    bool halvesAreAlike(string s)
    {
        const int N = static_cast<int>(s.size());
        const int Half = N / 2;
        
        int AVowels = GetNrOfVowels(s, 0, Half);
        int BVowels = GetNrOfVowels(s, Half, N);
        
        return (AVowels == BVowels);
    }
    
private:
    int GetNrOfVowels(const string& S, int Begin, int End)
    {
        int NrOfVowels = 0;
        for(int i = Begin; i < End; i++)
        {
            if(IsVowel(S[i]))
            {
                NrOfVowels++;
            }
        }
        
        return NrOfVowels;
    }
    
    bool IsVowel(char C)
    {
        for(char Vowel : Vowels)
        {
            if(C == Vowel)
            {
                return true;
            }
        }
        
        return false;
    }
};