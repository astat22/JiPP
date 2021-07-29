#include<cstdlib>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ostream>

using namespace std;

template<typename T>
class Matrix
{
    int sizeX, sizeY;
    vector< vector<T> > M;
    public:
       Matrix <T> (int x, int y, vector< vector<T> > Mat)
       {
           M=Mat;
           sizeX=x;//this.M.size();
           sizeY=y;//this.M[0].size();
       }
       int getX() const
       {
           return sizeX;
       }
       int getY() const
       {
           return sizeY;
       }
       T element(int i, int j) const
       {
           return M[i][j];
       }
       T set(int i, int j, int val)
       {
          M[i][j]=val;
       }
       Matrix Matrix::operator+(const Matrix<T> &Matrix2)
       {
           Matrix<T> C(getX(),getY(),M);
           if(getX()==Matrix2.getX() && getY()==Matrix2.getY())
           {
              for(int i=0;i<sizeX;i++)
              {
                 for(int j=0;j<sizeY;j++)
                 {
                    //cout<<element(i,j)+Matrix2.element(i,j)<<" ";
                    C.set(i,j,element(i,j)+Matrix2.element(i,j));
                 }
                 //cout<<endl;
              }
              //cout<<endl;
           }
           else
           {
               cout<<"Blad. Nie mozna dodawac macierzy o roznych wymiarach."<<endl;
           }
           return C;
       }
       Matrix Matrix::operator-(const Matrix<T> &Matrix2)
       {
           Matrix<T> C(getX(),getY(),M);
           if(getX()==Matrix2.getX() && getY()==Matrix2.getY())
           {
              for(int i=0;i<sizeX;i++)
              {
                 for(int j=0;j<sizeY;j++)
                 {
                    //cout<<element(i,j)+Matrix2.element(i,j)<<" ";
                    C.set(i,j,element(i,j)-Matrix2.element(i,j));
                 }
                 //cout<<endl;
              }
              //cout<<endl;
           }
           else
           {
               cout<<"Blad. Nie mozna dodawac macierzy o roznych wymiarach."<<endl;
           }
           return C;
       }
       Matrix Matrix::operator*(const Matrix<T> &Matrix2)
       {
       
           vector< vector<T> > NovaM;
           for(int i=0;i<getY();i++)
           {
              vector<T> R;
              for(int j=0;j<Matrix2.getX();j++)
              {
                  R.push_back(0);
                  for(int k=0;k<getX();k++)
                  {
                     R[j]+=element(k,i)*Matrix2.element(j,k);
                  }
              }
              NovaM.push_back(R);
              R.clear();
           }
           Matrix<T> C(getY(),Matrix2.getX(),NovaM);
           return C;
       }
       Matrix Matrix::operator=(short a)
       {
              Matrix<T> C(getX(),getY(),M);
              return C;
       }
       void swap(int i, int j, int x, int y)
       {
            T temp = element(i,j);
            set(i,j,element(x,y));
            set(x,y,temp);
       }
       Matrix<T> transpoze()
       {
            vector< vector<T> > NovaM;
            for(int i=1;i<getY();i++)
            {
               vector<T> R;
               for(int j=0;j<getX();j++)
                  R.push_back(0);
               NovaM.push_back(R);
               R.clear();
            }
            for(int i=0;i<getX();i++)
               for(int j=0;j<getY();j++)
                  NovaM[j][i]=element(i,j);   
            Matrix<T> C(getY(),getX(),NovaM);
            return C;
       }
};
template<typename T>
    ostream & operator<< (ostream &wyjscie, Matrix<T> &Mat)
    {
        for(int i=0;i<Mat.getY();i++)
        {
           for(int j=0;j<Mat.getX();j++)
              cout<<Mat.element(j,i)<<" ";
           cout<<endl;
        }
        return wyjscie<<endl;
    };
int main()
{
    vector< vector<int> > Tab;
    vector< vector<int> > Tab2;
    for(int i=0;i<5;i++)
    {
       vector<int> R, R2;
       for(int j=0;j<5;j++)
       {
          R.push_back(i*j+j+2);
          R2.push_back(5+2*i-j);
          //R.push_back(1);
          //R2.push_back(1);
       }
       Tab.push_back(R);
       Tab2.push_back(R2);
       R.clear();
       R2.clear();
    }
    cout<<Tab[3][2]<<endl;
    Matrix<int> M1(5,5,Tab);
    Matrix<int> M2(5,5,Tab2);
    Tab.clear();
    Tab2.clear();
    cout<<M1.element(3,2)<<endl;
    cout<<M2.element(3,2)<<endl;
    Matrix<int> M3=M1+M2;
    cout<<M3.element(3,2)<<endl;
    Matrix<int> M4 = M1*M3;
    cout<<M4.element(1,1)<<endl;
    cout<<M4;
    system("Pause");
    return 0;
}
