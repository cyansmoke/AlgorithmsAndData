#include <iostream>

int min(int a, int b) {
    return a >= b ? b : a;
}

int max(int a, int b) {
    return a >= b ? a : b;
}

void find() {
    int b_i[] = {1, 3, 4, 5, 6, 20};
    int w_i[] = {10, 12, 3, 2, 1, 4};
    int p_i[] = {3, 1, 4, 55, 90, 3};
    const int w = 13;
    const int n = 6;
    int back[n + 1][w];
    for (int i = 0; i < w; i++) {
        back[0][i] = 0;
    }
    for (int i = 1; i < n + 1; i++) {
        for (int c = 1; c < w + 1; c++) {
            back[i][c] = back[i - 1][c];
            for (int l = min(b_i[i], c / w_i[i]); l > 1; l--) {
                back[i][c] = max(back[i][c], back[i - 1][c - l * w_i[i]] + p_i[i] * l);
            }
        }
    }

    std::cout << back[n][w - 1];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    find();
    return 0;
}

