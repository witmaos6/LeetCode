class Solution {
    const int Mod = 1e9 + 7;
public:
    int sumSubarrayMins(vector<int>& arr)
    {
        const int N = static_cast<int>(arr.size());
        int StackSum = arr.front(), Answer = arr.front();
        stack<pair<int, int>> Monotonic;
        Monotonic.push({arr.front(), 1});
        
        for(int i = 1; i < N; i++)
        {
            pair<int, int> P = {arr[i], 1};
            
            while(!Monotonic.empty() && Monotonic.top().first >= arr[i])
            {
                auto[X, Y] = Monotonic.top();
                StackSum -= (X * Y);
                P.second += Y;
                Monotonic.pop();
            }
            StackSum += P.first * P.second;
            long long Temp = Answer + StackSum;
            Answer = static_cast<int>(Temp % Mod);
            Monotonic.push(P);
        }
        
        return Answer;
    }
};