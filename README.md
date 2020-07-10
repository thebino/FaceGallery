# FaceGallery

FaceGallery is an open source application to manage images within faces.

Clustering images by faces is a common thing in our daily lives. On Smartphones,
social media platforms even on CCTV.

[![Sample](https://via.placeholder.com/350)](http://creativecommons.org/licenses/by-nc-nd/3.0/)

## Table of contents

* [Privacy](#privacy)
* [Getting started](#getting-started)
  * [Prerequisites](#prerequisites)
  * [Installation](#installation)
* [Technical](#technical)
* [Contribution](#contribution)
* [License](#license)


## Privacy
**None of your data eg. faces, names or images are used outside your computer or network.**

As distinguished from many other applications, this app focuses on privacy.


## Getting started
To setting up this project locally, you may need to install some libraries first.

1. Download the [latest release](https://github.com/thebino/FaceGallery/releases)
2. Run the application


### Prerequisites
1. Download and install [opencv](https://opencv.org/releases/).
2. [tensorflow C API](https://www.tensorflow.org/install/lang_c) will be downloaded automatically by cmake.


### Installation
For mac or linux builds
```shell
> cmake -DCMAKE_PREFIX_PATH=/path/to/qt-static . -B build
> cmake --build build --config Release
```

For windows builds
```shell
cmake -G "Visual Studio 15 2017" -A x64 . -B build
cmake --build build --config Release
```


## Technical
Facedetection is archived by the *MTCNN* <sup>1</sup> method.
Described 2016 in the Paper 
    [Joint Face Detection and Alignment Using Multitask Cascaded Convolutional Networks](https://arxiv.org/abs/1604.02878) 
by [Kaipeng Zhang](http://kpzhang93.github.io/)

The implementation was extracted from this [MTCNN project](https://github.com/OAID/FaceDetection)

<sup>1</sup> Multi-Task Cascaded Convolutional Neural Network


## Contribution
Any Contributions to this project are greatly appreciated.

1. Fork it (<https://github.com/thebino/FaceApplication>)
2. Create your feature branch (`git checkout -b Feature/fooBar`)
3. Commit your changes (`git commit -am 'Add detailed description'`)
4. Push to the branch (`git push origin Feature/fooBar`)
5. Create a new Pull Request


## License
Stürmer Benjamin – [@BenjaminStrmer](https://twitter.com/BenjaminStrmer) – webmaster@stuermer-benjamin.de

<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br />This work is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.


