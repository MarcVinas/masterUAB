#ifndef _ENEMY_H
#define _ENEMY_H

class CRenderableObject {};
class CCharacterController {};
class CPath {};

#include <string>

class CEnemy{
private:
	enum TState
	{
		IDLE,
		CINEMATICS, 
		PATROL,
		SHOOTHING,
		DEAD,
		HIT
	};
	float x,y,z;
	std::string m_Name;
	TState m_State;
	CRenderableObject *m_RenderableObject;
	CCharacterController *m_CharacterController;
	int m_CurrentWaypoint;
	CPath *m_Path;

public:
	CEnemy();
	virtual ~CEnemy();

	void setPosX(float _x);
	void setPosY(float _y);
	void setPosZ(float _z);
	float getPosX();
	float getPosY();
	float getPosZ();

	void setName(std::string _name);
	std::string getName();

	void setRenderableObject(CRenderableObject *_renderableObejct);
	CRenderableObject * getRenderableObject();

	void setCharacterController(CCharacterController *_characterController);
	CCharacterController * getCharacterController();

	void setCurrentWaypoint(int _currentWaypoint);
	int getCurrentWaypoint();

	void setPath(CPath *_path);
	CPath * getPath();
}

#endif