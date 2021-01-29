#pragma once
#include "Includes.hpp"

ref class ComboBoxItemDelegate
{
private:
	System::String^ item;

public:
	System::String^ getItem();
	void setItem( const STRSAFE_LPSTR newItem );
	void clear();
};

