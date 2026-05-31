class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids)
    {
        sort(asteroids.begin(), asteroids.end());

        long long Mass = mass;
        for(int& Asteroid : asteroids)
        {
            if(Asteroid <= Mass)
            {
                Mass += Asteroid;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};