
template< typename T, int b = 8, int bit = sizeof(T) * 8> void radix_sort(T* a, int n) {
    T temp[200200];
    T *dist = temp, *src = a;
    constexpr T mask = (1 << b) - 1;
    constexpr int kn = (bit + b - 1) / b;
    for (int k = 0; k < kn; ++k) {
        T bucket[1 << b] = {};
        T index[1 << b];
        for (int i = 0; i < n; ++i) bucket[mask & (src[i] >> (b*k))] += 1;
        index[0] = 0;
        for (int i = 0; i < (1 << b) - 1; ++i) index[i + 1] = index[i] + bucket[i];
        for (int i = 0; i < n; ++i) dist[index[mask & (src[i] >> (b*k))]++] = src[i];
        swap(dist, src);
    }
    if (kn % 2 == 1) {
        memcpy(a, src, sizeof(T) * n);
    }
}
