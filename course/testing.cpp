#include "include/testing.h"

int main()
{
    DataFrame df("./data.csv");

    df.print();

    df.filter(1, 28).print();
    df.filter(1, 28, false).print();

    df.sort_values(2);
    df.print();
    df.sort_values(1, false);
    df.print();

    df.drop(0);
    df.print();

    return 0;
}