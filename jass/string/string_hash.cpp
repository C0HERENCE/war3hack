#include "string_hash.h"
#define STRING_TO_LONG(s) (*((s) + 0) + ((*((s) + 1) + ((*((s) + 2) + (*((s) + 3) << 8)) << 8)) << 8))

#define T1(A, B, C)                  \
(A) = ((C)>>13)^((A)-(B)-(C)); \
(B) = ((A)<< 8)^((B)-(C)-(A)); \
(C) = ((B)>>13)^((C)-(A)-(B)); \
(A) = ((C)>>12)^((A)-(B)-(C)); \
(B) = ((A)<<16)^((B)-(C)-(A)); \
(C) = ((B)>> 5)^((C)-(A)-(B)); \
(A) = ((C)>> 3)^((A)-(B)-(C)); \
(B) = ((A)<<10)^((B)-(C)-(A)); \
(C) = ((B)>>15)^((C)-(A)-(B)); \

#define T2(A, B, C)                  \
(C) = ((C)^((B)>>15))+(B)+(A); \
(B) = ((B)^((A)<<10))+(A)+(C); \
(A) = ((A)^((C)>> 3))+(C)+(B); \
(C) = ((C)^((B)>> 5))+(B)+(A); \
(B) = ((B)^((A)<<16))+(A)+(C); \
(A) = ((A)^((C)>>12))+(C)+(B); \
(C) = ((C)^((B)>>13))+(B)+(A); \
(B) = ((B)^((A)<< 8))+(A)+(C); \
(A) = ((A)^((C)>>13))+(C)+(B); \


uint32_t string_hash_ex(const char* str, size_t size, uint32_t prev)
{
	unsigned char* p = (unsigned char*)str;
	size_t len = size;

	uint32_t A = 0x9E3779B9;
	uint32_t B = 0x9E3779B9;
	uint32_t C = prev;

	if (len >= 12)
	{
		size_t step = len / 12;
		do
		{
			A += STRING_TO_LONG(p+0);
			B += STRING_TO_LONG(p+4);
			C += STRING_TO_LONG(p+8);

			T1(A, B, C);

			p += 12;
			len -= 12;
		}
		while (--step != 0);
	}

	C = C + size;

	switch (len)
	{
	case 11: C += p[10]<<24;
	case 10: C += p[9]<<16;
	case  9: C += p[8]<<8;
	case  8: B += p[7]<<24;
	case  7: B += p[6]<<16;
	case  6: B += p[5]<<8;
	case  5: B += p[4];
	case  4: A += p[3]<<24;
	case  3: A += p[2]<<16;
	case  2: A += p[1]<<8;
	case  1: A += p[0];
		break;
	default:
		break;
	}

	T1(A, B, C);

	return C;
}

#undef T1
#undef T2
#undef STRING_TO_LONG

uint32_t string_hash(const char* str)
{
	char buffer[0x400];
	size_t len = 0;

	while (str[len]  != '\0')
	{
		if (len >= 0x3FF) break;

		if ('a' <= str[len] && str[len] <= 'z') 
			buffer[len] = str[len] - 'a' + 'A';
		else if (str[len] == '/')
			buffer[len] = '\\';
		else
			buffer[len] = str[len];

		len++;
	}

	return string_hash_ex(buffer, len, 0);
}