#include<cstdlib>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ostream>

using namespace std;

template<typename T>
class Array
{
  public:
  int H, L, N;
  vector<T> Ar;
    Array<T> (int l, int h)
    {
       int n=h-l;
       H=h; N=n; L=l; 
       for(int i=0; i<N; i++)
       {
          Ar.push_back(0);
       }
    }
    Array<T> (const Array<T>& A)
    {
       //H=A.getH();
       H=A.H;
       L=A.L;//A.getL();
       N=H-L;
       for(int i=0;i<N;i++)
         Ar.push_back(A.getElement(i+L)); 
         //Ar.push_back(A.Ar[i]);
    }
    Array<T>(vector<T> A)
    {
       H=A.size();
       L=0;
       N=H;
       for(int i=0;i<N;i++)
         Ar.push_back(A[i]);
    }
    int getH() const
    {
        return H;
    }
    int getL() const
    {
        return L;
    } 
    T getElement(int i) const 
    {
        if(i>H-1 || i<L)
        {
           cout<<"Blad - przekroczony rozmiar tablicy"<<endl;
           return Ar[H];
        }
        return Ar[i-L];
    }
/*    const Array<T>& operator=(const Array<T>& A)
    {
       H=A.getH();
       L=A.getL();
       N=H-L;
       Ar.clear();
       for(int i=0;i<N;i++)
         Ar.push_back(A.getElement(i+H));
       
    }*/
    const Array<T>& operator=(const Array<T>& A)
    {
          Array<T> C(A);
          return C;
    }
    T & operator[](int i) 
    {
        return Ar[i-L];
    }
};

template<typename T>
    ostream & operator<< (ostream &wyjscie, Array<T> &A)
    {
        for(int i=0;i<A.N;i++)
        {
           cout<<"["<<A.L+i<<","<<A.Ar[i]<<"] ";
        }
        return wyjscie<<endl;
    };
template<typename T>
    ostream & operator>> (ostream &wejscie, Array<T> &A)
    {
       T element;
       for(int i=0;i<A.N;i++)
       {
          cout<<"podaj element o indeksie "<<i+A.getL()<<": ";
          cin>>element;
       }    
       //return wejscie>>endl;
    }

int main()
{
    vector<int> Tab, Tab2;
    for(int i=0;i<10;i++)
    {
       Tab.push_back(10*i-i*i);
       Tab2.push_back(i*i*i-3);
    }
    Array<int> A1(Tab);
    Array<int> A2=A1; //dzia³a operator przypisania
    Array<int> A3(A2); //dzia³a konstruktor 2
    cout<<A2.getH()<<",  "<<A1.getH()<<endl;
    cout<<A1[5]<<"="<<A2[5]<<endl; //dzia³a operator []
    cout<<A1; //dzia³a operator <<
    system("Pause");
    return 0;
}
