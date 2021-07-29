//Zadanie. Merge Sort
#include<iostream>
#include<algorithm>
#include <time.h>
using namespace std;

void Merge(int A[], int k, int m, int l);


template<int k, int l> inline void mergeSort (int *A)
{
    if(k<l)
    {
    mergeSort<k,(k+l)/2>(A);
    mergeSort<(k+l)/2+1,l>(A);
    Merge(A,k,(k+l)/2,l);
    }
}

void Merge(int A[], int k, int m, int l)
{
    int i, j, x, B[l];
    i=k;
    j=m+1;
    x=0;
    while(i<=m||j<=l)
    {
        if(i>m)
        {
            B[x]=A[j];
            j++;
        }//if i>m
        else
        {
            if(j>l)
            {
                B[x]=A[i];
                i++;
            }//if j>l,i<=m
            else
            {
                if(A[i]<A[j])
                {
                    B[x]=A[i];
                    i++;
                }//if j<=l,i<=m,A[i]<A[j]
                else
                {
                    B[x]=A[j];
                    j++;
                }//j<=l,i<=m,A[i]>=A[j]
            }//else j<=l,i<=m
        }//else i<=m
        x++;
    }//while
    for(i=k;i<l+1;i++)
    {
        A[i]=B[i-k];
    }
}//Merge

main() {
//	timespec start, stop;

  int F[16] = {10,16,12,3, 34,22,74,1, 78,56,234,2, 999,6,3,45};
//  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
  mergeSort<0,15>(F);
//  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
//  std::cout<<" "<<(stop.tv_sec - start.tv_sec) * 1e9 + (stop.tv_nsec-start.tv_nsec) / 1e9<<endl<<endl;
  for(int i=0;i<16;i++)
      cout<<F[i]<<" ";
  return 0;
}

