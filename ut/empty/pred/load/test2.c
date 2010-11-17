#include <stdlib.h>
#include <veb.h>
#include <9unit.h>

uint
fill(Veb T, uint m)
{
	uint n = 0;
	for (int i = 0; i < m; ++i) {
		uint x = rand()%T.M;
		if (vebpred(T, x) != x) {
			vebput(T, x);
			++n;
		}
	}
	return n;
}

int
main(void)
{
	srand(83843);
	uint M = rand()%(1 << 16);
	Veb T = vebnew(M, 0);
	uint m = fill(T, 10);
	uint n = 0;
	uint i = vebpred(T, M);
	while (i != M) {
		++n;
		if (i == 0)
			break;
		i = vebpred(T, i-1);
	}
	test(n == m);
	free(T.D);
	return 0;
}
