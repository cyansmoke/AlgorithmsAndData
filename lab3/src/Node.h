#ifndef LAB3_NODE_H
#define LAB3_NODE_H

class Node {
private:
    Node *left = 0;
    Node *right = 0;
    int height = 1;
    int key = 0;
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
    int get_key();

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
    void set_key(int key);

    /**
     * @return pointer to left element
     */
    Node *get_left();

    /**
     * @return pointer to right element
     */
    Node *get_right();

    /**
     * @return height of element
     */
    int get_height();

    /**
     * set_height of element
     */
    void set_height(int);
};


#endif //LAB3_NODE_H
