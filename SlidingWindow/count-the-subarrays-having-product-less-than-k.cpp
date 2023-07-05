
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {

        int low = 0;
        int high = 0;

        int count = 0;
        long long product = 1;

        while (high < n) {
            product *= a[high];
            while (low <= high and product >= k) {
                product /= a[low];
                low++;
            }
            if (product < k) {
                count += (high - low + 1);
                high++;
            }

        }
        return count;

    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        long long int k;
        cin >> n >> k;
        vector<int> arr(n);
        for (i = 0; i < n; i++) cin >> arr[i];
        Solution obj;
        cout << obj.countSubArrayProductLessThanK(arr, n, k) << endl;
    }
    return 0;
}

