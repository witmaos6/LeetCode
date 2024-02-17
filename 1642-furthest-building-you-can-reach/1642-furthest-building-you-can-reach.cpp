class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders)
    {
        const int N = static_cast<int>(heights.size());
        priority_queue<int, vector<int>> MaxHeap;
        
        int i = 0;
        for(i = 0; i < N - 1; i++)
        {
            int Diff = heights[i + 1] - heights[i];
            if(Diff < 0)
            {
                continue;
            }
            
            bricks -= Diff;
            MaxHeap.push(Diff);
            
            if(bricks < 0)
            {
                bricks += MaxHeap.top();
                MaxHeap.pop();
                ladders--;
            }
            
            if(ladders < 0)
            {
                break;
            }
        }
        
        return i;
    }
};