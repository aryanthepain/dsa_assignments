#include "./include/testing.h"

int main()
{
    DataFrame df("./data2.csv");

    df.print();

    df.plot();
    df.hist(1);
    df.boxplot(2);

    return 0;
}