//
// AxDCT - A collection of inexact DCT Algorithms
// Copyright (C) 2019 Andrea Aletto <andrea.aletto8@gmail.com>
//
// This file is part of AxDCT.
//
// AxDCT is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// AxDCT is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with AxDCT.  If not, see <http://www.gnu.org/licenses/>.
//

/******************************************************************************
 * @file   BC12.cpp
 * @author Andrea Aletto
 * @date   11 feb 2019
 * @brief  Implementation of BC12 algorithm class
 ******************************************************************************/

#include "BC12.h"
#include <cnl/fixed_point.h>
using cnl::fixed_point;

cv::Mat BC12::getT(){

    cv::Mat T = cv::Mat::zeros(8,8,CV_16S);

    T.at<int16_t>(0, 0) = 1; 
    T.at<int16_t>(0, 1) = 1;
    T.at<int16_t>(0, 2) = 1;
    T.at<int16_t>(0, 3) = 1;
    T.at<int16_t>(0, 4) = 1;
    T.at<int16_t>(0, 5) = 1;
    T.at<int16_t>(0, 6) = 1;
    T.at<int16_t>(0, 7) = 1;

    T.at<int16_t>(1, 0) = 1; 
    T.at<int16_t>(1, 7) = -1;

    T.at<int16_t>(2, 0) = 1;
    T.at<int16_t>(2, 3) = -1;
    T.at<int16_t>(2, 4) = -1;
    T.at<int16_t>(2, 7) = 1;

    T.at<int16_t>(3, 2) = -1;
    T.at<int16_t>(3, 5) = 1;

    T.at<int16_t>(4, 0) = 1; 
    T.at<int16_t>(4, 1) = -1;
    T.at<int16_t>(4, 2) = -1;
    T.at<int16_t>(4, 3) = 1;
    T.at<int16_t>(4, 4) = 1;
    T.at<int16_t>(4, 5) = -1;
    T.at<int16_t>(4, 6) = -1;
    T.at<int16_t>(4, 7) = 1;

    T.at<int16_t>(5, 1) = -1;
    T.at<int16_t>(5, 6) = 1;

    T.at<int16_t>(6, 1) = -1;
    T.at<int16_t>(6, 2) = 1;
    T.at<int16_t>(6, 5) = 1;
    T.at<int16_t>(6, 6) = -1;

    T.at<int16_t>(7, 3) = -1;
    T.at<int16_t>(7, 4) = 1;

    return T;
}

cv::Mat BC12::getD(){

    cv::Mat D = cv::Mat::zeros(8,8,CV_16S);

    D.at<int16_t>(0, 0) = to_rep( fixed_point<int16_t, -8> {1/sqrt(8)});
    D.at<int16_t>(1, 1) = to_rep( fixed_point<int16_t, -8> {1/sqrt(2)});
    D.at<int16_t>(2, 2) = to_rep( fixed_point<int16_t, -8> {0.5      });
    D.at<int16_t>(3, 3) = to_rep( fixed_point<int16_t, -8> {1/sqrt(2)});
    D.at<int16_t>(4, 4) = to_rep( fixed_point<int16_t, -8> {1/sqrt(8)});
    D.at<int16_t>(5, 5) = to_rep( fixed_point<int16_t, -8> {1/sqrt(2)});
    D.at<int16_t>(6, 6) = to_rep( fixed_point<int16_t, -8> {0.5      });
    D.at<int16_t>(7, 7) = to_rep( fixed_point<int16_t, -8> {1/sqrt(2)});

    return D;
}

