#include "Tree.h"
#include "Node.cpp"

/**
 * wrapper of height
 * @param node
 * @return
 */
unsigned char height(Node *node) {
    return node ? node->get_height() : 0;
}

/**
 * @param node
 * @return difference between left and right children of node
 */
int balance_factor(Node *node) {
    return height(node->get_right()) - height(node->get_left());
}

/**
 * check height between left and right children of
 * @param node
 * set bigger to current
 */
void fix_height(Node *node) {
    unsigned char hl = height(node->get_left());
    unsigned char hr = height(node->get_right());
    node->set_height((hl > hr ? hl : hr) + 1);
}

/**
 * rotate tree to right from
 * @param node
 * @return new root
 */
Node *rotate_right(Node *node) {
    Node *left = node->get_left();
    node->set_left(left->get_right());
    left->set_right(node);
    fix_height(node);
    fix_height(left);
    return left;
}

/**
 * rotate tree to left from
 * @param node
 * @return new root
 */
Node *rotate_left(Node *node) {
    Node *right = node->get_right();
    node->set_right(right->get_left());
    right->set_left(node);
    fix_height(node);
    fix_height(right);
    return right;
}

/**
 * balance tree from
 * @param node
 * @return new root
 */
Node *balance(Node *node) {
    fix_height(node);
    if (balance_factor(node) == 2) {
        if (balance_factor(node->get_right()) < 0)
            node->set_right(rotate_right(node->get_right()));
        return rotate_left(node);
    }
    if (balance_factor(node) == -2) {
        if (balance_factor(node->get_left()) > 0)
            node->set_left(rotate_left(node->get_left()));
        return rotate_right(node);
    }
    return node;
}

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
    return balance(node);
}

Node *find_min(Node *node) {
    return node->get_left() ? find_min(node->get_left()) : node;
}

Node *remove_min(Node *node) {
    if (node->get_left() == NULL)
        return node->get_right();
    node->set_left(remove_min(node->get_left()));
    return balance(node);
}

Node *remove(Node *node, int key) {
    if (!node) return NULL;
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
        return balance(min);
    }
    return balance(node);
}

/**
 * fun to search
 * @param node
 * with
 * @param key
 * @return true if founded, false if not
 */
bool find(Node *node, int key) {
    if (node == NULL) {
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
    if (root == NULL) return;
    deleteTree(root->get_left());
    deleteTree(root->get_right());
    delete (root);
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
    this->root = insert(this->root, key);
}

void Tree::remove_node(int key) {
    this->root = remove(this->root, key);
}

using namespace std;

struct Trunk {
    Trunk *prev;
    string str;

    Trunk(Trunk *prev, string str) {
        this->prev = prev;
        this->str = str;
    }
};

void showTrunks(Trunk *p) {
    if (p == NULL) return;

    showTrunks(p->prev);

    cout << p->str;
}

void printTree(Node *root, Trunk *prev, bool isLeft) {
    if (root == NULL) return;

    string prev_str = "    ";
    auto *trunk = new Trunk(prev, prev_str);

    printTree(root->get_left(), trunk, true);

    if (!prev) {
        trunk->str = "--";
    } else if (isLeft) {
        trunk->str = ".--";
        prev_str = "   |";
    } else {
        trunk->str = "`--";
        prev->str = prev_str;
    }

    showTrunks(trunk);
    cout << root->get_key() << endl;

    if (prev) {
        prev->str = prev_str;
    }

    trunk->str = "   |";

    printTree(root->get_right(), trunk, false);
}

void Tree::print() {
    printTree(this->root, NULL, false);
}