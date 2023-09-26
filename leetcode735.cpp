//735. Asteroid Collision



#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
//**********************TRIAL*********************************************
//*********WRONG SOLUTION (EXPECTED OUTPUT NOT GIVING)***********************
class Solution 
{
 public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        int i=0;
        for(i;i<asteroids.size()-1;i++)
        {
           if(asteroids[i]*asteroids[i+1]<0)
           {
               if(asteroids[i]>0)
               {
                   if(asteroids[i]==-asteroids[i+1])
                   {
                       asteroids.erase(asteroids.begin()+i);
                       asteroids.erase(asteroids.begin()+i+1);
                   }
                   else if(asteroids[i]<-asteroids[i+1])
                   {
                        asteroids.erase(asteroids.begin()+i);
                   }
                   else
                   {
                        asteroids.erase(asteroids.begin()+i+1);
                   }
               }
           } 
        }
        return asteroids;
        
    }
};
int main()
{
    Solution obj;
    vector<int> vect{10,2,-5}; //ans is supposed to be 10
    obj.asteroidCollision(vect);
    for(int i=0;i<vect.size();i++) cout<<vect[i]<<" ";
    return 0;
}
*/



//why problem???
class Solution 
{
  public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack <int> s;
        for(int i=0;i<asteroids.size();i++)
        {
            if(s.empty() || asteroids[i]>0)
            {
                s.push(asteroids[i]);
            }
            else
            {
                
                while(true)
                {
                  int top=s.top();

                  if(top<0)
                  {
                     s.push(asteroids[i]);
                     break;
                  }
                  else if(top==(-asteroids[i]))
                  {
                      s.pop();
                      break;

                  }
                  else if(top>(-asteroids[i]))
                  {
                      break;
                  }
                  else
                  {
                      s.pop();
                      if(s.empty())
                      {
                          s.push(asteroids[i]);
                          break;
                      }
                  }

                }
                
            }
        }
       //trying to debug
       for(int i=s.size();i<asteroids.size();i++) asteroids.erase(asteroids.begin()+i);
       //here something is wrong
        for(int i=s.size()-1;i>=0;i--)
        {
            asteroids[i]=s.top();
            s.pop();
        }
        
        return asteroids;
    }
}; 

int main()
{
    Solution obj;
    vector<int> vect{10,2,-5}; //ans is supposed to be 10
    obj.asteroidCollision(vect);
    for(int i=0;i<vect.size();i++) cout<<vect[i]<<" ";
    return 0;
}


/*
//ACCEPTED SOLUTION ********************************************************
class Solution 
{
  public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack <int> s;
        for(int i=0;i<asteroids.size();i++)
        {
            if(s.empty() || asteroids[i]>0)
            {
                s.push(asteroids[i]);
            }
            else
            {
                
                while(true)
                {
                  int top=s.top();

                  if(top<0)
                  {
                     s.push(asteroids[i]);
                     break;
                  }
                  else if(top==(-asteroids[i]))
                  {
                      s.pop();
                      break;

                  }
                  else if(top>(-asteroids[i]))
                  {
                      break;
                  }
                  else
                  {
                      s.pop();
                      if(s.empty())
                      {
                          s.push(asteroids[i]);
                          break;
                      }
                  }

                }
                
            }
        }
       vector<int> output(s.size(),0);
        for(int i=s.size()-1;i>=0;i--)
        {
            output[i]=s.top();
            s.pop();
        }
        return output;
    }
};
*/