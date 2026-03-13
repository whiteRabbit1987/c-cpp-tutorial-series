// vector + complex demo
// vector<complex<T>>      = stores complex numbers in contiguous dynamic array
// begin() / end()         = return iterators (pointer‑like objects) to first/one‑past‑last
// iterator->member        = operator-> used because iterators behave like pointers
// prev(it, n)             = moves iterator backward by n (uses iterator arithmetic)
// end() - 1               = valid because vector iterators support random‑access arithmetic

#include <vector>
#include <iostream>
#include <complex>

int main(){
    std::vector<std::complex<double>> points;

    points.push_back(std::complex<double>(3.5, 4.0));
    points.push_back(std::complex<double>(1.0, -2.1));
    points.push_back(std::complex<double>(-5.3, 6.0));
    points.push_back(std::complex<double>(7.2, 8.9));

    std::cout << "The first real part: " 
              << points.begin()->real() << std::endl; 
              // begin() returns iterator → operator-> gives access to complex<double>

    std::cout << "Imaginary part at index 1: " 
              << points[1].imag() << std::endl; 
              // operator[] gives direct reference (random‑access)

    std::cout << "Next to last real: " 
              << prev(points.end(), 2)->real() << std::endl; 
              // prev(it, n) = move iterator backward n steps

    std::cout << "Last imaginary: " 
              << (points.end() - 1)->imag() << std::endl;
              // end() - 1 works because vector iterators support pointer‑like arithmetic

    std::cout << std::endl << std::endl;
    return 0;
}
