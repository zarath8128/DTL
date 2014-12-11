#include <Matrix.h>
#include <Vector.h>

using namespace DTL::LA;

int main()
{
	constexpr unsigned int N = 10;
	HilbertMatrix<double> hm(N);
	Vector<double> v(N), w(N);


	for(unsigned int r = 0; r < N; ++r)
	{
		v[r] = 1;
		for(unsigned int c = 0; c < N; ++c)
			std::cout << hm(r, c) << " ";
		std::cout << "\n";
	}

	hm(v, w);

	for(unsigned int i = 0; i < N; ++i)
		std::cout << "x[" << i << "] = " << v[i] << ", Ax[" << i << "] = " << w[i] << std::endl;
}
