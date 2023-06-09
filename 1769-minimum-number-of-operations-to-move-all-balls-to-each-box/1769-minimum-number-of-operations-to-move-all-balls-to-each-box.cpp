class Solution {
public:
    vector<int> minOperations(string boxes)
    {
        const int N = static_cast<int>(boxes.size());
        
        vector<int> Answer(N);
        int LastCost = 0;
        int Sum = boxes[0] - '0';
        
        for(int i = 1; i < N; i++)
        {
            Answer[i] += Sum + LastCost;
            LastCost = Answer[i];
            Sum += (boxes[i] - '0');
        }
        
        LastCost = 0;
        Sum = boxes.back() - '0';
        
        for(int i = N - 2; i >= 0; i--)
        {
            Answer[i] += Sum + LastCost;
            LastCost += Sum;
            Sum += (boxes[i] - '0');
        }
        
        return Answer;
    }
};