cv::Mat BC12::getQ(){

    cv::Mat Q = cv::Mat::zeros(8,8,CV_16S);

    Q.at<int16_t>(0, 0) = to_rep( fixed_point<int16_t, 0>{16} );
    Q.at<int16_t>(1, 0) = to_rep( fixed_point<int16_t, 0>{12} );
    Q.at<int16_t>(2, 0) = to_rep( fixed_point<int16_t, 0>{14} );
    Q.at<int16_t>(3, 0) = to_rep( fixed_point<int16_t, 0>{14} );
    Q.at<int16_t>(4, 0) = to_rep( fixed_point<int16_t, 0>{18} );
    Q.at<int16_t>(5, 0) = to_rep( fixed_point<int16_t, 0>{24} );
    Q.at<int16_t>(6, 0) = to_rep( fixed_point<int16_t, 0>{49} );
    Q.at<int16_t>(7, 0) = to_rep( fixed_point<int16_t, 0>{72} );
    Q.at<int16_t>(0, 1) = to_rep( fixed_point<int16_t, 0>{11} );
    Q.at<int16_t>(1, 1) = to_rep( fixed_point<int16_t, 0>{12} );
    Q.at<int16_t>(2, 1) = to_rep( fixed_point<int16_t, 0>{13} );
    Q.at<int16_t>(3, 1) = to_rep( fixed_point<int16_t, 0>{17} );
    Q.at<int16_t>(4, 1) = to_rep( fixed_point<int16_t, 0>{22} );
    Q.at<int16_t>(5, 1) = to_rep( fixed_point<int16_t, 0>{35} );
    Q.at<int16_t>(6, 1) = to_rep( fixed_point<int16_t, 0>{64} );
    Q.at<int16_t>(7, 1) = to_rep( fixed_point<int16_t, 0>{92} );
    Q.at<int16_t>(0, 2) = to_rep( fixed_point<int16_t, 0>{10} );
    Q.at<int16_t>(1, 2) = to_rep( fixed_point<int16_t, 0>{14} );
    Q.at<int16_t>(2, 2) = to_rep( fixed_point<int16_t, 0>{16} );
    Q.at<int16_t>(3, 2) = to_rep( fixed_point<int16_t, 0>{22} );
    Q.at<int16_t>(4, 2) = to_rep( fixed_point<int16_t, 0>{37} );
    Q.at<int16_t>(5, 2) = to_rep( fixed_point<int16_t, 0>{55} );
    Q.at<int16_t>(6, 2) = to_rep( fixed_point<int16_t, 0>{78} );
    Q.at<int16_t>(7, 2) = to_rep( fixed_point<int16_t, 0>{95} );
    Q.at<int16_t>(0, 3) = to_rep( fixed_point<int16_t, 0>{16} );
    Q.at<int16_t>(1, 3) = to_rep( fixed_point<int16_t, 0>{19} );
    Q.at<int16_t>(2, 3) = to_rep( fixed_point<int16_t, 0>{24} );
    Q.at<int16_t>(3, 3) = to_rep( fixed_point<int16_t, 0>{29} );
    Q.at<int16_t>(4, 3) = to_rep( fixed_point<int16_t, 0>{56} );
    Q.at<int16_t>(5, 3) = to_rep( fixed_point<int16_t, 0>{64} );
    Q.at<int16_t>(6, 3) = to_rep( fixed_point<int16_t, 0>{87} );
    Q.at<int16_t>(7, 3) = to_rep( fixed_point<int16_t, 0>{98} );
    Q.at<int16_t>(0, 4) = to_rep( fixed_point<int16_t, 0>{24}  );
    Q.at<int16_t>(1, 4) = to_rep( fixed_point<int16_t, 0>{26}  );
    Q.at<int16_t>(2, 4) = to_rep( fixed_point<int16_t, 0>{40}  );
    Q.at<int16_t>(3, 4) = to_rep( fixed_point<int16_t, 0>{51}  );
    Q.at<int16_t>(4, 4) = to_rep( fixed_point<int16_t, 0>{68}  );
    Q.at<int16_t>(5, 4) = to_rep( fixed_point<int16_t, 0>{81}  );
    Q.at<int16_t>(6, 4) = to_rep( fixed_point<int16_t, 0>{103} );
    Q.at<int16_t>(7, 4) = to_rep( fixed_point<int16_t, 0>{112} );
    Q.at<int16_t>(0, 5) = to_rep( fixed_point<int16_t, 0>{40} );
    Q.at<int16_t>(1, 5) = to_rep( fixed_point<int16_t, 0>{58} );
    Q.at<int16_t>(2, 5) = to_rep( fixed_point<int16_t, 0>{57} );
    Q.at<int16_t>(3, 5) = to_rep( fixed_point<int16_t, 0>{87} );
    Q.at<int16_t>(4, 5) = to_rep( fixed_point<int16_t, 0>{109} );
    Q.at<int16_t>(5, 5) = to_rep( fixed_point<int16_t, 0>{104} );
    Q.at<int16_t>(6, 5) = to_rep( fixed_point<int16_t, 0>{121} );
    Q.at<int16_t>(7, 5) = to_rep( fixed_point<int16_t, 0>{100} );
    Q.at<int16_t>(0, 6) = to_rep( fixed_point<int16_t, 0>{51} );
    Q.at<int16_t>(1, 6) = to_rep( fixed_point<int16_t, 0>{60} );
    Q.at<int16_t>(2, 6) = to_rep( fixed_point<int16_t, 0>{69} );
    Q.at<int16_t>(3, 6) = to_rep( fixed_point<int16_t, 0>{80} );
    Q.at<int16_t>(4, 6) = to_rep( fixed_point<int16_t, 0>{103} );
    Q.at<int16_t>(5, 6) = to_rep( fixed_point<int16_t, 0>{113} );
    Q.at<int16_t>(6, 6) = to_rep( fixed_point<int16_t, 0>{120} );
    Q.at<int16_t>(7, 6) = to_rep( fixed_point<int16_t, 0>{103} );
    Q.at<int16_t>(0, 7) = to_rep( fixed_point<int16_t, 0>{61} );
    Q.at<int16_t>(1, 7) = to_rep( fixed_point<int16_t, 0>{55} );
    Q.at<int16_t>(2, 7) = to_rep( fixed_point<int16_t, 0>{56} );
    Q.at<int16_t>(3, 7) = to_rep( fixed_point<int16_t, 0>{62} );
    Q.at<int16_t>(4, 7) = to_rep( fixed_point<int16_t, 0>{77} );
    Q.at<int16_t>(5, 7) = to_rep( fixed_point<int16_t, 0>{92} );
    Q.at<int16_t>(6, 7) = to_rep( fixed_point<int16_t, 0>{101} );
    Q.at<int16_t>(7, 7) = to_rep( fixed_point<int16_t, 0>{99} );

    return Q;
}

