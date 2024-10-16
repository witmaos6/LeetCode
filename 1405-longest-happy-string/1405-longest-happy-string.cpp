class Solution {
    using Pair = pair<int, char>;
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<Pair, vector<Pair>> MaxHeap;
        if (a > 0) MaxHeap.emplace(a, 'a');
        if (b > 0) MaxHeap.emplace(b, 'b');
        if (c > 0) MaxHeap.emplace(c, 'c');

        string Result;

        while (!MaxHeap.empty())
        {
            auto [Freq1, Char1] = MaxHeap.top();
            MaxHeap.pop();

            if (Result.size() >= 2 && Result.back() == Char1 && Result[Result.size() - 2] == Char1)
            {
                if (MaxHeap.empty())
                    break;

                auto [Freq2, Char2] = MaxHeap.top();
                MaxHeap.pop();

                Result += Char2;
                Freq2--;

                if (Freq2 > 0)
                {
                    MaxHeap.emplace(Freq2, Char2);
                }

                MaxHeap.emplace(Freq1, Char1);
            }
            else
            {
                Result += Char1;
                Freq1--;

                if (Freq1 > 0)
                {
                    MaxHeap.emplace(Freq1, Char1);
                }
            }
        }
        return Result;
    }
};