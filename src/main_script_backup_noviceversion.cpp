#include "flycapture/FlyCapture2.h"
#include "pointgreyStream.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include <iostream>

using namespace FlyCapture2;

int main()
{
    FlyCapture2::Error error;
    FlyCapture2::Camera camera;
    FlyCapture2::CameraInfo camInfo;
/// Connect the camera
    error = camera.Connect( 0 );
    if ( error != PGRERROR_OK )
    {
        std::cout << "Failed to connect to camera" << std::endl;
        return false;
    }

    // Get the camera info and print it out
    error = camera.GetCameraInfo( &camInfo );
    if ( error != PGRERROR_OK )
    {
        std::cout << "Failed to get camera info from camera" << std::endl;
        return false;
    }
    std::cout << camInfo.vendorName << " "
              << camInfo.modelName << " "
              << camInfo.serialNumber << std::endl;

    error = camera.StartCapture();
    if ( error == PGRERROR_ISOCH_BANDWIDTH_EXCEEDED )
    {
        std::cout << "Bandwidth exceeded" << std::endl;
        return false;
    }
    else if ( error != PGRERROR_OK )
    {
        std::cout << "Failed to start image capture" << std::endl;
        return false;
    }
    //Declare a Property struct.

    FlyCapture2::Property prop;
//Define the property to adjust.
prop.type = SHUTTER;
//Ensure the property is on.
prop.onOff = true;
//Ensure auto-adjust mode is off.
prop.autoManualMode = false;
//Ensure the property is set up to use absolute value control.
prop.absControl = true;
//Set the absolute value of shutter to 20 ms.
prop.absValue = 10;
error = camera.SetProperty( &prop );

//Set the property.
prop.type = BRIGHTNESS;
prop.absControl = true;
prop.absValue =0.5;


error = camera.SetProperty( &prop );

prop.type = GAIN;
prop.autoManualMode = false;
prop.absControl = true;
prop.absValue=20.0;
error = camera.SetProperty( &prop );

camera.SetVideoModeAndFrameRate( VIDEOMODE_640x480Y8 , FRAMERATE_30);
    // capture loop
    char key = 0;
    while(key != 'q')
    {
        // Get the image
        Image rawImage;
        Error error = camera.RetrieveBuffer( &rawImage );
        if ( error != PGRERROR_OK )
        {
                std::cout << "capture error" << std::endl;
                continue;
        }

        // convert to rgb
        Image rgbImage;
        rawImage.Convert( FlyCapture2::PIXEL_FORMAT_BGR, &rgbImage );

        // convert to OpenCV Mat
        unsigned int rowBytes = (double)rgbImage.GetReceivedDataSize()/(double)rgbImage.GetRows();
        cv::Mat image = cv::Mat(rgbImage.GetRows(), rgbImage.GetCols(), CV_8UC3, rgbImage.GetData(),rowBytes);

        cv::imshow("image", image);
        key = cv::waitKey(1);
    }

    error = camera.StopCapture();
    if ( error != PGRERROR_OK )
    {
        // This may fail when the camera was removed, so don't show
        // an error message
    }

    camera.Disconnect();

    return 0;
}
