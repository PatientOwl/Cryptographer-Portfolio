/*
From the tutorial link: https://www.educba.com/c-plus-plus-hash-table/

Open Hashing (separate chaining) Hashing Example
*/

#include <iostream>
#include <list>
using namespace std;

class HashMapTable
{
	// initializing the size of the hash table
	int table_size;

	// a pointer* list to an array on the table containing the keys
	list<int>* table;

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
	table = new list<int>[table_size];	// allocating 'new' dynamic memory to create list during runtime
}

// insert function to push the keys in hash table
void HashMapTable::insertElement(int key)
{
	int index = hashFunction(key);	// index of array equating to the key%table_size
	table[index].push_back(key);	// adding a new item at the end of the array table
}
// delete function to delete the element from the hash table
void HashMapTable::deleteElement(int key)
{
	int index = hashFunction(key);
	
	// finding the key at the computed index
	list <int> ::iterator i;	// creating an iterator object so the arrays of <list> can be iterated/checked
	for (i = table[index].begin(); i != table[index].end(); i++) {
		if (*i == key)
			break;
	}
	
	// removing the key from the hash table, if found
	if (i != table[index].end())
		table[index].erase(i);
}

// display function to showcase the whole hash table
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
	int arr[] = {20, 34, 56, 54, 76, 87};
	int n = sizeof(arr) / sizeof(arr[0]);
	
	// table_size of hash table as 6
	HashMapTable ht(6);
	for (int i = 0; i < n; i++)
		ht.insertElement(arr[i]);
	
	// deleting key 76 from the hash table
	//ht.deleteElement(76);
	
	// displaying the final data of hash table
	ht.displayHashTable();
	
	return 0;
}
