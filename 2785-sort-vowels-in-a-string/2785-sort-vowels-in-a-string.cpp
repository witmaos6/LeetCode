class Solution {
    vector<char> Vowels = {'A','E','I','O','U','a','e','i','o','u'};
public:
    string sortVowels(string s)
    {
        const int N = static_cast<int>(s.size());
        priority_queue<char, vector<char>, greater<char>>MinHeap;
        vector<int> VowelIndex;
        
        for(int i = 0; i < N; i++)
        {
            if(IsVowel(s[i]))
            {
                VowelIndex.push_back(i);
                MinHeap.push(s[i]);
            }
        }
        
        for(int Index : VowelIndex)
        {
            s[Index] = MinHeap.top();
            MinHeap.pop();
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