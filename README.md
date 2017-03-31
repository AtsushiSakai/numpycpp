# numpycpp
[![Build Status](https://travis-ci.org/AtsushiSakai/numpycpp.svg?branch=master)](https://travis-ci.org/AtsushiSakai/numpycpp)

A c++ header library for matrix operation inspired Numpy and Scipy using Eigen.

This library has some APIs which Numpy or Scipy has, but Eigen doesn't.

You can use it with only Eigen, and only include it.

# Requrements

- [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page)

# How to use

Just add a compile option to add the Eigen path, and include numpycpp.h in your code.

# APIs

The test code: numpycppTest.cpp helps to understand APIs.

## vstack

## hstack

    Eigen::MatrixXf x(3,1);
    x<<5.0,
       6.0,
       7.0;

    Eigen::MatrixXf y(3,1);
    y<<1.0,
       10.0,
       100.0;

    Eigen::MatrixXf a = hstack(x,y);
    //a:
    //5   1
    //6  10
    //7 100

## kron

Compute the Kronecker product

A composite array made of blocks of the second array scaled by the first.

Inspired numpy.kron. (*see: https://docs.scipy.org/doc/numpy/reference/generated/numpy.kron.html)




## block_diag_


# License 

MIT

# Author

Atsushi Sakai ([@Atsushi_twi](https://twitter.com/Atsushi_twi))

