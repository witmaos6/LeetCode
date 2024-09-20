class Solution {
public:
    string shortestPalindrome(string str)
    {
        string ReverseStr = str;
        reverse(ReverseStr.rbegin(), ReverseStr.rend());
        
        int Length = FindLPS(str + "#" + ReverseStr);
        
        return ReverseStr.substr(0, ReverseStr.length() - Length) + str;
    }
    
private:
    int FindLPS(const string& str)
    {
        const int N = static_cast<int>(str.size());
        vector<int> LPS(N, 0);
        int Length = 0, i = 1;
        
        while(i < N)
        {
            if(str[Length] == str[i])
            {
                LPS[i++] = ++Length;
            }
            else
            {
                if(Length != 0)
                {
                    Length = LPS[Length-1];
                }
                else
                {
                    LPS[i++] = 0;
                }                  
            }
        }
        
        return LPS[N - 1];
    }
};
