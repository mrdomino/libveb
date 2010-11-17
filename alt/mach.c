#define WORD \
	sizeof(int)*8

static const unsigned char LOG[] =
{
	1, 1, 2, 2, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4,
	5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
	6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
	6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
	8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
	8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8
};

int
ctz(unsigned int x)
{
	return (x & -x)-1;
}

int
fls(unsigned int x)
{
	register unsigned int i, j;
	if ((i = x >> 16)) {
		if ((j = x >> 24))
			return 24+LOG[j];
		return 16+LOG[i];
	}
	if ((i = x >> 8))
		return 8+LOG[i];
	return LOG[x];
}

int
flsl(unsigned long long x)
{
	register unsigned long long i, j, k;
	if ((i = x >> 32)) {
		if ((j = x >> 48)) {
			if ((k = x >> 56))
				return 56+LOG[k];
			return 48+LOG[j];
		}
		if ((j = x >> 40))
			return 40+LOG[j];
		return 32+LOG[i];
	}
	if ((i = x >> 16)) {
		if ((j = x >> 24))
			return 24+LOG[j];
		return 16+LOG[i];
	}
	if ((i = x >> 8))
		return 8+LOG[i];
	return LOG[x];
}
