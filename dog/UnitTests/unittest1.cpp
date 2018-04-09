#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(Maths)
	{
	public:
		TEST_METHOD(AddInts)
		{
			int x = 3;
			int y = 2;
			int z = 1;
			int expected = 6;
			std::vector<int> numbers = { x, y, z };
			int result = maths::add(numbers);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(SubInts)
		{
			int x = 3;
			int y = 2;
			int z = 1;
			int expected = 0;
			std::vector<int> numbers = { x, y, z };
			int result = maths::sub(numbers);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(MulInts)
		{
			int x = 3;
			int y = 5;
			int expected = 15;
			std::vector<int> numbers = { x, y };
			int result = maths::mul(numbers);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(DivInts)
		{
			int x = 10;
			int y = 2;
			int expected = 5;
			std::vector<int> numbers = { x, y };
			int result = maths::div(numbers);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(SinInt)
		{
			int x = 90;
			int expected = 1;
			int result = maths::_sin(x);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(CosInt)
		{
			int x = 180;
			int expected = -1;
			int result = maths::_cos(x);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TanInt)
		{
			int x = 45;
			int expected = 1;
			int result = maths::_tan(x);
			Assert::AreEqual(expected, result);
		}
	};
}