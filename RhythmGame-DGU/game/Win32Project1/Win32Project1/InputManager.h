#pragma once
#include<map>
using namespace std;
enum eKeyStatus
{
	KEY_NONE,
	DOWN,
	HOLD,
	UP,
};
enum eTrackNum;
union SDL_Event;
class InputManager
{
private:
	static InputManager* _instance;
public:
	static InputManager* GetInstance();
private:
	InputManager();
public:
	~InputManager();
private:
	map<eTrackNum, int> _trackKeyMap;
	map<int, eKeyStatus> _keyStatus;
public:
	void Init();
	bool IsKeyDown(int keycode);
	bool IsKeyHold(int keycode);
	bool IsKeyUp(int keycode);
	int GetKeyCode(eTrackNum trackNum);
	void UpdateInput(SDL_Event sdlEvent);
};