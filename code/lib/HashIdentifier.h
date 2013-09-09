//====================== #INCLUDES ===================================
#include "stdafx.h"
//====================================================================

//====================== HashIdentifier Class =================================
// Description:
//		class for hash identification
//====================================================================

class HashIdentifier
{
public:
	HashIdentifier(const tstring & value, UINT identifier);
	~HashIdentifier();
	HashIdentifier(const HashIdentifier& yRef);									
	HashIdentifier& operator=(const HashIdentifier& yRef);

	bool operator==(const HashIdentifier& rhs) const;
	bool operator!=(const HashIdentifier& rhs) const;
	bool operator<(const HashIdentifier& rhs) const;
	bool operator>(const HashIdentifier& rhs) const;
	bool operator<=(const HashIdentifier& rhs) const;
	bool operator>=(const HashIdentifier& rhs) const;

	inline const UINT64 & GetKey() const { return Key; }
	inline const tstring & GetValue() const { return Value; }
	inline const UINT & GetIdentifier() const { return Identifier; }

	void SetValue(const tstring & value);
	void SetIdentifier(UINT identifier);
private:
	void GenerateKey();

	UINT64 Key;
	tstring Value;
	UINT Identifier;
};