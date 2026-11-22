class Solution {
public:
    bool checkString(string s)
    {
        const int N = s.size();

        for(int i = 1; i < N; i++)
        {
            if(s[i - 1] == 'b' && s[i] == 'a')
                return false;
        }
        return true;
    }
};