#ifndef IUPDATABLE_H
#define IUPDATABLE_H

class IUpdatable
{
public:
	virtual ~IUpdatable() {}
	virtual void Update() = 0;
};

#endif