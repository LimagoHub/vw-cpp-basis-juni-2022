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
		public:
			/// <summary>
			/// 
			/// </summary>
			Stapel()
			{
				std::cout << "ctor" << std::endl;
			}

			/// <summary>
			/// 
			/// </summary>
			/// <param name="value"></param>
			void push(const int value) // Verhalten im Fehlerfall
			{
				std::cout << "push" << std::endl;
			}
			/// <summary>
			/// 
			/// </summary>
			/// <returns></returns>
			int pop() // Verhalten im Fehlerfall
			{
				std::cout << "pop" << std::endl;
				return 0;
			}

			bool is_empty()
			{
				std::cout << "is_empty" << std::endl;
				return true;
			}

			bool is_full()
			{
				std::cout << "is_full" << std::endl;
				return true;
			}
		};

	}
}