class Solution {
    const char Ball = '1';
public:
    vector<int> minOperations(string boxes)
    {
        const int N = static_cast<int>(boxes.size());
        
        vector<int> BallIndex;
        
        for(int i = 0; i < N; i++)
        {
            if(boxes[i] == Ball)
            {
                BallIndex.push_back(i);
            }
        }
        
        vector<int> Answer(N);
        
        for(int i = 0; i < N; i++)
        {
            for(int& Index : BallIndex)
            {
                Answer[i] += abs(Index - i);
            }
        }
        
        return Answer;
    }
};