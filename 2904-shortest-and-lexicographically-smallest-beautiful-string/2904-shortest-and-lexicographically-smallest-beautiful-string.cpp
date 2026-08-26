class Solution {
public:
    string shortestBeautifulSubstring(string s, int k)
    {
        const int N = s.size();
        int L = 0;
        int CountOne = 0;

        auto Cmp = [](const string& A, const string& B)
        {
            if(A.size() == B.size())
                return A > B;
            
            return (A.size() > B.size());
        };
        priority_queue<string, vector<string>, decltype(Cmp)> Beauties(Cmp);

        for(int R = 0; R < N; R++)
        {
            if(s[R] == '1')
            {
                CountOne++;

                while(CountOne > k || s[L] == '0')
                {
                    if(s[L] == '1')
                    {
                        CountOne--;
                    }
                    L++;
                }

                if(CountOne == k)
                {
                    string Beauty = s.substr(L, R - L + 1);
                    Beauties.push(Beauty);
                }
            }
        }

        return Beauties.empty() ? "" : Beauties.top();
    }
};