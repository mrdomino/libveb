#include <stdlib.h>
#include <veb.h>
#include <9unit.h>

int
main(void)
{
	uint M = 1 << 16;
	Veb T = vebnew(M, 0);
	vebput(T, 0x000f);
	test(vebsucc(T, 0x000f) == 0x000f);
	vebput(T, 0x00f0);
	test(vebsucc(T, 0x00f0) == 0x00f0);
	vebput(T, 0x0f00);
	test(vebsucc(T, 0x0f00) == 0x0f00);
	vebput(T, 0xf000);
	test(vebsucc(T, 0xf000) == 0xf000);
	uint x = vebsucc(T, 0);
	test(x == 0x000f);
	x = vebsucc(T, x+1);
	test(x == 0x00f0);
	x = vebsucc(T, x+1);
	test(x == 0x0f00);
	x = vebsucc(T, x+1);
	test(x == 0xf000);
	x = vebsucc(T, x+1);
	test(x == M);
	free(T.D);
	return 0;
}
