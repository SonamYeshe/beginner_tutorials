## beginner_tutorials breif
"First Publisher/Subscriber" ROS package. Talker publishes the string "God gives you shoes, fits you." and listener subscribes that message.

## Build
```
git clone --recursive https://github.com/SonamYeshe/beginner_tutorials.git
cd <path to catkin_ws/src>
cd ..
catkin_make
```

## Run
$ roscore
open a new terminal and $ rosrun beginner_tutorials talker 
open a new terminal and $ rosrun beginner_tutorials listener

## cpplint
$ cd <path to parent folder of the catkin_ws>
$ wget https://raw.githubusercontent.com/google/styleguide/gh-pages/cpplint/cpplint.py
$ chmod +x cpplint.py
$ cd <path to catkin_ws>
$ ../cpplint.py --extensions=h,hpp,cpp $( find . -name *.h -or -name *.hpp -or -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/" )

## cppcheck
$ cd <path to catkin_ws>
$ cppcheck --enable=all --std=c++11 -I include/ --check-config --suppress=missingIncludeSystem $( find . -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/" )


