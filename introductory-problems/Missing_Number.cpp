#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    int missing = 0;
    for(int i=1; i<=n; i++) missing = missing ^ i;
    for(int i=0; i<n-1; i++) {
        int a; cin >> a;
        missing = missing ^ a;
    }
    cout << missing << "\n";
    return 0;
}