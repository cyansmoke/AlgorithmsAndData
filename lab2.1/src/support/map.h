#pragma once

#include "List.h"

enum Color {
    BLACK, RED,
};

template<typename K, typename V1, class V2>
class Node {
private:
    Color color;
    Node<K, V1, V2> *left, *right, *parent;
    K key;
    V1 value1;
    V2 value2;
public:
    Node() : color(RED), left(nullptr), right(nullptr), parent(nullptr) {}

    Node(K key, V1 value1) : color(RED), left(nullptr), right(nullptr), parent(nullptr), key(key),
                             value1(value1) {}

    Node(K key, V1 value1, V2 value2) : color(RED), left(nullptr), right(nullptr), parent(nullptr),
                                        key(key), value1(value1), value2(value2) {}

    bool isLeft() { return this == parent->getLeft(); }

    Node<K, V1, V2> *sibling() {
        if (parent == nullptr)
            return nullptr;

        if (isLeft())
            return parent->right;

        return parent->left;
    }

    bool hasRedChild() {
        return (left != nullptr && left->getColor() == RED) || (right != nullptr && right->getColor() == RED);
    }

    void setColor(Color color) {
        this->color = color;
    }

    Color getColor() {
        if (this == nullptr)
            return BLACK;
        return color;
    }

    void setLeft(Node *ptr) {
        left = ptr;
    }

    Node *getLeft() {
        return left;
    }

    void setRight(Node *ptr) {
        right = ptr;
    }

    Node *getRight() {
        return right;
    }

    void setParent(Node *parent) {
        this->parent = parent;
    }

    Node *getParent() {
        return parent;
    }

    void setKey(K key) {
        this->key = key;
    }

    K getKey() {
        return key;
    }

    void setValue1(V1 value) {
        this->value1 = value;
    }

    V1 getValue1() {
        return value1;
    }

    void setValue2(V2 value) {
        value2.insertListInBack(value);
    }

    V2 getValue2() {
        return value2;
    }
};

#pragma endregion

#pragma region CLASS_MAP

template<typename K, typename V1, class V2>
class map {
private:
    Node<K, V1, V2> *root;

    void fixInsertion(Node<K, V1, V2> *&node) {
        if (root == node) {
            node->setColor(BLACK);
            return;
        }
        Color c;
        Node<K, V1, V2> *parent = nullptr, *grandparent = nullptr, *uncle = nullptr;
        while (node != root && node->getColor() == RED && node->getParent()->getColor() == RED) {
            parent = node->getParent();
            grandparent = parent->getParent();
            if (parent == grandparent->getLeft()) {
                uncle = grandparent->getRight();
                if (uncle->getColor() == RED) {
                    parent->setColor(BLACK);
                    grandparent->setColor(RED);
                    uncle->setColor(BLACK);
                    node = grandparent;
                } else {
                    if (node == parent->getRight()) {
                        leftRotate(parent);
                        node = parent;
                        parent = node->getParent();
                    }
                    rightRotate(grandparent);
                    c = parent->getColor();
                    parent->setColor(grandparent->getColor());
                    grandparent->setColor(c);
                    node = parent;
                }
            } else {
                uncle = grandparent->getLeft();
                if (uncle->getColor() == RED) {
                    parent->setColor(BLACK);
                    grandparent->setColor(RED);
                    uncle->setColor(BLACK);
                    node = grandparent;
                } else {
                    if (node == parent->getLeft()) {
                        rightRotate(parent);
                        node = parent;
                        parent = node->getParent();
                    }
                    leftRotate(grandparent);
                    c = parent->getColor();
                    parent->setColor(grandparent->getColor());
                    grandparent->setColor(c);
                    node = parent;
                }
            }
        }
        root->setColor(BLACK);
    }

    Node<K, V1, V2> *minValueNode(Node<K, V1, V2> *node) {

        Node<K, V1, V2> *ptr = node;

        while (ptr->getLeft() != nullptr) {
            ptr = ptr->getLeft();
        }

        return ptr;
    }

    void leftRotate(Node<K, V1, V2> *node) {
        Node<K, V1, V2> *right_child = node->getRight();
        node->setRight(right_child->getLeft());

        if (node->getRight() != nullptr)
            node->getRight()->setParent(node);

        right_child->setParent(node->getParent());

        if (node->getParent() == nullptr)
            root = right_child;
        else if (node == node->getParent()->getLeft())
            node->getParent()->setLeft(right_child);
        else
            node->getParent()->setRight(right_child);

        right_child->setLeft(node);
        node->setParent(right_child);
    }

