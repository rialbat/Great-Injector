#pragma once
#include "Includes.hpp"

ref class ComboBoxItemDelegate
{
private:
	wchar_t* item;

public:
	wchar_t* getItem();
	void setItem( const STRSAFE_LPSTR newItem );
};

