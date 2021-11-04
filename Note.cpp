

#include "Note.h"
#include <iostream>
#include<string>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/core/mat.hpp>

void Note::loadModel(std::string model)
{
	classifierModel = model;

	if (!noteCascade.load(classifierModel))
	{
		std::cout << "File was not load";
		
	}

	std::cout << "File was loaded" << std::endl;


}

void Note::noteDetection(cv::Mat frame)
{
	// function to create a gray scale image
	cv::cvtColor(frame, frameGray, cv::COLOR_BGR2GRAY);

	// function detects the objects in the image an return a vector of rectangles
	noteCascade.detectMultiScale(frameGray, notes);

	for (size_t i = 0; i < notes.size(); i++)
	{
		cv::Point center(notes[i].x + notes[i].width / 2, notes[i].y + notes[i].height / 2);
		ellipse(frame, center, cv::Size(notes[i].width / 2, notes[i].height / 2), 0, 0, 360, cv::Scalar(0, 0, 255), 3);

		//need this?
		noteROI = frameGray(notes[i]);

		//call function to write notes names
		writeNotes(i, frame);
	}
}

cv::Mat Note::drawRectangle(cv::Mat frame)
{
	cv::Point x1(130, 150);
	cv::Point y2(550, 340);

	rectangle(frame, x1, y2, cv::Scalar(0, 255, 0), 3);

	return frame;
}

cv::Mat Note::edgeDetection(cv::Mat frame)
{
	int low = 50;
	int high = 150;

	cv::Mat edge;
	cv::Canny(frame, frame, low, high);

	return frame;
}

void Note::writeNotes(size_t index, cv::Mat frame)
{
	if (notes[index].y >= D_LOW && notes[index].y <= D_HIGH)
	{
		putText(frame, "D", cv::Point(notes[index].x, notes[index].y), cv::FONT_HERSHEY_COMPLEX, 1.0, CV_RGB(0, 0, 0), 3);
	}

	else if (notes[index].y >= M_LOW && notes[index].y <= M_HIGH)
	{
		putText(frame, "M", cv::Point(notes[index].x, notes[index].y), cv::FONT_HERSHEY_COMPLEX, 1.0, CV_RGB(0, 0, 0), 3);
	}

	else if (notes[index].y >= G_LOW && notes[index].y <= G_HIGH)
	{
		putText(frame, "G", cv::Point(notes[index].x, notes[index].y), cv::FONT_HERSHEY_COMPLEX, 1.0, CV_RGB(0, 0, 0), 3);
	}

	else if (notes[index].y >= F_LOW && notes[index].y <= F_HIGH)
	{
		putText(frame, "F", cv::Point(notes[index].x, notes[index].y), cv::FONT_HERSHEY_COMPLEX, 1.0, CV_RGB(0, 0, 0), 3);
	}

	else if (notes[index].y >= B_LOW && notes[index].y <= B_HIGH)
	{
		putText(frame, "B", cv::Point(notes[index].x, notes[index].y), cv::FONT_HERSHEY_COMPLEX, 1.0, CV_RGB(0, 0, 0), 3);
	}
}
