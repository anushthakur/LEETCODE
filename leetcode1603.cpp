//1603. Design Parking System



//Time complexity: O(1)
//Space complexity: O(1)


/*
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    bool b = true;
    cout << b << endl;
    cout << boolalpha << b << endl;
    cout << noboolalpha << b << endl;
    return 0;
}
*/        


//TRIAL
#include<iostream>
using namespace std;

class ParkingSystem 
{
 public:
 int big;
 int medium;
 int small;


   bool help(int carType)
   {
       switch(carType)
        {
            case 1:
                if(big)
                {
                    big--;
                }
                else return false;
                break;
            case 2:
                if(medium)
                {
                    medium--;
                }
                else return false;
                break;  

                case 3:
                if(small)
                {
                    small--;
                }
                else return false;
                break;    
        }
        return true;
   }
   
    ParkingSystem(int big, int medium, int small) 
    {
        this->big=big;
        this->medium=medium;
        this->small=small;
        
    }


    
    bool addCar(int carType) 
    {
        return help(carType);
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */

int main()
{
    ParkingSystem* obj = new ParkingSystem(1, 1, 0);
    bool param_1 = obj->addCar(1);
    bool param_2 = obj->addCar(2);
    bool param_3 = obj->addCar(3);
    bool param_4 = obj->addCar(1);

    cout<<boolalpha<<param_1<<" "<<boolalpha<<param_2<<" "<<boolalpha<<param_3<<" "<<boolalpha<<param_4;
    return 0;
}


//LEETCODE OTHER SOLUTION


class ParkingSystem {
public:
        int big;
        int medium;
        int small;

    ParkingSystem(int big, int medium, int small) {
         this->big = big;
         this->medium = medium;
         this->small = small;
    }
    
    bool addCar(int carType) {
        
         if(carType == 1 && big == 0 || carType == 2 && medium == 0 || carType == 3 && small == 0)
          return false;

          if(carType == 1) big--;
          if(carType == 2) medium--;
          if(carType == 3) small--;

        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */