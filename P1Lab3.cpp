//#include<cstdlib>
#include <iostream>
//#include <stdlib.h>

using namespace std;

template <int N> //szablon
class FP{
    public:   //domyœlnie prywatne
    static inline int Pow(int a){
           if(N%2==1)
               return a*FP<N-1>::Pow(a);
           int x = FP<N/2>::Pow(a);
           return x*x;
    }      
};

template<>
class FP<1>
{
      public:
      static inline int Pow(int a)
      {
          return a;
      }
};

int main (void)
{
    int a;
    cin>>a;
    std::cout<<FP<7>::Pow(a); //3^7
    system("Pause");
    return 0;
}
