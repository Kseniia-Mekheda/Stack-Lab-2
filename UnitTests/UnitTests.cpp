#include "pch.h"
#include "CppUnitTest.h"
#include "../Stack/stack.h"
#include <sstream>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTests
{
	TEST_CLASS(StackTests)
	{
	public:
		TEST_METHOD(TestPush)
		{
			Stack S;
			S.push(2);
			Assert::AreEqual(S.peek(), 2);

			S.push(35);
			Assert::AreEqual(S.peek(), 35);
		}
		TEST_METHOD(TestPop)
		{
			Stack S;
			S.push(1);
			S.push(2);
			S.push(3);

			Assert::AreEqual(S.pop(), 3);
			Assert::AreEqual(S.pop(), 2);
			Assert::AreEqual(S.pop(), 1);
			Assert::IsTrue(S.isEmpty());
		}

		TEST_METHOD(TestIsEmpty)
		{
			Stack S;
			Assert::IsTrue(S.isEmpty());
			S.push(1);
			Assert::IsFalse(S.isEmpty());
			S.pop();
			Assert::IsTrue(S.isEmpty());
		}

		TEST_METHOD(TestTopElement)
		{
			Stack S;
			S.push(1);
			S.push(2);
			S.push(3);

			Assert::AreEqual(S.peek(), 3);
			S.pop();
			Assert::AreEqual(S.peek(), 2);
		}

		TEST_METHOD(DeleteSuccess)
		{
			Stack S;
			S.push(1);
			S.push(2);
			S.push(3);

			S.~Stack();
			Assert::IsTrue(S.isEmpty());
		}

		TEST_METHOD(PrintTest)
		{
			Stack S;
			S.push(1);
			S.push(2);
			S.push(3);

			std::ostringstream output;
			std::streambuf* oldOutput = std::cout.rdbuf();
			std::cout.rdbuf(output.rdbuf());

			S.print();

			std::cout.rdbuf(oldOutput);

			Assert::AreEqual("Your stack: \n3 2 1 \n", output.str().c_str());
		}

		TEST_METHOD(StackCopy)
		{
			Stack S;
			S.push(1);
			S.push(2);
			S.push(3);

			Stack C(S);

			Assert::AreEqual(S.peek(), C.peek());
			S.pop();
			C.pop();
			Assert::AreEqual(S.peek(), C.peek());
			Assert::AreEqual(S.pop(), 2);
			Assert::AreEqual(S.pop(), 1);

			Assert::IsTrue(S.isEmpty());
			Assert::IsFalse(C.isEmpty());
		}
	};
}
