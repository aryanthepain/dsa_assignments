#include "./include/testing.h"

int main()
{
    DataFrame df("./data.csv");

    df.print();
    DataFrame hi = df.head();
    hi.print();
    hi = df.tail();
    hi.print();

    return 0;
}