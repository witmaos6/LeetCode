#include <bit>
using namespace std;

class SparseTable
{
    vector<vector<int>> Min, Max;

public:
    SparseTable(const vector<int>& Nums)
    {
        const size_t N = Nums.size();

        int W = bit_width(N);
        Min.resize(W, vector<int>(N));
        Max.resize(W, vector<int>(N));

        for(int i = 0; i < N; i++)
        {
            Min[0][i] = Max[0][i] = Nums[i];
        }

        for(int i = 1; i < W; i++)
        {
            for(int j = 0; j + (1 << i) <= N; j++)
            {
                Min[i][j] = min(Min[i - 1][j], Min[i - 1][j + (1 << (i - 1))]);
                Max[i][j] = max(Max[i - 1][j], Max[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    int Query(int Left, int Right)
    {
        int K = bit_width((uint32_t)Right - Left) - 1;
        return max(Max[K][Left], Max[K][Right - (1 << K)]) - min(Min[K][Left], Min[K][Right - (1 << K)]);
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k)
    {
        const int N = nums.size();
        
        SparseTable LUT(nums);

        priority_queue<tuple<int, int, int>> MaxHeap;
        for(int i = 0; i < N; i++)
        {
            MaxHeap.emplace(LUT.Query(i, N), i, N);
        }

        long long Result = 0;
        while(get<0>(MaxHeap.top()) && k--)
        {
            auto[Val, L, R] = MaxHeap.top();
            MaxHeap.pop();

            Result += Val;
            MaxHeap.emplace(LUT.Query(L, R - 1), L, R - 1);
        }
        return Result;
    }
};