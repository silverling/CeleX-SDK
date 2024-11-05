#ifndef VIDEOSTREAM_H
#define VIDEOSTREAM_H
#include <QApplication>
#include <QDebug>
#include <fstream>
#include <iostream>
#include <stdio.h>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavdevice/avdevice.h>
#include <libavfilter/avfilter.h>
#include <libavformat/avformat.h>
#include <libswresample/swresample.h>
}

#define DATASIZE 800 * 1280
#define FPS 30
using namespace std;

class VideoStream {
  public:
    VideoStream();
    ~VideoStream();
    bool avWriterInit(const char *out_filename);
    void avWtiter(char *buffer);
    bool avWriterRelease();

  private:
    AVStream *addVideoStream(AVFormatContext *oc, enum AVCodecID codec_id);

  private:
    AVFormatContext *ofmt_ctx;
    AVPacket pkt;
    int frameCount;
    unsigned char *mydata;
};

#endif // VIDEOSTREAM_H
