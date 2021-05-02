#include "CppUnitTest.h"
#include <iostream>
#include <string>
#include "../Lab4/List.h"
#include "../Lab4/IMessage.h"
#include "../Lab4/Logger.h"
#include "../Lab4/ILoggerChannel.h"
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab4Test
{
	TEST_CLASS(Lab4Test)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		}
		TEST_METHOD(TestBuildSimpleList)
		{
			List<int> lista;
			int testint = 1;
			lista.add_element(1);
			lista.add_element(2);
			lista.add_element(3);
			for (auto i : lista)
			{
				Assert::IsTrue(i == testint);
				testint++;

			}
		}
		TEST_METHOD(TestRemoveLastElement)
		{
			List<int> lista;
			int testint = 1;
			lista.add_element(1);
			lista.add_element(2);
			lista.add_element(3);
			lista.add_element(7);
			lista.remove_element();
			for (auto i : lista)
			{
				Assert::IsTrue(i == testint);
				testint++;
			}
		}

		TEST_METHOD(TestIteratorAddStandard)
		{
			List<int> lista;
			int testint = 1;
			lista.add_element(1);
			lista.add_element(3);
			lista.add_element(4);
			auto it = lista.begin();
			++it;
			lista.iterator_add(it, 2);
			auto it_value = *it;
			for (auto i : lista)
			{
				Assert::IsTrue(i == testint);
				testint++;
			}
			Assert::IsTrue(it_value == 2);
		}

		TEST_METHOD(TestIteratorRemoveStandard)
		{
			List<int> lista;
			int testint = 1;
			lista.add_element(1);
			lista.add_element(8);
			lista.add_element(2);
			lista.add_element(3);
			auto it = lista.begin();
			++it;
			lista.iterator_remove(it);
			auto it_value = *it;
			for (auto i : lista)
			{
				Assert::IsTrue(i == testint);
				testint++;
			}
			Assert::IsTrue(it_value == 2);
		}
		TEST_METHOD(TestIteratorAddThenRemoveStandard)
		{
			List<int> lista;
			int testint = 1;
			lista.add_element(1);
			lista.add_element(7);
			lista.add_element(3);
			auto it = lista.begin();
			++it;
			lista.iterator_add(it, 2);
			++it;
			lista.iterator_remove(it);
			auto it_value = *it;
			for (auto i : lista)
			{
				Assert::IsTrue(i == testint);
				testint++;
			}
			Assert::IsTrue(it_value == 3);
		}
		TEST_METHOD(TestIteratorAddInTheEnd)
		{
			List<int> lista;
			int testint = 1;
			lista.add_element(1);
			lista.add_element(2);
			lista.add_element(3);
			auto it = lista.end();
			lista.iterator_add(it, 4);
			auto it_value = *it;
			for (auto i : lista)
			{
				Assert::IsTrue(i == testint);
				testint++;
			}
			Assert::IsTrue(it_value == 4);
		}
		TEST_METHOD(TestIteratorRemoveNothing)
		{
			List<int> lista;
			int testint = 1;
			lista.add_element(1);
			lista.add_element(2);
			lista.add_element(3);
			auto it = lista.end();
			lista.iterator_remove(it);
			for (auto i : lista)
			{
				Assert::IsTrue(i == testint);
				testint++;
			}
		}
		TEST_METHOD(TestIteratorAddFirst)
		{
			List<int> lista;
			int testint = 1;
			lista.add_element(2);
			lista.add_element(3);
			lista.add_element(4);
			auto it = lista.begin();
			lista.iterator_add(it, 1);
			auto it_value = *it;
			for (auto i : lista)
			{
				Assert::IsTrue(i == testint);
				testint++;
			}
			Assert::IsTrue(it_value == 1);
		}
		TEST_METHOD(TestIteratorRemoveFirst)
		{
			List<int> lista;
			int testint = 1;
			lista.add_element(9);
			lista.add_element(1);
			lista.add_element(2);
			lista.add_element(3);
			auto it = lista.begin();
			lista.iterator_remove(it);
			auto it_value = *it;
			for (auto i : lista)
			{
				Assert::IsTrue(i == testint);
				testint++;
			}
			Assert::IsTrue(it_value == 1);
		}
		TEST_METHOD(TestListForStrings)
		{
			List<std::string> lista;
			std::string teststr = "baaa";
			std::string combined_elements = "";
			lista.add_element("a");
			lista.add_element("a");
			lista.add_element("a");
			auto it = lista.begin();
			lista.iterator_add(it, "b");
			auto it_value = *it;
			for (auto i : lista)
			{
				combined_elements += i;
			}
			Assert::IsTrue(combined_elements == "baaa");
			Assert::IsTrue(it_value == "b");
		}
		TEST_METHOD(TestBuildSimpleLoggerChannelFile)
		{
			ILoggerChannelFile b(Trace, None, "testlogs.txt");
			Assert::IsTrue(b.maximumSeverity() == "trace");
			Assert::IsTrue(b.minimumSeverity() == "none");
			Assert::IsTrue(b.console_or_file == 'f');

		}
		TEST_METHOD(TestBuildSimpleLoggerChannelConsole)
		{
			ILoggerChannelConsole b(Trace, None);
			Assert::IsTrue(b.maximumSeverity() == "trace");
			Assert::IsTrue(b.minimumSeverity() == "none");
			Assert::IsTrue(b.console_or_file == 'c');

		}
	};
}
