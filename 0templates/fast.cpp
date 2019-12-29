chrono::high_resolution_clock::time_point step_time[10];
int step_time_i = 0;
void measure_time() {
    step_time[step_time_i++] = chrono::high_resolution_clock::now();
}
double calc_microsecond(const chrono::high_resolution_clock::time_point &a, const chrono::high_resolution_clock::time_point &b) {
    return chrono::duration_cast<chrono::microseconds>(b - a).count() / 1000.0;
}
void print_time() {
    if (step_time_i < 2) return;
    fprintf(stderr, "Time: ");
    if (step_time_i > 2)
        fprintf(stderr, "%.3f ", calc_microsecond(step_time[0], step_time[step_time_i-1]));
    rep(i, step_time_i - 1)
        fprintf(stderr, "%.3f ", calc_microsecond(step_time[i], step_time[i+1]));
    fprintf(stderr, "\n");
}

char buf[1000*1000];
int bufi = 0;
template<typename T>
void readi(T &n) {
    bool negative = false;
    int c;
    n = 0;
    c = buf[bufi++];
    if (c == '-') negative = true, c = buf[bufi++];
    for (; '0' <= c && c <= '9'; c = buf[bufi++])
        n = 10 * n + c - '0';
    if (negative) n = -n;
}

