#pragma once

#include <string>
#include <string_view>

namespace ext
{

	template<class T>
	auto to_string(const T& _Obj)
	{
		return _Obj.to_string();
	}



}