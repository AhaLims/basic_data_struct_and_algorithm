#pragma once
//Ӧ�� �ö����������������ʽ
//disavantage:û�м���ֵ������ ֻ�ܿ��Ҳ��ҵõ�
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

	//Ҫ��ҪΪ������ �Ӹ� string child;
	//height = level + 1
	//�����и���ָ�� binNode*father;
};


////û�����ϵĽڵ�
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
	binNode<T> * removeElement(binNode<T> *��const T &);//////////////
	binNode<T> * insert(const T &,binNode<T> * );//if this element is bigger ,insert to left
	binNode<T> * getRoot() { return root; };
	void preorder() { root->preorder(); }const;
	bool FindElement(binNode<T> *,const T)const;
private:
	binNode<T> * root;

};
