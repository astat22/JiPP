#include<cstdlib>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <ostream>

using namespace std;

template<typename T>
class Wielomian
{
    public:
    vector<T> W;
    Wielomian(vector<T> Wsp)
    {
        W=Wsp;
    };
    //friend ostream &operator<< <>(ostream &wyjscie, Wielomian<T> &Wi);
    Wielomian Wielomian::operator+(const Wielomian &W2)
    {
        size_t max = W.size();
        size_t min = max;
        if (W2.W.size()>max)
        {
            max = W2.W.size();
        }
        else
        {
            min=W2.W.size();
            //*Wk = new Wielomian<T>(this.W); 
        }
        for(int i=0;i<min;i++)
        {
            W[i]+=W2.W[i];
        }
        for(int i=min+1;i<max;i++)
        {
            W.push_back(W2.W[i]);
        }
    };
    Wielomian Wielomian::operator*(const Wielomian &W2)
    {
        size_t n1 = W.size();
        size_t n2 = W2.size();
        size_t max = n1+n2;
    }
};
template<typename T>
    ostream & operator<< (ostream &wyjscie, Wielomian<T> &Wi)
    {
            for(int i=0;i<Wi.W.size();i++)
                wyjscie<<Wi.W[i]<<"x^"<<i<<"+";
            return wyjscie<<endl;
    };

int main (void)
{
    vector<int> Tab;
    vector<int> Tab2;
    for(int i=0;i<3;i++)
    {
        Tab.push_back(i*3);
        Tab2.push_back(2-i);
    }    
    Wielomian<int> W1(Tab);
    Wielomian<int> W2(Tab2);
    cout<<W1;
    W1+W2;
    Wielomian<int>W3=W1+W2;
    cout<<W3;
    system("Pause");
    return 0;
}
