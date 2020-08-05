#include "SparseVector.h"
#include "SparseVectorIterator.h"

int main()
{
    std::array<int, 7>  a = {1, 0, 0, 0, 4, 5, 0 };
    SparseVector<int, 7>  v{a};

    std::array<int, 7>  b = {4, 0, 0, 0, 0, 1, 4 };
    SparseVector<int, 7>  w{b};

    SparseVector<int, 100>  x;
    x.set(55, 1);
    x.set(23,2);
    x.set(30,3);
    x.set(2,4);

    std::cout << "Initialize vectors" <<std::endl;
    std::cout << "x = " << x;
    std::cout << "v = " << v;
    std::cout << "w = " << w << std::endl;

    std::cout << "Multiplikation with scalar" <<std::endl;
    std::cout << "2*v = " << 2*v << std::endl;

    double s = v * w;
    std::cout << "Calculate scalarproduct" <<std::endl;
    std::cout << "<v,w> = " << s << std::endl << std::endl;

    std::cout << "Addition of vectors" <<std::endl;
    std::cout << "v+w = " << v+w << std::endl;

    std::cout << "Subtraction of vectors" <<std::endl;
    std::cout << "v-w = " << v-w << std::endl;

    return 0;
}