#pragma once

#include <../General/Debug.h>

namespace DTL
{
	namespace LA
	{

		//template Vector-like
		//{
		//public:
		//  const unsigned int N;
		//	any_type operator[](unsigned int i)
		//};

		//Reference Implementation of Vector-like class
		template<class T>
		class Vector
		{
			T *buf;
		public:
			const unsigned int N;
			Vector(unsigned int N):buf(new T[N]), N(N){}
			~Vector(){delete [] buf;}

			T &operator[](unsigned int i)
			{
				ASSERT(i < N, "index : %d, N : %d", i, N);
				return buf[i];
			}
			
			const T &operator[](unsigned int i) const
			{
				ASSERT(i < N, "index : %d, N : %d", i, N);
				return buf[i];
			}	
		};

		template<class V>
		class WrapVector
		{
			V &v;
			const unsigned int offset;

		public:
			const unsigned int N;
			WrapVector(V &v, unsigned int N, unsigned int offset = 0)
				:v(v), offset(offset), N(N){}

			auto operator[](unsigned int i)
			{
				ASSERT(i < N, "index : %d, N : %d", i, N);
				return v[i + offset];
			}

			auto operator[](unsigned int i) const 
			{
				ASSERT(i < N, "index : %d, N : %d", i, N);
				return [this, i](const V &v){return v[offset + i];}(v);
			}
		};

		template<class V>
		auto makeWrapVector(V &v, unsigned int N, unsigned int offset = 0)
		{
			return WrapVector<V>(v, N, offset);
		}
	}
}
