#include <stdio.h>
#include <string.h>
#include <opencv2/opencv.hpp>

using namespace cv;

void usage()
{
	printf("--Usage FrameCutter via Video--");
}

bool captureFrames(char* filename)
{
	bool ret = false;
	std::string outfilename;

	VideoCapture capture(filename);
	int max_frame = (int)capture.get(CV_CAP_PROP_FRAME_COUNT);
	
	for (int i = 0; i < max_frame; i++)
	{
		Mat frameImg;
		capture >> frameImg;

		outfilename = "";
		outfilename += filename;
		outfilename += "_";
		outfilename += std::to_string(i);
		outfilename += ".jpg";

		imwrite(outfilename, frameImg);
	}

	return ret;
}


int main(int argc, char** argv)
{
	if (2 < argc)
	{
		printf("Please check command line arguments\n");
		return;
	}
		
	captureFrames(argv[1]);

	return 0;
}
