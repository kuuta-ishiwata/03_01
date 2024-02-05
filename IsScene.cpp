#include "IsScene.h"

int  IsScene::sceneNo = Title;

IsScene::~IsScene() {};

int IsScene::GetSceneNo() { return sceneNo; }

void IsScene::Setkeys(char* keys, char* prekeys)
{
	keys_ = keys;
	preKeys_ = prekeys;

}