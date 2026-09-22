class Solution {
    struct FNode
    {
        int Remain[5];
        int Prod;
        public:
            FNode()
            {
                fill(Remain, Remain + 5, 0);
                Prod = 1;
            }
    };
    class SegmentTree
    {
        int K;
        int N;
        vector<FNode> Nodes;
        public:
            SegmentTree(vector<int>& Nums, int inK)
            {
                K = inK;
                N = Nums.size();
                Nodes.resize(4 * N);
                Build(Nums, 0, 0, N - 1);
            }
        private:
            void Build(vector<int>& Nums, int Curr, int Left, int Right)
            {
                if(Left == Right)
                {
                    Nodes[Curr].Remain[Nums[Left]] = 1;
                    Nodes[Curr].Prod = Nums[Left];
                    return;
                }
                int Mid = (Left + Right) / 2;
                Build(Nums, 2 * Curr + 1, Left, Mid);
                Build(Nums, 2 * Curr + 2, Mid + 1, Right);
                Merge(Curr);
            }

            void Merge(int Curr)
            {
                int Left = 2 * Curr + 1;
                int Right = 2 * Curr + 2;
                Nodes[Curr].Prod = (Nodes[Left].Prod * Nodes[Right].Prod) % K;
                
                for(int i = 0; i < K; i++)
                {
                    Nodes[Curr].Remain[i] = Nodes[Left].Remain[i];
                }
                for(int i = 0; i < K; i++)
                {
                    int NewVal = (i * Nodes[Left].Prod) % K;
                    Nodes[Curr].Remain[NewVal] += Nodes[Right].Remain[i];
                }
            }
        public:
            void Update(int Curr, int Left, int Right, int Target, int Value)
            {
                if(Left == Right)
                {
                    for(int i = 0; i < K; i++)
                    {
                        Nodes[Curr].Remain[i] = 0;
                    }
                    Nodes[Curr].Remain[Value] = 1;
                    Nodes[Curr].Prod = Value;
                    return;
                }

                int Mid = (Left + Right) / 2;
                if(Target <= Mid)
                {
                    Update(2 * Curr + 1, Left, Mid, Target, Value);
                }
                else
                {
                    Update(2 * Curr + 2, Mid + 1, Right, Target, Value);
                }
                Merge(Curr);
            }

            FNode Query(int Curr, int QL, int QR, int Left, int Right)
            {
                if(QR < Left || QL > Right)
                    return FNode();

                if(QL <= Left && Right <= QR)
                    return Nodes[Curr];

                int Mid = (Left + Right) / 2;
                FNode NLeft = Query(2 * Curr + 1, QL, QR, Left, Mid);
                FNode NRight = Query(2 * Curr + 2, QL, QR, Mid + 1, Right);
                Merge(NLeft, NRight);
                return NLeft;
            }
        private:
            void Merge(FNode& N1, FNode& N2)
            {
                for(int i = 0; i < K; i++)
                {
                    int NewValue = (i * N1.Prod) % K;
                    N1.Remain[NewValue] += N2.Remain[i];
                }
                N1.Prod = (N1.Prod * N2.Prod) % K;
            }
    };
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries)
    {
        const int N = nums.size();
        const int Q = queries.size();
        for(int& Num : nums)
        {
            Num %= k;
        }

        for(vector<int>& Query : queries)
        {
            Query[1] %= k;
        }

        SegmentTree Seg(nums, k);
        vector<int> Result;

        for(vector<int>& Query : queries)
        {
            int Index = Query[0];
            int Value = Query[1];
            int Begin = Query[2];
            int X = Query[3];

            Seg.Update(0, 0, N - 1, Index, Value);
            Result.push_back(Seg.Query(0, Begin, N - 1, 0, N -1).Remain[X]);
        }
        return Result;
    }
};