class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids)
    {
        priority_queue<int, vector<int>, greater<int>> Hold;
        long long Mass = mass;
        for(int& Asteroid : asteroids)
        {
            while(!Hold.empty() && Hold.top() <= Mass)
            {
                Mass += Hold.top();
                Hold.pop();
            }
            if(Asteroid <= mass)
            {
                Mass += Asteroid;
            }
            else
            {
                Hold.push(Asteroid);
            }
        }

        while(!Hold.empty())
        {
            if(Hold.top() <= Mass)
            {
                Mass += Hold.top();
                Hold.pop();
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};