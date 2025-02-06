Smiley Finder
========================================

Analyse a text block covering the following condition:
1. Computes the start position in the text of all the smileys. Smileys are defined as the character colon plus an optional dash character and a bracket. e.g: :-] or :(
2. Computes the top 10 used words (excluding smileys)
3. Supports the following output formats: Console, Simple text file, XML file. Any combination of these backends can be specified through command line arguments (Console only, Text file only, Text file + XML file, Text file + XML + console, etc). Each output should contain all the above information (1 and 2 from this list).

Additional information:
· UTF8 encoding can be assumed
· Lines are separated by '\n'
· Words are separated by whitespace
· There are some edge cases that should be considered:
· Whitespace can be '\t', multiple consecutive whitespace characters, etc
· The text can consist of a single line without '\n' at the end. The line count should be 1 in such a case.

# Quick start

## Build Application

* To build application
```
cd build
cmake ..
make
```

* To run application
```
./src/smileyfinder
```

***Default output format is console.***

To enable other format use as following

```
-c, --console : To enable the output in console
-t, --text    : To enable the output in text file
-x, --xml     : To enable the output in xml file
```

For example to enable test and xml format
```
./src/smileyfinder -t -x
```

## Unit Test
* To build unit test
```
cd build
cmake -DENABLE_UT_BUILD=ON ..
make
```

* To run unit test

```
./tests/smileyfinder_gtest
```

## Code Coverage
Already a generated coverage report located in ``` reports/ccov ```.

In case to run again, follow below steps


* First, Install lcov on local machine. using,  
```
sudo apt-get update -y
sudo apt-get install -y lcov
```
* Now, The code coverage can be performed by executing the ``` run_code_coverage.sh ``` script from the root directory,
```
./run_code_coverage.sh
```
* After, the successful execution of the script, the outputs are generated in ``` reports/ccov ``` directory.  
* Open the ``` html/index.html ```, it will display the coverage output in a graphical view.
* Also find the text view of the coverage report in ``` reports/ccov/report.txt ```
