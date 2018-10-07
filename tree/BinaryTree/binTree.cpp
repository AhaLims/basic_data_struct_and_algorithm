#include"binTree.h"

#include<iostream>
using namespace std;
int maxlevel = 0;

template<typename T>
binNode<T>::binNode()
{
	leftChild = rightChild = nullptr;
	Element = 0;
	level = 0;
	father = nullptr;
}

template<typename T>
binNode<T>::binNode(const T & e)
{
	level = 0;
	father = nullptr;
	Element = e;
	leftChild = rightChild = nullptr;
}
template<typename T>
binNode<T>::binNode(const T & e, binNode<T> * f)
{
	leftChild = rightChild = nullptr;
	Element = e;
	father = f;
}

template<typename T>
binNode<T>::binNode(binNode * f)
{
	leftChild = rightChild = nullptr;
	Element = 0;
	father = f;
}

template<typename T>
binNode<T>::~binNode()//delete tree
{
	if (leftChild != nullptr)delete leftChild;
	if (rightChild != nullptr)delete rightChild;
}

template<typename T>
void binNode<T>::setLeft(const T & e)
{
	if (leftChild == nullptr)
		leftChild = new binNode(e,this);
	else leftChild->Element = e;
	leftChild->level = level + 1;
}

template<typename T>
void binNode<T>::setRight(const T & e)
{
	if (rightChild == nullptr)
		rightChild = new binNode(e,this);
	else rightChild->Element = e;
	rightChild->level = level + 1;
}

template<typename T>
T * binNode<T>::left()
{
	return leftChild;
}

template<typename T>
T * binNode<T>::right()
{
	return rightChild;
}

template<typename T>
bool binNode<T>::ifLeaf()
{
	if (leftChild == nullptr && rightChild == nullptr)
		return true;
	return false;
}


template<typename T>
void binNode<T>::visit()
{
	std::cout << element()<<" ";
}

template<typename T>
void binNode<T>::preorder(binNode <T> * r)
{
	if (r == nullptr) return;
	r->visit();
	preorder(r->leftChild);
	preorder(r->rightChild);
}

template<typename T>
void binNode<T>::postorder(binNode <T> * r)
{
	if (r == nullptr) return;
	postorder(r->leftChild);
	postorder(r->rightChild);
	r->visit();
}

template<typename T>
void binNode<T>::inorder(binNode <T> * r)
{
	if (r == nullptr) return;
	inorder(r->leftChild);
	r->visit();
	inorder(r->rightChild);
}

template<typename T>
void binNode<T>::path()
{
	
	if (father == nullptr)return;
	this->father->path();
	//cout << Element;
}

//template<typename T>
//binTree<T>::binTree()
//{
//	root = nullptr;
//}
//
//template<typename T>
//binTree<T>::~binTree()
//{
//	if(root != nullptr)delete root;
//}

template<typename T>
BST<T>::BST()
{
	root = new binNode<T>();
}

template<typename T>
BST<T>::BST(const T& e )
{
	root = new binNode<T>(e);
}

template<typename T>
BST<T>::~BST()
{
	delete root;
}

template<typename T>
binNode<T> * BST<T>::deleteMin(binNode <T> * rt)//???可是没有实际上的delete啊...
{
	if (rt->left == nullptr)return rt->right;
	else
	{
		rt->setLeft(deleteMin(rt->left()));
		return rt;
	}
}

template<typename T>
binNode<T> * BST<T>::getMin(binNode<T> * rt)
{
	if (rt->left == nullptr) return rt;
	else return getMin(rt->left);//this function is continously called.
	//and we can get the element located on the leftest
}

template<typename T>
binNode<T> * BST<T>::removeElement(binNode<T> * e,const T & k)
{
	//这时候应该需要父节点吧？！
	//if (e == nullptr) return nullptr;
	if (e == nullptr) return nullptr;//报错 应该输入声明？？？
	else if (k < e->element())
	{
		//e -> set
	}
	else if (k < e->element())
	{
		
	}
	else
	{

	}
}



