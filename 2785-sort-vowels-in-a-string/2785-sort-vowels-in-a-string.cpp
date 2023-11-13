class Solution {
    array<char, 10> Vowels = {'A','E','I','O','U','a','e','i','o','u'};
public:
    string sortVowels(string s)
    {
        const int N = static_cast<int>(s.size());
        unordered_map<char, int> Table;
        vector<int> SVowelIndex;
        
        for(int i = 0; i < N; i++)
        {
            if(IsVowel(s[i]))
            {
                Table[s[i]]++;
                SVowelIndex.push_back(i);
            }
        }
        
        int VowelIndex = 0;
        
        for(int Index : SVowelIndex)
        {
            while(Table[Vowels[VowelIndex]] <= 0)
            {
                VowelIndex++;
            }
            
            s[Index] = Vowels[VowelIndex];
            Table[Vowels[VowelIndex]]--;
        }
        
        
        return s;
    }
    
private:
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