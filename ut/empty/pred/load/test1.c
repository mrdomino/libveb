#include <stdlib.h>
#include <veb.h>
#include <9unit.h>

Veb
fill(uint M)
{
	Veb T = vebnew(M, 0);
	for (int i = 0; i < 1000; ++i) {
		uint x = rand()%M;
		vebput(T, x);
	}
	return T;
}

int
main(void)
{
	srand(433849);
	uint M = rand()%(1 << 16);
	Veb T = fill(M);
	uint i = i = vebpred(T, M-1);
	while (i < M) {
		vebdel(T, i);
		uint j = vebpred(T, i);
		test(i != j);
		i = j;
	}
	free(T.D);
	return 0;
}
