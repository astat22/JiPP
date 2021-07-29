#include<cstdlib>
#include <iostream>
#include <stdlib.h>

using namespace std;

template<class T>
class Matrix
{
 public:
    int m;
    Matrix operator+(Matrix &M1)
    {
        Matrix<T> *X = new Matrix<T>(this.m);       
        for(int i=0;i<M1.m;i++)
            for(int j=0;j<M1.m;j++)
                 X.M[i][j]=this.M[i][j]+M1.M[i][j];
        return *X;                
    };
    Matrix operator-(Matrix &M1)
    {
         Matrix<T> *X = new Matrix<T>(this.m);
      
        for(int i=0;i<M1.m;i++)
            for(int j=0;j<M1.m;j++)
                 X.M[i][j]=this.M[i][j]-M1.M[i][j];
        return X;                
    };
     Matrix operator*(Matrix &M1)
     {
         Matrix<T> *X = new Matrix<T>(this.m);      
        for(int i=0;i<this.M;i++)
            for(int j=0;j<this.M;j++)
            {
                X.M[i][j]=0;
                for(int i2=0;i2<this.m;i2++)
                    X.M[i][j]+= this.M[i2][j]*M1[i][i2];
            }
                    
        return X;                
    };
    T *M[];
    Matrix<T>(int n)
    {
        m=n;
        *M = new T [n];
        for(int i=0;i<n;i++)
            M[i] = new T[n];
        //M[0][0]=3;
    };
    void set(int i, int j, T value)
    {
        M[i][j] = value;
    };
    T element(int i, int j)
    {
        return this.M[i][j];
    };
    Matrix Matrix::operator=(const Matrix &M1)
    {     
        for(int i=0;i<M1.m;i++)
            for(int j=0;j<M1.m;j++)
                 M[i][j]=M1.M[i][j];
        return this;                
    };
};
template<typename T>
    ostream & operator<< (ostream &wyjscie, Matrix<T> &M)
    {
            for(int i=0;i<M.m;i++)
            {
                for(int j=0;j<M.m;j++)
                {
                    wyjscie<<M.M[i][j]<<" ";
                }
                cout<<endl;
            }
            return wyjscie<<endl;
    };
int main (void)
{
    Matrix<int> *M1 = new Matrix<int>(5);
    Matrix<int> *M2 = new Matrix<int>(5);
    M1=M2;
    M1->set(1,1,2);
   // cout<<Matrix::M1.element(1,1)<<endl;
    cout<<M1<<endl;
//    M1+M2;
    system("Pause");
    return 0;
}
