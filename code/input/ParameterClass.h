#pragma once
//====================== #INCLUDES ===================================
#include "XMLParser.h"
//====================================================================

//====================== ParameterClass Class =================================
// Description:
//		A stand automatic parameter class.
//		With a custom XML format it will reconogize the correct variables automaticly
//====================================================================

class ParameterClass final
{
public:
	ParameterClass();
	ParameterClass(const tstring & file);
	~ParameterClass();

	ParameterClass(const ParameterClass& yRef);									
	ParameterClass& operator=(const ParameterClass& yRef);

	void Refresh();

	template <typename T>
	T GetParameter(const tstring & parameter_name) const
	{
		pugi::xml_node root = m_pParser->GetRoot();
		for(const pugi::xml_node & child : root.children())
		{
			if(GetAttribueValue<tstring>(child, _T("name")) == parameter_name)
			{
				tstring parameter_value = GetAttribueValue<tstring>(child, _T("value"));
				return XMLConverter::ConvertTString<T>(parameter_value);
			}
		}
		
		return 0;
	}

	template <typename T>
	bool SetParameter(const tstring & parameter_name, const T & parameter)
	{
		pugi::xml_node root = m_pParser->GetRoot();
		for(pugi::xml_node & child : root.children())
		{
			if(GetAttribueValue<tstring>(child, _T("name")) == parameter_name)
			{
				SetAttributeValue<T>(child, _T("value"), parameter);
				return true;
			}
		}
		return false;
	}

	template <typename T>
	T GetChildParameter(const tstring & parameter_name, const tstring & child_name) const
	{
		pugi::xml_node node = GetChild(parameter_name);
		for(const pugi::xml_node & child : node.children())
		{
			if(GetAttribueValue<tstring>(child, _T("name")) == child_name)
			{
				tstring parameter_value = GetAttribueValue<tstring>(child, _T("value"));
				return XMLConverter::ConvertTString<T>(parameter_value);
			}
		}
		
		return 0;
	}

	template <typename T>
	bool SetChildParameter(const tstring & parameter_name, const tstring & child_name, const T & parameter)
	{
		pugi::xml_node node = GetChild(parameter_name);
		for(pugi::xml_node & child : node.children())
		{
			if(GetAttribueValue<tstring>(child, _T("name")) == child_name)
			{
				SetAttributeValue<T>(child, _T("value"), parameter);
				return true;
			}
		}
		return false;
	}

	void Save();

private:
	const pugi::xml_node & GetChild(const tstring & parameter_name) const;

	XMLParser *m_pParser;
	pugi::xml_node m_EmptyNode;
};