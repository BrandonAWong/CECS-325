// Brandon Wong
// CECS 325-02
// Prog 6 - Big Int
// Due 05/09/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>

class BigInt {
public:
    BigInt() { v.push_back('0'); }

    BigInt(int n) {
        for (char l : std::to_string(n)) 
            v.push_back(l);
        std::reverse(v.begin(), v.end());
    }

    BigInt(std::string str) {
        for (char l : str)
            v.push_back(l);
        std::reverse(v.begin(), v.end());
    }

    BigInt operator+(BigInt n) {
        std::vector<char> result {};
        int carry {0};
        int num {0};
        for (std::size_t i {0}; i < std::max(size(), n.size()); ++i) {
            if (i < std::min(size(), n.size())) {
                num = static_cast<int>(v[i])-static_cast<int>('0') + static_cast<int>(n.v[i])-static_cast<int>('0') + carry;
            }
            else
                num = ((size() == std::max(size(), n.size())) ? static_cast<int>(v[i]) : static_cast<int>(n.v[i]))-static_cast<int>('0') + carry;
            if (num > 9) {
                carry = 1;
                result.push_back(std::to_string(num)[1]);
            }
            else {
                carry = 0;
                result.push_back(std::to_string(num)[0]);
            }
        }
        if (carry)
            result.push_back('1');
        return BigInt({result.rbegin(), result.rend()});
    }

    BigInt operator-(BigInt n) {
        std::vector<char> result {};
        std::vector<int> vt {};
        for (char l : v)
            vt.push_back(static_cast<int>(l)-static_cast<int>('0'));
        for (int i {0}; i < size(); ++i) {
            if (vt[i] < 0 || i < n.size() && v[i] < n.v[i]) {
                vt[i+1] -= 1;
                vt[i] += 10; 
            }
            if (i < n.size())
                vt[i] = vt[i] - (static_cast<int>(n.v[i]) - static_cast<int>('0'));
            result.push_back(vt[i] + '0');
        }
        while (result[result.size()-1] == '0')
            result.pop_back();
        return BigInt({result.rbegin(), result.rend()});
    }

    BigInt operator*(BigInt n) {
        BigInt result {0};
        for (BigInt i {0}; i < ((*this < n) ? *this : n); ++i)
            result = (*this < n) ? n + result : *this + result;
        return result;
    }

    BigInt operator/(BigInt n) {
        BigInt divs {0};
        BigInt dividend (*this);
        while (n < dividend) {
            dividend = dividend - n;
            ++divs;
        }
        return divs;
    }

    BigInt operator%(BigInt n) {
        return BigInt(*this - (*this / n * n)) ;
    }

    BigInt operator++() { 
        *this = *this + 1;
        return *this;
    }

    BigInt operator++(int) {
        *this = *this + 1;
        return *this - 1;
    }

    bool operator==(BigInt n) { return v == n.v; }

    bool operator<(BigInt n) {
        if (size() != n.size())
            return size() < n.size();
        std::vector<char> vr {v.rbegin(), v.rend()};
        std::vector<char> nr {n.v.rbegin(), n.v.rend()};
        for (std::size_t i {0}; i < size(); ++i) {
            if (vr[i] < nr[i])
                return true;
        }
        return false;
    }

    void print() {
        std::vector<char> vr {v.rbegin(), v.rend()};
        for (char l : vr)
            std::cout << l;
        std::cout << '\n';
    }

    int size() { return v.size(); }

    BigInt fibo() { return fiboHelper(*this); }

    BigInt fact() {
        BigInt counter {1};
        BigInt result {1};
        while (counter < *this+1) {
            result = result * counter;
            ++counter;
        }
        return result; 
    }

    friend std::ostream& operator<<(std::ostream& out, const BigInt& n);
    friend BigInt operator+(int i, BigInt n);
    
private:
    std::vector<char> v;
    BigInt fiboHelper(BigInt n, BigInt a=0, BigInt b=1) {
        if (n < 4)
            return 0;
        return a + b + fiboHelper(n-1, b, a+b);
    }
};

std::ostream& operator<<(std::ostream& out, const BigInt& n) {
    std::vector<char> vr {n.v.rbegin(), n.v.rend()};
    if (n.v.size() <= 12) {
        for (char l : vr) 
            out << l;
    }
    else {
        out << vr[0] << '.';
        for (std::size_t i {1}; i < 7; ++i)
            out << vr[i];
        out << 'e' << n.v.size()-1;
    }
    return out;
}

BigInt operator+(int i, BigInt n) { return static_cast<BigInt>(i) + n; }

void testUnit() {
    int space = 10;
    std::cout << "\a\nTestUnit:\n"<<std::flush;
    system("whoami");
    system("date");
    // initialize variables
    BigInt n1(25);
    BigInt s1("25");
    BigInt n2(1234);
    BigInt s2("1234");
    BigInt n3(n2);
    BigInt fibo(12345);
    BigInt fact(50);
    BigInt imax = INT_MAX;
    BigInt big("9223372036854775807");
    // display variables
    std::cout << "n1(int)    :"<<std::setw(space)<<n1<< '\n';
    std::cout << "s1(str)    :"<<std::setw(space)<<s1<< '\n';
    std::cout << "n2(int)    :"<<std::setw(space)<<n2<< '\n';
    std::cout << "s2(str)    :"<<std::setw(space)<<s2<< '\n';
    std::cout << "n3(n2)     :"<<std::setw(space)<<n3<< '\n';
    std::cout << "fibo(12345):"<<std::setw(space)<<fibo<< '\n';
    std::cout << "fact(50)   :"<<std::setw(space)<<fact<< '\n';
    std::cout << "imax       :"<<std::setw(space)<<imax<< '\n';
    std::cout << "big        :"<<std::setw(space)<<big<< '\n';
    std::cout << "big.print(): "; big.print(); 
    std::cout << '\n' << n2 << "/"<< n1<< " = "<< n2/n1 <<" rem "<<n2%n1<< '\n';
    std::cout << "fibo("<<fibo<<") = "<<fibo.fibo() <<  '\n';
    std::cout << "fact("<<fact<<") = "<<fact.fact() <<  '\n';
    std::cout << "10 + n1 = " << 10+n1 << '\n';
    std::cout << "n1 + 10 = " << n1+10 << '\n';
    std::cout << "(n1 == s1)? --> "<<((n1==s1)?"true":"false")<< '\n';
    std::cout << "n1++ = ? --> before:"<<n1++<<" after:"<<n1<< '\n';
    std::cout << "++s1 = ? --> before:"<<++s1<<" after:"<<s1<< '\n';
    std::cout << "s2 * big = ? --> "<< s2 * big<< '\n';
    std::cout << "big * s2 = ? --> "<< big * s2<< '\n';
}

int main() {
    testUnit();
    return 0;
}

