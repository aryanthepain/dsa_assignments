// author: Aryanthepain
#include "include/testing.h"

// /*
int main()
{
    DataFrame df("data.csv");

    DataFrame hi = df.filterString(0, "Bob");
    hi.print();

    return 0;
}
// */
/*
int main()
{
    // Load the dataframe
    DataFrame df("mpg.csv");

    cout << "First 5 rows of the dataset:" << endl;
    df.head();
    cout << endl;

    cout << "Dataset Info:" << endl;
    cout << "Shape of the dataset:" << df.shape().first << " X " << df.shape().second << "\n"
         << endl;
    df.describe();

    cout << "Analyzing the name column" << endl;
    size_t nameColumn = 8;
    df.describe(nameColumn);
    cout << "All of the names should be common, however they are not.\n"
         << "This is because there are multiple entries for a car with with multiple model years\n"
         << endl;

    cout << "\nUnique values in 'origin' column:" << endl;
    size_t originColumn = 7;
    auto uniqueOrigin = df.unique(originColumn);
    auto originData = get<Array<string>>(uniqueOrigin);
    originData.print();

    // Filter rows where 'origin' is 'USA'
    size_t mpgColumn = 0;
    for (size_t i = 0; i < originData.size(); i++)
    {
        string targetOrigin = originData[i];
        cout << "\nTop Cars in '" << targetOrigin << "':" << endl;
        DataFrame originFilteredDf = df.filterString(originColumn, targetOrigin);
        originFilteredDf.sort_values(mpgColumn);
        originFilteredDf.head();
    }

    // Statistical analysis for 'mpg' column
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

    cout << "\nFlagging rows where 'mpg' > 30:" << endl;
    auto flaggedDf = df.apply(
        mpgColumn,
        [](const variant<double, string> &value) -> variant<double, string>
        {
            return get<double>(value) > 30.0 ? "High MPG" : "Low MPG";
        });
    flaggedDf.head();

    // Plotting
    cout << "\nPlotting 'mpg' column distribution:" << endl;
    df.hist(mpgColumn);

    cout << "\nBoxplot for 'mpg' column:" << endl;
    df.boxplot(mpgColumn);

    cout << "\nLine plot for 'mpg' column:" << endl;
    df.plot(mpgColumn);

    return 0;
}
*/