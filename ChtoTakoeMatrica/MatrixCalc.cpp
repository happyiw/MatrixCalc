#include <numeric>
#include <iostream>
#include <limits>

using namespace std;

struct arr_result {
    int i;
    int j;
    int number;
};

int main()
{
    int n, m;

    arr_result* minarr = new arr_result;
    arr_result* maxarr = new arr_result;

    cin >> n >> m;
    while (cin.fail() or (n <= 0) or (m <= 0) or (n != m)) {

            cin.clear();
            cout << "Wrong numbers " << endl;
            cin.ignore(numeric_limits < streamsize >::max(), '\n');
            cin >> n >> m;
    }

    int** arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[m];
        for (int j = 0; j < m; j++) {
            arr[i][j] = (rand() % 8) + 2;

            if ((i == 1) and (j == 1)) {
                minarr->i = i;
                minarr->j = j;
                minarr->number = arr[i][j];
            }
            else {
                if (i < j) {
                    if (arr[i][j] < minarr->number) {
                        minarr->i = i;
                        minarr->j = j;
                        minarr->number = arr[i][j];
                    }
                }
            }
            if ((i + 1) > (m - j)) {
                if (arr[i][j] > maxarr->number) {
                    maxarr->i = i;
                    maxarr->j = j;
                    maxarr->number = arr[i][j];
                }
            }
            cout << arr[i][j] << " ";
        }
        cout << '\n';
    }
    cout << endl << minarr->number << endl << maxarr->number;
}

