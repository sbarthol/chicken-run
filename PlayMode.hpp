#include "Mode.hpp"

#include "Scene.hpp"
#include "Sound.hpp"

#include <glm/glm.hpp>

#include <vector>
#include <deque>

struct PlayMode : Mode {
	PlayMode();
	virtual ~PlayMode();

	//functions called by main loop:
	virtual bool handle_event(SDL_Event const &, glm::uvec2 const &window_size) override;
	virtual void update(float elapsed) override;
	virtual void draw(glm::uvec2 const &drawable_size) override;

	//----- game state -----

	//input tracking:
	struct Button {
		uint8_t downs = 0;
		uint8_t pressed = 0;
	} left, right, down, up;

	bool space_pressed = false;

	//local copy of the game scene (so code can change it during gameplay):
	Scene scene;

	Scene::Transform *chicken = nullptr;
	Scene::Transform *gun = nullptr;
	Scene::Transform *wall = nullptr;
	Scene::Transform *impact = nullptr;

	// angle between 0 and 360 degrees,
	// mathematical
	size_t chicken_dir = 0;
	size_t hits = 0;
	size_t gunshots = 0;

	void fire_gun();
	
	//camera:
	Scene::Camera *camera = nullptr;

};
