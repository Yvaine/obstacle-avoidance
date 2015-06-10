//
// Created by paul on 01/06/15.
//

#include "HorizonMedianRescaler.h"

HorizonMedianRescaler::HorizonMedianRescaler(int bufferSize) : valueSmoother(bufferSize) {

}

void HorizonMedianRescaler::scale16bitTo8bit(const Image16bit &src, const Horizon &horizon, Image8bit &dst) {
    HorizonImageHistogram histogram(src, horizon);
    int localPeakValue = histogram.getMode();
    int bufferedPeakValue = valueSmoother.calculateSmoothedValue(localPeakValue);

    int newMinPixelValue, newMaxPixelValue;
    histogram.find8bitWindow(bufferedPeakValue, newMinPixelValue, newMaxPixelValue);

    Rescaling::rescale8bitWindow(src, dst, newMinPixelValue);

}
