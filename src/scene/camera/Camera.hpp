#pragma once

#include "maths.hpp"
#include "opengl.hpp"
#include "utils.hpp"

namespace scene{

/**
 * Possible options for camera movement. 
 * Used as abstraction to stay away from window-system specific input methods
*/
enum CameraMovement {
    CAM_FORWARD,
    CAM_BACKWARD,
    CAM_LEFT,
    CAM_RIGHT
};

/**
 * Default camera's yaw
*/
[[maybe_unused]] const float YAW = -90.0f;

/**
 * Default camera's pitch
*/
[[maybe_unused]] const float PITCH =  0.0f;

/**
 * Default camera's speed
*/
[[maybe_unused]] const float SPEED =  2.5f;

/**
 * Default camera's sensitivity
*/
[[maybe_unused]] const float SENSITIVITY =  0.1f;

/**
 * Default camera's zoom
*/
[[maybe_unused]] const float ZOOM =  45.0f;

/**
 * The maximum zoom
*/
const float MAX_ZOOM = 45.0f;

/**
 * The minimum zoom
*/
const float MIN_ZOOM = 1.0f;

/**
 * The maximum pitch
*/
const float MAX_PITCH = 89.0f;

/**
 * The minimum pitch
*/
const float MIN_PITCH = -89.0f;

/**
 * A class to manipulate a camera
*/
class Camera{
    public:
        // Attributes
        /**
         * The camera's position
        */
        glm::vec3 mPosition;
        
        /**
         * The camera's front direction
        */
        glm::vec3 mFront;

        /**
         * The camera's up direction
        */
        glm::vec3 mUp;

        /**
         * The camera's right direction
        */
        glm::vec3 mRight;

        /**
         * The world's up direction
        */
        glm::vec3 mWorldUp;

        // options
        /**
         * The camera's speed
        */
        float mMovementSpeed;

        /**
         * The camera's sensitivity
        */
        float mSensitivity;

        /**
         * The camera's zoom
        */
        float mZoom;

        // angles
        /**
         * The camera's yaw angle
        */
        float mYaw;

        /**
         * The camera's pitch angle
        */
        float mPitch;

        /**
         * Tells if the camera can't go up or own
        */
        float mIsFPS;

        /**
         * Defines the near plane's depth of the camera's frustrum
        */
        float mZmin;

        /**
         * Defines the far plane's depth of the camera's frustrum
        */
        float mZmax;

        /**
         * The camera's field of view in radians
        */
        float mFov;

        /**
         * The camera far plane's width
        */
        int mWidth;

        /**
         * The camera far plane's height
        */
        int mHeight;

