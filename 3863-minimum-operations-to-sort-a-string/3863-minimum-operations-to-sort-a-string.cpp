class Solution {
public:
    int minOperations(string s)
    {
        const int N = s.size();
        bool Sorted = true;
        for(int i = 1; i < N; i++)
        {
            if(s[i] < s[i - 1])
            {
                Sorted = false;
                break;
            }
        }

        if(Sorted)
            return false;
        if(N == 2)
            return -1;
        
        char Min = *min_element(s.begin(), s.end());
        char Max = *max_element(s.begin(), s.end());

        if(s[0] == Min || s[N - 1] == Max)
            return 1;
        for(int i = 1; i < N - 1; i++)
        {
            if(s[i] == Min || s[i] == Max)
                return 2;
        }
        return 3;
    }
};