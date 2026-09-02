#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> p(n+1);
    p[1] = -1;
    for(int i=0; i<n-1; i++) {
        int a; cin >> a;
        p[i+2] = a;
    }

    while(q--) {
        int x, k;
        cin >> x >> k;
        while(k-- && x != -1) {
            x = p[x];
        }

        cout << x << endl;
    }

    return 0;
}