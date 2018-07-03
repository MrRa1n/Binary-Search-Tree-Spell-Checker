#include "bst.h"

// Creates an empty binary tree
BinarySearchTree::BinarySearchTree()
{
	root = new Node;
}

// Creates a binary tree with an initial value to store
BinarySearchTree::BinarySearchTree(std::string word)
{
	root = new Node;
	root->data = word;
	root->left = nullptr;
	root->right = nullptr;
}

// Helper function for copying from an existing tree
void CopyExistingTree(Node*& new_tree, Node*& existing_tree)
{
	if (existing_tree == nullptr)
	{
		new_tree = nullptr;
	}
	else
	{
		// Allocate memory for new_tree
		new_tree = new Node;
		// Set data of new_tree to existing_tree
		new_tree->data = existing_tree->data;
		// Call method recursively on left and right side
		CopyExistingTree(new_tree->left, existing_tree->left);
		CopyExistingTree(new_tree->right, existing_tree->right);
	}
}

// Creates a binary tree by copying an existing tree
BinarySearchTree::BinarySearchTree(const BinarySearchTree& rhs)
{
	BinarySearchTree& new_rhs = const_cast<BinarySearchTree&>(rhs);
	// If passed tree root is nullptr, set current tree root to nullptr
	if (rhs.root == nullptr)
	{
		root = nullptr;
	}
	// Call copy method on tree root node
	else CopyExistingTree(this->root, new_rhs.root);
}

void destructorhelper(Node*& node)
{
	if (node != nullptr)
	{
		destructorhelper(node->left);
		destructorhelper(node->right);
		delete node;
	}
}

// Destroys (cleans up) the tree
BinarySearchTree::~BinarySearchTree()
{
    destructorhelper(root);
}

// Helper function for inserting word into tree
void inserthelper(Node** node, const std::string word)
{
	// If word is less than node data
	if (word < (*node)->data)
	{
		// If left node is not nullptr, call inserthelper with left node
		if ((*node)->left != nullptr)
		{
			inserthelper(&(*node)->left, word);
		}
		else
		{
			// Create new left node
			(*node)->left = new Node;
			(*node)->left->data = word;
			(*node)->left->left = nullptr;
			(*node)->left->right = nullptr;
		}
	}
	// If word is greater than node data
	else if (word > (*node)->data)
	{
		// If right node is not nullptr, call inserthelper with right node
		if ((*node)->right != nullptr)
		{
			inserthelper(&(*node)->right, word);
		}
		else
		{
			// Create new right node
			(*node)->right = new Node;
			(*node)->right->data = word;
			(*node)->right->left = nullptr;
			(*node)->right->right = nullptr;
		}
	}
}
// Adds a word to the tree
void BinarySearchTree::insert(std::string word)
{
	// If node is not nullptr, pass word to helper method
	if (root != nullptr)
	{
		inserthelper(&root, word);
	}
	// Allocate memory for root and assign word
	else
	{
		root = new Node;
		root->data = word;
		root->left = nullptr;
		root->right = nullptr;
	}
}

void removehelper(Node*& node, const std::string& word)
{
	if (node == nullptr)
		return;
	// If word is greater than current node, go right
	if (word > node->data)
	{
		removehelper(node->right, word);
	}
	// If word is less than current node, go left
	else if (word < node->data)
	{
		removehelper(node->left, word);
	}
	// If word is equal to current node
	else
	{
		// If there are two child nodes
		if (node->left != nullptr && node->right != nullptr)
		{
			Node* min_node = node->right;
			// Find minimum node in right sub-tree
			while (min_node->left != nullptr)
				min_node = min_node->left;
			// Replace data of node being deleted with minimum of found node
			node->data = min_node->data;
			// Delete duplicate node
			removehelper(node->right, min_node->data);
		}
		// Make copy of right node and delete current
		else if (node->left == nullptr)
		{
			Node* temp = node->right;
			delete node;
			node = temp;
			return;
		}
		// Make copy of left node and delete current
		else if (node->right == nullptr)
		{
			Node* temp = node->left;
			delete node;
			node = temp;
			return;
		}
		// If there are no child nodes, delete current
		else
		{
			delete node;
			node = nullptr;
			return;
		}
	}
}

