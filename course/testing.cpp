#include "include/testing.h"

int main()
{
    DataFrame df("./data.csv");

    df.print();

    DataFrame copydf = df.copy();

    copydf.print();

    return 0;
}