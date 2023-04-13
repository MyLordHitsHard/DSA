// bhaisaab dimaag kharaab kr diya is question ne
// merge sort se kiya hai

class Solution{
  public:
    long long ans = 0;
    
    void merge_fun(long long arr[], long long l, long long m, long long r) {
        long long n1 = m - l + 1;
        long long n2 = r - m;
        long long left[n1], right[n2];
        
        for (long long i = 0; i < n1; i++) {
            left[i] = arr[l+i];
        }
        for (long long i = 0; i < n2; i++) {
            right[i] = arr[m+1+i];
        }
        
        int i = 0, j = 0, k = l;
        
        while ((i < n1) && (j < n2)) {
            if (left[i] <= right[j]) {
                arr[k] = left[i];
                i++;
            }
            
            else {
                ans += n1 - i;
                arr[k] = right[j];
                j++;
            }
            k++;
        }
        
        while (i < n1) {
            arr[k++] = left[i++];
        }
        
        while (j < n2) {
            arr[k++] = right[j++];
        }
    }
    
    void sol(long long arr[], long long l, long long r) {
        if (l < r) {
            int m = (l + r) / 2;
            sol(arr, l, m);
            sol(arr, m+1, r);
            merge_fun(arr, l, m, r);
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        sol(arr, 0, N-1);
        return ans;
    }

};
