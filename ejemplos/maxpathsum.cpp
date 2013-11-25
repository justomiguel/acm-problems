#include <stdio.h>
#include <algorithm>

using namespace std;

int s[1024][1024];
int n;

int main(){
	scanf("%d",&n);
	for(int i = 0;i < n;++i)
		for(int j = 0;j <= i;++j)
			scanf("%d",&s[i][j]);
	for(int i = n-1;--i >= 0;)
		for(int j = 0;j <= i;++j)
			s[i][j] += max(s[i+1][j],s[i+1][j+1]);
	printf("%d\n",s[0][0]);
}