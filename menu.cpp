#include <iostream>
#include <time.h>
using namespace std;


int main()
{
srand(time(0)); 

    int arr1[10000], arr2[10000]; //array 1 is original array, array 2 is the copied array

    for(int i = 0; i < 10000; i++) //randomizing array 
        arr1[i] = rand() % 100;
    
int choice;
bool choiceOn = true;
while (choiceOn != false){
cout << "****************************\n";
cout << " 1 - Selection Sort.\n";
cout << " 2 - Insertion Sort\n";
cout << " 3 - Bubble Sort\n";
cout << " 4 - Merge Sort\n";
cout << " 5 - Quick Sort\n";
cout << " 6 - Heap Sort\n";
cout << " 7 - Exit.\n";
cout << " Enter in a choice and press enter: ";

cin >> choice;

switch (choice)
{
    
case 1:
//enter code here for selection sort
break;
case 2:
//enter code here for insertion sort
break;
case 3:
//enter the code here for bubble sort
break;
case 4:
//enter the code here for merge sort
break;
case 5:
//enter code here for quick sort
break;
case 6:
//enter code here for heap sort
break;
case 7:
//enter code here for program exit
break;
default:
//enter code here for default case
break;
}

}

}
