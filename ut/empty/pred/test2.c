#include <stdlib.h>
#include <veb.h>
#include <9unit.h>

int
main(void)
{
	uint M = 1<<16;
	Veb T = vebnew(M,0);
	vebput(T,0xf000);
	test(vebpred(T,0xf000) == 0xf000);
	vebput(T,0x0f00);
	test(vebpred(T,0x0f00) == 0x0f00);
	vebput(T,0x00f0);
	test(vebpred(T,0x00f0) == 0x00f0);
	vebput(T,0x000f);
	test(vebpred(T,0x000f) == 0x000f);
	uint x = vebpred(T,M-1);
	test(x == 0xf000);
	x = vebpred(T,x-1);
	test(x == 0x0f00);
	x = vebpred(T,x-1);
	test(x == 0x00f0);
	x = vebpred(T,x-1);
	test(x == 0x000f);
	x = vebpred(T,x-1);
	test(x == M);
	free(T.D);
	return 0;
}