//bigger element is stored in the left child
template<typename T>
binNode<T>* BST<T>::insert(const T & e,binNode<T> * r)//not recursion version
{
	
	while (r != nullptr)
	{
		if (r->element() < e)//规则 左节点必定是严格小于父节点的，右节点>=父节点
		{
			if (r->leftChild != nullptr)r = r->leftChild;
			else
			{
				r->leftChild= new binNode<T>(e, r);
				return r->leftChild;
			}
		}
		else
		{
			if (r->rightChild != nullptr) r = r->rightChild;
			else
			{
				r->rightChild = new binNode<T>(e, r);
				return r->rightChild;
			}
		}
	}
	if (r == nullptr)
	{
		r = new binNode<T>(e);
		cout << "now this element is" << r->element() << endl;
		return r;
	}
	//if (r->element() < e)
	//{
	//	if(r->leftChild() != nullptr)
	//	cout << "the father is " << r->element()<<endl;
	//	cout << "now insert left\n";

	//	return insert(e, r->LeftChild());
	//}
	//else return insert(e, r->RightChild());
	//why is it wrong...

}

template<typename T>
bool BST<T>::FindElement(binNode<T> * r, const T key)const
{
	if (r == nullptr)return false;
	if (r->element() == key) return true;
	if (r->element() < key)return FindElement(r->leftChild, key);
	else return FindElement(r->rightChild, key);
}

//int main()
//{
//	int order,element;
//	BST<int> tree(1);
//	while (true)
//	{
//		cout << "enter order\n";
//		cout << "1.insert an element\n";
//		cout << "2.see the tree\n";
//		cout << "3.find a certain element\n";
//		cin >> order;
//		switch (order)
//		{
//		case 1:
//			cin >> element;
//			tree.insert(element,tree.getRoot());
//			break;
//		case 2:
//			tree.preorder();
//			cout << endl;
//			break;
//		case 3:
//			cout << "please enter this element\n";
//			cin >> element;
//			if (tree.FindElement(tree.getRoot(), element))cout << "find\n";
//			else cout << "unfind\n";
//		}
//	}
//	/*while (true)
//	{
//		cout << "enter order\n";
//		cout << "1.insert in its left\n";
//		cout << "2.insert in its right\n";
//		cout << "3.go to left\n";
//		cout << "4.go to right\n";
//		cout << "5.see this tree\n";
//		cin >> order;
//		switch (order)
//		{
//		case 1:
//			cout << "enter element\n";
//			cin >> element;
//			now->setLeft(element);
//			break;
//		case 2:
//			cout << "enter element\n";
//			cin >> element;
//			now->setRight(element);
//			break;
//		case 3:
//			now = root.leftChild;
//			break;
//		case 4:
//			now = root.rightChild;
//		case 5:
//			cout << "preorder:\n";
//			root.preorder();
//			cout << endl;
//			cout << "inorder:\n";
//			root.inorder();
//			cout << endl;
//			cout << "postorder:\n";
//			root.postorder();
//			cout << endl;
//			break;
//
//		}
//	}*/
//}
//给出前序  中序遍历


#include<iostream>
using namespace std;
#include<string>
//return position


bool find(string s, char t,int &pos) //s string   t target
{
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		if (s[i] == t)
		{
			pos = i;
			return true;
		}
	}
	return false;
}

//返回当前的根节点
binNode<char> * buildTree(binNode<char> * father,string left,string right,string pre)
{
	if (left.length() <= 1)
	{
		if (left.length() == 1)
		{
			father->leftChild = new binNode<char>(left[0]);
		}
	}
	else
	{
		int pos = 0;
		while (!find(left,pre[pos],pos))
		{
			pos++;
		}
		buildTree(father, left.substr(0, pos), left.substr(pos + 1, left.length()), pre);

			
	}
	if (right.length() <= 1)
	{
		if (right.length() == 1) father->rightChild = new binNode<char>(right[0]);
	}
	else
	{
		int pos = 0;
		while (!find(right, pre[pos], pos))
		{
			pos++;
		}
		buildTree(father, right.substr(0, pos), right.substr(pos + 1, right.length());
	}

	return father;
}

int main()
{
	string pre, in;
	cin >> pre >> in;
	binNode<char> *root;
	root = new binNode<char>(pre[0]);
	int pos;
	find(in, pre[0],pos);
	buildTree(root, in.substr(0, pos), in.substr(pos + 1, in.length()),pre);




	delete root;
}


