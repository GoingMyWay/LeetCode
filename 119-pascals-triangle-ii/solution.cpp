class Solution {
public:
    vector<int> getRow(int rowIndex) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> a(rowIndex + 1);
        
        a[0] = 1;
        for(int i = 1; i <= rowIndex; i++)
            for(int j = i; j >= 0; j--)
                if (j == i)
                    a[j] = a[j-1];
                else if (j == 0)
                    a[j] = a[j];
                else
                    a[j] = a[j-1] + a[j];
                    
        return a;                    
    }
};