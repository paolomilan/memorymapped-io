# Project 3: Simple device driver and practice memory mapped file I/O

The goal of this project is (1) to obtain a good understanding of device drivers and file systems, (2) to learn the uses of a Loadable Kernel Module, and (3) to understand the difference between regular file I/O and memory-mapped file I/O.

## Getting Started and Installation

On your machine, assuming you have git installed, run the following command to
clone a repository:

    $ git clone https://github.com/paolomilan/csce311-project3.git
Head into the directory and you should see two source files, io.cpp, and mmio.cpp.
Run the following command:

    $ make io | make mmio
You can then run either the io "app" or mmio "app" followed by the desired text file
name as follows: 

    $ ./io anna.txt     or      > $ ./mmio anna.txt
    
You should see the print out of the number of instances a character appears in the
input .txt file. You should also see the execution time of the program.

## Built With

* [Ubuntu 18.04 LTS](https://www.ubuntu.com/download/desktop) - Main environment used

## Versioning

Current version: v1.0.
For the versions available, see the [tags on this repository](https://github.com/csce311-project1/tags). 

## Authors

* **Paolo Milan** - [paolomilan](https://github.com/paolomilan)
* **Patrick Scott**  - [pkellz](https://github.com/pkellz)


See also the list of [contributors](https://github.com/pkellz/csce311-project1/graphs/contributors) who participated in this project.

## License

This project is licensed under the MIT License - see the [LICENSE.md](https://github.com/paolomilan/csce311-project3/blob/master/LICENSE) file for details

## Acknowledgments

* StackOverflow
* CSCE 311 course

