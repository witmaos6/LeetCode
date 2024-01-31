class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        const int N = static_cast<int>(temperatures.size());
        vector<int> Answer(N);
        stack<pair<int, int>> St;
        
        for(int i = 0; i < N; i++)
        {
            while(!St.empty() && temperatures[i] > St.top().first)
            {
                int Day = St.top().second;
                Answer[Day] = i - Day;
                St.pop();
            }
            St.push({temperatures[i], i});
        }
        return Answer;
    }
};