cv::Mat BC12::getCQ(){

    cv::Mat CQ = cv::Mat::zeros(8,8,CV_16S);

    CQ.at<int16_t>(0, 0) = to_rep( fixed_point<int16_t, 0>{17});
    CQ.at<int16_t>(1, 0) = to_rep( fixed_point<int16_t, 0>{18});
    CQ.at<int16_t>(2, 0) = to_rep( fixed_point<int16_t, 0>{24});
    CQ.at<int16_t>(3, 0) = to_rep( fixed_point<int16_t, 0>{47});
    CQ.at<int16_t>(4, 0) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(5, 0) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(6, 0) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(7, 0) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(0, 1) = to_rep( fixed_point<int16_t, 0>{18});
    CQ.at<int16_t>(1, 1) = to_rep( fixed_point<int16_t, 0>{21});
    CQ.at<int16_t>(2, 1) = to_rep( fixed_point<int16_t, 0>{26});
    CQ.at<int16_t>(3, 1) = to_rep( fixed_point<int16_t, 0>{66});
    CQ.at<int16_t>(4, 1) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(5, 1) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(6, 1) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(7, 1) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(0, 2) = to_rep( fixed_point<int16_t, 0>{24});
    CQ.at<int16_t>(1, 2) = to_rep( fixed_point<int16_t, 0>{26});
    CQ.at<int16_t>(2, 2) = to_rep( fixed_point<int16_t, 0>{56});
    CQ.at<int16_t>(3, 2) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(4, 2) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(5, 2) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(6, 2) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(7, 2) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(0, 3) = to_rep( fixed_point<int16_t, 0>{47});
    CQ.at<int16_t>(1, 3) = to_rep( fixed_point<int16_t, 0>{66});
    CQ.at<int16_t>(2, 3) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(3, 3) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(4, 3) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(5, 3) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(6, 3) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(7, 3) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(0, 4) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(1, 4) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(2, 4) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(3, 4) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(4, 4) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(5, 4) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(6, 4) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(7, 4) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(0, 5) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(1, 5) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(2, 5) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(3, 5) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(4, 5) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(5, 5) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(6, 5) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(7, 5) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(0, 6) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(1, 6) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(2, 6) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(3, 6) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(4, 6) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(5, 6) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(6, 6) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(7, 6) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(0, 7) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(1, 7) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(2, 7) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(3, 7) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(4, 7) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(5, 7) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(6, 7) = to_rep( fixed_point<int16_t, 0>{99});
    CQ.at<int16_t>(7, 7) = to_rep( fixed_point<int16_t, 0>{99});

    return CQ;
}

