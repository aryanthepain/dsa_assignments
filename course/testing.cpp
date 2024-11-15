#include "include/df.h"

int main()
{
    // Sample data for testing
    std::vector<std::vector<std::variant<double, std::string>>> inputData = {
        {1.0, "Alice"},
        {2.0, "Bob"},
        {3.0, "Charlie"},
        {4.0, "David"},
        {5.0, "Eve"}};

    std::vector<std::string> columnNames = {"Age", "Name"};
    std::vector<std::string> rowLabels = {"Row1", "Row2", "Row3", "Row4", "Row5"};

    // Create a DataFrame
    DataFrame df(inputData, columnNames, rowLabels);

    // Print the DataFrame
    df.print();

    return 0;
}