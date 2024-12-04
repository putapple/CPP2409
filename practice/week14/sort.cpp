#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> data = { 5, 2, 4, 1, 3 };
    sort(data.begin(), data.end());
    for (int n : data) {
        cout << n << ' ';
    }
    cout << endl;
    return 0;
}