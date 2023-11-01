#include <iostream>
#include <queue>

namespace avl {
    struct node {
        int info;
        uint height;
        node *left, *right, *parent;

        explicit node(int i, uint h = 1, node* l = nullptr, node* r = nullptr, node* p = nullptr)
                : info(i), height(h), left(l), right(r), parent(p) {}
    };

    int calcBalance(node *x) {
        if (x == nullptr)
            return 0;

        uint lHeight = x->left != nullptr ? x->left->height : 0;
        uint rHeight = x->right != nullptr ? x->right->height : 0;
        return int(lHeight - rHeight);
    }

    void updateHeight(node *x) {
        if (x == nullptr)
            return;

        uint lHeight = x->left != nullptr ? x->left->height : 0;
        uint rHeight = x->right != nullptr ? x->right->height : 0;
        x->height = std::max(lHeight, rHeight) + 1;
    }

    node *rotateRight(node *x) {
        int originalInfo = x->info;
        node *originalParent = x->parent;

        node *l = x->left;
        node *tmp = l->right;
        l->right = x;
        l->parent = nullptr;
        x->left = tmp;
        x->parent = l;

        updateHeight(l);
        updateHeight(x);
        l->parent = originalParent;
        if (originalParent != nullptr) {
            if (originalParent->left != nullptr and originalParent->left->info == originalInfo)
                originalParent->left = l;
            else
                originalParent->right = l;
        }

        return l;
    }

    node *rotateLeft(node *x) {
        int originalInfo = x->info;
        node *originalParent = x->parent;

        node *r = x->right;
        node *tmp = r->left;
        r->left = x;
        r->parent = nullptr;
        x->right = tmp;
        x->parent = r;

        updateHeight(r);
        updateHeight(x);
        r->parent = originalParent;
        if (originalParent != nullptr) {
            if (originalParent->left != nullptr and originalParent->left->info == originalInfo)
                originalParent->left = r;
            else
                originalParent->right = r;
        }

        return r;
    }

    node *balanceTree(node *root) {
        int balance = calcBalance(root);

        if (balance > 1) {
            if (calcBalance(root->left) > 0) {
                return rotateRight(root);
            } else {
                root->left = rotateLeft(root->left);
                return rotateRight(root);
            }
        }

        if (balance < -1) {
            if (calcBalance(root->right) < 0) {
                return rotateLeft(root);
            } else {
                root->right = rotateRight(root->right);
                return rotateLeft(root);
            }
        }

        if (root->left)
            updateHeight(root->left);
        if (root->right)
            updateHeight(root->right);
        updateHeight(root);

        return root;
    }

    node *insert(node *root, int key) {
        node *newNode = new node(key);
        if (root == nullptr)
            return newNode;

        node *current = root;
        while (current != nullptr) {
            if (key < current->info) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    newNode->parent = current;
                    current = nullptr;
                } else {
                    current = current->left;
                }
            } else if (key > current->info) {
                if (current->right == nullptr) {
                    current->right = newNode;
                    newNode->parent = current;
                    current = nullptr;
                } else {
                    current = current->right;
                }
            } else {
                delete newNode;
                return root;
            }
        }

        current = newNode;
        node *prev = nullptr;
        while (current != nullptr) {
            updateHeight(current);
            current = balanceTree(current);
            updateHeight(current);

            prev = current;
            current = current->parent;
        }

        return prev;
    }

    /// @brief TODO: Create method for removing nodes
    /// @param root root of the tree
    /// @param key key on which we delete
    /// @return return deleted node?
    node *remove(node *root, int key) {
        return nullptr;
    }

    nullptr_t removeAll(node *root) {
        if (root == nullptr)
                return nullptr;

        std::queue<node *> q;
        q.push(root);
        while (!q.empty()) {
            auto levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                node *n = q.front();
                q.pop();

                if (n->left != nullptr)
                    q.push(n->left);
                if (n->right != nullptr)
                    q.push(n->right);

                delete n;
            }
        }
        return nullptr;
    }

    void levelOrder(node *root) {
        if (root == nullptr) {
            std::cout << "Tree is empty..." << std::endl;
            return;
        }

        std::queue<node *> q;
        q.push(root);
        while (!q.empty()) {
            auto levelSize = q.size();

            for (int i = 0; i < levelSize; i++) {
                node* n = q.front();
                std::cout << n->info << " ";
                q.pop();

                if (n->left != nullptr)
                    q.push(n->left);
                if (n->right != nullptr)
                    q.push(n->right);
            }

            std::cout << std::endl;
        }
    }
}

