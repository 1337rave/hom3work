#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

const int MAX_ROWS = 2;
const int MAX_COLS = 3;

void shiftArray(int arr[MAX_ROWS][MAX_COLS], string direction, int n) {
    int temp[MAX_ROWS][MAX_COLS];

    if (direction == "left" || direction == "right") {
        for (int i = 0; i < MAX_ROWS; i++) {
            for (int j = 0; j < MAX_COLS; j++) {
                int newCol = (direction == "left") ? (j - n + MAX_COLS) % MAX_COLS : (j + n) % MAX_COLS;
                temp[i][newCol] = arr[i][j];
            }
        }
    }
    else if (direction == "up" || direction == "down") {
        for (int i = 0; i < MAX_ROWS; i++) {
            int newRow = (direction == "up") ? (i - n + MAX_ROWS) % MAX_ROWS : (i + n) % MAX_ROWS;
            for (int j = 0; j < MAX_COLS; j++) {
                temp[newRow][j] = arr[i][j];
            }
        }
    }

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            arr[i][j] = temp[i][j];
        }
    }
}

int main() {
    srand(time(0)); 

    int array[MAX_ROWS][MAX_COLS];

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            array[i][j] = rand() % 10; 
        }
    }

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    string direction;
    cout << "Enter the shift direction (left, right, up, down): ";
    cin >> direction;

    int n;
    cout << "Enter the number of positions to shift: ";
    cin >> n;

    shiftArray(array, direction, n);

    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
