#include<cstring>
#include <cstdlib>

#define RANGE 255

int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x) return mid;

        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;

        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    if (left < j) quickSort(arr, left, j);

    if (i < right) quickSort(arr, i, right);
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

bool isSorted(const int a[], int n) {
    while (--n > 1)
        if (a[n] < a[n - 1])
            return false;
    return true;
}

void swap(int *a, int *b) {
    int *t = a;
    a = b;
    b = t;
}

void shuffle(int a[], int n) {
    for (int i = 0; i < n; i++) swap(&a[i], &a[rand() % n]);
}

void bogosort(int a[], int n) {
    while (!isSorted(a, n)) shuffle(a, n);
}

void countSort(char arr[]) {
    char output[strlen(arr)];

    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));

    for (i = 0; arr[i]; ++i) ++count[arr[i]];

    for (i = 1; i <= RANGE; ++i) count[i] += count[i - 1];

    for (i = 0; arr[i]; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    for (i = 0; arr[i]; ++i) arr[i] = output[i];
}