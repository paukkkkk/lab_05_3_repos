#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_05_3/lab05_3.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab051
{
	TEST_CLASS(UnitTestLab051)
	{
	public:

		TEST_METHOD(TestP_GreaterOrEqualOne)
		{
			double x = 1.5; 
			double actual = p(x);

			double expected = ((cos(x) * cos(x)) - sin(x)) / exp(sin(x));

			Assert::AreEqual(expected, actual, 0.0001, L"Function p failed for abs(x) >= 1");
		}

		TEST_METHOD(TestP_LessThanOne)
		{
			double x = 0.5; 
			double actual = p(x);

			Assert::IsFalse(isnan(actual), L"Result is NaN");
			Assert::IsFalse(isinf(actual), L"Result is Infinity");

			bool isValidRange = (actual > -10.0 && actual < 10.0);
			Assert::IsTrue(isValidRange, L"Result is out of expected range");
		}

		TEST_METHOD(TestP_BoundaryValue)
		{
			double x = 1.0; 
			double actual = p(x);
			double expected = ((cos(x) * cos(x)) - sin(x)) / exp(sin(x));

			Assert::AreEqual(expected, actual, 0.0001, L"Function p failed at boundary x = 1.0");
		}
	};
}
