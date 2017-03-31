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

Stack matrix in sequence vertically

imspired by numpy.vstack

see :https://docs.scipy.org/doc/numpy/reference/generated/numpy.vstack.html

    Eigen::MatrixXf x(3,1);
    x<<5.0,
       6.0,
       7.0;

    Eigen::MatrixXf y(3,1);
    y<<1.0,
       10.0,
       100.0;

    Eigen::MatrixXf a = vstack(x,y);
    //ans<<5,
    //     6,
    //     7,
    //     1,
    //     10,
    //     100;

## hstack

Stack matrix in sequence horizontally

imspired by numpy.hstack

see: https://docs.scipy.org/doc/numpy/reference/generated/numpy.hstack.html
 

    Eigen::MatrixXf x(3,1);
    x<<5.0,
       6.0,
       7.0;

    Eigen::MatrixXf y(3,1);
    y<<1.0,
       10.0,
       100.0;

    Eigen::MatrixXf a = hstack(x,y);
    //a=
    //5   1
    //6  10
    //7 100

## kron

Compute the Kronecker product

A composite array made of blocks of the second array scaled by the first.

Inspired numpy.kron. 

*see: https://docs.scipy.org/doc/numpy/reference/generated/numpy.kron.html


    Eigen::MatrixXf x(1,3);
    x<<1.0,10.0,100.0;

    Eigen::MatrixXf y(1,3);
    y<<5.0,6.0,7.0;

    Eigen::MatrixXf a = kron(x,y);
    // a = [5 50 500  6 60 600  7  70 700]


## block_diag_

Create a block diagonal matrix from provided matrices

inspired scipy.linalg.block_diag

see: https://docs.scipy.org/doc/scipy-0.14.0/reference/generated/scipy.linalg.block_diag.html


    Eigen::MatrixXf x(3,1);
    x<<5.0,
       6.0,
       7.0;

    Eigen::MatrixXf y(1,3);
    y<<1.0,10.0,100.0;

    Eigen::MatrixXf a = block_diag(x,y);
    //a=  5,  0,  0,  0,
    //    6,  0,  0,  0,
    //    7,  0,  0,  0,
    //    0,  1, 10,100;


# License 

MIT

# Author

Atsushi Sakai ([@Atsushi_twi](https://twitter.com/Atsushi_twi))

