class Solution {
    const double EPS = 1e-6;
public:
    bool judgePoint24(vector<int>& cards)
    {
        vector<double> Nums;
        Nums.reserve(4);
        for(int& Card : cards)
        {
            Nums.push_back((double)Card);
        }
        return DFS(Nums);
    }

    bool DFS(vector<double>& Nums)
    {
        const int N = static_cast<int>(Nums.size());
        if(N == 1)
        {
            return fabs(Nums[0] - 24.0) < EPS;
        }

        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                if(i == j)
                    continue;

                vector<double> Next;
                for(int k = 0; k < N; k++)
                {
                    if(k != i && k != j)
                        Next.push_back(Nums[k]);
                }

                for(double& Value : Compute(Nums[i], Nums[j]))
                {
                    Next.push_back(Value);
                    if(DFS(Next))
                        return true;
                    Next.pop_back();
                }
            }
        }
        return false;
    }

    vector<double> Compute(double a, double b)
    {
        vector<double> Result;
        Result.push_back(a + b);
        Result.push_back(a - b);
        Result.push_back(b - a);
        Result.push_back(a * b);
        if(fabs(b) > EPS)
            Result.push_back(a / b);
        if(fabs(a) > EPS)
            Result.push_back(b / a);
        return Result;
    }
};