#define PRINT_MAT(mat, msg) std::cout<< std::endl <<msg <<":" <<std::endl <<mat <<std::endl;

cv::Mat BC12::getYQuantizationMatix(){
    cv::Mat D_t, quantizationMatrix = cv::Mat::zeros(8,8, CV_16S);
    
    transpose(this->getD().diag(), D_t);
    matrix_mult<int16_t>(this->getD().diag(), D_t, quantizationMatrix, CV_16S);
    for(int i=0; i<8;i++){
        for(int j=0;j<8;j++){
            int16_t q_val = quantizationMatrix.at<int16_t>(i,j); 

            //rounding
            if(q_val & 0b0000000100000000){
                q_val = q_val >> 8;
                q_val &= 0x00FF;
                q_val++;
            } else {
                q_val = q_val >> 8;
                q_val &= 0x00FF;
            }
            quantizationMatrix.at<int16_t>(i,j) = q_val;
        }
    }

    quantizationMatrix /= this->getQ();

    return quantizationMatrix;

}

cv::Mat BC12::getCbQuantizationMatix(){
    cv::Mat D_t, quantizationMatrix = cv::Mat::zeros(8,8, CV_16S);
    
    transpose(this->getD().diag(), D_t);
    matrix_mult<int16_t>(this->getD().diag(), D_t, quantizationMatrix, CV_16S);

    for(int i=0; i<8;i++){
        for(int j=0;j<8;j++){
            int16_t q_val = quantizationMatrix.at<int16_t>(i,j); 

            //rounding
            if(q_val & 0b0000000100000000){
                q_val = q_val >> 8;
                q_val &= 0x00FF;
                q_val++;
            } else {
                q_val = q_val >> 8;
                q_val &= 0x00FF;
            }
            quantizationMatrix.at<int16_t>(i,j) = q_val;
        }
    }

    quantizationMatrix /= this->getCQ();
    return quantizationMatrix;
}

cv::Mat BC12::getCrQuantizationMatix(){
    cv::Mat D_t, quantizationMatrix = cv::Mat::zeros(8,8, CV_16S);
    
    transpose(this->getD().diag(), D_t);
    matrix_mult<int16_t>(this->getD().diag(), D_t, quantizationMatrix, CV_16S);

    for(int i=0; i<8;i++){
        for(int j=0;j<8;j++){
            int16_t q_val = quantizationMatrix.at<int16_t>(i,j); 

            //rounding
            if(q_val & 0b0000000100000000){
                q_val = q_val >> 8;
                q_val &= 0x00FF;
                q_val++;
            } else {
                q_val = q_val >> 8;
                q_val &= 0x00FF;
            }
            quantizationMatrix.at<int16_t>(i,j) = q_val;
        }
    }

    quantizationMatrix /= this->getCQ();
    return quantizationMatrix;
}

cv::Mat BC12::getYDequantizationMatix(){
    return this->getQ();
}

cv::Mat BC12::getCrDequantizationMatix(){
    return this->getCQ();
}

