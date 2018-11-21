

enum eScene 
{
	SCENE_TITLE,
	SCENE_GAME,
	SCENE_RESULT,
	SCENE_STARTMENU,
	SCENE_OPTION,
	SCENE_OPTION1,
	SCENE_RANK1,
	SCENE_QUIT
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