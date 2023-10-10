#ifndef CHECK_FLIP_H
#define CHECK_FLIP_H

#include <iostream>
#include <vector>
#include <Eigen/Sparse>
#include <Eigen/Core>
#ifdef WITH_MPFR
#include <unsupported/Eigen/MPRealSupport>
#endif

template <typename Scalar>
int check_flip(const Eigen::Matrix<Scalar, Eigen::Dynamic, Eigen::Dynamic> &uv, const Eigen::MatrixXi &Fn, bool print_flip = false);

#endif