#include<iostream>
#include<string>
using namespace std;
//task 2
/*2. Write a C++ program that overloads arithmetic addition for concatenating two 
names of persons in person class and use comparator operator to come name of 
persons in person class.*/
class Person
{
private:
string name;
public:
//default constructor
Person()
{
    name="";

}
//setter function
void setName()
{
  
    getline(cin,name);
}
//operator overload for catenation
Person operator+(Person &obj)
{
Person temp;
temp.name=name+obj.name;
return temp;
}
//comaparator of two names ffunction of class
bool comparator(Person &obj)
{
    if(name==obj.name)
    {
        return true;
    }
    else{
        return false;
    }
}
//getter function
void Print()
{
    cout<<name<<endl;
}
};
//here the body of main starts
int main()
{
Person p1,p2,catenation;

  cout<<"Enter the Name of 1 person : ";
p1.setName();
cout<<"Enter the Name of 1 person : ";
p2.setName();
catenation=p1+p2;
catenation.Print();

if(p1.comparator(p2))
{
    cout<<"**Both have same names**\n";
}
else{
    cout<<"**Different names**\n";
}
return 0;
}