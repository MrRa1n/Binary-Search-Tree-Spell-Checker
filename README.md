# Spell Checker Application
Version: 1.0.0
Author: Toby Cook

The function of this program is to read in a text (.txt) file and check if it contains any spelling mistakes. It does this by comparing each word from the file to a dictionary file stored in a Binary Search Tree. If there are any incorrect words, they will be displayed in the command window accompanied by the total count of incorrectly spelled words.

- Read contents of specified text file
- Split into individual words
- Compare each word to dictionary using Binary Search Tree methods
- If word is not in dictionary, print to console

---

## How to Build from Source
#### Toolchain Used
The application has been built using the `Microsoft Visual C++ Build Tools 2017` including:
```
Microsoft (R) Program Maintenance Utility Version 14.12.25834.0
Microsoft (R) C/C++ Optimizing Compiler Version 19.12.25834 for x86
Microsoft (R) Incremental Linker Version 14.12.25834.0
```
A makefile has been provided with different options for creating the BinarySearchTree library, compiling the test file and compiling the spell check file. There are also options for running the spell check applications with different arguments.
#### Compiling the BinarySearchTree Library
This compiles the BinarySearchTree into a library to use with other files. This must be compiled first before other commands can be run.
```sh
C:\spellchecker> nmake create-lib
```
#### Compiling the Test File for the BinarySearchTree
The test file will check that the methods in the BinarySearchTree library work as supposed to. This command will link the `test.obj` and `BinarySearchTree.lib`
```sh
C:\spellchecker> nmake test-build
```
#### Compiling the Spellcheck File
This will compile the `spellcheck.cpp` file into an object file without generating an executable. It will link the spellcheck object file with the `BinarySearchTree.lib` we created above, cleaning the leftover object file afterwards.
```sh
C:\spellchecker> nmake spellcheck-build
```
---
## Running the Application
The makefile provided has a number of different tests that can be run on the application. This should simplify the test process and can also be run manually.

#### Run Spellcheck with No Input File
This is the most basic test as simply runs the spellcheck application with no text file as an argument.
```sh
C:\spellchecker> nmake spellcheck-none
```
#### Run Spellcheck with `single_words_test.txt`
Run the spellcheck application with the `single_words_test.txt` file as an argument.
```sh
C:\spellchecker> nmake spellcheck-single
```
#### Run Spellcheck with `sentences_test.txt`
Run the spellcheck application with the `sentences_test.txt` file as an argument.
```sh
C:\spellchecker> nmake spellcheck-sentence
```
#### Clean Up Junk Files
Clean up any unnecessary files creating during the build process.
```sh
C:\spellchecker> nmake clean
```
---
## Fully Automated Tests
The fully automated tests will create the BinarySearchTree library and link the files using one command.
#### BinarySearchTree Test
Create `BinarySearchTree.lib` and compile test application.
```sh
C:\spellchecker> nmake all-test-bst
```
#### Spellcheck Test with No Input File
Create `BinarySearchTree.lib`, compile spellcheck and run application with no input file.
```sh
C:\spellchecker> nmake all-test-none
```
#### Spellcheck Test with `single_words_test.txt`
Create `BinarySearchTree.lib`, compile spellcheck and run application with `single_words_test.txt` input file.
```sh
C:\spellchecker> nmake all-test-single
```
#### Spellcheck Test with `sentences_test.txt`
Create `BinarySearchTree.lib`, compile spellcheck and run application with `sentences_test.txt` input file.
```sh
C:\spellchecker> nmake all-test-sentence
```
---
## Manual Testing (Microsoft C++ Build Tools)
The files can be compiled manually for extra testing not outlined in the makefile.
### Compiling the BinarySearchTree Library
First we must create the object file for the BinarySearchTree.
```sh
cl /c BinarySearchTree.cpp
```
Now we can output the library file by typing the following command:
```sh
lib /OUT:BinarySearchTree.lib BinarySearchTree.obj
```
Finally, we should clean up the object file that was created. 
```sh
del BinarySearchTree.obj
```
### Compile and Run Test Application
First we must create the object file for the `test.cpp` file.
```sh
cl /c test.cpp
```
Next we will manually link the test object file with our `BinarySearchTree.lib`
```sh
link test.obj BinarySearchTree.lib
```
and clean up the leftover `test.obj` file.
```sh
del test.obj
```
Then to run the file, simply type:
```sh
test
```
### Compile and Run Spellcheck Application
First we must create the object file for the `spellcheck.cpp` file.
```sh
cl /c spellcheck.cpp
```
Next we will manually link the spellcheck object file with our `BinarySearchTree.lib`
```sh
link spellcheck.obj BinarySearchTree.lib
```
and clean up the leftover `spellcheck.obj` file.
```sh
del spellcheck.obj
```
#### Running the Spellcheck
The `spellcheck` application can take an input file as an argument, otherwise if no input file is provided, the user will be prompted for a file name.
|Command|Description|
|-----|-----|
|-i *filename* | The name of the input text file to read from. |
##### No Input File
```sh
spellcheck
```
##### `single_words_test.txt` File
```sh
spellcheck -i single_words_test.txt
```
##### `sentences_test.txt` File
```sh
spellcheck -i sentences_test.txt
```