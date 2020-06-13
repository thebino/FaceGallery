# FaceGallery

FaceGallery is an open source application to manage images within included faces.

Clustering images by faces is a common thing in our daily lives. On Smartphones,
social media platforms even on CCTV.

#### Privacy
**None of your data eg. faces, names or images are used outside your computer or network.**

As distinguished from many other applications, this app focuses on privacy.

#### Contribution
Contributions to the codebase are welcome and we would love to hear back from your app experience.

#### Technical
Facedetection is archived by the *MTCNN* <sup>1</sup> method.
Described 2016 in the Paper 
    [Joint Face Detection and Alignment Using Multitask Cascaded Convolutional Networks](https://arxiv.org/abs/1604.02878) 
by [Kaipeng Zhang](http://kpzhang93.github.io/)

The implementation was extracted from this [MTCNN project](https://github.com/OAID/FaceDetection)

<sup>1</sup> Multi-Task Cascaded Convolutional Neural Network

## Table of contents

Setup:

  * <a href='#installation'>Installation</a><br>

Development:

  * <a href='#preparation'>Preparation</a><br>
  * <a href='#build'>Build</a><br>
  * <a href='https://github.com/thebino/FaceGallery/issues'>Known Issues</a><br>

License:
  * <a href='#license'>License</a><br>


## Installation
1. Download the [latest release](https://github.com/thebino/FaceGallery/releases)
2. Run the application

## Development
#### Preparation
1. Download and install [opencv](https://opencv.org/releases/).
2. [tensorflow C API](https://www.tensorflow.org/install/lang_c) will be downloaded automatically by cmake.

#### Build
For mac or linux builds
```shell script
> cmake . -B build
> cmake --build build
```

For windows builds
```shell script
cmake -G "Visual Studio 15 2017" -A x64 ..
cmake --build . --config Debug -b build
```

#### Flow
This app is separated in multiple steps:

1. Face Detection
Locating faces on the images
2. Face Recognition
Compare faces with alreday known ones
3. Facial expression
Descripe the persons mood
4. Object detection
Tag the surroundings


## License
<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.
