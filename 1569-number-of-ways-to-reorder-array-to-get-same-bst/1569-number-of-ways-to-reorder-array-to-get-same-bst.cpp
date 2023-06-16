class Solution {
    const int Mod = 1e9 + 7;
    vector<vector<long long>> Pascal;
public:
    int numOfWays(vector<int>& nums)
    {
        int N = static_cast<int>(nums.size());
        
        for(int i = 0; i < N + 1; i++)
        {
            Pascal.push_back(vector<long long>(i + 1, 1));
            
            for(int j = 1; j < i; j++)
            {
                Pascal[i][j] = (Pascal[i - 1][j] + Pascal[i - 1][j - 1]) % Mod;
            }
        }
        
        return DFS(nums) - 1;
    }
    
private:
    int DFS(vector<int>& nums)
    {
        if(nums.size() <= 2)
            return 1;
        
        vector<int> Left;
        vector<int> Right;
        int N = static_cast<int>(nums.size());
        
        for(int i = 1; i < N; i++)
        {
            if(nums[i] < nums[0])
            {
                Left.push_back(nums[i]);
            }
            else
            {
                Right.push_back(nums[i]);
            }
        }
        
        long long LeftWays = DFS(Left) * Pascal[N - 1][Left.size()] % Mod;
        long long TotalWays = LeftWays * DFS(Right) % Mod;
        
        return static_cast<int>(TotalWays);
    }
};