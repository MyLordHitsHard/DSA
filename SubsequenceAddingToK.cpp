#include <bits/stdc++.h>


int arr[3] = {1, 2, 1};

int sum = 2;

void fun(int ind, std::vector<int>& a, int s) {
    if (ind == 3) {
        
        if (s == sum) {
            for (auto i : a) {
                std::cout << i << " ";
            }
            std::cout << "\n";
        }
        
        return;
    }
    
    a.push_back(arr[ind]);
    s += arr[ind];
    fun(ind+1, a, s);
    a.pop_back();
    s -= arr[ind];
    fun(ind+1, a, s);
}

int main() {
    
    
    std::vector<int> a;
    
    fun(0, a, 0);
    
    
    return 0;
}
