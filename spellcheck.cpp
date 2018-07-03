/**
* Spell Checker
*
* This application compares an input text file with a word dictionary
* to check for spelling mistakes in that file. If the word does not
* occur in the dictionary, it is printed to the console as an
* incorrectly spelled word.
*
* The word dictionary is read into a BinarySearchTree and the text
* input file is read into a vector. The program then loops over 
* the words in the string vector and checks for occurrences in the
* BinarySearchTree.
*
* @author - Toby Cook (40316565)
* @version - 1.0.2
*
* Last modified - 15:00, 17/04/2018
*
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstring>
#include "bst.h"

/**
* Read in a file and return the contents to a string.
*
* @param {string} &filename - Takes reference to name of file read in
* @return {string} data - Returns a string containing data from text file
*
*/
std::string read_file(const std::string& filename)
{
	std::ifstream file(filename);
	if (!file)
	{
		return std::string("");
	}

	std::string data;
	// Find total number of bytes of file
	file.seekg(0, file.end);
	data.resize(file.tellg());
	file.seekg(0, file.beg);
	// Read text into data string
	file.read(&data[0], data.size());
	file.close();

	return data;
}

/**
* Take the data that has been read in from the file and 
* split into tokens, adding them to words vector.
*
* @param {vector<string>} &words - Takes a reference to string vector to store each tokenized word
* @param {string} &data - Takes a reference to the data that has been read in from the input file
*
*/
void split_words(std::vector<std::string>& words, std::string& data)
{
	const char* delim = " .,?!:;/\"\'\n\t";
	// Set token to first word
	char* token = strtok(&data[0], delim);
	// Split rest of words
	while (token != nullptr)
	{
		// Convert each word from dictionary to lower case
		for (int i = 0; i < strlen(token); ++i)
		{
			char word = tolower(token[i]);
			token[i] = word;
		}
		// Push word to end of vector
		words.push_back(token);
		// Get the next word
		token = strtok(nullptr, delim);
	}
}

int main(int argc, char** argv)
{
	std::string file_to_check, file_data;
	const std::string word_dictionary = "dictionary.txt";

	BinarySearchTree* tree = new BinarySearchTree();
	std::vector<std::string> words;

	for (int i = 0; i < argc; ++i)
	{
		// Set file name if provided as argument
		if (std::string(argv[i]) == "-i" && argv[i+1] != nullptr)
		{
			file_to_check = argv[i+1];
		}
	}

	// Prompt user for file name
	if (file_to_check.empty())
	{
		std::cout << "File name: ";
		getline(std::cin, file_to_check);
		std::cout << std::endl;
	}

	if (!file_to_check.empty())
	{
		// Read words from dictionary.txt into file_data string
		file_data = read_file(word_dictionary);
		// Split the words and store into vector
		split_words(words, file_data);
		// Insert words into Binary Search Tree
		for (int i = 0; i < words.size(); ++i)
		{
			std::stringstream(words[i]) >> *tree;
		}

		// Store the data read from specified file
		file_data = read_file(file_to_check);
		// Split sentences and store each word in words vector
		split_words(words, file_data);
		std::cout << "\n";

		int spell_count = 0;
		// Loop through words vector and check if it exists in dictionary
		for (int i = 0; i < words.size(); ++i)
		{
			// Print out non-occurring words
			if (!tree->exists(words[i]))
			{
				spell_count++;
				std::cout << words[i] << std::endl;
			}
		}
		std::cout << "\n";
		
		std::cout << spell_count << " spelling mistakes" << std::endl;
	} 
	else
	{
		// If still no file specified, print message and exit
		std::cerr << "No file specified!";
		return 1;
	}

	// Free the memory
	delete tree;
	return 0;
}