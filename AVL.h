#ifndef AVL_H
#define AVL_H

#include<iostream>
#include<cassert>
#include<iomanip>

template <typename T>
struct node
{
	T info;
	int balance;
	node *left, *right;
};


template <typename T>
class AVL
{
public:
	AVL();
	~AVL();
	AVL(const AVL&);
	AVL& operator=(const AVL&);

	bool empty() const;

	T rootAVL() const;
	int balanceAVL() const;
	AVL leftAVL() const;
	AVL rightAVL() const;

	void insNode(const T& x);
	void delNode(const T& x);

	void print_tree() const{
		pr1(root, 0);
		cout << endl;
	}
	void createAVL();

private:
	node<T>* root;
	void deleteAVL(node<T>* &)const;
	
	void copy(node<T>*&, node<T>* const&) const;
	void copyAVL(AVL<T> const& other)
	{
		copy(root, other.root);
	}

	void pr1(const node<T>*, int) const;
	void leftRotate(node<T>*&);
	void rightRotate(node<T>*&);
	int insertElem(node<T>*&, const T&);
	int deleteElem(node<T>*&, const T&);
};


template <typename T>
AVL<T>::AVL()
{
	root = NULL;
}

template <typename T>
AVL<T>::~AVL()
{
	deleteAVL(root);
}

template <typename T>
AVL<T>::AVL(const AVL<T>& other)
{
	copyAVL(other);
}

template <typename T>
void AVL<T>::insNode(const T& x)
{
	insertElem(root, x);
}

template <typename T>
void AVL<T>::delNode(const T& x)
{
	deleteElem(root, x);
}

template <typename T>
AVL<T>& AVL<T>::operator=(const AVL<T>& other)
{
	if (this != &other)
	{
		deleteAVL(root);
		copyAVL(r);
	}
	return *this
}

template <typename T>
void AVL<T>::copy(node<T>*& pos, node<T>* const& pos2) const
{
	pos = NULL;
	if (pos2)
	{
		pos = new node<T>;
		assert(pos != NULL);
		pos->info = pos2->info;
		copy(pos->left, pos2->left);
		copy(pos->right, pos2->right);
	}
}

template <typename T>
void AVL<T>::deleteAVL(node<T>*& p) const
{
	if (p)
	{
		deleteAVL(p->left);
		deleteAVL(p->right);
		delete p;
		p = NULL;
	}
}

template <typename T>
bool AVL<T>::empty() const
{
	return root == NULL;
}

template <typename T>
T AVL<T>::rootAVL() const
{
	return root->info;
}

template <typename T>
int AVL<T>::balanceAVL() const
{
	return root->balance;
}

template <typename T>
AVL<T> AVL<T>::leftAVL() const
{
	AVL<T> temp;
	copy(temp.root, root->left);
	return temp;
}

template <typename T>
AVL<T> AVL<T>::rightAVL() const
{
	AVL<T> temp;
	copy(temp.root, root->right);
	return temp;
}

template <typename T>
void AVL<T>::createAVL()
{
	char ch = 'y';
	while (ch == 'y')
	{
		T x;
		cout << "x = ?"; cin >> x;
		insNode(x);
		cout << "ch = y/n?";
		cin >> ch;
	}
}


template <typename T>
void AVL<T>::leftRotate(node<T>*& pos)
{
	node<T>* p = pos;
	pos = pos->right;
	p->right = pos->left;
	pos->left = p;
	p->balance = p->balance - 1;
	if (pos->balance > 0)
		p->balance = p->balance - pos->balance;
	pos->balance = pos->balance - 1;
	if (p->balance < 0)
		pos->balance = pos->balance + p->balance;
}

template <typename T>
void AVL<T>::rightRotate(node<T>*& pos)
{
	node<T>* p = pos;
	pos = pos->left;
	p->left = pos->right;
	pos->right = p;
	p->balance = p->balance + 1;
	if (pos->balance < 0)
		p->balance = p->balance - pos->balance;
	pos->balance = pos->balance + 1;
	if (p->balance > 0)
		pos->balance = pos->balance + p->balance;
}

template <typename T>
int AVL<T>::insertElem(node<T>*& r, const T&x)
{
	int h = 0;
	if (!r)
	{
		r = new node<T>;
		assert(r != NULL);
		r->info = x;
		r->balance = 0;
		r->left = NULL;
		r->right = NULL;
		h = 1;
	}
	else
	if ( const_cast<T&>(x) > r->info)
	{
		if (insertElem(r->right, x))
		{
			r->balance++;
			if (r->balance == 1)
				h = 1;
			else
			if (r->balance == 2)
			{
				if (r->right->balance == -1)
					rightRotate(r->right);
				leftRotate(r);
			}
		}
	}
	else
	if ( const_cast<T&>(x) < r->info)
	{
		if (insertElem(r->left, x))
		{
			r->balance--;
			if (r->balance == -1)
				h = 1;
			else
			if (r->balance == -2)
			{
				if (r->left->balance == -1)
					leftRotate(r->left);
				rightRotate(r);
			}
		}
	}
	return h;
}

template <typename T>
int AVL<T>::deleteElem(node<T>*& r, const T&x)
{
	node<T>** p, *temp;
	int h = 0;
	if (!r)
		return 0;
	if ( const_cast<T&>(x) < r->info)
	{
		if (deleteElem(r->left, x))
		{
			r->balance++;
			if (r->balance == 0)
				h = 1;
			else if (r->balance == 2)
			{
				if (r->right->balance == -1)
					rightRotate(r->right);
				leftRotate(r);
				if (r->balance == 0)
					h = 1;
			}
		}
	}
	else if (const_cast<T&>(x) > r->info)
	{
		if (deleteElem(r->right, x))
		{
			r->balance--;
			if (r->balance == 0)
				h = 1;
			else if (r->balance == -2)
			{
				if (r->left->balance == 1)
					leftRotate(r->left);
				rightRotate(r);
				if (r->balance == 0)
					h = 1;
			}
		}
	}
	else
	{
		if (!r->right)
		{
			temp = r;
			r = r->left;
			delete temp;
			return 1;
		}
		else
		if (!r->left)
		{
			temp = r;
			r = r->right;
			delete temp;
			return 1;
		}
		else
		{
			p = &r->left;
			while ((*p)->right)
				p = &(*p)->right;
			r->info = (*p)->info;
			(*p)->info = x;
			if (deleteElem(r->left, x))
			{
				r->balance++;
				if (r->balance == 0)
					h = 1;
				else
				if (r->balance == 2)
				{
					if (r->right->balance == -1)
						rightRotate(r->right);
					leftRotate(r);
					if (r->balance == 0)
						h = 1;
				}
			}
		}
	}
	return h;
}

template <typename T>
void AVL<T>::pr1(const node<T>* p, int n) const
{
	if (p)
	{
		n = n + 7;
		pr1(p->right, n);
		cout << setw(n) << p->info << " " << p->balance << endl;
		pr1(p->left, n);
	}
}




#endif