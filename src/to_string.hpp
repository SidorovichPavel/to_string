#pragma once

#include <string>
#include <string_view>

namespace ext
{
	template<class T>
	auto to_string(const T& _Obj) -> decltype(std::declval<T>().to_string())
	{
		return _Obj.to_string();
	}

	template<class T>
	auto to_string(T& _Val) -> 
		std::enable_if_t<std::is_convertible_v<T, std::string>, std::string>
	{
		return std::string(_Val);
	}

	template<class T>
	auto to_string(T&& _Val) ->
		std::enable_if_t<std::is_convertible_v<T, std::string>, std::string>
	{
		return std::string(std::move(_Val));
	}

	template<class T>
	auto to_string(T& _Val) -> std::enable_if_t<std::is_convertible_v<T, int>, std::string>
	{
		return ::std::to_string(_Val);
	}

	template<class T>
	auto to_string(T&& _Val) -> std::enable_if_t<std::is_convertible_v<T, int>, std::string>
	{
		return ::std::to_string(std::move(_Val));
	}

	template<class T>
	auto to_string(const T& _Conteiner) -> 
		decltype(::ext::to_string(std::declval<typename T::iterator::value_type>()))
	{
		std::string result;
		for (auto&& elem : _Conteiner)
		{
			if (!result.empty())
				result += ", ";
			result += ::ext::to_string(elem);
		}
		result += ";";
		return result;
	}

	template<class... Args>
	auto to_string(Args&&... args) -> std::enable_if_t<(sizeof...(Args) > 1), std::string>
	{
		return (... += (::ext::to_string(std::forward<Args>(args)) + " "));
	}



}