#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <ostream>
#include <cmath>
#include <string>
#include "QueueArray.hpp"

namespace bst
{
	template < class T >
	class BinarySearchTree
	{
		public:
		BinarySearchTree();
		BinarySearchTree(const BinarySearchTree&) = delete;
		BinarySearchTree(BinarySearchTree&&) noexcept;
		virtual ~BinarySearchTree();

		BinarySearchTree& operator=(const BinarySearchTree&) = delete;
		BinarySearchTree& operator=(BinarySearchTree&&) noexcept;

		bool searchKeyIterative(const T& key) const;
		bool insertNode(const T& key);
		bool deleteNode(const T& key);
		void output(std::ostream& out) const;
		int getNumberOfNodes() const;
		int getHeight() const;
		void inorderWalkIterative(std::ostream& out) const;
		void inorderWalk(std::ostream& out) const;
		void walkByLevels(std::ostream& out) const;
		bool isSimilar(const BinarySearchTree& other) const;
		bool isIdenticalKey(const BinarySearchTree& other) const;

		std::string getPath(const T& key) const;

		private:
		struct Node
		{
			T key_;
			Node* left_;
			Node* right_;
			Node* p_;
			Node(T key, Node* left = nullptr, Node* right = nullptr, Node* p = nullptr):
				key_(key),
				left_(left),
				right_(right),
				p_(p)
			{}
		};
		Node* root_;

		Node* searchNodeIterative(const T& key) const;
		void output(std::ostream& out, Node* const node) const;
		int getNumberOfNodes(Node* const node) const;
		int getHeight(Node* const node) const;
		void inorderWalk(std::ostream& out, Node* const node) const;

		static Node* getMin(Node* const node);
		static Node* getNext(Node* const node);
	};
}

template < class T >
bst::BinarySearchTree< T >::BinarySearchTree():
	root_(nullptr)
{}
template < class T >
bst::BinarySearchTree< T >::BinarySearchTree(BinarySearchTree&& src) noexcept:
	root_(src.root_)
{
	src.root_ = nullptr;
}
template < class T >
bst::BinarySearchTree< T >::~BinarySearchTree()
{
	while (root_)
	{
		deleteNode(root_->key_);
	}
}

template < class T >
bst::BinarySearchTree< T >& bst::BinarySearchTree< T >::operator=(BinarySearchTree&& src) noexcept
{
	if (this != &src)
	{
		root_ = src.root_;
		src.root_ = nullptr;
	}
	return *this;
}

