#include "include/testing.h"

int main()
{
    DataFrame df("./data.csv");

    df.print();

    cout << df.sum(1) << endl;
    cout << df.mean(1) << endl;
    auto [q1, q2, q3] = df.quartiles(2);
    cout << q1 << endl;
    try
    {
        df.mean(0);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        df.mean(5);
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}