    void rightRotate(Node<K, V1, V2> *node) {
        Node<K, V1, V2> *left_child = node->getLeft();
        node->setLeft(left_child->getRight());

        if (node->getLeft() != nullptr) {
            node->getLeft()->setParent(node);
        }

        left_child->setParent(node->getParent());

        if (node->getParent() == nullptr) {
            root = left_child;
        } else if (node == node->getParent()->getLeft()) {
            node->getParent()->setLeft(left_child);
        } else {
            node->getParent()->setRight(left_child);
        }

        left_child->setRight(node);
        node->setParent(left_child);
    }

    void delSubTree(Node<K, V1, V2> *node) {
        while (node != nullptr) {
            delSubTree(node->getLeft());
            delSubTree(node->getRight());
            delete node;
            node = nullptr;
        }
        root = nullptr;
    }

    void setKeys(List<K> &ls, Node<K, V1, V2> *node) {
        while (node) {
            setKeys(ls, node->getLeft());
            ls.insertLast(node->getKey());
            setKeys(ls, node->getRight());
            return;
        }
    }

    void setValues1(List<V1> &ls, Node<K, V1, V2> *node) {
        while (node) {
            setValues1(ls, node->getLeft());
            ls.insertLast(node->getValue1());
            setValues1(ls, node->getRight());
            return;
        }
    }

    void setValues2(List<V2> &ls, Node<K, V1, V2> *node) {
        while (node) {
            setValues2(ls, node->getLeft());
            ls.insertLast(node->getValue2());
            setValues2(ls, node->getRight());
            return;
        }
    }

    Node<K, V1, V2> *replace(Node<K, V1, V2> *x) {
        if (x->getLeft() != nullptr && x->getRight() != nullptr)
            return minValueNode(x->getRight());

        if (x->getLeft() == nullptr && x->getRight() == nullptr)
            return nullptr;

        if (x->getLeft() != nullptr)
            return x->getLeft();
        else
            return x->getRight();
    }

    // returns pointer to element with required key
    Node<K, V1, V2> *search(K key) {
        Node<K, V1, V2> *temp = root;
        while (temp != nullptr && key != temp->getKey()) {
            if (key < temp->getKey()) {
                temp = temp->getLeft();
            } else {
                temp = temp->getRight();
            }
        }
        return temp;
    }

    void swapValues(Node<K, V1, V2> *u, Node<K, V1, V2> *v) {
        K key = u->getKey();
        u->setKey(v->getKey());
        v->setKey(key);
        V1 value1 = u->getValue1();
        u->setValue1(v->getValue1());
        v->setValue1(value1);
        V2 value2 = u->getValue2();
        u->setValue2(v->getValue2());
        v->setValue2(value2);
    }

    void removeNode(Node<K, V1, V2> *v) {
        Node<K, V1, V2> *u = replace(v);

        bool uvBlack = ((u == nullptr || u->getColor() == BLACK) && (v->getColor() == BLACK));
        Node<K, V1, V2> *parent = v->getParent();

        if (u == nullptr) {
            if (v == root) {
                root = nullptr;
            } else {
                if (uvBlack) {
                    fixDoubleBlack(v);
                } else {
                    if (v->sibling() != nullptr)
                        v->sibling()->setColor(RED);
                }

                if (v->isLeft()) {
                    parent->setLeft(nullptr);
                } else {
                    parent->setRight(nullptr);
                }
            }
            delete v;
            return;
        }
        if (v->getLeft() == nullptr || v->getRight() == nullptr) {
            if (v == root) {
                v->setKey(u->getKey());
                v->setLeft(nullptr);
                v->setRight(nullptr);
                delete u;
            } else {
                if (v->isLeft()) {
                    parent->setLeft(u);
                } else {
                    parent->setRight(u);
                }
                delete v;
                u->setParent(parent);
                if (uvBlack) {
                    fixDoubleBlack(u);
                } else {
                    u->setColor(BLACK);
                }
            }
            return;
        }
        swapValues(u, v);
        removeNode(u);
    }

