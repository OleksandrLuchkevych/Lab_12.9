#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12.9/Lab_12.9.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            Node* root = new Node(1);
            root->left = new Node(2);
            root->right = new Node(3);
            root->left->left = new Node(4);
            root->left->right = new Node(5);
            root->right->left = new Node(6);
            root->right->right = new Node(7);
            root->left->left->left = new Node(8);
            root->left->left->left->left = new Node(5);
            root->left->left->left->right = new Node(6);
            root->left->left->right = new Node(9);

            int t = countNodesWithBothChildren(root);

            Assert::AreEqual(t, 5);
		}
	};
}
