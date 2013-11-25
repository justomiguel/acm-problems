#include <stdio.h>
#include <cmath>
#include <stdlib.h>
#include <algorithm>

using namespace std;

int m[5000];
int monedas[] = {1,5,10,25,50,100};

int calculoMin(int t){
	if(m[t] != -1) return m[t];
	m[t] = t;
	for(int i = 0;i < 6;++i){
		if(t-monedas[i]>=0)
			m[t] = min(m[t],calculoMin(t-monedas[i])+1);
	}
	return m[t];
}

int main(){
	int q;
	scanf("%d",&q);
	for(int i = 0;i < 5000;++i)
		m[i] = -1;
	printf("%d\n",calculoMin(q));
}