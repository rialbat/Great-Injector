#include "ComboBoxItemDelegate.hpp"

wchar_t* ComboBoxItemDelegate::getItem()
{
	return item;
}

void ComboBoxItemDelegate::setItem(const STRSAFE_LPSTR newItem)
{
	//1 ������� StringCbPrintfA((STRSAFE_LPSTR)item, sizeof(*item), "%s", newItem);
	item = (wchar_t*)newItem;
	//3 ������� mbstowcs(item, newItem, sizeof(item));
}