namespace set {
    using set = avl::node;

    nullptr_t initEmpty() {
        return nullptr;
    }

    set *initWithValue(int value) {
        return new avl::node(value);
    }

    set *addElement(set *set, int element) {
        return avl::insert(set, element);
    }

    bool isElementInSet(set *set, int element) {
        avl::node *ptr = set;
        while (ptr != nullptr) {
            if (ptr->info == element)
                return true;

            if (element < ptr->info) {
                ptr = ptr->left;
            } else {
                ptr = ptr->right;
            }
        }

        return false;
    }

    set *addAllElements(set *src, set *target) {
        if (src == nullptr)
            return target;

        std::queue<set *> q;
        q.push(src);
        while (!q.empty()) {
            set* n = q.front();
            target = avl::insert(target, n->info);
            q.pop();

            if (n->left != nullptr)
                q.push(n->left);
            if (n->right != nullptr)
                q.push(n->right);
        }

        return target;
    }

    void deleteSet(set *set) {
        avl::removeAll(set);
    }
}


int main() {
    std::string userInput;
    bool shouldContinueExecuting = true;
    set::set *skup1 = nullptr, *skup2 = nullptr;

    while (shouldContinueExecuting) {
        std::cout << "Izaberite opciju:" << std::endl;
        std::cout << "1. Print" << std::endl;
        std::cout << "2. Empty initialization" << std::endl;
        std::cout << "3. Check element" << std::endl;
        std::cout << "4. Union" << std::endl;
        std::cout << "5. Add element" << std::endl;
        std::cout << "6. Exit" << std::endl;

        int choice;
        bool isInputCorrect = true;
        while (isInputCorrect) {
            std::cin >> userInput;
            try {
                choice = std::stoi(userInput);
                isInputCorrect = false;
            } catch (const std::invalid_argument& e) {
                std::cerr << "Wrong input" << std::endl;
                continue;
            }
        }
        std::cout << std::endl;

        switch (choice) {
            case 1: {
                std::cout << "First: " << std::endl;
                avl::levelOrder(skup1);
                std::cout << std::endl;

                std::cout << "Second: " << std::endl;
                avl::levelOrder(skup2);
                std::cout << std::endl;

                break;
            }
            case 2: {
                skup1 = set::initEmpty();
                skup2 = set::initEmpty();

                break;
            }
            case 3: {
                std::cout << "Enter element to check: " << std::endl;
                std::cin >> userInput;
                int element;
                try {
                    element = std::stoi(userInput);
                    isInputCorrect = false;
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Wrong input!" << std::endl;
                    continue;
                }

                std::cout << "First result of search: " << set::isElementInSet(skup1, element) << std::endl;
                std::cout << "Second result of search: " << set::isElementInSet(skup2, element) << std::endl;

                break;
            }
            case 4: {
                set::set *tmp = set::initEmpty();
                tmp = set::addAllElements(skup1, tmp);
                tmp = set::addAllElements(skup2, tmp);

                std::cout << "Union " << std::endl;
                avl::levelOrder(tmp);

                set::deleteSet(tmp);
                break;
            }
            case 5: {
                std::cout << "Enter where you want to add element to: " << std::endl;
                std::cin >> userInput;
                int s;
                try {
                    s = std::stoi(userInput);
                    if (s != 1 and s != 2)
                        throw std::invalid_argument("");
                } catch (const std::invalid_argument& e) {
                    std::cerr << "Wrong input." << std::endl;
                    continue;
                }

                std::cout << "Enter element you wish to add to tree: " << std::endl;
                std::cin >> userInput;
                int element = std::stoi(userInput);

                if (s == 1)
                    skup1 = set::addElement(skup1, element);
                else
                    skup2 = set::addElement(skup2, element);

                break;
            }
            case 6: {
                set::deleteSet(skup1);
                set::deleteSet(skup2);

                std::cout << "Exiting..." << std::endl;
                shouldContinueExecuting = false;
                break;
            }
            default:
                std::cout << "Uknown option!" << std::endl;
        }
        std::cout << std::endl;
    }

    return 0;
}
