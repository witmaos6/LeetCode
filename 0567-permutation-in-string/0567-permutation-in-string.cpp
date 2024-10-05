class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        int s1Size = static_cast<int>(size(s1));
        int s2Size = static_cast<int>(size(s2));

        if (s1Size > s2Size)
        {
            return false;
        }
        vector<int> FreqS1 = SetFreq(s1, s1Size);
        vector<int> FreqS2 = SetFreq(s2, s1Size);

        if(FreqS1 == FreqS2)
        {
            return true;
        }

        for(int i = s1Size; i < s2Size; i++)
        {
            int OldChar = s2[i] - 'a';
            int NewChar = s2[i - s1Size] - 'a';

            FreqS2[NewChar]--;
            FreqS2[OldChar]++;

            if(FreqS1 == FreqS2)
            {
                return true;
            }   
        }

        return false;
    }

private:
    vector<int> SetFreq(const string& s, const int& size)
    {
        vector<int>Set(26);
        for(int i = 0; i < size; i++)
        {
            Set[s[i] - 'a']++;
        }
        return Set;
    }
};