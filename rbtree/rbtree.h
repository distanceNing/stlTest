#ifndef _YNSTL_RBTREE_H_
#define _YNSTL_RBTREE_H_

#include <string>
//template <typename KEY,typename VALUE>
//<KEY, VALUE>
#define VALUE std::string
#define KEY int

typedef struct 
{

	typedef  RbTreeNode tree_node;
	typedef VALUE value_type;
	typedef KEY key_type;

	tree_node* left_child;
	tree_node* right_child;
	tree_node* parent;
	unsigned char color;
	key_type key;
	value_type value;
}RbTreeNode;


//template <typename KEY, typename VALUE>
//<KEY, VALUE>
class RbTree
{
protected:
	using rbtree_node = RbTreeNode;

public:
	static const unsigned char kBlack = 0;
	static const unsigned char kRed = 1;

	RbTree(): root_(new rbtree_node){
		root_->color = kBlack;
		root_->left_child = NULL;
		root_->right_child = NULL;
		root_->parent = NULL;
	}

	void insert(KEY key, VALUE value)
	{
		rbtree_node* node = makeNode(key, value);
		rbtree_node* temp = root_;
		rbtree_node* parent = temp->parent;
		while (temp != NULL)
		{
			parent = temp;
			if (key < temp->key) {
				temp = temp->right_child;
			}
			else if (key > temp->key)
			{
				temp = temp->left_child;
			}
			else {
				return;
			}
		}
		node->parent = parent;
		if (parent->key > key){
			parent->left_child = node;
		}
		else{
			parent->right_child = node;
		}
		node->color = kRed;
	}


	~RbTree() {}

private:
	inline rbtree_node* makeNode(KEY key, VALUE value)
	{
		rbtree_node* node=new rbtree_node;
		node->key = key;
		node->value = value;
		node->parent = NULL;
		node->left_child = NULL;
		node->right_child = NULL;
		return node;
	}

	void leftRotate(rbtree_node* node)
	{

	}

	void rightRotate(rbtree_node* node)
	{}


private:
	rbtree_node* root_;
};






#endif // !_YNSTL_RBTREE_H_

