#include <string>
#include "CEnemy.h"

void CEnemy::setPosX(float _x) {x = _x;}
void CEnemy::setPosY(float _y) {y = _y;}
void CEnemy::setPosZ(float _z) {z = _z;}
float CEnemy::getPosX() {return x;}
float CEnemy::getPosY() {return y;}
float CEnemy::getPosZ() {return z;}

void CEnemy::setName(std::string _name) { m_Name = _name; }
std::string CEnemy::getName() { return m_Name; }

void CEnemy::setRenderableObject(CRenderableObject *_renderableObejct) {
	m_RenderableObject = _renderableObejct;
}

CRenderableObject * CEnemy::getRenderableObject() {
	return m_RenderableObject;
}

void CEnemy::setCharacterController(CCharacterController *_characterController) {
	m_CharacterController = _characterController;
}

CCharacterController * CEnemy::getCharacterController() {
	return m_CharacterController;
}

void CEnemy::setCurrentWaypoint(int _currentWaypoint) {
	m_CurrentWaypoint = _currentWaypoint;
}

int CEnemy::getCurrentWaypoint() {
	return m_CurrentWaypoint;
}

void CEnemy::setPath(CPath *_path) {
	m_Path = _path;
}

CPath * CEnemy::getPath() {
	return m_Path;
}