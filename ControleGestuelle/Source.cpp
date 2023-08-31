#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <Windows.h>

#include <iostream>

using namespace std;
using namespace cv;

int main()
{
	Mat image;
	VideoCapture cap;
	cap.set(CAP_PROP_FRAME_WIDTH, 640);
	cap.set(CAP_PROP_FRAME_HEIGHT, 480);
	cap.open(0);

	while (1) {
		try {

			// Si la touche x est appuyé, sortir du programme
			if (GetAsyncKeyState('X')) {
				break;
			}

			cap >> image;

			Mat hsv;
			cvtColor(image, hsv, COLOR_BGR2HSV);

			Mat1b masqueVert;
			inRange(hsv, Scalar(66, 40, 40), Scalar(86, 255, 255), masqueVert);

			// Contours du masque vert
			vector<vector<Point>> contours;
			findContours(masqueVert, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

			// Si il y a un contour
			if (contours.size() > 0) {
				// Trouver le plus grand contour
				int max = 0;
				for (int i = 1; i < contours.size(); i++) {
					if (contourArea(contours[i]) > contourArea(contours[max])) {
						max = i;
					}
				}

				// Trouver le centre du contour
				Moments m = moments(contours[max]);
				Point centre(m.m10 / m.m00, m.m01 / m.m00);

				// Affichage
				circle(image, centre, 5, Scalar(0, 0, 255), -1);
				circle(masqueVert, centre, 5, Scalar(0, 0, 255), -1);
				drawContours(image, contours, max, Scalar(0, 255, 0), 2);

				SetCursorPos(centre.x, centre.y);
			}

			imshow("image", image);
			imshow("masqueVert", masqueVert);
			waitKey(33);
		}
		catch (Exception& e) {
			cout << e.what() << endl;
		}
	}
	return 0;
}