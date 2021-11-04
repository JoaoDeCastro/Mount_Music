#pragma once

/**
 * @file Note.h
 *
 * @brief Class to simulate a music note and recognize it on a 3d plane video
 *
 * @ingroup 
 *
 * @author Joao DeCastro
 * Contact: decastro008@wcsu.edu
 *
 */



#include <iostream>
#include<string>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/core/mat.hpp>

/**
 * Implementation of a music note detection project
 *
 * This class will represent a music note, and it will operate different functions.
 * The model will be trained to recognize the pieces in a 3D video plane
 *
 */
class Note
{
	
	std::string classifierModel;
	cv::Mat frameGray;
	std::vector<cv::Rect> notes;
	cv::Mat noteROI;
	cv::CascadeClassifier noteCascade;

	int const D_LOW = 185;
	int const D_HIGH = 198;

	int const M_LOW = 300;
	int const M_HIGH = 313;

	int const G_LOW = 260;
	int const G_HIGH = 278;

	int const F_LOW = 148;
	int const F_HIGH = 155;

	int const B_LOW = 215;
	int const B_HIGH = 235;

public:

	/**
	 * function to load the file of the cascade model
	 * @param the path of the model file
	 */
	void loadModel(std::string model);

	/**
	 * Detects the objects, and draw circles when object is found it uses the model
	 * @param frame the video object to find the object
	 */
	void noteDetection(cv::Mat frame);

	/**
	 * Draw a rectangle to the screen where it sets the boundary when to put the music notes
	 * on the screen
	 *@param frame the video object in use
	 */
	cv::Mat drawRectangle(cv::Mat frame);

	/**
	 * function to detect edges on an image
	 * @param frame video to be used
	 *
	 */
	cv::Mat edgeDetection(cv::Mat frame);

	/**
	 * function to write the names of each notes when it is detected by the model
	 * @param the gray frame being in used be the detectNote function
	 *
	 */
	void writeNotes(size_t index, cv::Mat frame);
	
	/**
	 * function to lal an image to the model
	 * @param the directory of the image
	 */
	//cv::Mat showImage(std::string path);

	
};
