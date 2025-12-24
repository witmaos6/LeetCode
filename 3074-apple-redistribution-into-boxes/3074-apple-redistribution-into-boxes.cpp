class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity)
    {
        priority_queue<int, vector<int>> MaxHeap;
        for(int& Box : capacity)
        {
            MaxHeap.push(Box);
        }
    
        int AppleSum = accumulate(apple.begin(), apple.end(), 0);
        while(!MaxHeap.empty())
        {
            int CurrBox = MaxHeap.top();
            MaxHeap.pop();
            AppleSum -= CurrBox;

            if(AppleSum <= 0)
            {
                break;
            }
        }

        return capacity.size() - MaxHeap.size();
    }
};