#pragma once

#include <vector>

namespace scene{

class Object;
class Light;
class Camera;

/**
 * A class to represent the main scene
*/
class Scene{

    public:
        /**
         * All the objects of the scene as a list
        */
        std::vector<Object*> mObjects;

        /**
         * All the light sources as a list
        */
        std::vector<Light*> mLights;

        /**
         * The camera of the scene
        */
        Camera* mCamera;

};

}