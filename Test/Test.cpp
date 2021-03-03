#include "pch.h"
#include "CppUnitTest.h"
#include "../pampam/pampam.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{
	TEST_CLASS(Test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[3][3] = { {34, 27, 6}, {5, 1, 44}, {11, 2, 48} };
			int* pa[3] = { a[0], a[1], a[2] };

			int max = Max(pa, 3, 3);

			Assert::AreEqual(max, 126);

		}
	};
}

//	34  27   6
//	5   1  44
//	11   2  48
//		=
//	   126
