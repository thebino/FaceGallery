/**
 *  Face Gallery
 *
 *
 */

#include <tensorflow/c/c_api.h>
#include "tensorflow_mtcnn.hpp"
#include "utils.hpp"
#include <opencv2/opencv.hpp>
#include <iterator>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    const char *img_path = "resources/beatles.jpg";
    std::cout << "TensorFlow Version: " << TF_Version() << std::endl;

    // read image
    cv::Mat frame = cv::imread(img_path);

    if (frame.data) {
        auto mtcnn1 = new tf_mtcnn();
        mtcnn1->load_model("resources");

        std::vector<face_box> face_info;
        mtcnn1->detect(frame, face_info);

        cout << "detected faces: " << face_info.size() << endl;

        for(unsigned int i = 0; i < face_info.size(); i++) {
            face_box& box = face_info[i];

            printf("face %d: x0,y0 %2.5f %2.5f  x1,y1 %2.5f  %2.5f conf: %2.5f\n",
                i, box.x0,box.y0,box.x1,box.y1, box.score);
            printf("landmark: ");

            for(unsigned int j = 0; j < 5; j++) {
                printf(" (%2.5f %2.5f)",box.landmark.x[j], box.landmark.y[j]);
            }

            printf("\n");

            // draw face box
            cv::rectangle(frame, cv::Point(box.x0, box.y0), cv::Point(box.x1, box.y1), cv::Scalar(255, 0, 255), 1);

            // draw landmarks
            for (int l = 0; l < 5; l++) {
                cv::circle(frame, cv::Point(box.landmark.x[l], box.landmark.y[l]), 1, cv::Scalar(255, 0, 255), 2);
            }
        }

        // write result into file
        cv::imwrite("output.jpg", frame);

        // Display image.
        cv::imshow("Result", frame);
        
        // wait for key stroke to exit
        cv::waitKey(0);
    } else {
        cout << "Could not read image" << endl;
    }
}
