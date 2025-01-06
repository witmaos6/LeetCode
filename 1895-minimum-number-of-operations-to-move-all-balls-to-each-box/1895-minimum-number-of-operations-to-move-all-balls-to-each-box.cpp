class Solution {
public:
    vector<int> minOperations(string boxes)
    {
        const int N = static_cast<int>(boxes.size());

        int LeftCount = 0;
        int RightCount = 0;
        int RequireMove = 0;
        for(int i = 0; i < N; i++)
        {
            if(boxes[i] == '1')
            {
                RightCount++;
                RequireMove += i;
            }
        }

        vector<int> Result(N);
        for(int i = 0; i < N; i++)
        {
            Result[i] = RequireMove;

            if(boxes[i] == '1')
            {
                RightCount--;
                LeftCount++;
            }
            RequireMove -= RightCount;
            RequireMove += LeftCount;
        }
        
        return Result;
    }
};