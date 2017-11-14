## beginner_tutorials breif
"First Publisher/Subscriber" ROS package. Talker publishes the string "God gives you shoes, fits you." and listener subscribes that message. 

Add a service in the talker node which can change the output string to whatever you want. Add a change_output_string_client node to offer an alternative method to call the added service in the talker node.

## Build
```
$ git clone --recursive https://github.com/SonamYeshe/beginner_tutorials.git
$ cd <path to catkin_ws>
$ git checkout Week10_HW
$ catkin_make
```

## Run
run the ros service first.
```
$ roscore
```

1. run all the command line seperately in different terminals:

open a new terminal and 
```
$ rosrun beginner_tutorials talker 
```
open a new terminal and 
```
$ rosrun beginner_tutorials listener
```

2. Using launch file to call all the nodes in the same terminal, and see the results in the rqt_console(note that the console should be opened in another terminal):

```
$ roslaunch beginner_tutorials talkerdynamic.launch
$ rosrun rqt_console rqt_console
```

Now you have two methods to change the output string. First, open a new terminal and
```
$ rosservice call /change_output_string "new_string: '<any string you prefer>'"
```
Or, in a new terminal,
```
$ rosrun beginner_tutorials change_output_string_client <any string you prefer>
```
## cpplint
```
$ cd <path to parent folder of the beginner_tutorials>
$ wget https://raw.githubusercontent.com/google/styleguide/gh-pages/cpplint/cpplint.py
$ chmod +x cpplint.py
$ cd <path to beginner_tutorials>
$ ../cpplint.py $( find . -name \*.hpp -or -name \*.cpp | grep -vE -e "^./build/" -e "^./vendor/" -e "^./docs/" -e "^./results" )
```

## cppcheck
```
$ cd <path to beginner_tutorials>
$ cppcheck --enable=all --std=c++11 --includes-file=cppcheck.txt --check-config --suppress=missingIncludeSystem $( find . -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/" )
```


## Dependency

1. ROS kinetic

##ss
catkin_make tests
catkin_make test
catkin_make run_tests_beginner_tutorials
rostest beginner_tutorials change_output_string_clients.launch
