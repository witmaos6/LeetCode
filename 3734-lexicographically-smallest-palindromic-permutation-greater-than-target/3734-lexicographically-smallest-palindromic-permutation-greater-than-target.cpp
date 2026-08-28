class Solution {
public:
    string lexPalindromicPermutation(string s, string target)
    {
        vector<int> Table(26);

        for(char& C : s)
        {
            Table[C - 'a']++;
        }

        int Odd = 0;
        char Mid = 0;

        for(int C = 0; C < 26; C++)
        {
            if(Table[C] & 1)
            {
                Odd++;
                Mid = 'a' + C;
            }
        }

        if(Odd > 1)
            return "";

        vector<int> Half(26);
        for(int C = 0; C < 26; C++)
        {
            Half[C] = Table[C] / 2;
        }

        string Calendrix = s;
        int M = s.size() / 2;
        string Left;

        for(int i = 0; i < M; i++)
        {
            bool Found = false;

            for(int C = 0; C < 26; C++)
            {
                if(Half[C] == 0)
                    continue;

                Half[C]--;
                Left.push_back('a' + C);

                if(Build(Left, Half, Mid) > target)
                {
                    Found = true;
                    break;
                }

                Left.pop_back();
                Half[C]++;
            }
            if(!Found)
                return "";
        }

        string Result = Left;
        if(Mid)
            Result.push_back(Mid);
        
        for(int i = M - 1; i >= 0; i--)
        {
            Result.push_back(Left[i]);
        }

        return Result > target ? Result : "";
    }

    string Build(const string& Left, const vector<int>& Table, char Mid)
    {
        string Half = Left;

        for(int C = 25; C >= 0; C--)
        {
            Half.append(Table[C], char('a' + C));
        }

        string Result = Half;

        if(Mid)
            Result.push_back(Mid);
        
        int N = Half.size();
        for(int i = N - 1; i >= 0; i--)
        {
            Result.push_back(Half[i]);
        }
        return Result;
    }
};