/**
* Various helpful type conversion and comparison functions.
*/

#pragma once

#include <string>

/// Converts various values to a string.
std::string ToString(int value);
std::string ToString(uint32_t value);
std::string ToString(float value);

/// Converts a string value to an int value.
int ToInt(const std::string& value);

/// Converts a char value to an int value.
int ToInt(const char value);

/// Converts a string value to an unsigned int value.
unsigned int ToUnsignedInt(const std::string& value);

/// Converts a string value to a double value.
double ToDouble(const std::string& value);

/// Converts a string value to a float value.
float ToFloat(const std::string& value);

// ---- Is Value Functions ----

/**
 * Checks whether the given string could be parsed as an integer.
 */
bool IsInt(const std::string& value);

/**
 * Checks whether the given string could be parsed as an unsigned integer.
 */
bool IsUnsignedInt(const std::string& value);

// ---- Comparison Functions ----

/**
 * Finds if two floats are equal within a certain limit.
 */
bool FloatsAreEqual(float x, float y, float limit = 0.001f);
