#ifndef LAB3_NODE_H
#define LAB3_NODE_H

class Node {
private:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
public:
    /**
     * constructor
     */
    Node(int data);

    /**
     * destructor
     */
    ~Node();

    /**
     * return data of element
     */
    int get_data();

    /**
    * set left element
    */
    void set_left(Node *left);

    /**
    * set right element
    */
    void set_right(Node *right);

    /**
    * set data of element
    */
    void set_data(int data);

    /**
     * @return pointer to left element
     */
    Node *get_left();

    /**
     * @return pointer to right element
     */
    Node *get_right();
};


#endif //LAB3_NODE_H
