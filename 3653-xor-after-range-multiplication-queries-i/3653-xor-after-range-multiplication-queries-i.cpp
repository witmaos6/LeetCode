class Solution {
    const int Mod = 1e9 + 7;
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries)
    {
        for(vector<int>& Query : queries)
        {
            Apply(nums, Query);
        }
        return accumulate(nums.begin(), nums.end(), 0, bit_xor<>());
    }

private:
    void Apply(vector<int>& Nums, vector<int>& Query)
    {
        const int L = Query[0], R = Query[1], K = Query[2], V = Query[3];
        for(int i = L; i <= R; i += K)
        {
            long long X = Nums[i];
            X *= V;
            if(X >= Mod)
                X %= Mod;
            
            Nums[i] = X;
        }
    }
};