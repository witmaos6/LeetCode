class Solution {
public:
    string lexGreaterPermutation(string s, string target)
    {
        vector<int> Table(26);

        for(char& C : s)
        {
            Table[C - 'a']++;
        }
        for(char& C : target)
        {
            Table[C - 'a']--;
        }

        const int N = target.size();
        for(int i = N - 1; i >= 0; i--)
        {
            int Curr = target[i] - 'a';
            Table[Curr]++;

            bool Flag = true;
            for(int c = 0; c < 26; c++)
            {
                if(Table[c] < 0)
                {
                    Flag = false;
                    break;
                }
            }
            if(!Flag)
                continue;

            int Next = -1;
            for(int c = Curr + 1; c < 26; c++)
            {
                if(Table[c] > 0)
                {
                    Next = c;
                    break;
                }
            }

            if(Next == -1)
                continue;
            
            Table[Next]--;

            string Result = target.substr(0, i);
            Result += char('a' + Next);

            for(int c = 0; c < 26; c++)
            {
                Result.append(Table[c], char('a' + c));
            }

            return Result;
        }
        return "";
    }
};