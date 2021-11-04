#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include <opencv2/videoio.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

#include "Note.h"


int main()
{

	Note note;
	note.loadModel("C:/C++_Tests/OpenCV_1/OpenCV_1/cascade_notes/cascade.xml");
	cv::Mat frame;



	cv::VideoCapture capture(0);
	if (!capture.isOpened())
	{
		std::cout << "Could not open video";
		return -1;
	}
	
	
	
	while (capture.read(frame))
	{
		if (frame.empty())
		{
			std::cout << "No frame captured from camera";
			break;
		}

		note.noteDetection(frame);
		frame = note.drawRectangle(frame);
		
		imshow("Mount your music", frame);
		if (cv::waitKey(10) == 'q')

		{
			break;
		}

	}


	

	

	return 0;
}



