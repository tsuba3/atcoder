// begin fast io
template <typename IStream = decltype(cin), typename OStream = decltype(cout)>
struct FastIO {
    char *buf, *OUT, *out;
    OStream& os;

    FastIO(size_t input_size = 1e7, size_t output_size = 1e7): os(cout) {
        buf = new char[input_size];
        OUT = new char[output_size];
        out = OUT;
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cin.read(buf, input_size);
    }

    FastIO(IStream& in, OStream& out, size_t input_size = 1e7, size_t output_size = 1e7): os(out) {
        buf = new char[input_size];
        OUT = new char[output_size];
        this-> out = OUT;
        in.read(buf, input_size);
    }

    ~FastIO() {
        os.write(OUT, out - OUT);
    }

    char readc() {
        return *buf++;
    }

    template<typename T>
    void readui(T &n) {
        n = 0;
        char c = readc();
        for (; '0' <= c && c <= '9'; c = readc())
            n = 10 * n + c - '0';
    }

    template<typename T>
    void readi(T &n) {
        bool negative = false;
        if (*buf == '-') negative = true, buf++;
        readui(n);
        if (negative) n = -n;
    }

    template<typename T>
    void readuf(T &x) {
        x = 0;
        T y = 0;
        int z = 0;
        char c = readc();
        for (; '0' <= c && c <= '9'; c = readc())
            x = 10 * x + c - '0';
        if (buf[-1] == '.')
            for (; '0' <= c && c <= '9'; c = readc(), ++z)
                y = 10 * y + c - '0';
        x += y / pow(10, z);
    }

    template<typename T>
    void readf(T &x) {
        bool negative = false;
        if (*buf == '-') negative = true, buf++;
        readuf(x);
        if (negative) x = -x;
    }

    string_view reads() {
        const char *begin = buf;
        char c;
        while (c = readc(), c >= '!') {}
        return string_view(begin, buf - begin - 1);
    }

    string_view readline() {
        const char *begin = buf;
        while (readc() != '\n') {}
        return string_view(begin, buf - begin - 1);
    }

    void writec(const char c) {
        *out++ = c;
    }

    void writes(const string& s) {
        memcpy(out, s.c_str(), s.size());
        out += s.size();
    }

    void writes(const string_view& s) {
        memcpy(out, s.data(), s.size());
        out += s.size();
    }

    constexpr static char digit_pairs[] = {
            "00010203040506070809"
            "10111213141516171819"
            "20212223242526272829"
            "30313233343536373839"
            "40414243444546474849"
            "50515253545556575859"
            "60616263646566676869"
            "70717273747576777879"
            "80818283848586878889"
            "90919293949596979899"
    };

    template<typename T>
    void writeui(T n) {
        if (n == 0) { writec('0'); return; }
        int size;
        if (n >= 1e12) {
            if (n >= 1e16) {
                if (n >= 1e18) {
                    if (n >= 1e19) size = 20;
                    else size = 19;
                } else {
                    if (n >= 1e17) size = 18;
                    else size = 17;
                }
            } else {
                if (n >= 1e14) {
                    if (n >= 1e15) size = 16;
                    else size = 15;
                } else {
                    if (n >= 1e13) size = 14;
                    else size = 13;
                }
            }
        } else if (n >= 1e4) {
            if (n >= 1e8) {
                if (n >= 1e10) {
                    if (n >= 1e11) size = 12;
                    else size = 11;
                } else {
                    if (n >= 1e9) size = 10;
                    else size = 9;
                }
            } else {
                if (n >= 1e6) {
                    if (n >= 1e7) size = 8;
                    else size = 7;
                } else {
                    if (n >= 1e5) size = 6;
                    else size = 5;
                }
            }
        } else {
            if (n >= 1e2) {
                if (n >= 1e3) size = 4;
                else size = 3;
            } else {
                if (n >= 1e1) size = 2;
                else size = 1;
            }
        }
        char *c = out + size;
        out += size;
        while (n >= 100) {
            int x = n % 100;
            n /= 100;
            *--c = digit_pairs[2 * x + 1];
            *--c = digit_pairs[2 * x];
        }
        while (n > 0) {
            *--c = '0' + (n % 10);
            n /= 10;
        }
    }

    template<typename T>
    void writei(T n) {
        if (n < 0) {
            writec('-');
            writeui(-n);
        } else {
            writeui(n);
        }
    }
};
// end fast io