// Removes a word from the tree
void BinarySearchTree::remove(std::string word)
{
	if (root != nullptr)
	{
		// If word exists call removehelper, otherwise ignore
		if (exists(word))
		{
			removehelper(root, word);
		}
		else return;
	}
}

// Checks if a word is in the tree
bool BinarySearchTree::exists(std::string word) const
{
	// Copy root to temp node
	Node *temp = root;
	while (temp != nullptr)
	{
		// Compare temp->data with passed word
		if (temp->data == word)
		{
			return true;
		}
		else if (temp->data > word)
		{
			temp = temp->left;
		}
		else if (temp->data < word)
		{
			temp = temp->right;
		}
	}
    return false;
}

// Helper method for inorder traverse
void inorderhelper(Node* node, std::string& value)
{
	if (node != nullptr)
	{
		if (node->left != nullptr)
		{
			inorderhelper(node->left, value);
		}
		if (node->data != "")
		{
			value += node->data + " ";
		}
		if (node->right != nullptr)
		{
			inorderhelper(node->right, value);
		}
	}
}

// Helper method for preorder traverse
void preorderhelper(Node* node, std::string& value)
{
	if (node != nullptr)
	{
		if (node->data != "")
		{
			value += node->data + " ";
		}
		if (node->left != nullptr)
		{
			preorderhelper(node->left, value);
		}
		if (node->right != nullptr)
		{
			preorderhelper(node->right, value);
		}
	}
}

// Helper method for postorder traverse
void postorderhelper(Node* node, std::string& value)
{
	if (node != nullptr)
	{
		if (node->left != nullptr)
		{
			postorderhelper(node->left, value);
		}
		if (node->right != nullptr)
		{
			postorderhelper(node->right, value);
		}
		if (node->data != "")
		{
			value += node->data + " ";
		}
	}
}

// Prints the tree to standard out in numerical order
std::string BinarySearchTree::inorder() const
{
	std::string value = "";
	inorderhelper(root, value);
	if (value != "")
	{
		// Remove space at end
		value.erase(prev(value.end()));
		return value;
	}
	else return std::string("");
}

// Prints the tree in pre-order
std::string BinarySearchTree::preorder() const
{
    std::string value = "";
    preorderhelper(root, value);

	if (value != "")
	{
		// Remove space at end
		value.erase(prev(value.end()));
		return value;
	}
	else return std::string("");
}

// Prints the tree in post-order
std::string BinarySearchTree::postorder() const
{
    std::string value = "";
    postorderhelper(root, value);

	if (value != "")
	{
		// Remove space at end
		value.erase(prev(value.end()));
		return value;
	}
	else return std::string("");
}

bool equality(const Node* lhs, const Node* rhs)
{
	// Check nodes are not nullptr
	if (lhs != nullptr && rhs != nullptr)
	{
		// Check if left and right node contain same data
		if (lhs->data.compare(rhs->data) == 0)
		{
			// Call equality on left and right branches
			equality(lhs->left, rhs->left);
			equality(lhs->right, rhs->right);
			return true;
		}
		else return false;
	}
	else return false;
}

// Checks if two trees are equal
bool BinarySearchTree::operator==(const BinarySearchTree& other) const
{
	return (equality(this->root, other.root));
}

// Checks if two trees are not equal
bool BinarySearchTree::operator!=(const BinarySearchTree& other) const
{
    return (!equality(this->root, other.root));
}


// Reads in words from an input stream into the tree
std::istream& operator>>(std::istream& in, BinarySearchTree& tree)
{
	std::string input;
	// While there is an input, insert value into tree
	while (in)
	{
		in >> input;
		tree.insert(input);
	}
    return in;
}


// Writes the words, in-order, to an output stream
std::ostream& operator<<(std::ostream& out, const BinarySearchTree& tree)
{
	// Output tree using inorder method
	out << tree.inorder();
    return out;
}
