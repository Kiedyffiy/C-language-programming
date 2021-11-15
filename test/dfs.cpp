#include "bits/stdc++.h"
//输出m个正整数拼成n的所有可能 
int m, arr[103];  // arr 用于记录方案(我认为在树状读取中会覆盖输出，合理)
void dfs(int n, int i, int a) {
  if (n == 0 && i == m+1) {
    for (int j = 1; j <= i - 1; ++j) printf("%d ", arr[j]);
    printf("\n");
  }//else return;
  if (i <= m) {
    for (int j = a; j <= n; ++j) {
      arr[i] = j;
      dfs(n - j, i + 1, j);  //!
    }
  }
}
int main(){
int n;
scanf("%d%d", &n, &m);
dfs(n, 1, 1);
}
