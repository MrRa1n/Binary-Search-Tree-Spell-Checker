all-test-bst: create-lib test-build clean
# Test to create library and build with no input file specified
all-test-none: create-lib spellcheck-build spellcheck-none clean
# Test to create library and build with single_words_test.txt input file specified
all-test-single: create-lib spellcheck-build spellcheck-single clean
# Test to create library and build with sentences_test.txt input file specified
all-test-sentence: create-lib spellcheck-build spellcheck-sentence clean
# Create BinarySearchTree library file
create-lib:
	cl /c BinarySearchTree.cpp
	lib /OUT:BinarySearchTree.lib BinarySearchTree.obj
	del BinarySearchTree.obj
# Compile test file and manually link BinarySearchTree.lib
test-build:
	cl /c test.cpp
	link test.obj BinarySearchTree.lib
	del test.obj
	test
# Compile spellcheck file and manually link with BinarySearchTree.lib
spellcheck-build:
	cl /c spellcheck.cpp
	link spellcheck.obj BinarySearchTree.lib
	del spellcheck.obj
# Run spellcheck.exe with no input file argument
spellcheck-none:
	spellcheck
# Run spellcheck.exe with single_words_test.txt
spellcheck-single:
	spellcheck -i single_words_test.txt
# Run spellcheck.exe with sentences_test.txt
spellcheck-sentence:
	spellcheck -i sentences_test.txt
# Clean up files
clean:
	del *.exe
	del *.obj
	del *.lib