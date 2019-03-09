#pragma once

#include <string>
#include <map>
#include <conio.h>

/*
*	The purpose of the Object is to be any datatype
*/


/*
*	The purpose of this class is to store a int value as a Object.
*	It provides some methods to streamline output by using standard C++ methods to convert to a string.
*	Integer objects interact almost as standard ints, allowing algorithmic actions.
*/
class Integer
{
private:
	int value;

public:
	Integer() {}
	Integer(int val) : value(val) {}
	~Integer() {}


	Integer operator=(int val)
	{
		value = val;
		return *this;
	}
	Integer operator=(Integer cls)
	{
		value = cls.value;
		return *this;
	}
	Integer& operator++()
	{
		++value;
		return *this;
	}
	Integer operator++(int)
	{
		Integer rslt(*this);
		++(*this);
		return rslt;
	}
	Integer& operator--()
	{
		--value;
		return *this;
	}
	Integer operator--(int)
	{
		Integer rslt(*this);
		--(*this);
		return rslt;
	}
	Integer operator+(Integer cls)
	{
		value += cls.value;
		return *this;
	}
	Integer operator+(int val)
	{
		value += val;
		return *this;
	}
	Integer operator-(Integer cls)
	{
		value -= cls.value;
		return *this;
	}
	Integer operator-(int val)
	{
		value -= val;
		return *this;
	}
	Integer operator*(Integer cls)
	{
		value *= cls.value;
		return *this;
	}
	Integer operator*(int val)
	{
		value *= val;
		return *this;
	}
	Integer operator/(Integer cls)
	{
		value /= cls.value;
		return *this;
	}
	Integer operator/(int val)
	{
		value /= val;
		return *this;
	}

	friend std::ostream& operator<<(std::ostream& os, const Integer& cls)
	{
		os << cls.value;
		return os;
	}

	std::string toString()
	{
		return std::to_string(value);
	}
	static Integer parseInt(std::string val)
	{
		return Integer(std::stoi(val));
	}
};

/*
*	The purpose of this class is to store a double value as a Object.
*	It provides some methods to streamline output by using standard C++ methods to convert to a string.
*/
class Double
{
private:
	double value;

public:
	Double() {}
	Double(double val) : value(val) {}
	~Double() {}

	Double operator=(double val)
	{
		value = val;
		return *this;
	}
	Double operator=(int val)
	{
		value = val;
		return *this;
	}
	Double operator=(Double cls)
	{
		value = cls.value;
		return *this;
	}
	Double& operator++()
	{
		++value;
		return *this;
	}
	Double operator++(int)
	{
		Double rslt(*this);
		++(*this);
		return rslt;
	}
	Double& operator--()
	{
		--value;
		return *this;
	}
	Double operator--(int)
	{
		Double rslt(*this);
		--(*this);
		return rslt;
	}
	Double operator+(Double cls)
	{
		value += cls.value;
		return *this;
	}
	Double operator+(double val)
	{
		value += val;
		return *this;
	}
	Double operator+(int val)
	{
		value += val;
		return *this;
	}
	Double operator-(Double cls)
	{
		value -= cls.value;
		return *this;
	}
	Double operator-(double val)
	{
		value -= val;
		return *this;
	}
	Double operator-(int val)
	{
		value -= val;
		return *this;
	}
	Double operator*(Double cls)
	{
		value *= cls.value;
		return *this;
	}
	Double operator*(double val)
	{
		value *= val;
		return *this;
	}
	Double operator*(int val)
	{
		value *= val;
		return *this;
	}
	Double operator/(Double cls)
	{
		value /= cls.value;
		return *this;
	}
	Double operator/(double val)
	{
		value /= val;
		return *this;
	}
	Double operator/(int val)
	{
		value /= val;
		return *this;
	}
	friend std::ostream& operator<<(std::ostream& os, const Double& cls)
	{
		os << cls.value;
		return os;
	}
	std::string toString()
	{
		return std::to_string(value);
	}
	static Double parseDouble(std::string val)
	{
		return Double(std::stod(val));
	}
};

/*
*	The purpose of this class is to hold any number of key-value pairs opposed to creating numerous amounts of variables.*
*	Key-Value Pairs are stored as map<string, string>, and are accessed via put and get methods.
*
*	Currently Supports:
*		- Strings
*		- Integer or int
*		- Double or double
*		- Any data that can be stored as a string (char array)
*	
*	Flow
*	- If a Key-Value pair exists and you attempt to add another with the same name
*		- Existing value is overwritten with the new value for that Key
*	- If a Key-Value pair
*/
class Variables
{
private:
	std::map<std::string, std::string> KeyValuePairs;

	// Helper Methods

