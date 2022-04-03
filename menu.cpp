#include <iostream>
#include <time.h>
using namespace std;


int main()
{
srand(time(0)); 

    int arr1[10000], arr2[10000]; //array 1 is original array, array 2 is the copied array

    for(int i = 0; i < 10000; i++) //randomizing array 
        arr1[i] = rand() % 100;

}
