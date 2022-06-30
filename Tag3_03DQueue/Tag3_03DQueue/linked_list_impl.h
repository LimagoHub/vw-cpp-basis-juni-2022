#pragma once
#include <memory>
#include "liste.h"

using namespace std;
/// <summary>
		/// 
		/// </summary>
		/// <typeparam name="T"></typeparam>
template<class T>
class linked_list_impl :public liste<T>
{
	template<class T>
	struct kettenglied
	{

		std::shared_ptr<kettenglied<T>> nach;
		std::weak_ptr<kettenglied<T>> vor;
		T data;


		kettenglied(T data)
			: data(data), nach{ nullptr }, vor{ nach }
		{
		}
	};

	std::shared_ptr<kettenglied<T>> start;
	std::shared_ptr<kettenglied<T>> akt;

public:
	linked_list_impl()
		: start{ nullptr }, akt{ nullptr }
	{
	}

	auto append(T value) -> void override
	{
		auto neu = make_shared<kettenglied<T>>(value);
		
		if( is_empty())
		{
			start = neu;
		} else
		{
			this->move_last();
			akt->nach = neu;
			neu->vor = akt;
			
		}
		akt = neu;
	}


	auto update(T value) -> bool override
	{
		if(is_empty())
			return false;

		akt->data = value;
		return true;
	}

	auto remove() -> bool override {

		if (is_empty()) return false;

		if(is_begin_of_list() && is_end_of_list())
		{
			start.reset();
			akt.reset();
			return true;
		}

		if (is_begin_of_list())
		{
			move_next();
			start = akt;
			start->vor.reset();
			return true;
		}

		if (is_end_of_list())
		{
			move_previous();
			akt->nach.reset();
			return true;
		}

		akt->vor.lock()->nach = akt->nach;
		akt->nach->vor = akt->vor;
		move_next();

		return true;

	}

	std::optional<T> get() const override
	{
		return is_empty() ? std::nullopt : std::optional<T>{ akt->data };
	}

	auto move_first()  -> bool override
	{
		if (is_empty())
			return false;
		akt = start;
		return true;
	}
	auto move_previous() -> bool override
	{
		if(is_begin_of_list())
			return false;

		akt = akt->vor.lock();
		return true;
	}

	auto move_next() -> bool override
	{
		if (is_end_of_list())
			return false;

		akt = akt->nach;
		return true;
	}

	auto is_empty() const -> bool override
	{
		return start.use_count() == 0;
	}

	auto is_begin_of_list() const -> bool override
	{
		return start == akt;
	}

	auto is_end_of_list() const -> bool override
	{
		return is_empty() || akt->nach.use_count() == 0;
	}
	
};