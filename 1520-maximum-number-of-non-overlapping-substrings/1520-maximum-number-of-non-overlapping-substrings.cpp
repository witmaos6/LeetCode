class Solution {
public:
    vector<string> maxNumOfSubstrings(string s)
    {
        const int N = s.size();
        vector<int> First(26, N), Last(26, -1);

        for(int i = 0; i < N; i++)
        {
            int C = s[i] - 'a';
            First[C] = min(First[C], i);
            Last[C] = i;
        }

        vector<pair<int, int>> V;
        for(int C = 0; C < 26; C++)
        {
            if(Last[C] == -1)
                continue;
            
            int L = First[C], R = Last[C];
            bool Flag = true;
            for(int i = L; i <= R; i++)
            {
                int D = s[i] - 'a';
                if(First[D] < L)
                {
                    Flag = false;
                    break;
                }
                R = max(R, Last[D]);
            }
            if(Flag)
            {
                V.push_back({R, L});
            }
        }
        sort(V.begin(), V.end());

        vector<string> Result;
        int R = -1;
        for(auto& [Nr, L] : V)
        {
            if(L > R)
            {
                Result.push_back(s.substr(L, Nr - L + 1));
                R = Nr;
            }
        }
        return Result;
    }
};