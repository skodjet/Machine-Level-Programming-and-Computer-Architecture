int a = 5;
int b = -2;
int ans;

int main() {
    ans = sum(a, b);
}

int sum(int a, int b) {
    int z = square(a);
    int w = square(b);
    return z + w;
}

int square(int x) {
    int y = x * x;
    return y;
}