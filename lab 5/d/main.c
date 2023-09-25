#include <stdio.h>
#include <stdint.h>



// Function to calculate the modular inverse
int modInverse(int a, int m) {
    int m0 = m, t, q;
    int x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

// Function to check if a number is a quadratic residue modulo p
int isQuadraticResidue(int x,int p) {
    for (int i = 0; i < p; i++) {
        if ((i * i) % p == x)
            return 1;
    }
    return 0;
}

// Function to find all points on the elliptic curve
void findPointsOnCurve(int p, int a,int b) {
   for (int x = 0; x < p; x++) {
        int y_squared = (x * x * x + a * x + b) % p;
        if (isQuadraticResidue(y_squared,p)) {
            int y = 0;
            while ((y * y) % p != y_squared) {
                y++;
            }
             printf("(%d, %d)\n", x, y);
             printf("(%d, %d)\n",x , p-y);
        }
    }
}

int main() {
    int a,b,p;
    printf("Enter the value of p:" );
    scanf("%d", &p);
    printf("Enter the value of a:" );
     scanf("%d", &a);
    printf("Enter the value of b:" );
     scanf("%d", &b);
    printf("Points on the elliptic curve y^2 = x^3 + %dx + %d (mod %d):\n", a, b, p);
    findPointsOnCurve(p,a,b);
    return 0;
}

