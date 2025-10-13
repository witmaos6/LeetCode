class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words)
    {
        const int N = static_cast<int>(words.size());
        int Prev = 0;
        for(int i = 1; i < N; i++)
        {
            if(IsAnagram(words[Prev], words[i]))
            {
                words[i] = "-";
            }
            else
            {
                Prev = i;
            }
        }
        vector<string> Result;
        for(string& Str : words)
        {
            if(Str != "-")
                Result.push_back(Str);
        }
        return Result;
    }
private:
    bool IsAnagram(string Str1, string Str2)
    {
        if(Str1.size() != Str2.size())
            return false;

        sort(Str1.begin(), Str1.end());
        sort(Str2.begin(), Str2.end());

        return Str1 == Str2;
    }
};