#include<iostream>
#include<experimental/coroutine>
//#include<experimental/generator>

using namespace std;

template<typename T> struct BinaryTree;
template<typename T>
struct Node{
    T value = T();
    Node<T> *left{nullptr};
    Node<T> *right{nullptr};
    Node<T> *parent{nullptr};

    BinaryTree<T>*  tree{nullptr};

    Node(T value) : value(value){}
    Node(T value, Node<T> *leftChild, Node<T> *rightChild)
        : value(value), left(leftChild), right(rightChild){
            this->left->tree = this->right->tree = tree;
            this->left->parent = this->right->parent = parent;
        }
    
    void set_tree(BinaryTree<T>* t){
        tree = t;
        if(left) left->set_tree(t);
        if(right) right->set_tree(t);
    }

    ~Node(){
        if(left) delete left;
        if(right) delete right;
    }
};

template<typename T> 
struct BinaryTree{

    Node<T>* root{nullptr};
    BinaryTree(Node<T> *root): root(root){
        root->set_tree(this);
    }
    ~BinaryTree(){
        if(root)delete root;
    }

    template<typename U>
    struct PreorderIterator{
        Node<U> * current;
        PreorderIterator(Node<U>* current): current(current){}
        bool operator!=(const PreorderIterator<U>& other){
            return current != other.current;
        }

        PreorderIterator<U>& operator++(){
            if(current->right){
                current = current->right;
                while(current->left){
                    current = current->left;
                }
            }else{
                Node<T>* p = current->parent;
                while(p && current==p->right){
                    current = p;
                    p = p->parent;
                }
                current = p;
            }
            return *this;
        }


        Node<U>& operator*(){
            return *current;
        }
    };
    typedef PreorderIterator<T> iterator;
    iterator begin(){
        Node<T>* n = root;
        if(n){
            while(n->left) n = n->left;
            return iterator{n};
        }
    }
    iterator end(){
        return iterator{nullptr};
    }
};

int main(){
    BinaryTree<string> familyTree {
        new Node<string>{"me", 
                        new Node<string> {"mother",
                            new Node<string>{"Mother's mother"},
                            new Node<string>{"Mother's father"}
                        },
        new Node<string>{"father"}}
    };

    for(auto it = familyTree.begin(); it!= familyTree.end(); ++it){
        cout << (*it).value << endl;
    }

    return 0;
}