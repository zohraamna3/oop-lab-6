#include <iostream>
#include <string>
using namespace std;
//task3
/*3. Create a class called Martix that represents a 3x3 matrix. Create a constructor 
for initializing the matrix with 0 values. Create another overloaded constructor 
for initializing the matrix to the values sent from outside. Overload the + and += 
operators for addition of two matrices, == operator for checking the equality of 
two matrices, and *operator for finding the product of the two matrices. Define 
all the member functions outside the class*/
class Matrix
{
private:
    int mat[3][3];

public:
//default constructor
    Matrix()
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                mat[i][j] = 0;
            }
        }
    }
    //parametrized constructor
    Matrix(int arr[][3])
    {
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                mat[i][j] = arr[i][j];
            }
        }
    }
    //getter function
    void display();
    Matrix operator+(Matrix &obj);//+ operator overload
    void operator+=(Matrix&obj);//+= operator overload
    Matrix operator*(Matrix&obj);//* operator oveload
    bool operator==(Matrix&obj);//==operator overload
};
void Matrix::display()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << mat[i][j] << "\t";
        }
        cout << endl;
    }
}
Matrix Matrix::operator+(Matrix &obj)
{

    Matrix temp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            temp.mat[i][j] = mat[i][j] + obj.mat[i][j];
        }
    }
    return temp;
}
void Matrix:: operator+=(Matrix&obj)
{
    
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            mat[i][j] = mat[i][j] + obj.mat[i][j];
        }
    }

}
Matrix Matrix::operator*(Matrix &obj)
{
    Matrix temp;
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
          temp.mat[i][j]=0;
            for(int k=0;k<3;k++)
            {
                temp.mat[i][j]+=mat[i][k]*obj.mat[k][j];

            }
        }
    }
    return temp;
}
bool Matrix::operator==(Matrix&obj)
{
    Matrix temp;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
        if( mat[i][j] != obj.mat[i][j])
        {
            return false;
        }
        
        }
    }
    return true;
}
//here the body of main starts
int main()
{
Matrix result;
    int array[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter the value of [" << i << "][" << j << "] = ";
            cin >> array[i][j];
        }
    }
    Matrix m1(array);
    cout << "\n--------Displaying 1st matrix--------\n";
    m1.display();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter the value of [" << i << "][" << j << "] = ";
            cin >> array[i][j];
        }
    }
    Matrix m2(array);
     cout << "\n--------Displaying 2st matrix--------\n";
   m2.display();
    result=m1+m2;
    cout << "\n--------Displaying sum of matrixes--------\n";
    result.display();
     
    result=m1*m2;
     cout << "\n--------Displaying multiplication of matrixes--------\n";
    result.display();
     cout << "\n--------Checking equality of matrixes--------\n";
    if(m1==m2)
    {
        cout<<"Equal matrices \n";
    }
    else{
        cout<<"Not equal matrices \n";
    }
    cout << "\n--------Displaying += operator overloaded matrix--------\n";
     m1+=m2;
     m1.display();
     return 0;
}