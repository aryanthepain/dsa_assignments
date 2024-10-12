// author: Aryanthepain
#include "tree.h"
using namespace std;

mathTreeNode::mathTreeNode(char x)
{
    val = x;
    right = nullptr;
    left = nullptr;
}
mathTreeNode::~mathTreeNode()
{
    if (right)
        delete right;
    if (left)
        delete left;

    right = nullptr;
    left = nullptr;
    val = -1;

    // delete &numberStack;
    // delete &opStack;
}

bool isNumber(char b)
{
    if ((int)b >= '0' && (int)b <= '9')
    {
        return true;
    }

    return false;
}

bool isOperator(char b)
{
    return (b == '+' || b == '-' || b == '*' || b == '/');
}

bool isOpenBracket(char b)
{
    return (b == '(');
}
bool isCloseBracket(char b)
{
    return (b == ')');
}

void mathTreeNode::printTree(int level)
{

    // Print the right child recursively
    if (right)
        right->printTree(level + 1);

    if (val >= 0)
    {
        // Print current node with indentation based on the level
        for (int i = 0; i < level; i++)
        {
            cout << "\t";
        }
        cout << val << endl;

        // debug code
        // cout << val << " " << right << " " << left << endl;
    }

    // Print the left child recursively
    if (left)
        left->printTree(level + 1);

    return;
}

/*
bool mathTreeNode::searchElement(int x)
{
    if (x < 0)
        return false;
    if (x == val)
    {
        return true;
    }
    if (x > val && right)
    {
        return right->searchElement(x);
    }
    else if (x < val && left)
    {
        return left->searchElement(x);
    }

    return false;
}

void mathTreeNode::deleteHelper(int x, mathTreeNode *curr)
{
    if (!curr)
        return;

    if (x < 0) // only deleting, no finding
    {
        // leaf node
        if (!curr->right && !curr->left)
        {
            if (right == curr)
            {
                right = nullptr;
            }
            else if (left == curr)
            {
                left = nullptr;
            }
            else
            {
                cerr << "Logic error in deleting leaf node" << endl;
            }

            delete curr;
            return;
        }

        // two children
        else if (curr->right && curr->left)
        {
            if (right == curr)
            {
                curr->val = curr->left->val;
                curr->deleteHelper(-1, curr->left);
            }
            else if (left == curr)
            {
                curr->val = curr->right->val;
                curr->deleteHelper(-1, curr->right);
            }
            else
            {
                cerr << "Logic error in deleting node with two children" << endl;
            }
            return;
        }

        // one child
        else
        {
            mathTreeNode *child = curr->right ? curr->right : curr->left;
            if (curr == right)
            {
                right = child; // Update root reference
            }
            else if (curr == left)
            {
                left = child; // Update root reference
            }

            curr->right = nullptr;
            curr->left = nullptr;
            // this has to be done otherwise the delete will call the destructor
            // which is not good
            delete curr;
            return;
        }
    }
    // only finding, no deleting
    else
    {
        if (x == curr->val)
        {
            this->deleteHelper(-1, curr);
        }
        else if (x > curr->val && curr->right)
        {
            curr->deleteHelper(x, curr->right);
        }
        else if (x < curr->val && curr->left)
        {
            curr->deleteHelper(x, curr->left);
        }
        else
        {
            cerr << "No such element found" << endl;
        }

        return;
    }

    return;
}
void mathTreeNode::deleteElement(int x)
{
    if (x < 0 || !right)
        return;
    mathTreeNode *curr = right;
    // we can do this as root node is always -1
    // due to the initialisation
    if (x == curr->val)
    {
        this->deleteHelper(-1, curr);
    }
    else if (x < curr->val && curr->left)
    {
        curr->deleteHelper(x, curr->left);
    }
    else if (x > curr->val && curr->right)
    {
        curr->deleteHelper(x, curr->right);
    }

    return;
}


void mathTreeNode::preOrder()
{
    if (val >= 0)
        cout << val << " ";
    if (left)
        left->preOrder();
    if (right)
        right->preOrder();

    if (val < 0)
        cout << endl;

    return;
}

void mathTreeNode::inOrder()
{
    if (left)
        left->inOrder();
    if (val >= 0)
        cout << val << " ";

    // debug code
    // cout << val << " " << right << " " << left << endl;
    if (right)
        right->inOrder();

    if (val < 0)
        cout << endl;

    return;
}

void mathTreeNode::postOrder()
{
    if (left)
        left->postOrder();
    if (right)
        right->postOrder();
    if (val >= 0)
    {
        cout << val << " ";
    }
    if (val < 0)
        cout << endl;

    return;
}
//
// void mathTreeNode::insertOp(char b, char next, stack<char> &numstack, stack<char> &opstack, mathTreeNode *&current, mathTreeNode *&root)
// {
//     val = b;
//     left = new mathTreeNode(numstack.top());
//     numstack.pop();
//     // doing according to the next token
//     if (isNumber(next))
//     {
//         right = new mathTreeNode
//     }
// }
*/

int determinePriority(char curr)
{
    if (curr == '+' || curr == '-')
        return 1;
    if (curr == '*' || curr == '/')
        return 2;
    return 0;
}

vector<char> infixToPostfix(vector<char> infix)
{
    vector<char> postfix;
    stack<char> opStack;

    for (int i = 0; i < infix.size(); i++)
    {
        if (isNumber(infix[i]))
        {
            postfix.push_back(infix[i]);
            continue;
        }

        if (isOperator(infix[i]))
        {
            while (!opStack.empty() &&
                   determinePriority(opStack.top()) >= determinePriority(infix[i]))
            {
                postfix.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(infix[i]);
            continue;
        }

        if (isOpenBracket(infix[i]))
        {
            opStack.push(infix[i]);
            continue;
        }

        if (isCloseBracket(infix[i]))
        {
            while (!opStack.empty() && !isOpenBracket(opStack.top()))
            {
                postfix.push_back(opStack.top());
                opStack.pop();
            }
            opStack.pop();
            continue;
        }

        if (infix[i] == ' ')
            continue;

        cerr << "Invalid token used. Valid tokens are digits 0-9 and operators- +, -, *, /, (, and )" << endl;
    }

    while (!opStack.empty())
    {
        postfix.push_back(opStack.top());
        opStack.pop();
    }

    return postfix;
}

mathTreeNode *build_tree(vector<char> expression)
{
    stack<mathTreeNode *> treeStack;

    for (int i = 0; i < expression.size(); i++)
    {
        if (isNumber(expression[i]))
        {
            treeStack.push(new mathTreeNode(expression[i]));
            continue;
        }

        // in postfix, token can be number or operator and nothing else
        mathTreeNode *newNode = new mathTreeNode(expression[i]);
        newNode->right = treeStack.top();
        treeStack.pop();
        newNode->left = treeStack.top();
        treeStack.pop();
        treeStack.push(newNode);
    }

    return treeStack.top();
}

mathTree::mathTree(string n)
{
    vector<char> infix;

    for (int i = 0; i < n.size(); i++)
    {
        infix.push_back(n[i]);
    }

    vector<char> postfix = infixToPostfix(infix);

    this->ptr = build_tree(postfix);
}

mathTree::~mathTree()
{
    delete this->ptr;
}

void mathTree::printTree()
{
    this->ptr->printTree();

    return;
}

/*
int main()
{
    string n;
    cin >> n;

    mathTree tree(n);

    tree.printTree();

    return 0;
}
*/
