#include <iostream>
#include <assert.h>
using namespace std;

class Solution
{
public:
    int countDigitOne(int n)
    {
        int count = 0;
        int weight;
        int former;
        int round;
        int base = 1; // long long
        former = 0;
        while (n)
        {
            weight = n % 10;
            round = n / 10;
            count += (round + (weight > 1 ? 1 : 0)) * base + (weight == 1 ? former + 1 : 0);
            former = former + n % 10 * base;
            base = base * 10;
            n = n / 10;
        }
        return count;
    }
};
int main()
{
    {
        Solution s;
        int n = 12;
        int count = s.countDigitOne(n);
        cout << count << endl;
        assert(count == 5);
    }
    {
        Solution s;
        int n = 13;
        int count = s.countDigitOne(n);
        cout << count << endl;
        assert(count == 6);
    }
    {
        Solution s;
        int n = 23;
        int count = s.countDigitOne(n);
        cout << count << endl;
        assert(count == 13);
    }
    {
        Solution s;
        int n = 123;
        int count = s.countDigitOne(n);
        cout << count << endl;
        assert(count == 57);
    }
    {
        Solution s;
        int n = 504;
        int count = s.countDigitOne(n);
        cout << count << endl;
        assert(count == 201);
    }
    {
        Solution s;
        int n = 514;
        int count = s.countDigitOne(n);
        cout << count << endl;
        assert(count == 207);
    }
    {
        Solution s;
        int n = 530;
        int count = s.countDigitOne(n);
        cout << count << endl;
        assert(count == 213);
    }
    {
        Solution s;
        int n = 534;
        int count = s.countDigitOne(n);
        cout << count << endl;
        assert(count == 214);
    }
    {
        Solution s;
        int n = 32324231;
        int count = s.countDigitOne(n);
        cout << count << endl;
        assert(count == 33470354);
    }
}