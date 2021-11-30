# expert-octo-memory

# yey, painter 

#Installation 
    git clone --recursive https://github.com/piotr233/expert-octo-memory

I use mvsc 2019 compiler, I don't know if it works with anything else and idc to be honest


## Debug
Next copy those three dll's 
    
    cmake-build-debug/sfml/lib/sfml-graphics-d-2.dll

    cmake-build-debug/sfml/lib/sfml-window-d-2.dll

    cmake-build-debug/sfml/lib/sfml-system-d-2.dll

their destination: 
    
      cmake-build-debug/

## Release
Next copy those three dll's


    /cmake-build-release/sfml/lib/sfml-graphics-2.dll

    /cmake-build-release/sfml/lib/sfml-window-2.dll

    /cmake-build-release/sfml/lib/sfml-system-2.dll

their destination:

      cmake-build-release/

that's it enjoy!

# Controls 

## first set up canvas size 

In [number_painter.cpp](number_painter.cpp)  
```c++
 MazePainter maze(800, 800, 10, 10);

```
last two numbers specify canvas width and height respectively



