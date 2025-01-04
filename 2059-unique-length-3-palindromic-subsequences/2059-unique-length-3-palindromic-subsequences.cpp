class Solution {
public:
    int countPalindromicSubsequence(string s)
    {        
        int Result = 0;
        for(int i = 0; i < 26; i++)
        {
            vector<bool> Exist(26);
            int Left = s.find('a' + i);
            if(Left == string::npos)
                continue;

            int Right = s.find_last_of('a' + i);
            if(Right - Left < 2)
                continue;

            for(int j = Left + 1; j < Right; j++)
            {
                Exist[s[j] - 'a'] = true;
                if(CountExist(Exist) == 26)
                    break;
            }
            Result += CountExist(Exist);
        }
        return Result;
    }
private:
    int CountExist(const vector<bool>& Arr)
    {
        int Count = 0;
        for(bool Exist : Arr)
        {
            if(Exist)
            {
                Count++;
            }
        }
        return Count;
    }
};