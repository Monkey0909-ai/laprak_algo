#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void insertionSort(string arr[], int n) {
    for (int i = 1; i < n; i++) {
        string key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(string arr[], int l, int m, int r) {
    int n1 = m - l + 1, n2 = r - m;
    string L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}
void mergeSort(string arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void shellSort(string arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int i = gap; i < n; i++) {
            string temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
}

int partition(long long arr[], int low, int high) {
    long long pivot = arr[high]; int i = low - 1;
    for (int j = low; j < high; j++)
        if (arr[j] <= pivot) swap(arr[++i], arr[j]);
    swap(arr[i + 1], arr[high]);
    return i + 1;
}
void quickSort(long long arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void bubbleSort(long long arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) swap(arr[j], arr[j + 1]);
}

void selectionSort(long long arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[minIdx]) minIdx = j;
        swap(arr[i], arr[minIdx]);
    }
}

void printArr(string arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << (i < n-1 ? ", " : "\n");
}
void printArrLong(long long arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << (i < n-1 ? ", " : "\n");
}

int main() {
    string nama1[] = {"Caca", "Radina", "Atress", "Lily", "Nisa"};
    int n = 5;
    cout << ">> Pilihan 1: Insertion Sort (Nama)\n";
    cout << "Sebelum : "; printArr(nama1, n);
    insertionSort(nama1, n);
    cout << "Sesudah : "; printArr(nama1, n);
    cout << "\n";

    string nama2[] = {"Tari", "Mona", "Bella", "Reva", "Intan"};
    cout << ">> Pilihan 2: Merge Sort (Nama)\n";
    cout << "Sebelum : "; printArr(nama2, n);
    mergeSort(nama2, 0, n - 1);
    cout << "Sesudah : "; printArr(nama2, n);
    cout << "\n";

    string nama3[] = {"Wulan", "Karin", "Desi", "Putri", "Amel"};
    cout << ">> Pilihan 3: Shell Sort (Nama)\n";
    cout << "Sebelum : "; printArr(nama3, n);
    shellSort(nama3, n);
    cout << "Sesudah : "; printArr(nama3, n);
    cout << "\n";

    long long nim1[] = {2510817320001LL, 2510817320045LL, 2510817320017LL, 2510817320033LL, 2510817320009LL};
    cout << ">> Pilihan 4: Quick Sort (NIM)\n";
    cout << "Sebelum : "; printArrLong(nim1, n);
    quickSort(nim1, 0, n - 1);
    cout << "Sesudah : "; printArrLong(nim1, n);
    cout << "\n";

    long long nim2[] = {2510817320052LL, 2510817320028LL, 2510817320061LL, 2510817320014LL, 2510817320037LL};
    cout << ">> Pilihan 5: Bubble Sort (NIM)\n";
    cout << "Sebelum : "; printArrLong(nim2, n);
    bubbleSort(nim2, n);
    cout << "Sesudah : "; printArrLong(nim2, n);
    cout << "\n";

    long long nim3[] = {2510817320073LL, 2510817320006LL, 2510817320049LL, 2510817320025LL, 2510817320058LL};
    cout << ">> Pilihan 6: Selection Sort (NIM)\n";
    cout << "Sebelum : "; printArrLong(nim3, n);
    selectionSort(nim3, n);
    cout << "Sesudah : "; printArrLong(nim3, n);

    return 0;
}