#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
typedef long long LL;

#ifdef _CPP_
#include <iostream>
using namespace std;
#endif

int isp(int a, int p[10000], size_t s) {
	if(!a || a == 1) return 0;
	int i;
	for(i = 0; i < s; i++) {
		if(!(a % p[i]))
			return 0;
	}
	return 1;
}

int main(int argc, char **argv) {
	freopen("gzf.in", "r", stdin);
	freopen("gzf.out","w", stdout);
	int i, cnt, p[10000], ps = 0;
	memset(p, 0, sizeof(p));
	for(i = 2; i < 500000; i++) {
		if(isp(i, p, ps)) {
			p[ps] = i;
			ps++;
		}
	}
	scanf("%i", &cnt);
	while(cnt--) {
		int i, l = 0, g = 1, z = 1, f = 0, *c, s = 0, t = 1, started = 0;
		c = (int*) calloc (ps, sizeof(int));
		memset(c, 0, ps);
		LL a, o;
#ifdef _CPP_
		cin>>a;
#else
		scanf("%lld", &a);
#endif
		o = a;
		for(i = 0; i < ps; i++) {
			if(a == 1) break;
			if(!(a % p[i]) && p[i] != o) {
				a /= p[i];
				c[i]++;
				i--, l++;
			}
		}
		s = ++i;
		for(i = 0; i < s; i++) {
			if(c[i] > 1) g = 0;
			t *= c[i] + 1;
			if(c[i]) started++;
			if(started && !c[i]) z = 0;
		}
		free(c);
		if(t % 3) f++;
		if(g) printf("G");
		if(z) printf("Z");
		if(f) printf("F");
		if(!g && !z && !f) printf("FUCK");
		printf("\n");
	}
	return 0;
}
