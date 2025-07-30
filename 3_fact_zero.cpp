#include <iostream>
using namespace std;

class FactZero 
{
    int n; 
    public:
    void accept_Find();
    int findNum(int n);
}F;

int FactZero::findNum(int n) 
{
    int low = 0, high = 5 * n, ans = -1;
    while (low <= high) 
    {
        int mid = (low + high) / 2;
        int count = 0, temp = mid;
        while (temp > 0) 
        {
            count += temp / 5;
            temp /= 5;
        }
        if (count >= n) 
        {
            ans = mid;
            high = mid - 1;
        } 
        else 
        {
            low = mid + 1;
        }
    }
    return ans;
}

void FactZero::accept_Find()
{
    cout << "Enter the number of trailing zeros: ";
    cin >> n;
    cout << "The least number whose factorial has" << n << " trailing zeroes is: " << findNum(n) << endl;
         
}

int main() 
{
   F.accept_Find();
    return 0;
}
