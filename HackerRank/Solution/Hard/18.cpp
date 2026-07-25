#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    char v;
    Node *l;
    Node *r;
    Node *m;
    bool leaf;
    Node(char val) : v(val), leaf(false), l(NULL), r(NULL), m(NULL) {}
};

char buf1[800];
char buf2[800];
Node *power_tree = NULL;
bool tree_loaded = false;

void mul2(char *src, char *dst, int &len)
{
    int offset = (src[0] > '4') ? 1 : 0;
    char v, carry = 0;
    dst[len] = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        v = ((src[i] - '0') * 2) + carry;
        carry = (v > 9) ? 1 : 0;
        dst[i + offset] = (v % 10) + '0';
    }
    if (offset)
    {
        dst[0] = '1';
        len++;
    }
}

Node *createValueNodes(char *s)
{
    Node *res = NULL;
    Node *cur = NULL;
    while (*s)
    {
        Node *n = new Node(*s);
        if (res == NULL)
        {
            cur = res = n;
        }
        else
        {
            cur->m = n;
            cur = n;
        }
        s++;
    }
    cur->leaf = true;
    return res;
}

Node *addValue(Node *tree, char *s)
{
    if (tree == NULL)
        return createValueNodes(s);
    if (tree->v > *s)
    {
        if (tree->l)
            addValue(tree->l, s);
        else
            tree->l = createValueNodes(s);
    }
    else if (tree->v < *s)
    {
        if (tree->r)
            addValue(tree->r, s);
        else
            tree->r = createValueNodes(s);
    }
    else if (tree->v == *s)
    {
        if (++s)
        {
            if (tree->m)
                addValue(tree->m, s);
            else
                tree->m = createValueNodes(s);
        }
        else
        {
            tree->leaf = true;
        }
    }
    return tree;
}

int find(Node *tree, const char *s)
{
    int res = 0;
    while (tree && *s)
    {
        if (tree->v > *s)
            tree = tree->l;
        else if (tree->v < *s)
            tree = tree->r;
        else if (tree->v == *s)
        {
            if (tree->leaf)
                res++;
            tree = tree->m;
            s++;
        }
    }
    return res;
}

void load_tree()
{
    int len = 1;
    buf1[0] = '1';
    buf1[1] = 0;
    power_tree = addValue(power_tree, buf1);
    for (int i = 0; i < 400; i++)
    {
        mul2(buf1, buf2, len);
        power_tree = addValue(power_tree, buf2);
        mul2(buf2, buf1, len);
        power_tree = addValue(power_tree, buf1);
    }
}

int count_powers(string s)
{
    int total = 0;
    const char *str = s.c_str();
    for (int i = 0; i < s.length(); i++)
    {
        total += find(power_tree, str + i);
    }
    return total;
}

int twoTwo(string a)
{
    if (!tree_loaded)
    {
        load_tree();
        tree_loaded = true;
    }
    return count_powers(a);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> s;
        cout << twoTwo(s) << endl;
    }

    return 0;
}