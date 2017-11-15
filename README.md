## beginner_tutorials Breif
"First Publisher/Subscriber" ROS package. Talker publishes the string "God gives you shoes, fits you." and listener subscribes that message. 

Add a service in the talker node which can change the output string to whatever you want. Add a change_output_string_client node to offer an alternative method to call the added service in the talker node.

Add a test to check the service in the talker node works perfectly.

Add rosbag command in the launch file.

## License
GNU General Public License v3.0

Permissions of this strong copyleft license are conditioned on making available complete source code of licensed works and modifications, which include larger works using a licensed work, under the same license. Copyright and license notices must be preserved. Contributors provide an express grant of patent rights.

## Disclaimer 
Jiawei Ge(SonamYeshe), hereby disclaims all copyright interest in the program `beginner_tutorials' (which makes passes at compilers) written by Jiawei Ge(SonamYeshe).

 (signature of Jiawei Ge), 14 November 2017

 Jiawei Ge

## Build
```
$ cd <path to catkin_ws/src>
$ git clone --recursive https://github.com/SonamYeshe/beginner_tutorials.git
$ git checkout Week11_HW
$ cd <path to catkin_ws>
$ catkin_make
$ catkin_make tests
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

## Tests
If you want to run the tests files,
```
$ cd <path to catkin_ws>
$ catkin_make test
```
Or in any directory,
```
$ rostest beginner_tutorials change_output_string_clients.launch
```

## Bagfiles
The bagfile is recorded by the command in the talkerdynamic.launchfile, the default setting is false. If you want to record again, just change the default in <arg name="record_all" default="false" /> to be "true".

To see the bag file info,
```
$ cd <path to catkin_ws/src/beginner_tutorials>
$ rosbag info results/record_all_topics_2017-11-14-22-45-16.bag
```

To play the bag file, close all the terminal except the roscore, first open listener node to receive message,
```
$ rosrun beginner_tutorials listener
```
Then,
```
$ rosbag play results/record_all_topics_2017-11-14-22-45-16.bag
```

## Cpplint
```
$ cd <path to parent folder of the beginner_tutorials>
$ wget https://raw.githubusercontent.com/google/styleguide/gh-pages/cpplint/cpplint.py
$ chmod +x cpplint.py
$ cd <path to beginner_tutorials>
$ ../cpplint.py $( find . -name \*.hpp -or -name \*.cpp | grep -vE -e "^./build/" -e "^./vendor/" -e "^./docs/" -e "^./results" )
```

## Cppcheck
```
$ cd <path to beginner_tutorials>
$ cppcheck --enable=all --std=c++11 --includes-file=cppcheck.txt --check-config --suppress=missingIncludeSystem $( find . -name *.cpp | grep -vE -e "^./build/" -e "^./vendor/" )
```


## Dependency

1. ROS kinetic

