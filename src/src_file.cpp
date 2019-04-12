#include "src_file.hpp"

namespace MY_PROJECT
{

int some_function(const DenseMatrix& A)
{
    return A.Rows() * A.Cols();
}

} // namespace MY_PROJECT
