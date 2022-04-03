void merge(int arr[], int i, int j, int k) {
   int mergedSize = k - i + 1;
   int mergePos = 0;
   int leftPos = 0;
   int rightPos = 0;
   int* mergedNumbers = new int[mergedSize];
   int leftPos = i;
   int rightPos = j + 1;
   
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

void selectionSort(int a[], int size) {
    int outer, inner, min;
    for (outer = 0; outer < size - 1; outer++) {
        min = outer;
        for (inner = outer + 1; inner < size; inner++) {
            if (a[inner] < a[min]) {
                min = inner;
            }
        }
        int temp = a[outer];
        a[outer] = a[min];

        a[min] = temp;
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

void mergeSort(int arr[], int i, int k) {
   int j = 0;
   
   if (i < k) {
      j = (i + k) / 2;
      
      mergeSort(arr, i, j);
      mergeSort(arr, j + 1, k);
      merge(arr, i, j, k);
   }
}
