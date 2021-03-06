#include <iostream>
#include <time.h>
#include "algos.hpp"

using namespace std;


int main() {
    srand(time(0)); 
    
    int arr1[10000], arr2[10000]; //array 1 is original array, array 2 is the copied array

    for(int i = 0; i < 10000; i++) //randomizing array 
        arr1[i] = rand() % 10000;
    
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
        bool sorting = choice >= 1 && choice <= 6;

        if (sorting) {
            for(int i = 0; i < 10000; i++) //copy content 
                arr2[i] = arr1[i];
        }
        const clock_t t = clock(); //save start epoch

        switch (choice) {
            case 1:
                cout << "Selection Sort\n";
                selectionSort(arr2, 10000);
            break;
            
            case 2:
                cout << "Insertion Sort\n";
                insertionSort(arr2, 10000);
            break;

            case 3:
                cout << "Bubble Sort\n";
                bubbleSort(arr2, 10000);
            break;

            case 4:
                cout << "Merge Sort\n";
                mergeSort(arr2, 0, 10000);
            break;

            case 5:
                cout << "Quick Sort\n";
                quicksort(arr2, 0, 10000);
            break;

            case 6:
                cout << "Heap Sort\n";
                heapsort(arr2, 10000);
            break;

            case 7:
                cout << "Program exited.\n";
                choiceOn = false;
            break;

            default:
                cout << "Invalid choice. \n";
                cout << "Try again.\n";
            break;
        }

        if(sorting){
            cout << "This sorting algorithm ran in " << float(clock() - t)/CLOCKS_PER_SEC << " secs\n"; //execution time in seconds
            
            for(int i = 0; i < 50; i++)
                cout << arr2[i] << " ";       

            cout << endl; 
        }
    }
}