	// Iterate array for key and assign data, if no key, return false, if key, return true
	bool iterateAssignData(std::string key, std::string val)
	{
		for (std::map<std::string, std::string>::iterator it = KeyValuePairs.begin(); it != KeyValuePairs.end(); ++it)
			if (it->first == key)
			{
				KeyValuePairs[key] = val;
				return true;
			}
		return false;
	}

	bool iterateFindKey(std::string key)
	{
		for (std::map<std::string, std::string>::iterator it = KeyValuePairs.begin(); it != KeyValuePairs.end(); ++it)
			if (it->first == key)
			{
				return true;
			}
		return false;
	}

public:
	// Class that holds variable amounts of Key-Value Paired KeyValuePairs
	Variables() {}
	~Variables() {}

	// Create Key-Value Pair of string and int
	void putInt(std::string key, int val)
	{
		if (!iterateAssignData(key, std::to_string(val)))
			KeyValuePairs.emplace(key, std::to_string(val));
	}
	// Create Key-Value Pair of string and Integer Object
	void putInt(std::string key, Integer cls)
	{
		if (!iterateAssignData(key, cls.toString()))
			KeyValuePairs.emplace(key, cls.toString());
	}
	// Create Key-Value Pair of string and double
	void putDouble(std::string key, double val)
	{
		if (!iterateAssignData(key, std::to_string(val)))
			KeyValuePairs.emplace(key, std::to_string(val));
	}
	// Create Key-Value Pair of string and Double Object
	void putDouble(std::string key, Double cls)
	{
		if (!iterateAssignData(key, cls.toString()))
			KeyValuePairs.emplace(key, cls.toString());
	}
	// Create Key-Value Pair of string and string
	void putString(std::string key, std::string val)
	{
		if (!iterateAssignData(key, val))
			KeyValuePairs.emplace(key, val);
	}
	// Create Key-Value Pair of string and Array
	void putArray(std::string key)
	{

	}

	// Retrieve Value of Key as int
	int getInt(std::string key)
	{
		for (std::map<std::string, std::string>::iterator it = KeyValuePairs.begin(); it != KeyValuePairs.end(); ++it)
			if (it->first == key)
				return std::stoi(it->second);
		return 0;
	}
	// Retrieve Value of Key as double
	double getDouble(std::string key)
	{
		for (std::map<std::string, std::string>::iterator it = KeyValuePairs.begin(); it != KeyValuePairs.end(); ++it)
			if (it->first == key)
				return std::stod(it->second);
		return 0;
	}
	// Retrieve Value of Key as string
	std::string getString(std::string key)
	{
		for (std::map<std::string, std::string>::iterator it = KeyValuePairs.begin(); it != KeyValuePairs.end(); ++it)
			if (it->first == key)
				return it->second;
		return "";
	}

	// Remove certain Key-Value Pair
	void removePair(std::string key)
	{
		if (iterateFindKey(key))
			KeyValuePairs.erase(key);
	}
	// Remove all Key-Value Pairs
	void clearValues()
	{
		KeyValuePairs.clear();
	}
	// Swap a Key-Value Pair value without changing the Key name
	void swapValues(std::string key1, std::string key2)
	{
		try
		{
			std::string key1Value = KeyValuePairs[key1];
			KeyValuePairs[key1] = KeyValuePairs[key2];
			KeyValuePairs[key2] = key1Value;
		}
		catch (...)
		{
			return;
		}
	}
	// Rename a Key-Value Pair Key
	void renameKey(std::string key, std::string newKeyVal)
	{
		try
		{
			for (std::map<std::string, std::string>::iterator it = KeyValuePairs.begin(); it != KeyValuePairs.end(); ++it)
				if (it->first == key)
				{
					std::swap(KeyValuePairs[newKeyVal], it->second);
					KeyValuePairs.erase(it);
					return;
				}
		}
		catch (...)
		{
			return;
		}
	}
	// Get all data as a string
	std::string toString()
	{
		std::string out;
		out.append("\n\nListing all Key-Value Pairs:\n");
		for (auto &e : KeyValuePairs)
			out.append("Key : " + e.first + ", Value : " + e.second + "\n");
		return out;
	}
	// Get number of Key-Value Pairs
	size_t size()
	{
		return KeyValuePairs.size();
	}


	// Set a New Variable Set with the same variables as a previous set
	Variables operator=(Variables obj)
	{
		KeyValuePairs = obj.KeyValuePairs;
	}
	// Print Key-Value pairs
	friend std::ostream& operator<<(std::ostream& os, const Variables& cls)
	{
		os << "\n\nListing all Key-Value Pairs:\n";
		for (auto &e : cls.KeyValuePairs)
			os << "Key : " << e.first << ", Value : " << e.second << "\n";
		return os;
	}
};