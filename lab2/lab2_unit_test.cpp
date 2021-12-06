
#include "CppUnitTest.h"
#include "..\lab2\cissoid.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace lab2unittest
{
	TEST_CLASS(lab2unittest)
	{
	public:
		
		TEST_METHOD(test_empty_constructor)
		{
			cissoid c;
			Assert::IsTrue(c.get_a() == 1);
		}
		TEST_METHOD(test_constructor_with_parameters)
		{
			cissoid c(5);
			Assert::IsTrue(c.get_a() == 5);
		}
		TEST_METHOD(test_set_method)
		{
			cissoid c(5);
			c.set_a(6);
			Assert::IsTrue(c.get_a() == 6);
		}
		TEST_METHOD(test_function_method)
		{
			cissoid c;
			double err = 0.0001;
			Assert::IsTrue(abs(c.f(0.1) - 0.0229416) < err);
			Assert::IsTrue(abs(c.f(0.2) - 0.0666666) < err);
			Assert::IsTrue(c.f(3) == 0);
		}
		TEST_METHOD(test_area_method)
		{
			cissoid c;
			double err = 0.01;
			Assert::IsTrue(abs(c.area() - 9.42477796) < err);
		}
		TEST_METHOD(test_distance_method)
		{
			cissoid c;
			double err = 0.001;
			Assert::IsTrue(abs(c.distance(30) - 0.5773502) < err);
			Assert::IsTrue(c.distance(90) == 0);
			Assert::IsTrue(c.distance(270) == 0);
		}
	};
}
