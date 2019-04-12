#ifndef MY_PROJECT_HPP
#define MY_PROJECT_HPP

#include "linalgcpp.hpp"

namespace MY_PROJECT
{

// Aliases to avoid unnecessary type verbosity
using SparseMatrix = linalgcpp::SparseMatrix<double>;
using DenseMatrix = linalgcpp::DenseMatrix;
using CooMatrix = linalgcpp::CooMatrix<double>;
using Vector = linalgcpp::Vector<double>;
using VectorView = linalgcpp::VectorView<double>;
using Timer = linalgcpp::Timer;
using Operator = linalgcpp::Operator;

using linalgcpp::linalgcpp_verify;
using linalgcpp::linalgcpp_assert;
// End Aliases

int some_function(const DenseMatrix& A);

} // namespace MY_PROJECT

#endif // MY_PROJECT_HPP
