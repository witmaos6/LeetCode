class ParkingSystem {
    vector<int> ParkSize;
public:
    ParkingSystem(int big, int medium, int small)
    {
        ParkSize = {0, big, medium, small};
    }
    
    bool addCar(int carType)
    {
        if(ParkSize[carType] > 0)
        {
            ParkSize[carType]--;
            return true;
        }
        
        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */