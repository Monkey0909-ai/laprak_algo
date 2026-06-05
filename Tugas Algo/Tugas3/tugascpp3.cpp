#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int count = 0;

    for (int i = 0; i < N; i++) {
        int target = X - a[i];

        auto it = lower_bound(a.begin() + i + 1, a.end(), target);

        if (it != a.end() && *it == target) {
            count++;
        }
    }

    cout << count << endl;

    return 0;
}