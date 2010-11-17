#include <stdlib.h>
#include <veb.h>
#include <9unit.h>

Veb
fill(uint M)
{
	Veb T = vebnew(M, 0);
	for (int i = 0; i < 8; ++i) {
		uint x = rand()%M;
		vebput(T, x);
		test(vebsucc(T, x) == x);
	}
	return T;
}

int
main(void)
{
	srand(438749);
	uint M = rand()%(1 << 16);
	Veb T = fill(M);
	uint i = i = vebsucc(T, 0);
	while (i < M) {
		vebdel(T, i);
		uint j = vebsucc(T, i);
		test(i != j);
		i = j;
	}
	free(T.D);
	return 0;
}
