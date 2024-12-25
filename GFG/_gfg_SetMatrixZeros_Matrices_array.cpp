#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void setMatrixZeroes(vector<vector<int>> &matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();

        bool rowZero = false; // Flag to check if the first row needs to be zero
        bool colZero = false; // Flag to check if the first column needs to be zero

        // Check if the first row has any zero
        for (int j = 0; j < cols; j++)
        {
            if (matrix[0][j] == 0)
            {
                rowZero = true;
                break;
            }
        }

        // Check if the first column has any zero
        for (int i = 0; i < rows; i++)
        {
            if (matrix[i][0] == 0)
            {
                colZero = true;
                break;
            }
        }

        // Use the first row and column as markers
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0; // Mark row i
                    matrix[0][j] = 0; // Mark column j
                }
            }
        }

        // Set matrix elements to zero based on markers
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Handle the first row if needed
        if (rowZero)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[0][j] = 0;
            }
        }

        // Handle the first column if needed
        if (colZero)
        {
            for (int i = 0; i < rows; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};

int main()
{
    Solution s;
    vector<vector<int>> mat = {{1, -1, 1}, {-1, 0, 1}, {1, -1, 1}};
    s.setMatrixZeroes(mat);
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[0].size(); j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}