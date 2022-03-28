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

void mergeSort(int arr[], int i, int k) {
   int j = 0;
   
   if (i < k) {
      j = (i + k) / 2;
      
      mergeSort(arr, i, j);
      mergeSort(arr, j + 1, k);
      merge(arr, i, j, k);
   }
}