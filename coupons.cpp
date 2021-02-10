//48165055

#include <bits/stdc++.h>
using namespace std;


int DP(int i, int j, int inf, vector<int>& a, vector<vector<int>>& dp) {
    if (j > i) return inf;
    else {
    int res;
        int cost = a[i];
        if (j <= 0) {
            if (i >= 1) {
                if (cost <= 500) {
                    int dif = min(DP(i - 1, j + 1, inf, a, dp), DP(i - 1, j, inf, a, dp) + cost);
                    res = dif;
                } else {
                    return DP(i - 1, j + 1, inf, a, dp);
                }
            } else return 0;
        } else {
            if (dp[i][j] != -1) return dp[i][j];
            if (cost > 500) {
                int dif = min(DP(i - 1, j + 1, inf, a, dp), DP(i - 1, j - 1, inf, a, dp) + cost);
                res = dif;
            } else {
                int dif = min(DP(i - 1, j + 1, inf, a, dp), DP(i - 1, j, inf, a, dp) + cost);
                res = dif;
            }
        }
        dp[i][j] = res;
        return res;
    }
}


void GOODOLDDAYS(deque<int>& used, int i, int j, int inf, vector<int>& a, vector<vector<int>>& dp) {
    if (j < i) {
        int cost = a[i];
        if (j <= 0) {
            if (i >= 1) {
                if (cost > 500) {
                    used.push_back(i);
                    GOODOLDDAYS(used, i - 1, j + 1, inf, a, dp);
                } else {
                    bool addi = (DP(i, j, inf, a, dp) == DP(i - 1, j + 1, inf, a, dp));
                    if (addi) {
                        used.push_back(i);
                        GOODOLDDAYS(used, i - 1, j + 1, inf, a, dp);
                    } else GOODOLDDAYS(used, i - 1, j, inf, a, dp);
                }
            }
        } else {
            if (cost <= 500) {
                bool addi = (DP(i - 1, j + 1, inf, a, dp) == DP(i, j, inf, a, dp));
                if (addi) {
                    used.push_back(i);
                    GOODOLDDAYS(used, i - 1, j + 1, inf, a, dp);
                } else {
                    GOODOLDDAYS(used, i - 1, j, inf, a, dp);
                }
            } else {
                bool addi = (DP(i - 1, j + 1, inf, a, dp) == DP(i, j, inf, a, dp));
                if (addi) {
                    used.push_back(i);
                    GOODOLDDAYS(used, i - 1, j + 1, inf, a, dp);
                } else {
                    GOODOLDDAYS(used, i - 1, j - 1, inf, a, dp);
                }
            }
        }
    }
}


int main() {

	int inf = 1000000;

    int n;
	cin>>n;
    int k1 = 0;
    int k2 = 0;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin>>a[i];
        
	vector<vector<int>> dp(n+1, vector<int>(n+2));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n + 1; j++)
            dp[i][j] = -1;
    }

    int ans = inf;

    for (int i = 0; i <= n; i++) {
        if (ans >= DP(n, i, inf, a, dp)) {
            ans = DP(n, i, inf, a, dp);
            k1 = i;
        }
    }

	cout<<ans<<" ";

    deque<int> used;

    GOODOLDDAYS(used, n, k1, inf, a, dp);

    k2 = used.size();

	cout<<k2<<endl;

	for(int i=k2-1; i>=0; --i) { cout<<used.at(i)<<" "; }
}