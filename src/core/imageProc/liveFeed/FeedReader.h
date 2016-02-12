//
// Created by denis on 06/02/16.
//

#ifndef OBSTACLE_DETECTION_LIVEFEEDERRECORD_H
#define OBSTACLE_DETECTION_LIVEFEEDERRECORD_H


class FeedReader {
public:
    FeedReader(bool shouldRecord, ImageStream *stream) : shouldRecord(shouldRecord), stream(stream) { }

    virtual void record();
protected:
    virtual void startRecording();
    virtual void stopRecording();
    virtual void beforeCapture();
    virtual void onImageRead(Image16bit image);


public:

    void setStream(ImageStream *stream) {
        FeedReader::stream = stream;
    }

private:
    ImageStream *stream;

    bool shouldRecord;

};

#endif //OBSTACLE_DETECTION_LIVEFEEDERRECORD_H
