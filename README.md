## beginner_tutorials breif
"First Publisher/Subscriber" ROS package. Talker publishes the string "God gives you shoes, fits you." and listener subscribes that message.

## Build
```
$ git clone --recursive https://github.com/SonamYeshe/ beginner_tutorials.git
$ cd <path to catkin_ws/src>
$ cd ..
$ catkin_make
```

## Run
```
$ roscore
```
open a new terminal and 
```
$ rosrun beginner_tutorials talker 
```
open a new terminal and 
```
$ rosrun beginner_tutorials listener
```
## cpplint
```
$ cd <path to parent folder of the beginner_tutorials>
$ wget https://raw.githubusercontent.com/google/styleguide/gh-pages/cpplint/cpplint.py
$ chmod +x cpplint.py
$ cd <path to beginner_tutorials>
$ ../cpplint $( find . -name \*.hpp -or -name \*.cpp | grep -vE -e "^./build/" -e "^./vendor/" -e "^./docs/" -e "^./results" )
```

## cppcheck
```
$ cd <path to beginner_tutorials>
$ cppcheck --enable=all --std=c++11 --includes-file=cppcheck.txt --check-config --suppress=missingIncludeSystem $( find . -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/" )
```

## Dependency

ROS kinetic

## rosservice
rosservice call /change_output_string "new_string: 'yes'"
rosrun beginner_tutorials change_output_string_client sssdadsadsadas

roslaunch beginner_tutorials talkdynamic.launch new_string:=asdsadadsa
