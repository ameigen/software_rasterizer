#include "Geometry.h"
template <typename T>
Model<T>::Model(const std::string filePath)
{
    // Read data from the file and initialize the Model object
    std::ifstream inFile(filePath);

    if (!inFile.is_open())
        throw std::runtime_error("Could not open file: " + filePath);
    // Check how many vertices and triangles`
    // Read the file and populate the 'triangles' vector
    // ...
}