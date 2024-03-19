#include "pch.h" 
#include "CppUnitTest.h"
#include "../Project12/main.cpp" 
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QueueTests
{
    TEST_CLASS(QueueTest)
    {
    public:

        TEST_METHOD(TestEnqueueDequeue)
        {
            Queue<int> q;

            Assert::IsTrue(q.isEmpty());

            q.enqueue(5);
            Assert::IsFalse(q.isEmpty());

            int item = q.dequeue();
            Assert::AreEqual(5, item);
            Assert::IsTrue(q.isEmpty());
        }

        TEST_METHOD(TestPeek)
        {
            Queue<int> q;

            Assert::ExpectException<std::runtime_error>([&] { q.peek(); });

            q.enqueue(5);
            Assert::AreEqual(5, q.peek());

            q.enqueue(10);
            Assert::AreEqual(5, q.peek());
        }

        TEST_METHOD(TestIsEmpty)
        {
            Queue<int> q;

            Assert::IsTrue(q.isEmpty());

            q.enqueue(5);
            Assert::IsFalse(q.isEmpty());

            q.dequeue();
            Assert::IsTrue(q.isEmpty());
        }
        TEST_METHOD(TestDequeueEmptyQueue)
        {
            Queue<int> q;

            Assert::ExpectException<std::runtime_error>([&] { q.dequeue(); });
        }

    };
    TEST_CLASS(PriorityQueueTests)
    {
    public:

        TEST_METHOD(TestEnqueueDequeue)
        {
            PriorityQueue<int> pq;

            Assert::IsTrue(pq.isEmpty());

            pq.enqueue(5, 2);
            Assert::IsFalse(pq.isEmpty());

            int item = pq.dequeue();
            Assert::AreEqual(5, item);
            Assert::IsTrue(pq.isEmpty());
        }

        TEST_METHOD(TestPeek)
        {
            PriorityQueue<int> pq;

            Assert::ExpectException<std::runtime_error>([&] { pq.peek(); });

            pq.enqueue(5, 2);
            Assert::AreEqual(5, pq.peek());

            pq.enqueue(10, 1);
            Assert::AreEqual(10, pq.peek());
        }

        TEST_METHOD(TestIsEmpty)
        {
            PriorityQueue<int> pq;

            Assert::IsTrue(pq.isEmpty());

            pq.enqueue(5, 2);
            Assert::IsFalse(pq.isEmpty());

            pq.dequeue();
            Assert::IsTrue(pq.isEmpty());
        }

        TEST_METHOD(TestDequeueEmptyPriorityQueue)
        {
            PriorityQueue<int> pq;

            Assert::ExpectException<std::runtime_error>([&] { pq.dequeue(); });
        }
    };
}