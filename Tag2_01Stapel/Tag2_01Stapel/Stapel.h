#pragma once

#include <iostream>
#include <cstring>
#include <stdexcept>

namespace vw
{


	namespace collections
	{


		/// <summary>
		/// Fachliche Beschreibung (Dokumentation)
		/// </summary>
		///
		
		class Stapel
		{
		private:
			size_t array_size;
			int *data;
			int index;

			void init(const Stapel& other)
			{
				array_size = other.array_size;
				index = other.index;
				data = new int[array_size];
				std::memcpy(data, other.data, array_size * sizeof(int));
			}
		
		public:
			/// <summary>
			/// 
			/// </summary>
			Stapel(const size_t array_size = 10):array_size(array_size),index(0),data(new int[array_size])
			{
				
			}

			Stapel(const Stapel& other)
			{
				init(other);
			}

			Stapel(Stapel&& other){

				array_size = other.array_size;
				index = other.index;
				data = other.data;

				other.data = new int[0];
				other.index = 0;
				other.array_size = 0;
			}

			Stapel& operator = (Stapel&& other)
			{
				array_size = other.array_size;
				index = other.index;
				data = other.data;

				other.data = new int[0];
				other.index = 0;
				other.array_size = 0;
				return *this;
			}

			Stapel& operator = (const Stapel& other)
			{
				delete[] data;
				init(other);
				return *this;
			}
			
			~Stapel()
			{
				delete[] data;
			}

			/// <summary>
			/// 
			/// </summary>
			/// <param name="value"></param>
			void push(const int & value) // Verhalten im Fehlerfall
			{
				if (is_full()) throw std::out_of_range{ "overflow" };
					
				data[index++] = value;
			}
			/// <summary>
			/// 
			/// </summary>
			/// <returns></returns>
			int pop() 
			{
				if (is_empty()) throw std::out_of_range{ "underflow" };
					
				return data[--index];
			}

			bool is_empty() noexcept
			{
				return index <= 0;
			}

			bool is_full() noexcept
			{
				return index>= array_size;
			}
		};

	}
}