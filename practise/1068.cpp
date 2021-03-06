#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    int coin[10001];
    int dp[10001][101] = {0};
    int check[10001][101] = {0};
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++) {
        scanf("%d", &coin[i]);
    }
    sort(coin + 1, coin + n + 1, greater<int>());
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (j < coin[i]) {
                dp[i][j] = dp[i-1][j];
            } else if (dp[i - 1][j] <= dp[i - 1][j - coin[i]] + coin[i]) {
                dp[i][j] = dp[i - 1][j - coin[i]] + coin[i];
                check[i][j] = coin[i];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
        
    }

    if (m != 0 && dp[n][m] == m) {
        int j = m, i = n;
        while (j > 0) {
            if (check[i][j] != 0) {
                if (j != m) printf(" ");
                printf("%d", check[i][j]);
                j = j - check[i][j];
            }
            i--;
        }
        printf("\n");
    } else {
        printf("No Solution\n");
    }

    return 0;
}