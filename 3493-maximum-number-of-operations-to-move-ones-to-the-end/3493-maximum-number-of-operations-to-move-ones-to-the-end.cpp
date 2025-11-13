class Solution {
public:
    int maxOperations(string s)
    {
        const int N = static_cast<int>(s.size());
        int Count = 0;
        int Count1 = (s[0] == '1');
        for(int i = 1; i < N; i++)
        {
            if(s[i] == '1')
            {
                Count1++;
            }
            else if(s[i - 1] == '1')
            {
                Count += Count1;
            }
        }
        return Count;
    }
};