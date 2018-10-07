#pragma once
//应用 用二叉树来表达代数表达式
//disavantage:没有键对值的索引 只能看找不找得到
template<typename T>

class binNode
{
public:
	binNode();//root
	binNode(const T &);//root
	binNode(const T &, binNode<T> * f);
	binNode(binNode * f);
	~binNode();
	void setLeft(const T &);
	void setRight(const T &);
	binNode* LeftChild(){return leftChild;};
	binNode* RightChild() { return rightChild; };
	T * left();
	T * right();
	//binNode* moveLeft();
	//binNode* moveRight();
	T& element() { return Element; };
	bool ifLeaf();
	void visit();
	void preorder(binNode <T> * );
	void postorder(binNode <T> *);
	void inorder(binNode <T> *);
	void path();
//private:
	binNode * leftChild, * rightChild, * father;
	T Element;
	int level;//root is level 0

	//要不要为了这题 加个 string child;
	//height = level + 1
	//可以有父亲指针 binNode*father;
};


////没有向上的节点
//template<typename T>
//class binTree//useless...
//{
//public:
//	binTree();
//	~binTree();
//	void preorder(binNode<T> * );
//	void postorder(binNode<T> * );
//	void inorder();
//private:
//	binNode<T> * root;
//};

template<typename T>//maybe consider more than one key word or use dictionary class
class BST
{
public:
	BST(const T&);
	BST() ;
	~BST();
	binNode<T> * deleteMin(binNode<T> *);///////////
	binNode<T> * getMin(binNode<T> *);////////////
	binNode<T> * removeElement(binNode<T> *，const T &);//////////////
	binNode<T> * insert(const T &,binNode<T> * );//if this element is bigger ,insert to left
	binNode<T> * getRoot() { return root; };
	void preorder() { root->preorder(); }const;
	bool FindElement(binNode<T> *,const T)const;
private:
	binNode<T> * root;

};
