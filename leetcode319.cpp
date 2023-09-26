//319.Bulb Switcher


//https://youtu.be/9XQxIvdqIt0


/*
//********************CONCEPT******************************
// CPP code to illustrate the use of sqrt function
#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;
 
// Driver Code
int main()
{
    double val1 = 225.0;
    double val2 = 300.0;
 
    cout << fixed << setprecision(12) << sqrt(val1) << endl;
    cout << fixed << setprecision(12) << sqrt(val2) << endl;
 
    return (0);
}

*/








/*

////The floor() function in C++ returns the largest possible integer value which is less than or equal to the given argument.It is defined in the cmath header file.

#include <iostream>
#include <cmath>
using namespace std;

int main() {

  // get the largest possible integer less than or equal to 68.95
  cout << floor(68.95);

  return 0;
}

// Output: 68


*/




//TIME COMPLEXITY OF THESE INBUILT FUNCTIONS:

//#include<cmath>
//sqrt() --->
//Time Complexity: O(√n)
//Auxiliary Space: O(1)



#include<cmath>

class Solution 

{
  public:
    int bulbSwitch(int n) 
    {
        double numofperfectsq=sqrt(n);
        int ans=floor(numofperfectsq);
        return ans;
    }
};