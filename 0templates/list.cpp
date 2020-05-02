// begin of list
/*
 * Array of linked list. N is max size of array. M is max total size of linked list.
 * An instance must be global variable to zero fill arrays.
 * Equivalent to vector<T>
*/
template<typename T, int N, int M>
class List {
    int k = 0;
public:
    int head[N];
    pair<int, T> nodes[M];
    class ListNode {
        List<T, N, M>& list;
        int i;
        int pointer;
    public:
        ListNode(List<T, N, M>& list, int i, int pointer = -1): list(list) {
            this->i = i, this->pointer = pointer;
        }
        void push_back(T x) {
            list.nodes[++list.k] = make_pair(list.head[i], x);
            list.head[i] = list.k;
        }
        void emplace_back(T&& x) {
            list.nodes[++list.k] = make_pair(list.head[i], x);
            list.head[i] = list.k;
        }
        T& operator *() { return list.nodes[pointer].second; }
        bool operator ==(ListNode& other) { return pointer == other.pointer; }
        bool operator !=(ListNode& other) { return pointer != other.pointer; }
        void operator ++() { pointer = list.nodes[pointer].first; }
        ListNode begin() {
            return ListNode(list, i, list.head[i]);
        }
        ListNode end() {
            return ListNode(list, i, 0);
        }
    };
    ListNode operator[](int i) {
        return ListNode(*this, i, head[i]);
    }
};
// end of list
