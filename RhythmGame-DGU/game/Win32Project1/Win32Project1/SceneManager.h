

enum eScene 
{
	SCENE_TITLE,
	SCENE_GAME,
	SCENE_GAME1,
	SCENE_GAME2,
	SCENE_GAME3,
	SCENE_RESULT,
	SCENE_STARTMENU,
	SCENE_OPTION,
	SCENE_OPTION1,
	SCENE_RankScene,
	SCENE_RANK1,
	SCENE_QUIT,
	SCENE_MUSICLIST,
	SCENE_MUSICLIST1,
	SCENE_MUSICLIST2,
	SCENE_MUSICLIST3,
	SCENE_OPTIONx1,
	SCENE_OPTIONx2,
	SCENE_OPTIONx3,
	SCENE_OPTIONk5,
	SCENE_OPTIONk7,
	SCENE_OPTIONk9,
	SCENE_OPTIONback

};

class Scene;

class SceneManager
{
	
private:
	SceneManager();
	~SceneManager();

private:
	static SceneManager* _instance;

public:
	static SceneManager* GetInstance();

	void Render();
	void Update(int deltaTime);

	void KeyUp(unsigned int keyCode);
	void KeyDown(unsigned int keyCode);

	void ChangeScene(eScene sceneType);
	void DeInit();

private:
	Scene* _scene;
};