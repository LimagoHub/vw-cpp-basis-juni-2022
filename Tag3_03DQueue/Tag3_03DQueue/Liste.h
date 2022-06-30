#pragma once
#include <optional>
template<class T>
class liste
{
public:
	virtual auto append(T value) -> void = 0;
	virtual auto update(T value) -> bool = 0;
	virtual auto remove() -> bool = 0;

	virtual auto get() const -> std::optional<T> = 0; // Ab c++17 bitte mit Optional
	virtual auto clear() -> void
	{
		while (remove());
	}

	virtual auto move_first() -> bool
	{
		if (is_empty())
			return false;
		while (move_previous());
		return true;
	}

	virtual auto move_last() -> bool
	{
		if (is_empty())
			return false;
		while (move_next());
		return true;
	}

	virtual auto move_previous() -> bool = 0;
	virtual auto move_next() -> bool = 0;
	virtual auto is_empty() const -> bool = 0;
	/// <summary>
			/// liefert true wenn entweder die Liste leer ist oder der Cursor auf dem ERSTEN Satz steht
			/// </summary>
			/// <returns></returns>
	virtual auto is_begin_of_list() const -> bool = 0;
	/// <summary>
	/// liefert true wenn entweder die Liste leer ist oder der Cursor auf dem letzten Satz steht
	/// </summary>
	/// <returns></returns>
	virtual auto is_end_of_list() const -> bool = 0;
};