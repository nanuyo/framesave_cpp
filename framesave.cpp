#include <opencv2/opencv.hpp>

int main()
{
    // Set the desired resolution
    const int width = 1920;
    const int height = 1080;

    // Open the default webcam
    cv::VideoCapture cap(0);

    // Set the webcam resolution
    cap.set(cv::CAP_PROP_FRAME_WIDTH, width);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT, height);

    // Set the number of frames to save
    const int numFrames = 30;

    // Create a buffer to store frames
    std::vector<cv::Mat> buffer;
    buffer.reserve(numFrames);

    // Loop to continuously save frames
    while (buffer.size() < numFrames)
    {
        // Capture frame-by-frame
        cv::Mat frame;
        cap >> frame;

        // Add the frame to the buffer
        buffer.push_back(frame);

        // Display the current frame
     //   cv::imshow("Frame", frame);

        // Break the loop if 'q' is pressed
       // if (cv::waitKey(1) == 'q')
         //   break;
    }

    // Save the frames from the buffer
    for (int i = 0; i < buffer.size(); ++i)
    {
        std::string fileName = "frame" + std::to_string(i+1) + ".jpg";
        cv::imwrite(fileName, buffer[i]);
    }

    // Release the webcam and close the window
    cap.release();
    cv::destroyAllWindows();

    return 0;
}
