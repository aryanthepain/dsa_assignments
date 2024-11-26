#include "./include/testing.h"

int main()
{
    DataFrame df("./data2.csv");

    df.print();

    vector<bool> missingValuesA = df.is_na(1);
    vector<bool> missingValuesB = df.is_na(2);

    for (bool value : missingValuesA)
    {
        cout << value << " ";
    }
    cout << endl;

    for (bool value : missingValuesB)
    {
        cout << value << " ";
    }
    cout << endl;
    df.print();

    df.fillna(2, 0.0);
    df.fillna(1, "Unknown");
    df.print();

    missingValuesA = df.is_na(1);
    missingValuesB = df.is_na(2);

    for (bool value : missingValuesA)
    {
        cout << value << " ";
    }
    cout << endl;

    for (bool value : missingValuesB)
    {
        cout << value << " ";
    }
    cout << endl;

    df.dropna(1);
    df.print();

    missingValuesA = df.is_na(1);
    missingValuesB = df.is_na(2);

    for (bool value : missingValuesA)
    {
        cout << value << " ";
    }
    cout << endl;

    for (bool value : missingValuesB)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}