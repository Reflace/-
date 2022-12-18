#pragma once

#include <iostream>

template <typename T, typename BinaryPredicate>
void ShellSort(T begin, T end, int *h, int t, BinaryPredicate op)
{
	auto pj = begin;
	auto pj1 = begin;

	for (int r = t - 1; r >= 0; --r)
	{
		auto pi = begin;
		for (advance(pi, h[r]); pi != end; ++pi)
		{
			// advance(pj, h[r]);
			pj = pi;
			auto buf = *pi;
			// advance(pj1, distance(begin, pj));
			pj1 = pj;
			if (distance(begin, pj1) >= h[r])
				advance(pj1, -h[r]); // pj kak begin using
			while (distance(begin, pj) >= h[r] && op(buf, *(pj1)))
			{
				*pj = *(pj1);
				// swap(*pj, *pj1);
				advance(pj, -h[r]);
				// advance(pj1, distance(begin, pj));
				pj1 = pj;
				if (distance(begin, pj1) >= h[r])
					advance(pj1, -h[r]);
			}
			*pj = buf;
		}
	}
}
