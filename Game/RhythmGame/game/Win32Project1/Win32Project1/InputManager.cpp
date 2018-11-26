//#include<stdio.h>
//#include<SDL.h>
//#include "InputManager.h"
////#include "TrackManager.h"
//InputManager* InputManager::_instance = NULL;
//InputManager* InputManager::GetInstance()
//{
//	if (_instance == NULL)
//	{
//		_instance = new InputManager();
//		_instance->Init();
//	}
//	return _instance;
//}
//InputManager::InputManager()
//{
//
//}
//InputManager::~InputManager()
//{
//}
////void InputManager::Init()
////{
////	_trackKeyMap.clear();
////	_trackKeyMap[eTrackNum::SCRATCH] = SDLK_a;
////	_trackKeyMap[eTrackNum::KEY1] = SDLK_s;
////	_trackKeyMap[eTrackNum::KEY2] = SDLK_d;
////	_trackKeyMap[eTrackNum::KEY3] = SDLK_f;
////	_trackKeyMap[eTrackNum::KEY4] = SDLK_g;
////	_trackKeyMap[eTrackNum::KEY5] = SDLK_h;
////	_trackKeyMap[eTrackNum::KEY6] = SDLK_j;
////	_trackKeyMap[eTrackNum::KEY7] = SDLK_k;
////
////	for (int i = 0; i < 100; i++)
////	{
////		_keyStatus[i] = eKeyStatus::KEY_NONE;
////		//SDL_GetScancodeFromKey()
////	}
////}
//bool InputManager::IsKeyDown(int keycode)
//{
//	keycode = SDL_GetScancodeFromKey(keycode);
//	if (eKeyStatus::DOWN == _keyStatus[keycode])
//	{
//		return true;
//	}
//	return false;
//}
//bool InputManager::IsKeyHold(int keycode)
//{
//	keycode = SDL_GetScancodeFromKey(keycode);
//	if (eKeyStatus::HOLD == _keyStatus[keycode])
//	{
//		return true;
//	}
//	return false;
//}
//bool InputManager::IsKeyUp(int keycode)
//{
//	keycode = SDL_GetScancodeFromKey(keycode);
//	if (eKeyStatus::UP == _keyStatus[keycode])
//	{
//		_keyStatus[keycode] = eKeyStatus::KEY_NONE;
//		return true;
//	}
//	return false;
//}
//int InputManager::GetKeyCode(eTrackNum trackNum)
//{
//	return _trackKeyMap[trackNum];
//}
//void InputManager::UpdateInput(SDL_Event sdlEvent)
//{
//	{
//		int keyCode = SDL_GetScancodeFromKey(sdlEvent.key.keysym.sym);
//		for (int i = 0; i < 100; i++)
//		{
//			if (eKeyStatus::DOWN == _keyStatus[i])
//			{
//				_keyStatus[i] = eKeyStatus::HOLD;
//			}
//			if (eKeyStatus::UP == _keyStatus[i])
//			{
//				_keyStatus[i] = eKeyStatus::KEY_NONE;
//			}
//		}
//
//		if (SDL_KEYDOWN == sdlEvent.type)
//		{
//			if (eKeyStatus::KEY_NONE == _keyStatus[keyCode])
//			{
//				_keyStatus[keyCode] = eKeyStatus::DOWN;
//			}
//		}
//		else if (SDL_KEYUP == sdlEvent.type)
//		{
//			if (eKeyStatus::HOLD == _keyStatus[keyCode])
//				_keyStatus[keyCode] = eKeyStatus::UP;
//		}
//	}
//}