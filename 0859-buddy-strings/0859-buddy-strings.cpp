class Solution {
public:
    bool buddyStrings(string s, string goal)
    {
        const int N = static_cast<int>(s.size());
        const int M = static_cast<int>(goal.size());
        if(N != M || N == 1 || M == 1)
        {
            return false;
        }
        
        if(s == goal)
        {
            vector<int> Table(26);
            
            for(int i = 0; i < N; i++)
            {
                Table[s[i] - 'a']++;
            }
            
            for(int i = 0; i < 26; i++)
            {
                if(Table[i] >= 2)
                {
                    return true;
                }
            }
            return false;
        }
        
        int One = -1;
        int Two = -1;
        for(int i = 0; i < N; i++)
        {
            if(s[i] != goal[i])
            {
                if(One == -1)
                {
                    One = i;
                }
                else if(Two == -1)
                {
                    Two = i;
                }
                else
                {
                    return false;
                }
            }
        }
        
        if(One == -1 || Two == -1)
        {
            return false;
        }
        
        if(s[One] == goal[Two] && s[Two] == goal[One])
        {
            return true;
        }
        return false;
    }
};