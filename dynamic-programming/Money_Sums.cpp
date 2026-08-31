#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i=0; i<n; i++) cin >> coins[i];

    unordered_set<int> st;
    for(int i=0; i<n; i++) {
        unordered_set<int> temp;
        temp.insert(coins[i]);
        for(auto it = st.begin(); it != st.end(); it++) {
            int sum = *it + coins[i];
            temp.insert(sum);
        }

        for(auto num: temp) st.insert(num);
    }

    vector<int> ans;
    for(auto num: st) ans.push_back(num);
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto i: ans) cout << i << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}