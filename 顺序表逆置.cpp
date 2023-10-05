#include <iostream>
using namespace std;

void reverseArray(int arr[], int N) {
    int left = 0;           
    int right = N - 1;      

    while (left < right) {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        left++;
        right--;
    }
}

int main() {
    int N;
    cin >> N;

    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < N; i++) {
        cout << arr[i];
        if (i < N - 1) {
            cout << " ";
        }
    }
    cout << endl;

    reverseArray(arr, N);

    for (int i = 0; i < N; i++) {
        cout << arr[i];
        if (i < N - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}

