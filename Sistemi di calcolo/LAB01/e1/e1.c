// Inserire la soluzione qui...

void uint2bin(unsigned x, char bin[32])
{
	for (int i = 31; i >= 0; i--)
	{
		bin[i] = (x & 1) + '0';
		x >>= 1;
	}
	bin[32] = 0;
}
