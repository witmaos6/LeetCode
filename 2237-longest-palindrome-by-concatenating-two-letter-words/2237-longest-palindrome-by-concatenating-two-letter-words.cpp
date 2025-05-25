class Solution {
public:
    int longestPalindrome(vector<string>& words)
    {
        vector<vector<int>> Table(26, vector<int>(26));
        int LongestPalindrome = 0;
        
        for(string& word : words)
        {
            int a = word[0]-'a';
            int b = word[1]-'a';
            
            if (Table[b][a]) 
            {
                LongestPalindrome += 4;
                Table[b][a]--;
            }
            else 
            {
                Table[a][b]++;
            }
        }
        
        for (int i = 0; i < 26; i++) 
        {
            if (Table[i][i]) 
            {
                LongestPalindrome += 2;
                break;
            }
        }
        
        return LongestPalindrome;
    }
};