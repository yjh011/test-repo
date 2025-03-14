양지혜 202401169 컴퓨터공학





#include <iostream>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

class Fraction {
private:
    int numerator;
    int denominator;

    void simplify() {
        if (numerator == 0) {
            denominator = 1;
            return;
        }
        int g = gcd(abs(numerator), denominator);
        numerator /= g;
        denominator /= g;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int denom = 1) : numerator(num), denominator(denom) {
        simplify();
    }

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }
};

Fraction add(const Fraction& f1, const Fraction& f2) {
    int num = f1.getNumerator() * f2.getDenominator() + f2.getNumerator() * f1.getDenominator();
    int denom = f1.getDenominator() * f2.getDenominator();
    return Fraction(num, denom);
}

Fraction subtract(const Fraction& f1, const Fraction& f2) {
    int num = f1.getNumerator() * f2.getDenominator() - f2.getNumerator() * f1.getDenominator();
    int denom = f1.getDenominator() * f2.getDenominator();
    return Fraction(num, denom);
}

Fraction multiply(const Fraction& f1, const Fraction& f2) {
    int num = f1.getNumerator() * f2.getNumerator();
    int denom = f1.getDenominator() * f2.getDenominator();
    return Fraction(num, denom);
}

Fraction divide(const Fraction& f1, const Fraction& f2) {
    int num = f1.getNumerator() * f2.getDenominator();
    int denom = f1.getDenominator() * f2.getNumerator();
    return Fraction(num, denom);
}

void print(const Fraction& fraction) {
    cout << fraction.getNumerator() << "/" << fraction.getDenominator() << endl;
}

int main() {
    Fraction* pFraction1 = new Fraction;
    Fraction* pFraction2 = new Fraction;

    int n1, d1, n2, d2;
    cin >> n1 >> d1 >> n2 >> d2;

    *pFraction1 = Fraction(n1, d1);
    *pFraction2 = Fraction(n2, d2);

    cout << "+: "; print(add(*pFraction1, *pFraction2));
    cout << "-: "; print(subtract(*pFraction1, *pFraction2));
    cout << "*: "; print(multiply(*pFraction1, *pFraction2));
    cout << "/: "; print(divide(*pFraction1, *pFraction2));

    delete pFraction1;
    delete pFraction2;

    return 0;
}



