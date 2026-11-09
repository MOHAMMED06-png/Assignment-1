TASK 1:انشاء مصفوفه بحجم يحدده المستخدم و انشاء مصفوفه بضعف حجم المصفوفه الاصليه
#include <iostream>
using namespace std;

// Function to resize the array
int* resizeArray(int inArray[], const int size)
{
    int* newArray = new int[size * 2];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = inArray[i];
        newArray[i + size] = inArray[i] * 2;
    }

    return newArray;
}

int main()
{
    int size;

    cout << "Enter size of the array: ";
    cin >> size;

    if (size <= 0)
    {
        cout << "Invalid size!" << endl;
        return 0;
    }

    int* arr = new int[size];

    cout << "Enter elements of array: ";

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }

    int* resizedArray = resizeArray(arr, size);

    cout << "Resized array: ";

    for (int i = 0; i < size * 2; i++)
    {
        cout << resizedArray[i];

        if (i < size * 2 - 1)
            cout << ", ";
    }

    cout << endl;

    delete[] arr;
    delete[] resizedArray;

    return 0;
}

task 2:انشاء مصفوفه مربعه
#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter matrix size: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid size!" << endl;
        return 0;
    }

    int** matrix = new int*[n];

    for (int i = 0; i < n; i++)
    {
        matrix[i] = new int[n];
    }

    cout << "Enter matrix elements:" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    bool isDiagonal = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && matrix[i][j] != 0)
            {
                isDiagonal = false;
            }
        }
    }

    if (isDiagonal)
        cout << "The matrix is Diagonal." << endl;
    else
        cout << "The matrix is NOT Diagonal." << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;

    return 0;
}
TASK 3:استقبال نص من المستخدم ثم استخراج عدد الاحرف من بدايه النص
#include <iostream>
#include <cstring>
using namespace std;

// Extract characters from the left
char* left(const char* target, const int count)
{
    char* result = new char[count + 1];

    for (int i = 0; i < count; i++)
    {
        result[i] = target[i];
    }

    result[count] = '\0';

    return result;
}

// Deallocate dynamic memory
void Destructor(char* p)
{
    delete[] p;
}

int main()
{
    char str[30];
    int count;

    cout << "Enter a string: ";
    cin.getline(str, 30);

    cout << "Enter count: ";
    cin >> count;

    if (count < 0 || count > strlen(str))
    {
        cout << "Count is out of range!" << endl;
        return 0;
    }

    char* result = left(str, count);

    cout << "Left substring: " << result << endl;

    Destructor(result);

    return 0;


TASK 4:برنامج يستقبل درجات الطلاب

#include <iostream>
#include <algorithm>
using namespace std;

// Find minimum mark
int findMin(int inArray[], const int size)
{
    int min = inArray[0];

    for (int i = 1; i < size; i++)
    {
        if (inArray[i] < min)
        {
            min = inArray[i];
        }
    }

    return min;
}

// Find maximum mark
int findMax(int inArray[], const int size)
{
    int max = inArray[0];

    for (int i = 1; i < size; i++)
    {
        if (inArray[i] > max)
        {
            max = inArray[i];
        }
    }

    return max;
}

// Calculate average
int computeAverage(int inArray[], const int size)
{
    int sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += inArray[i];
    }

    return sum / size;
}

// Calculate median
int computeMedian(int inArray[], const int size)
{
    int* sortedArray = new int[size];

    for (int i = 0; i < size; i++)
    {
        sortedArray[i] = inArray[i];
    }

    sort(sortedArray, sortedArray + size);

    int median;

    if (size % 2 == 1)
    {
        median = sortedArray[size / 2];
    }
    else
    {
        median = (sortedArray[size / 2 - 1]
                + sortedArray[size / 2]) / 2;
    }

    delete[] sortedArray;

    return median;
}

int main()
{
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    if (n <= 0)
    {
        cout << "Invalid number of students!" << endl;
        return 0;
    }

    int* marks = new int[n];

    cout << "Enter student marks:" << endl;

    for (int i = 0; i < n; i++)
    {
        do
        {
            cout << "Student " << i + 1 << ": ";
            cin >> marks[i];

            if (marks[i] < 0)
            {
                cout << "Negative marks are not allowed!" << endl;
            }

        } while (marks[i] < 0);
    }

    cout << "\nMaximum: " << findMax(marks, n) << endl;
    cout << "Minimum: " << findMin(marks, n) << endl;
    cout << "Average: " << computeAverage(marks, n) << endl;
    cout << "Median: " << computeMedian(marks, n) << endl;

    delete[] marks;

    return 0;
}

}
