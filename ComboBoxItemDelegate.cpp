#include "ComboBoxItemDelegate.hpp"

System::String^ ComboBoxItemDelegate::getItem()
{
	return item;
}

void ComboBoxItemDelegate::setItem(const STRSAFE_LPSTR newItem)
{
	//1 вариант StringCbPrintfA((STRSAFE_LPSTR)item, sizeof(*item), "%s", newItem);
	//item = newItem;
	//3 вариант mbstowcs(item, newItem, sizeof(item));
	for (int i = 0; newItem[i] != '\0'; i++)
	{
		item += wchar_t(newItem[i]);
	}
}

void ComboBoxItemDelegate::clear()
{
	item = "";
}