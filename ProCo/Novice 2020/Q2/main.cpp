// ––– ProCo Advanced 2020: Problem B –––

#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
using str = string;
using ll = long long;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;

int n;

int* ord(int arr[n])
{
  int order[n];
  for (int i = 0; i < n; i++) {
    order[i] = 1 + i;
  }
  sort(order, order + n, [arr](int a, int b) {
    return arr[a] < arr[b];
  });
  return order;
}

int* ord2(int arr[n][n], int k)
{
  int order[n];
  for (int i = 0; i < n; i++) {
    order[i] = 1 + i;
  }
  sort(order, order + n, [arr, k](int a, int b) {
    return arr[a][k] > arr[b][k];
  });
  return order;
}

bool eq(int arr1[n], int arr2[n])
{
  for (int i = 0; i < n; i++) {
    if (arr1[i] != arr2[i])
      return false;
  }
  return true;
}

int main()
{
  cin >> n;

  int arr[n][n];
  for (int i = 0; i < n; i++) {
    for (int k = 0; k < n; k++) {
      cin >> arr[i][k];
    }
  }

  for (int k = 1; k < n; k++) {
    if (!eq(ord(arr[0]), ord(arr[k]))) {
      cout << "NO" << endl;
      return 0;
    }
  }

  for (int k = 1; k < n; k++) {
    int order[n];
    for (int i = 0; i < n; i++) {
      order[i] = 1 + i;
    }
    sort(order, order + n, [arr], k](int a, int b) {
      return arr[a][k] > arr[b][k];
    });
    return order;
    if (!eq(ord2(arr, 0), ord2(arr, k))) {
      cout << "NO" << endl;
      return 0;
    }
  }

  cout << "YES" << endl;
}
