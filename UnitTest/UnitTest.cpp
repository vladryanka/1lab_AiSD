#include "pch.h"
#include "CppUnitTest.h"
#include "../АиСД_1лаба/List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(DefaultConstructorTest)
		{
			List List;
			Assert::IsTrue(List.get_size() == 0);
		}
		TEST_METHOD(ParametrConstructorTest)
		{
			List List(5);
			List::Node* buffer = List.head;
			Assert::IsTrue(buffer->element == 5);
			Assert::IsTrue(List.get_size() == 1);
		}
		TEST_METHOD(TestPush_back)
		{
			List List(5);
			Assert::IsTrue(List.get_size() == 1);
			List.push_back(6);
			List::Node* buffer = List.head;
			buffer = buffer->next;
			Assert::IsTrue(buffer->element = 6);
		}
		TEST_METHOD(TestPush_front)
		{
			List List(5);
			List.push_back(8);
			Assert::IsTrue(List.get_size() == 2);
			List::Node* buffer = List.head;
			List::Node* buffer1 = List.head;
			buffer1->element = buffer->element;
			List.push_front(9);
			buffer = List.head;
			Assert::IsTrue(buffer->element != buffer1->element);
		}
		TEST_METHOD(Testpop_back)
		{
			List List(5);
			List.push_back(4);
			List.pop_back();
			Assert::IsTrue(List.tail->element == 5);
			Assert::IsTrue(List.get_size() == 1);
		}
		TEST_METHOD(Testpop_front)
		{
			List List(5);
			List.push_back(8);
			Assert::IsTrue(List.get_size() == 2);
			List.pop_front();
			Assert::IsTrue(List.head->element == 8);
			Assert::IsTrue(List.get_size() == 1);
		}
		TEST_METHOD(Testinsert)
		{
			List List(5);
			List.push_back(8);
			List::Node* buffer = List.head;
			List.insert(1, 6);
			Assert::IsTrue(List.head->element == 6);
			List.insert(2, 7);
			buffer = List.head;
			buffer = buffer->next;
			Assert::IsTrue(buffer->element == 7);
			List.insert(3, 2);
			buffer = List.head;
			buffer = buffer->next;
			buffer = buffer->next;
			Assert::IsTrue(buffer->element == 2);
		}
		TEST_METHOD(Testat)
		{
			List List(5);
			List.push_back(8);
			List.push_back(7);
			List::Node* buffer = List.head;
			int check = List.at(2);
			buffer = List.head;
			buffer = buffer->next;
			Assert::IsTrue(buffer->element == check);
			check = List.at(1);
			Assert::IsTrue(List.head->element == check);
			check = List.at(3);
			Assert::IsTrue(List.tail->element == check);

		}
		TEST_METHOD(Testremove)
		{
			List List(5);
			List.push_back(8);
			List.push_back(4);
			List::Node* buffer = List.head;
			List.remove(1);
			Assert::IsTrue(List.head->element == 8);
			List.push_back(3);
			List.remove(3);
			Assert::IsTrue(List.tail->element == 4);
			List.push_back(0);
			List.remove(2);
			buffer = List.head;
			buffer = buffer->next;
			Assert::IsTrue(buffer->element == 0);
		}

		TEST_METHOD(Testget_size)
		{
			List List(5);
			List.push_back(8);
			Assert::IsTrue(List.get_size() == 2);
		}
		TEST_METHOD(Testclear)
		{
			List List(5);
			List.push_back(8);
			List.clear();
			Assert::IsTrue(List.head == NULL && List.tail == NULL);
		}
		TEST_METHOD(TestisEmpty)
		{
			List List;
			List.isEmpty();
			Assert::IsTrue(List.isEmpty() == true);
			Assert::IsTrue(List.get_size() == 0);
		}
		TEST_METHOD(Testset)
		{
			List List(5);
			List.push_back(9);
			List.push_back(8);
			int check = 6;
			List.set(6, 1);
			List::Node* buffer = List.head;
			Assert::IsTrue(List.head->element == check);
			List.set(5, 3);
			Assert::IsTrue(List.tail->element == 5);
			List.set(2, 2);
			buffer = buffer->next;
			Assert::IsTrue(buffer->element == 2);
		}
		TEST_METHOD(Testreverse)
		{
			List List(5);
			List.push_back(8);
			List.push_back(3);
			List::Node* buffer = List.head;
			List.reverse();
			Assert::IsTrue(buffer->element == 3);
			buffer = buffer->next;
			Assert::IsTrue(buffer->element == 8);
			buffer = buffer->next;
			Assert::IsTrue(buffer->element == 5);
		}
	};
}
