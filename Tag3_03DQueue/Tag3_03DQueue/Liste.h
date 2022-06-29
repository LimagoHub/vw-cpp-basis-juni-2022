#pragma once

template<class T>
class liste
{
public:
	virtual void append(T value) = 0;
	virtual bool update(T value) = 0;
	virtual bool remove() = 0;

	virtual T get() const = 0; // Ab c++17 bitte mit Optional
	virtual void clear() = 0;
	virtual bool move_first() = 0;
	virtual bool move_last() = 0;
	virtual bool move_previous() = 0;
	virtual bool move_next() = 0;
	virtual bool is_empty() const = 0;
	/// <summary>
			/// liefert true wenn entweder die Liste leer ist oder der Cursor auf dem ERSTEN Satz steht
			/// </summary>
			/// <returns></returns>
	virtual bool is_begin_of_list() const = 0;
	/// <summary>
	/// liefert true wenn entweder die Liste leer ist oder der Cursor auf dem letzten Satz steht
	/// </summary>
	/// <returns></returns>
	virtual bool is_end_of_list() const = 0;
};