    public:
        /**
         * Basic constructor using vectors
         * @param position The camera's initial position
         * @param front The camera's front direction
         * @param worldUp The world's up position
         * @param speed The camera's speed
         * @param sensitivity The camera's sensitivity
         * @param zoom The camera's initial zoom
         * @param yaw The camera's initial yaw
         * @param pitch The camera's initial pitch
         * @param fps Tell if the camera is a true fps camera
         * @param zmin The near plan's depth
         * @param zmax The far plan's depth
         * @param fov The field of view
         * @param width The far plane's width
         * @param height The far plane's height
        */
        Camera(
            glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f), 
            glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f),
            glm::vec3 worldUp = glm::vec3(0.0f, 1.0f, 0.0f),
            float speed = SPEED, float sensitivity = SENSITIVITY, float zoom = ZOOM, float yaw = YAW, float pitch = PITCH,
            bool fps = true, float zmin = 0.1f, float zmax = 100.0f, float fov = glm::radians(45.0f), 
            int width = SCR_WIDTH, int height = SCR_HEIGHT){
            mPosition = position;
            mFront = front;
            mWorldUp = worldUp;
            mMovementSpeed = speed,
            mSensitivity = sensitivity,
            mZoom = zoom,
            mYaw = yaw; mPitch = pitch;
            mIsFPS = fps;
            mZmin = zmin; mZmax = zmax;
            mFov = fov;
            mWidth = width; mHeight = height;
            updateCameraVectors();
        }

        /**
         * Basic constructor using points
         * @param posX The camera's x initial position
         * @param posY The camera's y initial position
         * @param posZ The camera's z initial position
         * @param frontX The camera's x front direction
         * @param frontY The camera's y front direction
         * @param frontZ The camera's z front direction
         * @param worldUpX The world's x up position
         * @param worldUpY The world's y up position
         * @param worldUpZ The world's z up position
         * @param speed The camera's speed
         * @param sensitivity The camera's sensitivity
         * @param zoom The camera's initial zoom
         * @param yaw The camera's initial yaw
         * @param pitch The camera's initial pitch
         * @param fps Tell if the camera is a true fps camera
         * @param zmin The near plan's depth
         * @param zmax The far plan's depth
         * @param fov The field of view
         * @param width The far plane's width
         * @param height The far plane's height
        */
        Camera(
            float posX = 0.0f, float posY = 0.0f, float posZ = 0.0f, 
            float frontX = 0.0f, float frontY = 0.0f, float frontZ = -1.0f, 
            float worldUpX = 0.0f, float worldUpY = 1.0f, float worldUpZ = 0.0f,
            float speed = SPEED, float sensitivity = SENSITIVITY, float zoom = ZOOM, float yaw = YAW, float pitch = PITCH,
            bool fps = true, float zmin = 0.1f, float zmax = 100.0f, float fov = glm::radians(45.0f), 
            int width = SCR_WIDTH, int height = SCR_HEIGHT){
            glm::vec3 position = glm::vec3(posX, posY, posZ);
            glm::vec3 front = glm::vec3(frontX, frontY, frontZ);
            glm::vec3 worldUp = glm::vec3(worldUpX, worldUpY, worldUpZ);
            Camera(position, front, worldUp, speed, sensitivity, zoom, yaw, pitch, fps, zmin, zmax, fov, width, height);
            updateCameraVectors();
        }

        /**
         * Get the view matrix using the LookAt matrix
         * @return The view matrix
        */
        glm::mat4 getViewMatrix(){
            return glm::lookAt(mPosition, mPosition + mFront, mUp);
        }

        /**
         * Get the projection matrix
         * @param ortho If set to true then return an orthographic projection (default false)
         * @return The projection matrix
        */
        glm::mat4 getProjectionMatrix(bool ortho = false){
            if(ortho)
                return glm::ortho(0.0f, (float)mWidth, 0.0f, (float)mHeight, mZmin, mZmax);
            return glm::perspective(glm::radians(mZoom), (float)mWidth / (float)mHeight, mZmin, mZmax);
        }

        /**
         * Turn a pixel into a ray
         * @param pixelX The pixel's abscissa
         * @param pixelY The pixel's ordinate
         * @return A ray 
        */
        maths::Ray* pixelToRay(int pixelX, int pixelY){
            maths::Vector3* destination = new maths::Vector3(pixelX, pixelY, mZmin);
            maths::Vector3* direction = new maths::Vector3((destination-new maths::Vector3(mPosition)));
            direction->normalize();
            return new maths::Ray(mPosition, direction);
        };

    private:
        /**
         * Calcuate the front, the right and the up vectors from the camera's angles 
        */
        void updateCameraVectors(){
            // calculate the new Front vector
            glm::vec3 front;
            front.x = cos(glm::radians(mYaw)) * cos(glm::radians(mPitch));
            front.y = sin(glm::radians(mPitch));
            front.z = sin(glm::radians(mYaw)) * cos(glm::radians(mPitch));
            mFront = glm::normalize(front);
            // also re-calculate the Right and Up vector
            mRight = glm::normalize(glm::cross(mFront, mWorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
            mUp    = glm::normalize(glm::cross(mRight, mFront));
        }

};

}