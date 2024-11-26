#include "./include/testing.h"

int main()
{
    DataFrame df("./data.csv");

    df.print();

    // // filter method
    // df.filterString(0, "Bob").print();
    // df.filterString(0, "Bob", false).print();
    // df.filterDouble(1, 28, false).print();
    // df.filterDouble(1, 28).print();

    // // drop function
    //  df.drop(1);

    // DataFrame df2("./data2.csv");
    // df2.print();
    // // concat function
    // df.concat(df, 0).print();
    // df.concat(df2, 1).print();

    // // sort function
    // df.sort_values(2);
    // df.print();
    // df.sort_values(2, false);
    // df.print();

    // apply function
    auto square = [](const variant<double, string> &x) -> variant<double, string>
    {
        if (holds_alternative<double>(x))
        {
            return get<double>(x) * get<double>(x);
        }
        else
        {
            return x;
        }
    };

    DataFrame result = df.apply(1, square);

    result.print();

    return 0;
}