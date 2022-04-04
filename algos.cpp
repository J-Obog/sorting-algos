//#include "algos.hpp"

void merge(int arr[], int i, int j, int k) {
   int mergedSize = k - i + 1;
   int mergePos = 0;
   int leftPos = 0;
   int rightPos = 0;
   int* mergedNumbers = new int[mergedSize];
   leftPos = i;
   rightPos = j + 1;
   
   while (leftPos <= j && rightPos <= k) {
      if (arr[leftPos] <= arr[rightPos]) {
         mergedNumbers[mergePos] = arr[leftPos];
         ++leftPos;
      } else {
         mergedNumbers[mergePos] = arr[rightPos];
         ++rightPos; 
      }
      ++mergePos;
   }
   
   while (leftPos <= j) {
      mergedNumbers[mergePos] = arr[leftPos];
      ++leftPos;
      ++mergePos;
   }
   
   while (rightPos <= k) {
      mergedNumbers[mergePos] = arr[rightPos];
      ++rightPos;
      ++mergePos;
   }
   
   for (mergePos = 0; mergePos < mergedSize; ++mergePos) {
      arr[i + mergePos] = mergedNumbers[mergePos];
   }
}

void selectionSort(int arr[], int n) {
    int outer, inner, min;
    for (outer = 0; outer < n - 1; outer++) {
        min = outer;
        for (inner = outer + 1; inner < n; inner++) {
            if (arr[inner] < arr[min]) {
                min = inner;
            }
        }
        int temp = arr[outer];
        arr[outer] = arr[min];

        arr[min] = temp;
    }
}

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n) {
   for (int i = 0; i < n - 1; i++) {
      for (int j = 0; j < n - i - 1; j++) {
         if (arr[j] > arr[j+1]) {
            int temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
   }
}

void mergeSort(int arr[], int i, int k) {
   int j = 0;
   
   if (i < k) {
      j = (i + k) / 2;
      
      mergeSort(arr, i, j);
      mergeSort(arr, j + 1, k);
      merge(arr, i, j, k);
   }
}

int partition(int arr[], int lowIndex, int highIndex) {
   int midpoint = lowIndex + (highIndex - lowIndex) / 2;
   int pivot = arr[midpoint];
   
   bool done = false; 
   while (!done) {
      while (arr[lowIndex] < pivot) {
         lowIndex += 1;
      }

      while (pivot < arr[highIndex]) {
         highIndex -= 1;
      }

      if (lowIndex >= highIndex) {
         done = true;
      } else {
         int temp = arr[lowIndex];
         arr[lowIndex] = arr[highIndex];
         arr[highIndex] = temp;
         lowIndex += 1;
         highIndex -= 1;
      }
   }
   
   return highIndex;
}

void quicksort(int arr[], int lowIndex, int highIndex) {
   if (lowIndex >= highIndex) {
      return;
   }

   int lowEndIndex = partition(arr, lowIndex, highIndex);

   quicksort(arr, lowIndex, lowEndIndex);
   quicksort(arr, lowEndIndex + 1, highIndex);
}

void maxHeapPercolateDown(int nodeIndex, int arr[], int n) {
   int childIndex = 2 * nodeIndex + 1;
   int value = arr[nodeIndex];

   while (childIndex < n) {
      int maxValue = value;
      int maxIndex = -1;
      for (int i = 0; i < 2 && i + childIndex < n; i++) {
         if (arr[i + childIndex] > maxValue) {
            maxValue = arr[i + childIndex];
            maxIndex = i + childIndex;
         }
      }

      if (maxValue == value) {
         return;
      }
      else {
         nodeIndex = maxIndex;
         childIndex = 2 * nodeIndex + 1;
      }
   }
}

void heapsort(int arr[], int n) {
   for(int i = n / 2 - 1; i >= 0; i--) {
      maxHeapPercolateDown(i, arr, n);
   }

   for(int i = n - 1; i > 0; i--) {
      maxHeapPercolateDown(0, arr, i);
   }
}