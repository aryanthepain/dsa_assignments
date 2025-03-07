// author: Aryanthepain
#include "include/testing.h"

/**
 * \brief Main function for analyzing the mpg dataset.
 *
 * This program loads a CSV file containing vehicle data, analyzes various columns,
 * and performs statistical calculations on the 'mpg' (miles per gallon) column.
 * It also filters and sorts the data based on specific criteria and plots the distributions.
 *
 * \return int Exit status of the program.
 */
int main()
{
    // Load the dataframe from the CSV file
    DataFrame df("mpg.csv");

    // Display the first 5 rows of the dataset
    cout << "First 5 rows of the dataset:" << endl;
    df.head();
    cout << endl;

    // Display dataset information
    cout << "Dataset Info:" << endl;
    cout << "Shape of the dataset:" << df.shape().first << " X " << df.shape().second << "\n"
         << endl;
    df.describe();

    // Analyze the 'name' column
    cout << "Analyzing the name column:\n"
         << endl;
    size_t nameColumn = 8; // Index of the 'name' column
    df.describe(nameColumn);
    cout << "All of the names should be common, however they are not.\n"
         << "This is because there are multiple entries for a car with multiple model years\n"
         << endl;

    // Display unique values in the 'origin' column
    cout << "\nUnique values in 'origin' column:" << endl;
    size_t originColumn = 7; // Index of the 'origin' column
    auto uniqueOrigin = df.unique(originColumn);
    auto originData = get<Array<string>>(uniqueOrigin);
    originData.print();

    // Filter rows where 'origin' is 'USA'
    size_t mpgColumn = 0; // Index of the 'mpg' column
    for (size_t i = 0; i < originData.size(); i++)
    {
        string targetOrigin = originData[i];
        cout << "\nTop Cars in '" << targetOrigin << "':" << endl;
        DataFrame originFilteredDf = df.filterString(originColumn, targetOrigin);
        originFilteredDf.sort_values(mpgColumn);
        originFilteredDf.head();
    }

    // Perform statistical analysis for the 'mpg' column
    cout << "\nStatistical analysis of 'mpg' column:" << endl;
    cout << "Sum: " << df.sum(mpgColumn) << endl;
    cout << "Mean: " << df.mean(mpgColumn) << endl;

    auto [q1, q2, q3] = df.quartiles(mpgColumn);
    cout << "Quartiles - Q1: " << q1 << ", Q2 (Median): " << q2 << ", Q3: " << q3 << endl;

    // Sorting by 'mpg' column in descending order
    cout << "\nSorting by 'mpg' column (descending):" << endl;
    DataFrame sortedDf = df.copy();
    sortedDf.sort_values(mpgColumn, false); // Sort in descending order
    sortedDf.head();

    // Filter rows where 'mpg' > 30
    double mpgThreshold = 30.0;
    cout << "\nFiltering rows where 'mpg' > " << mpgThreshold << ":" << endl;
    DataFrame filteredDf = df.filterDouble(mpgColumn, mpgThreshold, true);
    filteredDf.head();

    // Flagging rows where 'mpg' > 30
    cout << "\nFlagging rows where 'mpg' > 30:" << endl;
    auto flaggedDf = df.apply(
        mpgColumn,
        [](const variant<double, string> &value) -> variant<double, string>
        {
            return get<double>(value) > 30.0 ? "High MPG" : "Low MPG";
        });
    flaggedDf.head();

    // Plotting the distribution of the 'mpg' column
    cout << "\nPlotting 'mpg' column distribution:" << endl;
    df.hist(mpgColumn);

    // Line plot for the sorted 'mpg' column
    cout << "\nLine plot for sorted 'mpg' column:" << endl;
    sortedDf.plot(mpgColumn);

    return 0;
}