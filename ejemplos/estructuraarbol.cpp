#include <stdio.h>
#include <algorithm>

using namespace std;

#define Z(a) (memset(a,0,sizeof(a)))
#define GetN(a) (sizeof(a)/sizeof((a)[0]))

template <class T,unsigned int b,bool r>
class ArbolAc{public:
	T a[1<<(b+1)];
	inline void add(unsigned int i,T amount){
		if(r) i=(1<<b)-i-1;

		i+=(1<<b);
		while(i>0){
			a[i] += amount;
			i/=2;
		}
	};
	inline T get(unsigned int i){
		if(r) i=(1<<b)-i-1;

		i+=(1<<b);
		T x = 0;
		while(1){
			if(i%2==0)
				x += a[i];
			if((i&(i-1)) == 0)
				break;
			--i;i/=2;
		}
		return x;
	};
};

template <class T,unsigned int b,T n>
class ArbolAsoc{public:
	T a[1<<(b+1)];
	inline void set(unsigned int i,T amount){
		i+=(1<<b);
		a[i] = amount;
		T t = max(amount,a[i^1]);
		i/=2;
		while(i>0){
			a[i] = t;
			t = max(t,a[i^1]);
			i/=2;
		}
	};
	inline T get(unsigned int f,unsigned int t){
		f+=(1<<b);
		t+=(1<<b);
		T x = n;
		while(f < t){
			if(f%2!=0){
				x = max(x,a[f]);
				++f;
			}
			if(t%2==0){
				x = max(x,a[t]);
				--t;
			}
			f/=2;
			t/=2;
		}
		if(f == t)
			x = max(x,a[f]);
		return x;
	};
	inline T get2(unsigned int f){
		return a[f+(1<<b)];
	};
};

ArbolAc<unsigned int,6,false> ar;
ArbolAsoc<unsigned int,6,0> aq;
static const int incs[] = {1,6,3,7,9,3,1,6,4,2,7,98,8,1,1};
static const int puntos[] = {1,8,3,7,9,3,1,6,4,2,7,98,8,1,5};

int main(){
	for(int i = 0;i < GetN(incs);++i)		ar.add(i,incs[i]);
	for(int i = 0;i < 28;++i)				printf("%d,",ar.get(i));
	printf("\n\n");
	for(int i = 0;i < GetN(puntos);++i)	aq.set(i,puntos[i]);
	for(int i = 0;i < 28;++i)				printf("%d,",aq.get2(i));
	printf("\n");
	for(int i = 0;i < 10;++i)				printf("%d-%d:	%u\n",i,i+5,aq.get(i,i+5));
	return 0;
	/* Salida
	1,7,10,17,26,29,30,36,40,42,49,147,155,156,157,157,157,157,157,157,157,157,157,157,157,157,157,157,

	1,8,3,7,9,3,1,6,4,2,7,98,8,1,5,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0-5:    9
	1-6:    9
	2-7:    9
	3-8:    9
	4-9:    9
	5-10:   7
	6-11:   98
	7-12:   98
	8-13:   98
	9-14:   98
}