template < class T >
bool bst::BinarySearchTree< T >::searchKeyIterative(const T& key) const
{
	return searchNodeIterative(key);
}
template < class T >
bool bst::BinarySearchTree< T >::insertNode(const T& key)
{
	if (!root_)
	{
		Node* newNode = new Node(key);
		root_ = newNode;
		return true;
	}

	Node* current = root_;
	Node* previous = root_;
	while (current && (current->key_ != key))
	{
		previous = current;
		if (current->key_ < key)
		{
			current = current->right_;
		}
		else
		{
			current = current->left_;
		}
	}
	if (!current)
	{
		Node* newNode = new Node(key, nullptr, nullptr, previous);
		if (previous->key_ < key)
		{
			previous->right_ = newNode;
		}
		else
		{
			previous->left_ = newNode;
		}
	}
	return !current;
}
template < class T >
bool bst::BinarySearchTree< T >::deleteNode(const T& key)
{
	Node* toTermination = searchNodeIterative(key);
	if (!toTermination)
	{
		return false;
	}

	Node* parent = toTermination->p_;
	if (!parent && (!toTermination->left_ && !toTermination->right_))
	{
		root_ = nullptr;
	}
	else if (!toTermination->left_ && !toTermination->right_)
	{
		if (parent->left_ == toTermination)
		{
			parent->left_ = nullptr;
		}
		if (parent->right_ == toTermination)
		{
			parent->right_ = nullptr;
		}
	}
	else if (!parent && (!toTermination->left_ || !toTermination->right_))
	{
		if (toTermination->left_)
		{
			root_ = toTermination->left_;
			toTermination->left_->p_ = nullptr;
		}
		else
		{
			root_ = toTermination->right_;
			toTermination->right_->p_ = nullptr;
		}
	}
	else if (!toTermination->left_ || !toTermination->right_)
	{
		if (toTermination->left_)
		{
			if (parent->left_ == toTermination)
			{
				parent->left_ = toTermination->left_;
			}
			else
			{
				parent->right_ = toTermination->left_;
			}
			toTermination->left_->p_ = parent;
		}
		else
		{
			if (parent->left_ == toTermination)
			{
				parent->left_ = toTermination->right_;
			}
			else
			{
				parent->right_ = toTermination->right_;
			}
			toTermination->right_->p_ = parent;
		}
	}
	else
	{
		Node* successor = getNext(toTermination);
		toTermination->key_ = successor->key_;
		if (successor->p_->left_ == successor)
		{
			successor->p_->left_ = successor->right_;
			if (successor->right_)
			{
				successor->right_->p_ = successor->p_;
			}
		}
		else
		{
			successor->p_->right_ = successor->right_;
			if (successor->right_)
			{
				successor->right_->p_ = successor->p_;
			}
		}
		toTermination = successor;
	}
	delete toTermination;
	return true;
}
template < class T >
void bst::BinarySearchTree< T >::output(std::ostream& out) const
{
	output(out, root_);
}
template < class T >
int bst::BinarySearchTree< T >::getNumberOfNodes() const
{
	return getNumberOfNodes(root_);
}
template < class T >
int bst::BinarySearchTree< T >::getHeight() const
{
	return root_ ? getHeight(root_) - 1 : 0;
}
template < class T >
void bst::BinarySearchTree< T >::inorderWalkIterative(std::ostream& out) const
{
	Node* current = getMin(root_);
	while (current)
	{
		out << current->key_ << ' ';
		current = getNext(current);
	}
}
template < class T >
void bst::BinarySearchTree< T >::inorderWalk(std::ostream& out) const
{
	inorderWalk(out, root_);
}
template < class T >
void bst::BinarySearchTree< T >::walkByLevels(std::ostream& out) const
{
	if (!root_)
	{
		return;
	}

	qar::QueueArray<Node*> q(static_cast< int >(std::pow(2, getHeight())));
	q.enQueue(root_);
	Node* tmp = nullptr;
	while (!q.isEmpty())
	{
		tmp = q.deQueue();
		out << tmp->key_ << ' ';

		if (tmp->left_)
		{
			q.enQueue(tmp->left_);
		}
		if (tmp->right_)
		{
			q.enQueue(tmp->right_);
		}
	}
}
template < class T >
bool bst::BinarySearchTree< T >::isSimilar(const BinarySearchTree& other) const
{
	Node* current = getMin(root_);
	Node* otherCurrent = getMin(other.root_);
	while (current && otherCurrent && (current->key_ == otherCurrent->key_))
	{
		current = getNext(current);
		otherCurrent = getNext(otherCurrent);
	}
	return !current && !otherCurrent;
}
template < class T >
bool bst::BinarySearchTree< T >::isIdenticalKey(const BinarySearchTree& other) const
{
	Node* current = getMin(root_);
	Node* otherCurrent = getMin(other.root_);
	while (current && otherCurrent)
	{
		if (current->key_ == otherCurrent->key_)
		{
			return true;
		}
		else if (current->key_ < otherCurrent->key_)
		{
			current = getNext(current);
		}
		else
		{
			otherCurrent = getNext(otherCurrent);
		}
	}
	return false;
}
template < class T >
std::string bst::BinarySearchTree< T >::getPath(const T& key) const
{
	Node* current = root_;
	std::string dest = "";
	while (current && (current->key_ != key))
	{
		if (current->key_ < key)
		{
			dest += '1';
			current = current->right_;
		}
		else
		{
			dest += '0';
			current = current->left_;
		}
	}
	return (current ? dest : dest = "");
}

template < class T >
typename bst::BinarySearchTree< T >::Node* bst::BinarySearchTree< T >::searchNodeIterative(const T& key) const
{
	Node* current = root_;
	while (current && (current->key_ != key))
	{
		if (current->key_ < key)
		{
			current = current->right_;
		}
		else
		{
			current = current->left_;
		}
	}
	return current;
}
template < class T >
void bst::BinarySearchTree< T >::output(std::ostream& out, Node* const node) const
{
	if (node)
	{
		out << '(' << node->key_;
		output(out, node->left_);
		output(out, node->right_);
		out << ')';
	}
}
template < class T >
int bst::BinarySearchTree< T >::getNumberOfNodes(Node* const node) const
{
	if (!node)
	{
		return 0;
	}
	return (1 + getNumberOfNodes(node->left_) +
		getNumberOfNodes(node->right_));
}
template < class T >
int bst::BinarySearchTree< T >::getHeight(Node* const node) const
{
	int counter = 0;
	if (node)
	{
		int otherCounter = 0;
		counter = getHeight(node->left_);
		otherCounter = getHeight(node->right_);
		if (counter < otherCounter)
		{
			counter = otherCounter;
		}
		++counter;
	}
	return counter;
}
template < class T >
void bst::BinarySearchTree< T >::inorderWalk(std::ostream& out, Node* const node) const
{
	if (node)
	{
		inorderWalk(out, node->left_);
		out << node->key_ << ' ';
		inorderWalk(out, node->right_);
	}
}

template < class T >
typename bst::BinarySearchTree< T >::Node* bst::BinarySearchTree< T >::getMin(Node* const node)
{
	Node* current = nullptr;
	if (node)
	{
		current = node;
		while (current->left_)
		{
			current = current->left_;
		}
	}
	return current;
}
template < class T >
typename bst::BinarySearchTree< T >::Node* bst::BinarySearchTree< T >::getNext(Node* const node)
{
	if (node->right_)
	{
		return getMin(node->right_);
	}
	Node* current = node;
	Node* curParent = node->p_;
	while (curParent && (current == curParent->right_))
	{
		current = curParent;
		curParent = curParent->p_;
	}
	return curParent;
}

#endif
