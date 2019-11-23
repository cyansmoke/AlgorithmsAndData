#include "Tree.h"

/**
 * insert new node from root
 * @param node
 * with
 * @param key
 * @return new root
 */
Node *insert(Node *node, int key) {
    if (!node) return new Node(key);
    if (key < node->get_key()) {
        node->set_left(insert(node->get_left(), key));
    } else {
        node->set_right(insert(node->get_right(), key));
    }
    return node;
}

Node *find_min(Node *node) {
    return node->get_left() ? find_min(node->get_left()) : node;
}

Node *remove_min(Node *node) {
    if (node->get_left() == nullptr)
        return node->get_right();
    node->set_left(remove_min(node->get_left()));
    return node;
}

Node *remove(Node *node, int key) {
    if (!node) return nullptr;
    if (key < node->get_key())
        node->set_left(remove(node->get_left(), key));
    else if (key > node->get_key())
        node->set_right(remove(node->get_right(), key));
    else {
        Node *left = node->get_left();
        Node *right = node->get_right();
        delete (node);
        if (!right) return left;
        Node *min = find_min(right);
        min->set_right(remove_min(right));
        min->set_left(left);
        return min;
    }
    return node;
}

/**
 * fun to search
 * @param node
 * with
 * @param key
 * @return true if founded, false if not
 */
bool find(Node *node, int key) {
    if (node == nullptr) {
        return false;
    } else if (key == node->get_key()) {
        return true;
    } else if (key < node->get_key()) {
        return find(node->get_left(), key);
    } else if (key > node->get_key()) {
        return find(node->get_right(), key);
    }
    return false;
}

/**
 * delete tree from
 * @param root
 */
void deleteTree(Node *root) {
    if (root == nullptr) return;
    deleteTree(root->get_left());
    deleteTree(root->get_right());
    delete (root);
}

void printBT(const string& prefix, Node* node, bool isLeft, bool isRoot) {
    if( node != nullptr ) {

        if(!isRoot) {
            cout << prefix;
            cout << (isLeft ? "|--L " : "`--R ");
        } else {
            cout << "   ";
        }
        cout << node->get_key() << endl;

        printBT( prefix + (isLeft ? "|   " : "    "), node->get_left(), true, false);
        printBT( prefix + (isLeft ? "│   " : "    "), node->get_right(), false, false);
    }
}

Tree::Tree(int root_data) {
    this->root = new Node(root_data);;
}

Tree::~Tree() {
    deleteTree(this->root);
}

bool Tree::contains(int key) {
    return find(root, key);
}

void Tree::insert_node(int key) {
    insert(this->root, key);
}

void Tree::remove_node(int key) {
    this->root = remove(this->root, key);
}

void Tree::print() {
    printBT("", root, false, true);
}

TreeDftIterator Tree::create_dft_iterator() {
    return TreeDftIterator(root);
}

TreeBftIterator Tree::create_bft_iterator() {
    return TreeBftIterator(root);
}