#include <iostream>
#include <vector>
using namespace std;

void _merge(vector<int>& arr, int l, int m, int r) {
    vector<int> left(arr.begin() + l, arr.begin() + m + 1);
    vector<int> right(arr.begin() + m + 1, arr.begin() + r + 1);
    auto l_it = left.begin();
    auto r_it = right.begin();
    while (l_it < left.end() || r_it < right.end()) {
        if (l_it != left.end() && r_it != right.end()) {
            if (*l_it <= *r_it) {
                arr[l ++] = *l_it;
                l_it ++;
            } else {
                arr[l ++] = *r_it;
                r_it ++;
            }
        } else if (l_it != left.end()) {
            arr[l ++] = *l_it;
            l_it ++;
        } else {
            arr[l ++] = *r_it;
            r_it ++;
        }
    }
}

void _merge_sort(vector<int>& arr, int l, int r) {
    if (l >= r) {
        return;
    }
    int m = l + (r - l) / 2;
    _merge_sort(arr, l, m);
    _merge_sort(arr, m + 1, r);
    _merge(arr, l, m, r);
}
void merge_sort (vector<int>& arr) {
    _merge_sort(arr, 0, arr.size() - 1);
}

int main() {
    vector<int> to_sort {9,4,6,9,4,3,2,6,8,0,56,3,45,7,23};
    merge_sort(to_sort);
    for (const int i : to_sort) {
        cout << i << ", ";
    }
    cout << endl;
    return 0;
}
