class Solution {
public:
    int minimumDeletions(string s)
    {
        const int N = static_cast<int>(s.size());
        vector<int> Memo(N + 1);
        int B = 0;

        for(int i = 1; i <= N; i++)
        {
            if(s[i - 1] == 'b')
            {
                Memo[i] = Memo[i - 1];
                B++;
            }
            else
            {
                Memo[i] = min(Memo[i - 1] + 1, B);
            }
        }
        return Memo[N];
    }
};