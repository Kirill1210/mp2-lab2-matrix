#include <iostream>
#include "MyVector.h"
#include "Matrix.h"

//#include <chrono>

int main(int argc, char* argv[])
{
  TMatrix<int> a(5), b(5), c(5);
  int i, j, g = 5;
  cout << "TEST MATRIX" << endl;

  for (i = 0; i < 5; i++)
  {
    for (j = 0; j < g; j++)
    {
      a[i][j] = 10;
      b[i][j] = 5;
    }
    g--;
  }
    

  c = a + b;


  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b= " << endl << b << endl;
  cout << "Matrix c = a + b " << endl << c << endl;
  return 0;
}



//class Timer
//{
//private:
//	// Псевдонимы типов используются для удобного доступа к вложенным типам
//	using clock_t = std::chrono::high_resolution_clock;
//	using second_t = std::chrono::duration<double, std::ratio<1> >;
//
//	std::chrono::time_point<clock_t> m_beg;
//
//public:
//	Timer() : m_beg(clock_t::now())
//	{
//	}
//
//	void reset()
//	{
//		m_beg = clock_t::now();
//	}
//
//	double elapsed() const
//	{
//		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
//	}
//};
//
//int main()
//{
//  Timer t;
//
//  TMatrix<int> a(5), b(5), c(5);
//  int i, j, g = 5;
//  cout << "TEST MATRIX" << endl;
//
//  for (i = 0; i < 5; i++)
//  {
//    for (j = 0; j < g; j++)
//    {
//      a[i][j] = 10;
//      b[i][j] = 5;
//    }
//    g--;
//  }
//
//
//  c = a * b;
//  cout << "Matrix a = " << endl << a << endl;
//  cout << "Matrix b = a =  " << endl << b << endl;
//  cout << "Matrix c = a * b " << endl << c << endl;
//
//  std::cout << "Time elapsed: " << t.elapsed() << '\n';
//
//  return 0;
//}