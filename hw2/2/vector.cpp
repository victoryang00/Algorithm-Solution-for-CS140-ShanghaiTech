template <typename T> class Vector {
protected:
    Rank _size;
    int  _capacity;
    T *  _elem;

public:
    ///���췽�� ������ʼ��
    Vector(int capacity = DEFAULT_CAPACITY);
    void memset(T v, int size = 0);
    // ����ת����
    Vector(T const *A, Rank n) {
        copyFrom(A, 0, n);
    }
    Vector(T const *A, Rank low, Rank high) {
        copyFrom(A, low, high);
    }
    // ����ֱ�Ӹ�ֵ
    Vector(Vector<T> const &V) {
        copyFrom(V._elem, 0, V._size);
    }
    Vector(Vector<T> const &V, Rank low, Rank high) {
        copyFrom(V._elem, low, high);
    }

    ~Vector() {
        delete[] _elem;
    }
} template <typename T> void Vector<T>::copyFrom(T const *A, Rank low, Rank high) {
    _elem = new T[ _capacity = 2 * (high - low) ];
    _size = 0;
    while (low < high)
        _elem[ _size++ ] = A[ low++ ];
} ///ֻ���ӿ�
Rank size() const {
    return _size;
}
bool empty() const {
    return !_size;
}