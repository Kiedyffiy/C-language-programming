#include "bits/stdc++.h"
//���m��������ƴ��n�����п��� 
int m, arr[103];  // arr ���ڼ�¼����(����Ϊ����״��ȡ�лḲ�����������)
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
