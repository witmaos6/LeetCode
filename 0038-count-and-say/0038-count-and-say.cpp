class Solution {
public:
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }

        string S = countAndSay(n - 1);
        const int N = static_cast<int>(S.size());
        string Say;
        int i = 0;

        while (i < N)
        {
            char C = S[i];
            int CountNum = 0;
            while (S[i] == C)
            {
                CountNum++;
                i++;
            }
            Say += to_string(CountNum) + C;
        }

	    return Say;
    }
};