// ––– 2020 January: Bronze #3 –––

#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);
  for (int j = low; j <= high - 1; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
  }
}

void printArr(int arr[], int n) {
  cout << endl << arr[0];
  for (int i = 1; i < n; ++i) {
    cout << ' ' << arr[i];
  }
}

int main() {
  ifstream fin("cow.in");

  int n;
  // cin >> n;
  fin >> n;

  int cowh[n], stallh[n], num;
  for (int i = 0; i < n; ++i) {
    // cin >> num;
    fin >> num;

    cowh[i] = num;
  }
  for (int i = 0; i < n; ++i) {
    // cin >> num;
    fin >> num;

    stallh[i] = num;
  }

  printArr(cowh, n);
  printArr(stallh, n);

  quickSort(cowh, 0, n - 1);
  quickSort(stallh, 0, n - 1);

  printArr(cowh, n);
  printArr(stallh, n);

  int newLen;
  for (int i = n - 1; i > 0; i--) {
    if (cowh[i] != stallh[i]) {
      newLen = i + 1;
      break;
    }
  }
  int cowh2[newLen], stallh2[newLen];
  for (int i = 0; i < newLen; ++i) {
    cowh2[i] = cowh[i];
    stallh2[i] = stallh[i];
  }

  printArr(cowh2, newLen);
  printArr(stallh2, newLen);
}
