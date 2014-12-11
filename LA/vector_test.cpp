#include <Vector.h>

using namespace DTL::LA;

int main()
{
	Vector<double> v(20);
	auto w = makeWrapVector(v, 10, 5);

	for(unsigned int i = 0; i < 20; ++i)
		std::cout << "v[" << i << "] = " << (v[i] = i + 1.2) << std::endl;

	for(unsigned int i = 0; i < 10; ++i)
		std::cout << "w[" << i << "] = " << w[i] << std::endl;

	[](const auto &w){std::cout << w[0] << std::endl;}(w);
	//[](const auto &w){w[0] = 20;}(w);

	return 0;
}
