class Solution {
    vector<vector<int>> DP;
public:
    bool predictTheWinner(vector<int>& nums)
    {
        const int N = static_cast<int>(nums.size());
        
        DP.resize(N, vector<int>(N, -1));
        
        int Score = GetScore(nums, 0, N - 1);
        if(Score >= 0)
        {
            return true;
        }
        return false;
    }
    
private:
    int GetScore(vector<int>& Nums, int Left, int Right)
    {
        if(DP[Left][Right] != -1)
        {
            return DP[Left][Right];
        }
        if(Left == Right)
        {
            return Nums[Left];
        }
        
        int LeftChoise = Nums[Left] - GetScore(Nums, Left + 1, Right);
        int RightChoise = Nums[Right] - GetScore(Nums, Left, Right - 1);
        
        DP[Left][Right] = max(LeftChoise, RightChoise);
        
        return DP[Left][Right];
    }
};