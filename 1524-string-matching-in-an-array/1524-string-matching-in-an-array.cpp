class Solution {
public:
    vector<string> stringMatching(vector<string>& words)
    {
        const int N = static_cast<int>(words.size());
        vector<string> Result;
        for(int i = 0; i < N; i++)
        {
            for(int j = i + 1; j < N; j++)
            {
                if(words[i].size() < words[j].size())
                {
                    if(IsSubstring(words[j], words[i]) && IsUnique(Result, words[i]))
                    {
                        Result.push_back(words[i]);
                    }
                }
                else
                {
                    if(IsSubstring(words[i], words[j]) && IsUnique(Result, words[j]))
                    {
                        Result.push_back(words[j]);
                    }
                }
            }
        }
        
        return Result;
    }

private:
    bool IsSubstring(const string& Str, const string& Candidate)
    {
        const int StrSize = static_cast<int>(Str.size());
        const int CanSize = static_cast<int>(Candidate.size());

        if(StrSize <= CanSize)
            return false;

        for(int i = 0; i <= StrSize - CanSize; i++)
        {
            bool Flag = true;
            int Index = i;
            for(int j = 0; j < CanSize; j++)
            {
                if(Str[Index] != Candidate[j])
                {
                    Flag = false;
                    break;
                }
                Index++;
            }
            if(Flag)
                return true;
        }
        return false;
    }

    bool IsUnique(const vector<string>& Strs, const string& Input)
    {
        for(const string& Str : Strs)
        {
            if(Str == Input)
                return false;
        }
        return true;
    }
};