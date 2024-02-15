#include "opencv2/highgui/highgui.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    VideoCapture cap("C:/renksizvideo.mp4"); // open the video file for reading

    if (!cap.isOpened())  // if not success, exit program
    {
        cout << "Cannot open the video file" << endl;
        return -1;
    }

    double fps = cap.get(CAP_PROP_FPS); //get the frames per seconds of the video
    cout << "Frame per seconds : " << fps << endl;

    namedWindow("MyVideo", WINDOW_AUTOSIZE); //create a window called "MyVideo"

    while (1)
    {
        Mat frame;
        Mat graymat;

        bool bSuccess = cap.read(frame); // read a new frame from video

        if (!bSuccess) //if not success, break loop
        {
            cout << "Cannot read the frame from video file" << endl;
            break;
        }

        cvtColor(frame, graymat, COLOR_BGR2HSV); // Convert frame to grayscale

        imshow("MyVideo", frame); //show the original frame in "MyVideo" window
        imshow("MyVideobnw", graymat); //show the grayscale frame in "MyVideobnw" window

        if (waitKey(30) == 27) //wait for 'esc' key press for 30 ms. If 'esc' key is pressed, break loop
        {
            cout << "esc key is pressed by user" << endl;
            break;
        }
    }

    return 0;
}
// renksiz vidioyu renkli hale getirir
