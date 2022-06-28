#pragma once

#include <iostream>

namespace vw
{


	namespace collections
	{


		/// <summary>
		/// Fachliche Beschreibung (Dokumentation)
		/// </summary>
		class Stapel
		{
		private:
			static const int array_size{ 10 };
			int data[array_size];
			int index;
		
		public:
			/// <summary>
			/// 
			/// </summary>
			Stapel():index(0)
			{
				
			}

			/// <summary>
			/// 
			/// </summary>
			/// <param name="value"></param>
			void push(const int value) // Verhalten im Fehlerfall
			{
				if (!is_full())
					data[index++] = value;
			}
			/// <summary>
			/// 
			/// </summary>
			/// <returns></returns>
			int pop() // Verhalten im Fehlerfall
			{
				if (is_empty())
					return 0;
				return data[--index];
			}

			bool is_empty()
			{
				return index <= 0;
			}

			bool is_full()
			{
				return index>= array_size;
			}
		};

	}
}