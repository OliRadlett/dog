#include "stdafx.h"
#include "CppUnitTest.h"
#include "../dog/maths.h"
#include <vector>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(AddInts)
		{
			// https://blogs.msdn.microsoft.com/vcblog/2017/04/19/cpp-testing-in-visual-studio/
			// idk what im doing so use this...
			int x = 3;
			int y = 2;
			int z = 1;
			int expected = 6;
			std::vector<int> numbers = { x, y, z };
			int result = maths::add(numbers);
			// TODO maths classes should return valyes instead of just printing them to the console
			// Note this will also require some way of printing the returned values

			Assert::AreEqual(expected, result);
		}

	};
}