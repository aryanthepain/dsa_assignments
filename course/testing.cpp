#include "include/testing.h" // Include your DataFrame class definition

int main()
{
    DataFrame df("./data.csv");

    df.print();

    DataFrame copydf = df.copy();

    copydf.print();

    return 0;
}