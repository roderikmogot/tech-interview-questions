#include <iostream>
#include <map>
#include <vector>

using namespace std;

int ROWSS;
int COLSS;

void dfs(int matrix[ROWSS][COLSS], int r, int c, char currChar, vector<int> seenChar, int rows, int cols)
{
    if (r < 0 || c < 0 || r == rows || c == cols || matrix[r][c] == '#' || matrix[r][c] == true)
    {
        return
    }

    matrix[r][c] = true;

    if (matrix[r][c] != "." && matrix[r][c] != currChar)
    {
        seenChar.push_back(matrix[r][c])
    }

    dfs(matrix, r + 1, c, currChar, seenChar, rows, cols);
    dfs(matrix, r - 1, c, currChar, seenChar, rows, cols);
    dfs(matrix, r, c + 1, currChar, seenChar, rows, cols);
    dfs(matrix, r, c - 1, currChar, seenChar, rows, cols);

    return;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int rows, cols;
        cin >> rows;
        cin >> cols;

        ROWSS = rows;
        COLSS = cols;

        string matrix[rows][cols];

        for (int r = 0; r < rows; r++)
        {
            string inputRow;
            cin >> inputRow;
            for (int c = 0; c < inputRow.length(); c++)
            {
                matrix[r][c] = inputRow[r];
            }
        }

        int contested = 0;
        map<string, int> storeChar;
        vector<int> seenChar, currChar;

        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                if(matrix[r][c] != true and matrix[r][c] != "#" and matrix[r][c] != "."){
                    dfs(matrix, r, c, currChar, seenChar, rows, cols);

                    cout << seenChar.size() << endl;
                }
            }
            cout << endl;
        }
    }

    return 0;
}
