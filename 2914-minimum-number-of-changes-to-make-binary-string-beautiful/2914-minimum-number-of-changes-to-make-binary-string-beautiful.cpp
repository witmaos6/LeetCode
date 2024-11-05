class Solution {
public:
    int minChanges(string s)
    {
        const int N = static_cast<int>(s.size());
        int Count = 0;
        
        for(int i = 0; i < N; i += 2)
        {
            if(s[i] != s[i + 1])
            {
                ++Count;
            }
        }
        
        return Count;
    }
};