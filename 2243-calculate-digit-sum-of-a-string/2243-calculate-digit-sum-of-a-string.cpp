class Solution {
public:
    string digitSum(string s, int k)
    {
        while((int)s.size() > k)
        {
            int N = s.size();
            string RoundS;
            
            for(int i = 0; i < N; i += k)
            {
                int Range = min(N, i + k);
                int Num = 0;
                for(int j = i; j < Range; j++)
                {
                    Num += s[j] - '0';
                }

                RoundS += to_string(Num);
            }
            s = RoundS;
        }
        return s;
    }
};