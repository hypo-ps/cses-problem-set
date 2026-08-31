#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    ll ans = 0;
    int prev;
    cin >> prev;
    for(int i=1; i<n; i++) {
        int a;
        cin >> a;
        ans += max(0LL, 0LL + prev - a);
        prev = max(a, prev);
    }
    cout << ans << "\n";

    return 0;
}