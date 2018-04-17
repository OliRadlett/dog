#include "stdafx.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{		
	TEST_CLASS(Maths)
	{
	public:
		TEST_METHOD(AddInts)
		{
			double x = 3;
			double y = 2;
			double z = 1;
			double expected = 6;
			std::vector<double> numbers = { x, y, z };
			double result = maths::add(numbers);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(AddDoubles)
		{
			double x = 3.5;
			double y = 2.1;
			double z = 1.9;
			double expected = 7.5;
			std::vector<double> numbers = { x, y, z };
			double result = maths::add(numbers);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(SubInts)
		{
			double x = 3;
			double y = 2;
			double z = 1;
			double expected = 0;
			std::vector<double> numbers = { x, y, z };
			double result = maths::sub(numbers);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(MulInts)
		{
			double x = 3;
			double y = 5;
			double expected = 15;
			std::vector<double> numbers = { x, y };
			double result = maths::mul(numbers);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(DivInts)
		{
			double x = 10;
			double y = 2;
			double expected = 5;
			std::vector<double> numbers = { x, y };
			double result = maths::div(numbers);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(SinInt)
		{
			double x = 90;
			double expected = 1;
			double result = maths::_sin(x);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(SinDouble)
		{
			double x = 30.5;
			double expected = 0.508;
			double result = maths::_sin(x);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(CosInt)
		{
			double x = 180;
			double expected = -1;
			double result = maths::_cos(x);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(CosDouble)
		{
			double x = 30.5;
			double expected = 0.862;
			double result = maths::_cos(x);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TanInt)
		{
			double x = 45;
			double expected = 1;
			double result = maths::_tan(x);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(TanDouble)
		{
			double x = 60.5;
			double expected = 1.767;
			double result = maths::_tan(x);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(DegToRadDouble)
		{
			double x = 75.5;
			double expected = 1.318;
			double result = maths::round(maths::DegToRad(x) * 1000) / 1000;
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(DegToRadInt)
		{
			double x = 180;
			double expected = PI;
			double result = maths::DegToRad(x);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(RadToDegDouble)
		{
			double x = PI;
			double expected = 180;
			double result = maths::RadToDeg(x);
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(RadToDegInt)
		{
			double x = 1;
			double expected = 57.296;
			double result = maths::round(maths::RadToDeg(x) * 1000) / 1000;
			Assert::AreEqual(expected, result);
		}
		TEST_METHOD(DuplicateStrExists)
		{
			std::string name = "testString";
			bool expected = true;
			vars::InitString(name, "testValue");
			bool result = vars::exists(name);
			Assert::AreEqual(expected, result);
			// Possibly delete string after test to avoid confusion
		}
		TEST_METHOD(StrNotExists)
		{
			std::string name = "anotherTestString";
			bool expected = false;
			bool result = vars::exists(name);
			Assert::AreEqual(expected, result);
			// Possibly delete string after test to avoid confusion
		}
		TEST_METHOD(DuplicateNumExists)
		{
			std::string name = "testNumber";
			bool expected = true;
			vars::InitString(name, "testNumber");
			bool result = vars::exists(name);
			Assert::AreEqual(expected, result);
			// Possibly delete number after test to avoid confusion
		}
		TEST_METHOD(NumNotExists)
		{
			std::string name = "anotherTestNumber";
			bool expected = false;
			bool result = vars::exists(name);
			Assert::AreEqual(expected, result);
			// Possibly delete number after test to avoid confusion
		}
		TEST_METHOD(DuplicateBoolExists)
		{
			std::string name = "testBoolean";
			bool expected = true;
			vars::InitBoolean(name, "testBoolean");
			bool result = vars::exists(name);
			Assert::AreEqual(expected, result);
			// Possibly delete boolean after test to avoid confusion
		}
		TEST_METHOD(BoolNotExists)
		{
			std::string name = "anotherTestBoolean";
			bool expected = false;
			bool result = vars::exists(name);
			Assert::AreEqual(expected, result);
			// Possibly delete boolean after test to avoid confusion
		}
	};
}