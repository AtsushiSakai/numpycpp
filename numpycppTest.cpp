#include <math.h>
#include <chrono>
#include "gtest/gtest.h"
#include "../mpccpp/numpycpp.h"


TEST(numpycpp, test1) {
  Eigen::MatrixXf x(1,3);
  x<<1.0,10.0,100.0;
  PRINT(x);

  Eigen::MatrixXf y(1,3);
  y<<5.0,6.0,7.0;
  PRINT(y);

  Eigen::MatrixXf z = kron(x,y);
  PRINT(z);

  
  Eigen::VectorXf ans(9);
  ans<< 5,   6,   7,  50,  60,  70, 500, 600, 700;
  PRINT(ans);

  for(uint32_t i=0;i<ans.rows();i++){
    std::cout<<ans[i]<<","<<z(0,i)<<std::endl;
    ASSERT_LE(std::abs(ans[i]-z(0,i)), 0.01);
  }

}

TEST(numpycpp, test2) {
  Eigen::MatrixXf x(1,3);
  x<<5.0,6.0,7.0;
  PRINT(x);

  Eigen::MatrixXf y(1,3);
  y<<1.0,10.0,100.0;
  PRINT(y);

  Eigen::MatrixXf z = kron(x,y);
  PRINT(z);

  
  Eigen::VectorXf ans(9);
  ans<< 5,  50, 500,   6,  60, 600,   7,  70, 700;
  PRINT(ans);

  for(uint32_t i=0;i<ans.rows();i++){
    std::cout<<ans[i]<<","<<z(0,i)<<std::endl;
    ASSERT_LE(std::abs(ans[i]-z(0,i)), 0.01);
  }

}

TEST(numpycpp, test3) {
  Eigen::MatrixXf x(3,1);
  x<<5.0,6.0,7.0;
  PRINT(x);

  Eigen::MatrixXf y(1,3);
  y<<1.0,10.0,100.0;
  PRINT(y);

  Eigen::MatrixXf z = kron(x,y);
  PRINT(z);

  
  Eigen::MatrixXf ans(3,3);
  ans<< 5,  50, 500,   6,  60, 600,   7,  70, 700;
  PRINT(ans);

  Eigen::MatrixXf t = ans - z;
  PRINT(t);

  ASSERT_LE(std::abs(t.sum()), 0.01);

}


TEST(numpycpp, test4) {
  Eigen::MatrixXf x(3,1);
  x<<5.0,6.0,7.0;
  PRINT(x);

  Eigen::MatrixXf y(1,3);
  y<<1.0,10.0,100.0;
  PRINT(y);

  Eigen::MatrixXf z = block_diag(x,y);
  PRINT(z);

  
  Eigen::MatrixXf ans(4,4);
  ans<< 5,  0,  0,  0,
        6,  0,  0,  0,
        7,  0,  0,  0,
        0,  1, 10,100;
  PRINT(ans);


  ASSERT_LE(std::abs((ans-z).sum()), 0.01);

}


TEST(numpycpp, test5) {
  Eigen::MatrixXf x(3,1);
  x<<5.0,6.0,7.0;
  PRINT(x);

  Eigen::MatrixXf y(1,3);
  y<<1.0,10.0,100.0;
  PRINT(y);

  Eigen::MatrixXf z(2,2);
  z<<1.0,10.0,100.0, 1000.0;
  PRINT(z);

  Eigen::MatrixXf a = block_diag(x,y,z);
  PRINT(a);
  
  Eigen::MatrixXf ans(6,6);
  ans<<5,   0,   0,   0,   0,   0,
       6,   0,   0,   0,   0,   0,
       7,   0,   0,   0,   0,   0,
       0,   1,  10, 100,   0,   0,
       0,   0,   0,   0,   1,  10,
       0,   0,   0,   0, 100,1000;

  PRINT(ans);

  ASSERT_LE(std::abs((ans-a).sum()), 0.01);

}


TEST(numpycpp, test6) {
  Eigen::MatrixXf x(3,1);
  x<<5.0,6.0,7.0;
  PRINT(x);

  Eigen::MatrixXf y(3,1);
  y<<1.0,10.0,100.0;
  PRINT(y);

  Eigen::MatrixXf a = hstack(x,y);
  PRINT(a);
  
  Eigen::MatrixXf ans(3,2);
  ans<<5,   1,
       6,  10,
       7, 100;
  PRINT(ans);

  ASSERT_LE(std::abs((ans-a).sum()), 0.01);

}

TEST(numpycpp, test7) {
  Eigen::MatrixXf x(3,1);
  x<<5.0,6.0,7.0;
  PRINT(x);

  Eigen::MatrixXf y(3,1);
  y<<1.0,10.0,100.0;
  PRINT(y);

  Eigen::MatrixXf a = vstack(x,y);
  PRINT(a);
  
  Eigen::MatrixXf ans(6,1);
  ans<<5,
       6,
       7,
       1,
       10,
       100;
  PRINT(ans);

  ASSERT_LE(std::abs((ans-a).sum()), 0.01);

}

