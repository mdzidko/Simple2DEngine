#pragma once

class UniqueId
{
public:
	template<typename T> static int GetUId()
	{
		static int uId = GetId();
		return uId;
	}

private:
	static int GetId()
	{
		static int id;
		return id++;
	}
};