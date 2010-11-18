#include <stdlib.h>
#include <veb.h>
#include <9unit.h>

uint
fill(Veb T, uint m)
{
	uint n = 0;
	for (int i = 0; i < m; ++i) {
		uint x = rand()%T.M;
		if (vebsucc(T,x) != x) {
			vebput(T,x);
			++n;
		}
	}
	return n;
}

int
main(void)
{
	srand(83843);
	uint M = rand()%(1<<16);
	Veb T = vebnew(M,0);
	uint m = fill(T,1000);
	uint n = 0;
	uint i = vebsucc(T,0);
	while (i != M) {
		++n;
		i = vebsucc(T,i+1);
	}
	test(n == m);
	free(T.D);
	return 0;
}
