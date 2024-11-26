// // author: Aryanthepain
// #include "../include/df.h"

// // Missing value methods implementation
// vector<bool> DataFrame::is_na(size_t col) const
// {
//     vector<bool> missingValues;
//     if (col >= columns.size())
//     {
//         cout << "Column index out of bounds!" << endl;
//         return missingValues;
//     }
//     visit([&missingValues](const auto &array)
//           {
//         for (const auto& value : array) {
//             missingValues.push_back(value == variant<double, string>{}); // Adjust based on how missing values are represented
//         } }, columns[col]);
//     return missingValues;
// }

// void DataFrame::fillna(const variant<double, string> &value)
// {
//     for (size_t col = 0; col < columns.size(); ++col)
//     {
//         visit([this, &value](auto &array)
//               {
//             for (auto& elem : array) {
//                 if (elem == std ::variant<double, string>{}) { // Adjust based on how missing values are represented
//                     elem = value;
//                 }
//             } }, columns[col]);
//     }
// }

// void DataFrame::dropna()
// {
//     // Implementation to remove rows or columns with missing values
// }