    void fixDoubleBlack(Node<K, V1, V2> *x) {
        if (x == root) return;

        Node<K, V1, V2> *sibling = x->sibling(), *parent = x->getParent();
        if (sibling == nullptr) {
            fixDoubleBlack(parent);
        } else {
            if (sibling->getColor() == RED) {
                parent->setColor(RED);
                sibling->setColor(BLACK);
                if (sibling->isLeft()) {
                    rightRotate(parent);
                } else {
                    leftRotate(parent);
                }
                fixDoubleBlack(x);
            } else {
                if (sibling->hasRedChild()) {
                    if (sibling->getLeft() != nullptr && sibling->getLeft()->getColor() == RED) {
                        if (sibling->isLeft()) {
                            sibling->getLeft()->setColor(sibling->getColor());
                            sibling->setColor(parent->getColor());
                            rightRotate(parent);
                        } else {
                            sibling->getLeft()->setColor(parent->getColor());
                            rightRotate(sibling);
                            leftRotate(parent);
                        }
                    } else {
                        if (sibling->isLeft()) {
                            sibling->getRight()->setColor(parent->getColor());
                            leftRotate(sibling);
                            rightRotate(parent);
                        } else {
                            sibling->getRight()->setColor(sibling->getColor());
                            sibling->setColor(parent->getColor());
                            leftRotate(parent);
                        }
                    }
                    parent->setColor(BLACK);
                } else {
                    sibling->setColor(RED);
                    if (parent->getColor() == BLACK)
                        fixDoubleBlack(parent);
                    else
                        parent->setColor(BLACK);
                }
            }
        }
    }

public:
    map() : root(nullptr) {}

    ~map() {
        delSubTree(root);
    }

    void insert(K key, V1 value1, V2 value2) {
        auto *temp = new Node<K, V1, V2>(key, value1, value2);
        if (!root) {
            root = temp;
        } else {
            Node<K, V1, V2> *p = root;
            Node<K, V1, V2> *q = nullptr;
            while (p != nullptr) {
                q = p;
                if (p->getKey() < temp->getKey()) {
                    p = p->getRight();
                } else if (p->getKey() == temp->getKey()) {
                    throw "This element is already in the map";
                } else {
                    p = p->getLeft();
                }
            }
            temp->setParent(q);
            if (q->getKey() <= temp->getKey()) {
                q->setRight(temp);
            } else {
                q->setLeft(temp);
            }
        }
        fixInsertion(temp);
    }

    void insert(K key, V1 value1, V1 value2) {
        auto *temp = new Node<K, V1, V2>(key, value1);
        if (!root) {
            root = temp;
        } else {
            Node<K, V1, V2> *p = root;
            Node<K, V1, V2> *q = nullptr;
            while (p != nullptr) {
                q = p;
                if (p->getKey() < temp->getKey()) {
                    p = p->getRight();
                } else if (p->getKey() == temp->getKey()) {
                    delete temp;
                    p->setValue1(p->getValue1() + value2);
                    return;
                } else {
                    p = p->getLeft();
                }
            }
            temp->setParent(q);
            if (q->getKey() <= temp->getKey()) {
                q->setRight(temp);
            } else {
                q->setLeft(temp);
            }
        }
        fixInsertion(temp);
    }

    bool code_in_dict(V2 code) {
        bool is_found = false;
        return second_code_in_map(root, code, is_found);
    }

    V1 find_value1(K key) {
        if (!root)
            throw invalid_argument("Map is empty");
        Node<K, V1, V2> *temp = root;
        while (temp && temp->getKey() != key) {
            if (temp->getKey() < key)
                temp = temp->getRight();
            else
                temp = temp->getLeft();
        }
        if (!temp) throw "This element isn't in the map";
        return temp->getValue1();
    }

    V2 find_value2(K key) {
        if (!root) throw "Map is empty";
        Node<K, V1, V2> *temp = root;
        while (temp && temp->getKey() != key) {
            if (temp->getKey() < key)
                temp = temp->getRight();
            else
                temp = temp->getLeft();
        }
        if (!temp) throw "This element isn't in the map";
        return temp->getValue2();
    }

    void set_value2(K key, V2 &value) {
        Node<K, V1, V2> *temp = search(key);
        temp->setValue2(value);
    }

    K find_key(V2 code) {
        K key = '\0';
        bool is_found = false;
        second_find_key(root, code, key, is_found);
        return key;
    }

    void second_find_key(Node<K, V1, V2> *node, V2 code, K &key, bool &is_found) {
        if (node) {
            if (node->getValue2().compare(code)) {
                key = node->getKey();
                is_found = true;
                return;
            } else {
                second_find_key(node->getLeft(), code, key, is_found);
                if (is_found)
                    return;
                second_find_key(node->getRight(), code, key, is_found);
            }
        }
    }

    bool second_code_in_map(Node<K, V1, V2> *node, V2 code, bool &is_found) {
        if (node) {
            if (node->getValue2().compare(code)) {
                is_found = true;
                return true;
            } else {
                second_code_in_map(node->getLeft(), code, is_found);
                if (is_found)
                    return true;
                second_code_in_map(node->getRight(), code, is_found);
                return is_found;
            }
        }
    }
};