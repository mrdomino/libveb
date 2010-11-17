#include <stdlib.h>
#include <veb.h>
#include <9unit.h>

int
main(void)
{
	uint M = 1 << 16;
	Veb T = vebnew(M, 1);
	vebdel(T, 0x000f);
	test(vebsucc(T, 0x000f) != 0x000f);
	vebdel(T, 0x00f0);
	test(vebsucc(T, 0x00f0) != 0x00f0);
	vebdel(T, 0x0f00);
	test(vebsucc(T, 0x0f00) != 0x0f00);
	vebdel(T, 0xf000);
	test(vebsucc(T, 0xf000) != 0xf000);
	vebput(T, 0x000f);
	test(vebsucc(T, 0x000f) == 0x000f);
	vebput(T, 0x00f0);
	test(vebsucc(T, 0x00f0) == 0x00f0);
	vebput(T, 0x0f00);
	test(vebsucc(T, 0x0f00) == 0x0f00);
	vebput(T, 0xf000);
	test(vebsucc(T, 0xf000) == 0xf000);
	free(T.D);
	return 0;
}

