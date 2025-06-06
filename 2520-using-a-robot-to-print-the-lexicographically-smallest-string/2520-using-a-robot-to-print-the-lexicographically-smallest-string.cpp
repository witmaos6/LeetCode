class Solution {
public:
    string robotWithString(string s)
    {
        vector<int> Table(26);

        for(char& C : s)
        {
            Table[C - 'a']++;
        }

        stack<char> St;
        string T = "";
        for(char& C : s)
        {
            St.push(C);
            Table[C - 'a']--;

            while(!St.empty() && St.top() <= FirstChar(Table))
            {
                T += St.top();
                St.pop();
            }
        }

        while(!St.empty())
        {
            T += St.top();
            St.pop();
        }
        return T;
    }

private:
    char FirstChar(const vector<int>& Table)
    {
        for(int i = 0; i < 26; i++)
        {
            if(Table[i] > 0)
            {
                return 'a' + i;
            }
        }
        return 'a';
    }
};