cv::Mat BC12::getCbDequantizationMatix(){
    return this->getCQ();
}

void BC12::dct1d(const cv::Mat& input, cv::Mat& output){
    /* This function implements the 1D transformation of the algorithm BC12:

       output = T * input  

       where:
            * T is the trannsformation matrix, of size 8x8
            * input is the input column vector to transform, ofize 8x1 
            * output is the transformated input vector, of size 8x1 
    */

    assert(( (input.rows == 8) && (input.cols==1) ) && "Column vector of size 8x1 is needed for 1D-DCT.");
    assert( (input.type() == CV_16S) && "Unable to compute AxDCT-1D: element of type CV_16S required.");

    /***** DIRECT TRANSFORMATION X=T*x --- 24 adds *****/

    // int16_t x0 = input.at<int16_t>(0,0);
    // int16_t x1 = input.at<int16_t>(1,0);
    // int16_t x2 = input.at<int16_t>(2,0);
    // int16_t x3 = input.at<int16_t>(3,0);
    // int16_t x4 = input.at<int16_t>(4,0);
    // int16_t x5 = input.at<int16_t>(5,0);
    // int16_t x6 = input.at<int16_t>(6,0);
    // int16_t x7 = input.at<int16_t>(7,0);

    // output.at<int16_t>(0,0) = x0 + x1 + x2 + x3 + x4 + x5 + x6 + x7;
    // output.at<int16_t>(1,0) = x0 + (-x7);
    // output.at<int16_t>(2,0) = x0 + (-x3) + (-x4) + x7;
    // output.at<int16_t>(3,0) = x5 + (-x2);
    // output.at<int16_t>(4,0) = x0 + (-x1) + (-x2) + x3 + x4 + (-x5) + (-x6) + x7;
    // output.at<int16_t>(5,0) = x6 + (-x1);
    // output.at<int16_t>(6,0) = x2 + (-x1) + x5 + (-x6);
    // output.at<int16_t>(7,0) = x4 + (-x3);



    /****** Transformation using matrix factorization X = P*A3*A2*A1 * x --- 14 adds + 4 sign inversions ******/
    int16_t x0a = input.at<int16_t>(0,0);
    int16_t x1a = input.at<int16_t>(1,0);
    int16_t x2a = input.at<int16_t>(2,0);
    int16_t x3a = input.at<int16_t>(3,0);
    int16_t x4a = input.at<int16_t>(4,0);
    int16_t x5a = input.at<int16_t>(5,0);
    int16_t x6a = input.at<int16_t>(6,0);
    int16_t x7a = input.at<int16_t>(7,0);

    int16_t x0b = x0a + x7a;
    int16_t x1b = x1a + x6a;
    int16_t x2b = x2a + x5a;
    int16_t x3b = x3a + x4a;
    int16_t x4b = x3a + (-x4a);
    int16_t x5b = x2a + (-x5a);
    int16_t x6b = x1a + (-x6a);
    int16_t x7b = x0a + (-x7a);

    int16_t x0c = x0b + x3b;
    int16_t x1c = x1b + x2b;
    int16_t x2c = x1b + (-x2b);
    int16_t x3c = x0b + (-x3b);
    int16_t x4c = -x4b;
    int16_t x5c = -x5b;
    int16_t x6c = -x6b;
    int16_t x7c = x7b;

    int16_t x0d = x0c + x1c;
    int16_t x1d = x0c + (-x1c);
    int16_t x2d = -x2c;
    int16_t x3d = x3c;
    int16_t x4d = x4c;
    int16_t x5d = x5c;
    int16_t x6d = x6c;
    int16_t x7d = x7c;

    output.at<int16_t>(0,0) = x0d;
    output.at<int16_t>(1,0) = x7d;
    output.at<int16_t>(2,0) = x3d;
    output.at<int16_t>(3,0) = x5d;
    output.at<int16_t>(4,0) = x1d;
    output.at<int16_t>(5,0) = x6d;
    output.at<int16_t>(6,0) = x2d;
    output.at<int16_t>(7,0) = x4d;
}