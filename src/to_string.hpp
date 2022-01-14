#pragma once

#include <string>
#include <string_view>

namespace ext
{
	std::string to_string(const std::string& _String)
	{
		return _String;
	}

	std::string to_string(std::string&& _String)
	{
		return std::move(_String);
	}

	template<class T>
	auto to_string(const T& _Obj) -> decltype(std::declval<T>().to_string())
	{
		return _Obj.to_string();
	}

	template<class T>
	auto to_string(T&& _Val) ->
		std::enable_if_t<std::is_convertible_v<T, std::string>, std::string>
	{
		return std::string(std::forward<T>(_Val));
	}

	template<class T>
	auto to_string(T&& _Val) -> std::enable_if_t<std::is_convertible_v<T, int>, std::string>
	{
		return ::std::to_string(std::forward<T>(_Val));
	}

	template<class T, class U>
	std::string to_string(std::pair<T, U>& _Pair)
	{
		return { "{" + ::ext::to_string(std::forward<T>(_Pair.first)) + ":"
			+ ::ext::to_string(std::forward<U>(_Pair.second)) + "}" };
	}

	template<class T, class U>
	std::string to_string(std::pair<T, U>&& _Pair)
	{
		return { "{" + ::ext::to_string(std::forward<T>(_Pair.first)) + ":"
			+ ::ext::to_string(std::forward<U>(_Pair.second)) + "}" };
	}

	template<class T>
	auto to_string(const T& _Conteiner) -> std::enable_if_t<!std::is_same_v<T, std::string>,
		decltype(::ext::to_string(std::declval<typename T::iterator::value_type>()))>
	{
		std::string result;
		for (auto& elem : _Conteiner)
		{
			if (!result.empty())
				result += ", ";
			result += ::ext::to_string(const_cast<T::value_type&>(elem));
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