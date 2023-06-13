#include <iostream>
#include <string>
using namespace std;
//task 4
//Create a class called Time that has separate int member data for hours, minutes, 
//and seconds. Provide the following member functions for this class:
class Time
{
private:
    int hr;
    int min;
    int sec;

public:
    Time()
    {
        hr = 0;
        min = 0;
        sec = 0;
    }
    Time(int h, int m, int s)
    {
        if (h < 24)
        {
            hr = h;
        }
        if (m < 60)
        {
            min = m;
        }
        if (s < 60)
        {
            sec = s;
        }
    }
    void show()
    {
        cout << hr << " : " << min << " : " << sec << endl;
    }
    Time operator+(Time &obj)
    {
        Time temp;
        temp.hr = hr + obj.hr;
        temp.min = min + obj.min;
        temp.sec = sec + obj.sec;
        if (temp.hr > 24)
        {
            temp.hr = 0;
        }
        if (temp.min > 59)
        {
            temp.min = 0;
            temp.hr++;
            if (temp.hr > 24)
            {
                temp.hr = 0;
            }
        }
        if (temp.sec > 59)
        {
            temp.sec = 0;
            temp.min++;
            if (temp.min > 59)
            {
                temp.min = 0;
                temp.hr++;
                if (temp.hr > 24)
                {
                    temp.hr = 0;
                }
            }
        }
        return temp;
    }
       /*e) Overloaded operators for pre- and post- increment. These increment 
operators should add a 1 to the seconds unit of time. Keep track that seconds 
should not exceed 60.*/
    void operator++()
    {
        ++hr;
        if (hr > 24)
        {
            hr = 0;
        }
        ++min;
        if (min > 59)
        {
            min = 0;
            hr++;
            if (hr > 24)
            {
                hr = 0;
            }
        }
        ++sec;
        if (sec > 59)
        {
            sec = 0;
            min++;
            if (min > 59)
            {
                min = 0;
                hr++;
                if (hr > 24)
                {
                    hr = 0;
                }
            }
        }
    }
    void operator++(int)
    {
        hr++;
        if (hr > 24)
        {
            hr = 0;
        }
        min++;
        if (min > 59)
        {
            min = 0;
            hr++;
            if (hr > 24)
            {
                hr = 0;
            }
        }
        sec++;
        if (sec > 59)
        {
            sec = 0;
            min++;
            if (min > 59)
            {
                min = 0;
                hr++;
                if (hr > 24)
                {
                    hr = 0;
                }
            }
        }
    }
       /*f) Overload operators for pre- and post- decrement. These decrement operators 
should subtract a 1 from seconds unit of time. If number of seconds goes below 
0, take appropriate actions to make this value valid.*/
    void operator--()
    {
        if(hr != 0)
        {--hr;}
        else{
            hr=23;
        }
        if(min != 0)
        {
          --min;
        }
        else{
            min=59;
        }
        if (sec != 0)
        {
            --sec;
        }
        else{
            sec=59;
        }

    }
    void operator--(int)
    {
        if(hr != 0)
        {hr--;}
        else{
            hr=23;
        }
        if(min != 0)
        {
          min--;
        }
        else{
            min=59;
        }
        if (sec != 0)
        {
            sec--;
        }
        else{
            sec=59;
        }

    }
       /*g) Overload operators for Comparison of two time objects using >, <, <=, >=, 
== operator.*/
    bool operator==(Time&obj)
    {
        if(hr==obj.hr)
        {
            if(min==obj.min)
            {
                if(sec==obj.sec)
                {
                    return true;
                }
            }
        }
       
            return false;
    }
    bool operator>(Time&obj)
    {
        if(hr>obj.hr)
        {
           
                    return true;
            
        }
        else
        {
            return false;
        }
    }
     bool operator<(Time&obj)
    {
        if(hr<obj.hr)
        {
           
           return true;
            
        }
        else
        {
            return false;
        }
    }
    bool operator<=(Time & obj)
    {
        if(hr<=obj.hr)
        {
            return true;
        }
        else{
            return false;
        }
    }
     bool operator>=(Time & obj)
    {
        if(hr>=obj.hr)
        {
            return true;
        }
        else{
            return false;
        }
    }
};
int main()
{
       /*A main() programs should create two initialized Time objects and one that isn’t 
initialized. Then it should add the two initialized values together, leaving the 
result in the third Time variable. Finally it should display the value of this third 
variable. Check the functionalities of ++ and -- operators of this program for 
both pre- and post-incrementation*/
    Time t1(1, 23, 34), t2(21, 32, 12), t3;
    cout << "\n-----------displaying time 1----------------\n";
    t1.show();
    cout << "\n-----------displaying time 2----------------\n";
    t2.show();
    t3 = t1 + t2;
    cout << "\n-----------displaying sum of time 1 and tme 2----------------\n";
    t3.show();
    cout << "\n-----------displaying pre increment time 3----------------\n";
    ++t3;
    t3.show();
    cout << "\n-----------displaying post increment time 3----------------\n";
    t3++;
    t3.show();
     cout << "\n-----------displaying pre decrement time 3----------------\n";
    --t3;
    t3.show();
    cout << "\n-----------displaying post decrement time 3----------------\n";
    t3--;
    t3.show();
     cout << "\n-----------displaying operator== overload----------------\n";
     if(t1==t2)
     {
        cout<<"Both time 1 and time 2 are equal "<<endl;
     }
     else{
        cout<<"Both time 1 and time 2 are not equal "<<endl;
     }
     cout << "\n-----------displaying operator< overload----------------\n";
     if(t1<t2)
     {
        cout<<"Time 1 is less than Time 2 "<<endl;
     }
     else{
         cout<<"Time 1 is not less than Time 2 "<<endl;
     }
     cout << "\n-----------displaying operator> overload----------------\n";
     if(t1>t2)
     {
         cout<<"Time 1 is greater than Time 2 "<<endl;
     }
      else{
         cout<<"Time 1 is not greater than Time 2 "<<endl;
     }
     cout << "\n-----------displaying operator<= overload----------------\n";
      if(t1<=t2)
     {
         cout<<"Time 1 is less than or equal to  Time 2 "<<endl;
     }
      else{
         cout<<"Time 1 is not less or equal to Time 2 "<<endl;
     }
     cout << "\n-----------displaying operator>= overload----------------\n";
      if(t1>=t2)
     {
         cout<<"Time 1 is greater than or equal to Time 2 "<<endl;
     }
      else{
         cout<<"Time 1 is not greater than or equal to Time 2 "<<endl;
     }
    return 0;
}