#ifndef TEXTTHREAD
#define TEXTTHREAD

#include <ctime>
#include <stdint.h>
#include <string>

#include <QThread>
#include <QtCore>
#include <QPixmap>
#include <QImage>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

#define PACKET_SIZE 164
#define PACKET_SIZE_UINT16 (PACKET_SIZE/2)
#define PACKETS_PER_FRAME 60
#define FRAME_SIZE_UINT16 (PACKET_SIZE_UINT16*PACKETS_PER_FRAME)

class LeptonThread : public QThread
{
  Q_OBJECT;

public:
  LeptonThread();
  LeptonThread(std::string dir);
  ~LeptonThread();

  void run();

public slots:
  void performFFC();

signals:
  void updateText(QString);
  void updateImage(QImage);

private:

  QImage myImage;
  cv::Mat myMatrix;
  std::string output_dir;

  uint8_t result[PACKET_SIZE*PACKETS_PER_FRAME];
  uint16_t *frameBuffer;

};

#endif