#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include "CppUnitTest.h"
#include <fstream>
#include "../Lab_11.1/Lab_11.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		        {
            std::string line1 = "abc, -def";
            std::string line2 = "abc, def";
            std::string line3 = ", - , - , -";
            std::string line4 = "no matches here";

            Assert::AreEqual(1, countCommaDash(line1.c_str()), L"Error in counting ', -' in line 1");
            Assert::AreEqual(0, countCommaDash(line2.c_str()), L"Error in counting ', -' in line 2");
            Assert::AreEqual(3, countCommaDash(line3.c_str()), L"Error in counting ', -' in line 3");
            Assert::AreEqual(0, countCommaDash(line4.c_str()), L"Error in counting ', -' in line 4");
        }
	};
}
