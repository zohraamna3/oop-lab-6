#include<iostream>
using namespace std;
//task1
/*1. Write a C++ program to perform matrix addition using operator overloading 
concept*/
class Matrix
{
    private:
    int mat[3][3];
    public:
    //default constructor
    Matrix()
    {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                mat[i][j]=0;
            }
        }
    }
    //mutator function
    void setValue()
    {
         for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<"Enter the value of [ "<<i<<"][ "<<j<<"] = ";
                cin>>mat[i][j];
            }
        }
    }
    //overloaded + operator for matrix addition
    Matrix operator+(Matrix& obj)
    {
        Matrix temp;
         for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
              temp.mat[i][j]=  mat[i][j]+obj.mat[i][j];
            }
        }
        return temp;
    }
//accessor function of class matrix
   void displaySum()
   {
     for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<mat[i][j]<<"\t";
            }
            cout<<endl;
        }
   }
};
//here the body of main starts
int main()
{
Matrix m1,m2,result;
cout<<"_____________________________MATRIX 1____________________________________\n";
m1.setValue();
cout<<"_____________________________MATRIX 2____________________________________\n";
m2.setValue();
result=m1+m2;
cout<<"______________________________result_____________________________________\n";
result.displaySum();
return 0;
}