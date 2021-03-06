# numpycpp
[![Build Status](https://travis-ci.org/AtsushiSakai/numpycpp.svg?branch=master)](https://travis-ci.org/AtsushiSakai/numpycpp)

A c++ header library for matrix operation inspired Numpy, Scipy and MATLAB only using Eigen.

This library has some APIs which Numpy, Scipy, MATLAB has, but Eigen doesn't.

You can use it with only Eigen, and only include it.

# Requrements

- [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page)

# How to use

Just add a compile option to add the Eigen path, and include numpycpp.h in your code.

# APIs

The test code: numpycppTest.cpp helps to understand APIs.

## reshape

Gives a new shape to an array without changing its data.

This function is based on numpy.reshape 

see: https://docs.scipy.org/doc/numpy/reference/generated/numpy.reshape.html

    Eigen::MatrixXf x(6,1);
    x<<1.0,2.0,3.0,4.0,5.0,6.0;
    PRINT(x);

    Eigen::MatrixXf rx = reshape(x,2,3);
    PRINT(rx);
    //rx:
    //1 3 5
    //2 4 6

    Eigen::MatrixXf rx2 = reshape(x,3,2);
    PRINT(rx2);
    //rx2:
    //1 4
    //2 5
    //3 6


## isdiag

Detemine if matrix is diagonal

If matrix is not square, return false

It is inspired by MATLAB isdiag function.

see: https://www.mathworks.com/help/matlab/ref/isdiag.html



    Eigen::MatrixXf x(3,1);
    x<<5.0,6.0,7.0;
    bool flag = isdiag(x);//return false

    Eigen::MatrixXf x2(2,2);
    x2<<5.0,6.0,7.0,1.0;
    bool flag2 = isdiag(x2);//return false

    Eigen::MatrixXf x3(3,3);
    x3<<1.0,0.0,0.0,
        0.0,1.0,0.0,
        0.0,0.0,1.0;
    bool flag3 = isdiag(x3);//return true



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

see: https://docs.scipy.org/doc/numpy/reference/generated/numpy.kron.html


    Eigen::MatrixXf x(1,3);
    x<<1.0,10.0,100.0;

    Eigen::MatrixXf y(1,3);
    y<<5.0,6.0,7.0;

    Eigen::MatrixXf a = kron(x,y);
    // a = [5 50 500  6 60 600  7  70 700]


## block_diag

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

