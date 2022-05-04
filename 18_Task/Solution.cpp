#include <iostream>
#include <vector>

using namespace std;

const int n = 25;
#define numofDirections 4
char matrix[n][n];
const int check1[4] = { 1,0,-1,0 };
const int check2[4] = { 0,1,0,-1 };

bool used[n][n];

int paths = 0;

bool bounds(int &nextPosX, int &nextPosY, int &rows, int &cols)
{
    if (nextPosX < 0 || nextPosY < 0 || nextPosX > rows - 1 || nextPosY > cols - 1)
    {
        return false;
    }
    else if (matrix[nextPosX][nextPosY] == 'x')
    {
        return false;
    }
    else if (used[nextPosX][nextPosY] == true)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool allPosVisited(int &rows, int &cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (used[i][j] == false && matrix[i][j] != 'x')
            {
                return false;
            }
        }
    }
    return true;
}

void core(int startPositionX, int startPositionY, int &rows, int &cols)
{
    used[startPositionX][startPositionY] = true;
    if (matrix[startPositionX][startPositionY] == 'e')
    {
        if (true == allPosVisited(rows, cols))
        {
            paths++;
        }
    }

    int newRow, newCol;

    for (int i = 0; i < numofDirections; i++)
    {
        newRow = startPositionX + check1[i];
        newCol = startPositionY + check2[i];
        if (true == bounds(newRow, newCol, rows, cols))
        {
            core(newRow, newCol, rows, cols);
        }
    }
    used[startPositionX][startPositionY] = false;
}

int main()
{
    int rows = 0, cols = 0;
    cin >> rows >> cols;
    char input;

    int startPositionX = 0;
    int startPositionY = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> input;
            if (input == 's')
            {
                startPositionX = i;
                startPositionY = j;
            }
            matrix[i][j] = input;
        }
    }

    core(startPositionX, startPositionY, rows, cols);

    cout << paths << endl;

    return 0;
}