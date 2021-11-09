#include <string>
#include <inttypes.h>
#include <iostream>
using namespace std;
template < typename T >
void ToBinary(T data, string& str)
{
	union { T original_number; uint32_t utility; } u;
	u.original_number = data;
	str.clear();
	for (int j = 0; j < 4; j++)
	{
		for (int i = 0; i < 8; i++)
		{
			if (u.utility % 2)  str.push_back('1');
			else str.push_back('0');
			u.utility >>= 1;
		}
		str.push_back(' ');
	}
	// Запись строки задом наперёд
	string temp(str.rbegin(), str.rend());
	str = temp;
}

template<typename T>
T swap_bits(T data, int bits, int l1, int l2)
{
	union { T original_number; uint32_t utility; } u;
	u.original_number = data;
	uint32_t tmp,tmp2;
	tmp = ((u.utility >> (l1 - bits) & ~(u.utility >> l1 << bits)) << (l2 - bits));
	tmp2= ((u.utility >> (l2 - bits) & ~(u.utility >> l2 << bits)) << (l1 - bits));
	if (l2 != 32)
		u.utility = u.utility >> l2 << l2 | tmp | (u.utility & ~(u.utility >> l2 - bits<<l2-bits));
	else
		u.utility = tmp2 | (u.utility & ~(u.utility >> l1 - bits << l1 - bits));
	if(l1!=32)
		u.utility = u.utility >> l1 << l1 | tmp2 | (u.utility & ~(u.utility >> l1 - bits << l1 - bits));
	else
		u.utility = tmp2 | (u.utility & ~(u.utility >> l1 - bits << l1 - bits));
	return u.original_number;
}
