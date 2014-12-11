#pragma once

#include "../General/Debug.h"

namespace DTL
{
	namespace LA
	{
		//template Matrix-like
		//{
		//public:
		//	const unsigned int N;
		//	any_type operator()(unsigned int row, unsigned int column)
		//	void     operator()(const Vector-like &dom, Vector-like &cod)
		//}

		//Reference Implementation of Matrix-like object

		template<class T>
		struct HilbertMatrix
		{
			const unsigned int N;

			HilbertMatrix(unsigned int N):N(N){}
			T operator()(unsigned int row, unsigned int column) const
			{
				ASSERT(row < N && column < N, "Row : %d, Column : %d, N : %d", row, column, N);
				return 1./(row + column + 1);
			}

			template<class V1, class V2>
			void operator()(const V1 &dom, V2 &cod) const
			{
				ASSERT(N == dom.N && N == cod.N, "Matrix : %d, Vector1 : %d, Vector2 : %d",N, dom.N, cod.N);

				for(unsigned int i = 0; i < N; ++i)
				{
					cod[i] = 0;
					for(unsigned int j = 0; j < N; ++j)
						cod[i] += 1./(1 + i + j)*dom[j];
				}
			}
		};
	}
}
