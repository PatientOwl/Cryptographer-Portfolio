/*
* Linear Probing (open addressing / closed hashing)
* featuring lazy deletion for deleting keys from a hash table.
* 
* ~ Legend Artis 05/13/2022
*/

#include <iostream>
#include <vector>
using namespace std;

class HashMapTable
{
	// initializing the size of the hash table
	int table_size;

	// a pointer* vector that points to an array on the hash table containing the keys
	vector<int>* table;

public:
	// creating a parameterized constructor of the above class containing all the methods
	HashMapTable(int key);

	// hash function formula to compute the index using table_size and key
	int hashFunction(int key) {
		return (key % table_size);
	}

	// inserting a key in the hash table
	void insertElement(int key);

	// deleting a key in the hash table
	void deleteElement(int key);

	// displaying the full hash table
	void displayHashTable();
};

// using a scope resolution operator (::) to create the hash table with the given table size
HashMapTable::HashMapTable(int ts)
{
	this->table_size = ts;		// 'this' pointer calling this object's copy of Class table_size object
	table = new vector<int>[table_size];	// allocating 'new' dynamic memory to create vector during runtime
}

// insert function to push the keys in hash table
void HashMapTable::insertElement(int key)
{
	int index = hashFunction(key); // index of array equating to the key%table_size
	int tombstone = -1;
	
	while (!table[index].empty() && table[index].at(0) != key && table[index].at(0) != tombstone) {
		index = (index + 1) % table_size;
	}

	if (table[index].empty())
		table[index].push_back(key);
	else
		table[index].at(0) = tombstone;
}

// delete function to delete the element from the hash table
void HashMapTable::deleteElement(int key)
{
	int index = hashFunction(key);
	int tombstone = -1;

	// using lazy deletion (tombstone) strategy
	while (!table[index].empty()) {
		// if key (node) is found
		if (table[index].at(0) == key) {
			table[index].at(0) = tombstone;
			break;
		}
		else {
			index = (index + 1) % table_size;
		}
	}
}

// display function to showcase the entire hash table
void HashMapTable::displayHashTable() {
	// displaying the index in the first column
	for (int i = 0; i < table_size; i++) {
		cout << i;
		// displaying the keys of the index position in columns 2nd and beyond
		for (auto j : table[i])
			cout << " ==> " << j;
		cout << endl;
	}
}


int main()
{
	// array of all the keys to be inserted in the hash table
	int arr[] = { 20, 34, 56, 54, 76, 87 };
	int n = sizeof(arr) / sizeof(arr[0]);

	// table_size of hash table as 6
	HashMapTable ht(6);
	for (int i = 0; i < n; i++)
		ht.insertElement(arr[i]);

	// deleting a key from the hash table, replacing it with the tombstone value "-1"
	ht.deleteElement(87);

	// displaying the final data of hash table
	ht.displayHashTable();

	return 0;
}