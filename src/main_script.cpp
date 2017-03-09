#include "flycapture/FlyCapture2.h"
#include "pointgreyStream.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

using namespace FlyCapture2;

int main()
{
    cv::Mat curr_image_;
    PointgreyStream *mypointgrey = new PointgreyStream();
    mypointgrey->pointgreyInit(7,0.5,20.0);

    char key = 0;

    while(key!='q'){
      mypointgrey->getData();
     curr_image_=  mypointgrey->curr_image;
     cv::imshow("image", curr_image_);
     key=cv::waitKey(1);
    }

    return 0;
}
