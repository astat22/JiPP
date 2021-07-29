//Zadanie. Przepisać algorytm z wykładu i sprawdzić jego działanie 
//dla N=1,2,4,8,10,16
// KOMPILOWAĆ g++ bubbleSort.cpp -lrt
#include<iostream>
#include<algorithm>
#include <time.h>
using namespace std;
void inline bubble_sort_function (int* data, int N) {
  for(int i = N-1; i>0; --i)
    for(int j=0;j<i;++j)
      if(data[j]>data[j+1]) 
	std::swap(data[j],data[j+1]);   
}

template<int N> inline void loop(int *data) {
  if(data[0]>data[1]) std::swap(data[0],data[1]);
    loop<N-1>(++data);
}

template<> inline void loop<0>(int *data) {};

template<int N>  inline void bubble_sort_template(int * data) {
  loop<N-1>(data);
  
  bubble_sort_template<N-1>(data);
}

template<>  inline void bubble_sort_template<2>(int * data) {
  loop<1>(data);
};



main() {
	timespec start, stop;
  int a[1] = {1};
  int A[1] = {1};
  int b[2] = {5,4};
  int B[2] = {5,4};
  int c[4] = {4,2,8,1};
  int C[4] = {4,2,8,1};
  int d[8] = {0,2,7,4, 2,1,6,3};
  int D[8] = {0,2,7,4, 2,1,6,3};
  int e[10] = {5,4,3,2,1,9,8,7,6,5};
  int E[10] = {5,4,3,2,1,9,8,7,6,5};
  int f[16] = {10,16,12,3, 34,22,74,1, 78,56,234,2, 999,6,3,45};
  int F[16] = {10,16,12,3, 34,22,74,1, 78,56,234,2, 999,6,3,45};
  cout<<"N-metaprogramowanie-zwykla funkcja<<endl";
//dla N=2
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
  bubble_sort_template<2>(b);
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);

  std::cout<<"2: "<< (stop.tv_sec - start.tv_sec) * 1e9 + (stop.tv_nsec - start.tv_nsec) / 1e9 ;

  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
  bubble_sort_function(B,2);
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
  std::cout<<" "<<(stop.tv_sec - start.tv_sec) * 1e9 + (stop.tv_nsec-start.tv_nsec) / 1e9<<endl;

//dla N=4
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
  bubble_sort_template<4>(c);
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);

  std::cout<<"4: "<< (stop.tv_sec - start.tv_sec) * 1e9 + (stop.tv_nsec - start.tv_nsec) / 1e9 ;

  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
  bubble_sort_function(C,4);
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
  std::cout<<" "<<(stop.tv_sec - start.tv_sec) * 1e9 + (stop.tv_nsec-start.tv_nsec) / 1e9<<endl;

//dla N=8
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
  bubble_sort_template<8>(d);
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);

  std::cout<<"8: "<< (stop.tv_sec - start.tv_sec) * 1e9 + (stop.tv_nsec - start.tv_nsec) / 1e9 ;

  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
  bubble_sort_function(D,8);
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
  std::cout<<" "<<(stop.tv_sec - start.tv_sec) * 1e9 + (stop.tv_nsec-start.tv_nsec) / 1e9<<endl;
//dla N=10

  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
  bubble_sort_template<10>(e);
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);

  std::cout<<"10: "<< (stop.tv_sec - start.tv_sec) * 1e9 + (stop.tv_nsec - start.tv_nsec) / 1e9 ;

  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
  bubble_sort_function(E,10);
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
  std::cout<<" "<<(stop.tv_sec - start.tv_sec) * 1e9 + (stop.tv_nsec-start.tv_nsec) / 1e9<<endl;
//dla N=16
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
  bubble_sort_template<16>(e);
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);

  std::cout<<"16: "<< (stop.tv_sec - start.tv_sec) * 1e9 + (stop.tv_nsec - start.tv_nsec) / 1e9 ;

  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
  bubble_sort_function(E,16);
  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
  std::cout<<" "<<(stop.tv_sec - start.tv_sec) * 1e9 + (stop.tv_nsec-start.tv_nsec) / 1e9<<endl;
  return 0;
}




const int N=12;

