#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1005;
int n, q, mp[MAXN][MAXN], sum[MAXN][MAXN];
int X[MAXN], Y[MAXN], xx[MAXN], yy[MAXN];
int main()
{
    scanf("%d%d", &n,&q);
    int maxX = 0, maxY = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", &X[i], &Y[i]);
        xx[i] = X[i];
        yy[i] = Y[i];
    }
    sort(xx + 1, xx + n + 1);
    sort(yy + 1, yy + n + 1);
    for(int i = 1; i <= n; i++)
    {
        X[i] = lower_bound(xx + 1, xx + n + 1, X[i]) - xx;
        Y[i] = lower_bound(yy + 1, yy + n + 1, Y[i]) - yy;
        X[i]++; Y[i]++; mp[X[i]][Y[i]]++;
        maxX = max(maxX, X[i]);
        maxY = max(maxY, Y[i]);
    }
    for(int i = 1; i <= maxX; i++)
    {
        for(int j = 1; j <= maxY; j++)
        {
            sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + mp[i][j];
        }
    }
    int maxx = 0, cnt = 0;
    for(int i = 1; i <= maxX; i++)
    {
        for(int j = 1; j <= maxY; j++)
        {
            if(!mp[i][j])
            {
                int a = sum[i][j - 1] - sum[i - 1][j - 1];
                int b = sum[i][maxY] - sum[i - 1][maxY] - (sum[i][j] - sum[i - 1][j]);
                int c = sum[i - 1][j] - sum[i - 1][j - 1];
                int d = sum[maxX][j] - sum[maxX][j - 1] - (sum[i][j] - sum[i][j - 1]);
                int ans = min(min(a, b), min(c, d));
                if(ans > maxx)
                {
                    cnt = 1;
                    maxx = ans;
                }
                else if(ans == maxx) cnt++;
            }
        }
    }
    if(q==1)
    	printf("%d\n", maxx);
    else
		printf("%d\n", cnt);
    return 0;
}
