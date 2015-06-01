//
// Created by paul on 26/05/15.
//

#ifndef OBSTACLE_AVOIDANCE_IMAGEHISTOGRAMTEST_H
#define OBSTACLE_AVOIDANCE_IMAGEHISTOGRAMTEST_H

#include <iostream>
#include <gtest/gtest.h>
#include <geometry/Horizon.h>

#include <opencv2/core/core.hpp>
#include <imageProc/core/HorizonImageHistogram.h>

class ImageHistogramTest : public ::testing::Test {

protected:
    static cv::Mat makeThreeEvenPixelValues(const int &pixelValue0,
                                            const int &pixelValue1,
                                            const int &pixelValue2);
};


#endif //OBSTACLE_AVOIDANCE_IMAGEHISTOGRAMTEST_H
