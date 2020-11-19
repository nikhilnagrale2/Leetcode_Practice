class ParkingSystem {
public:
    vector<int> system;
    ParkingSystem(int big, int medium, int small) {
        system={0,big,medium,small};
    }
    
    bool addCar(int carType) {
        return --system[carType]>=0;
    }
};

/* learnt something new sentinel programming hence Tried out thanks to leetCode */

/*
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */