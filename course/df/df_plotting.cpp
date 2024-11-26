// author: Aryanthepain
#include "../include/df.h"

void DataFrame::plot() const
{
    for (size_t i = 0; i < columns.size(); ++i)
    {
        std::cout << "Plotting column " << i << std::endl;

        if (holds_alternative<Array<double>>(columns[i]))
        {
            const auto &array = get<Array<double>>(columns[i]);
            const auto &data = array.getData();

            // Write data to a temporary file
            std::ofstream outFile("temp_data.txt");
            for (size_t j = 0; j < data.size(); ++j)
            {
                outFile << j << " " << data[j] << std::endl; // x, y format
            }
            outFile.close();

            // Call gnuplot to plot the data
            std::string command =
                "gnuplot -e \"set terminal png; "
                "set output 'plots/plot_" +
                std::to_string(i) + ".png'; "
                                    "set title 'Plot of Column " +
                std::to_string(i) + "'; "
                                    "set xlabel 'Index'; "
                                    "set ylabel 'Value'; "
                                    "plot 'temp_data.txt' with lines title 'Column " +
                std::to_string(i) + "';\"";
            std::system(command.c_str());
        }
    }
}

void DataFrame::hist(size_t col) const
{
    if (col < columns.size())
    {
        std::cout << "Generating histogram for column " << col << std::endl;

        if (holds_alternative<Array<double>>(columns[col]))
        {
            const auto &array = get<Array<double>>(columns[col]);
            const auto &data = array.getData();

            // Write data to a temporary file
            std::ofstream outFile("temp_data.txt");
            for (const auto &value : data)
            {
                outFile << value << std::endl;
            }
            outFile.close();

            // Call gnuplot to generate the histogram
            std::string command =
                "gnuplot -e \"set terminal png; "
                "set output 'plots/histogram_" +
                std::to_string(col) + ".png'; "
                                      "set title 'Histogram of Column " +
                std::to_string(col) + "'; "
                                      "set xlabel 'Value'; "
                                      "set ylabel 'Frequency'; "
                                      "binwidth=1; "
                                      "bin(x,width)=width*floor(x/width); "
                                      "set style fill solid; "
                                      "set boxwidth binwidth; "
                                      "plot 'temp_data.txt' using (bin($1,binwidth)):(1.0) smooth freq with boxes title 'Frequency';\"";
            std::system(command.c_str());
        }
    }
    else
    {
        std::cerr << "Invalid column index" << std::endl;
    }
}

void DataFrame::boxplot(size_t col) const
{
    if (col < columns.size())
    {
        std::cout << "Creating box plot for column " << col << std::endl;

        if (holds_alternative<Array<double>>(columns[col]))
        {
            const auto &array = get<Array<double>>(columns[col]);
            const auto &data = array.getData();

            // Write data to a temporary file
            std::ofstream outFile("temp_data.txt");
            for (const auto &value : data)
            {
                outFile << value << std::endl;
            }
            outFile.close();

            // Call gnuplot to create the box plot
            std::string command =
                "gnuplot -e \"set terminal png; "
                "set output 'plots/boxplot_" +
                std::to_string(col) + ".png'; "
                                      "set title 'Box Plot of Column " +
                std::to_string(col) + "'; "
                                      "set style fill solid; "
                                      "plot 'temp_data.txt' using 1:1 with boxplot title 'Column " +
                std::to_string(col) + "';\"";
            std::system(command.c_str());
        }
    }
    else
    {
        std::cerr << "Invalid column index" << std::endl;
    }
}