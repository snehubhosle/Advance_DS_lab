#include <iostream>
using namespace std;

class find_max_shop 
{
public:
    int S[100], E[100], k, n;
    void sort_shops_by_end_time();
    int find_max_shops();
} F;

void find_max_shop::sort_shops_by_end_time() 
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (E[j] > E[j + 1]) 
            {
                int temp = E[j];
                E[j] = E[j + 1];
                E[j + 1] = temp;

                temp = S[j];
                S[j] = S[j + 1];
                S[j + 1] = temp;
            }
        }
    }
}

int find_max_shop::find_max_shops() 
{
    int persons[100];
    for (int i = 0; i < k; i++) 
    {
        persons[i] = 0; 
    }

    int count = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < k; j++) 
        {
            if (persons[j] <= S[i]) 
            { 
                persons[j] = E[i];   
                count++;
                break; 
            }
        }
    }
    return count;
}

int main() 
{
    cout << "Enter the number of shops: ";
    cin >> F.n;

    cout << "Enter the start times of shops:\n";
    for (int i = 0; i < F.n; i++) 
    {
        cin >> F.S[i];
    }
    cout << "Enter the end times of shops:\n";
    for (int i = 0; i < F.n; i++) 
    {
        cin >> F.E[i];
    }
    cout << "Enter the number of persons: ";
    cin >> F.k;
    F.sort_shops_by_end_time();
    int max_shops = F.find_max_shops();
    cout << "Maximum number of shops persons can visit: " << max_shops << endl;
    return 0;
}
