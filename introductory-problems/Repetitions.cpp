#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int low = 0, high = 0;
    int ans = 0;
    while(low < s.length()) {
        while(high < s.length() && s[low] == s[high]) high ++;
        ans = max(ans, high - low);
        low = high;
    }

    cout << ans << "\n";
    return 0;
}
