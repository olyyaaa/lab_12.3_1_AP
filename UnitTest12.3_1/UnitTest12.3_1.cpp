#include "pch.h"
#include "CppUnitTest.h"
#include "../lab_AP_12.03_1/lab_AP_12.03_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1231
{
    TEST_CLASS(UnitTest1231)
    {
    public:

        TEST_METHOD(TestMethod1)
        {
            int arr1[] = { 1, 2, 3, 4, 5 };
            int n1 = sizeof(arr1) / sizeof(arr1[0]);
            Elem* head1 = nullptr;
            Elem* tail1 = nullptr;
            for (int i = 0; i < n1; i++)
            {
                Elem* newNode = new Elem;
                newNode->data = arr1[i];
                newNode->next = nullptr;
                if (head1 == nullptr)
                {
                    head1 = newNode;
                    tail1 = newNode;
                }
                else
                {
                    tail1->next = newNode;
                    tail1 = newNode;
                }
                deleteBefore(&head1, 4);
                printList(head1);
            }
        }
    };
 }
