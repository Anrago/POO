template <class T>
class Stack
{
    struct nodo
    {
        T dato;
        struct nodo *previo = nullptr;
    };
    struct nodo *top = nullptr;

public:
    ~Stack();
    void Push(T dato);
    T Pop();
    bool IsEmpy() { return (top == nullptr); };
    void clear();
    T peek();
};
