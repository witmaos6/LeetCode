class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events)
    {
        sort(events.begin(), events.end(), [](const vector<int>& A, const vector<int>& B) {
            return A[0] < B[0];
        });
        
        const int N = static_cast<int>(events.size());
        vector<int> SuffixMax(N);
        SuffixMax[N - 1] = events[N - 1][2];
        for(int i = N - 2; i >= 0; --i)
        {
            SuffixMax[i] = max(events[i][2], SuffixMax[i + 1]);
        }
        
        int MaxSum = 0;
        for(int i = 0; i < N; i++)
        {
            int Left = i + 1;
            int Right = N - 1;
            int NextEventIndex = -1;
            
            while(Left <= Right)
            {
                int Mid = (Right + Left) / 2;
                if(events[Mid][0] > events[i][1])
                {
                    NextEventIndex = Mid;
                    Right = Mid - 1;
                }
                else
                {
                    Left = Mid + 1;
                }
            }
            
            if(NextEventIndex != -1)
            {
                int Sum = events[i][2] + SuffixMax[NextEventIndex];
                MaxSum = max(MaxSum, Sum);
            }
            MaxSum = max(MaxSum, events[i][2]);
        }
        
        return MaxSum;
    }
};