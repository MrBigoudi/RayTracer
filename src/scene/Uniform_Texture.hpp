#pragma once

#include "Texture_Material.hpp"

namespace scene {

class Texture_Material;

/**
 * A class to represent uniform textures
*/
class Uniform_Texture : Texture_Material{

    public:
        /**
         * The diffuse reflection property
        */
        float mKd;

        /**
         * The specular reflection property
        */
        float mKs;

        /**
         * The refractive index of the material
        */
        float mN;

    public:
        /**
         * A basic constructor
         * @param kd The diffuse reflection property
         * @param ks The specular reflection property
         * @param n The refractive index
        */
        Uniform_Texture(float kd, float ks, float n){
            mKd = kd;
            mKs = ks;
            mN = n;
        }

        /**
         * Cast a unifor texture into a printable string
         * @return The texture as a string
        */
        std::string toString() const override {
            char buffer[50];
            sprintf(buffer, "kd: %f, ks: %f, n: %f", mKd, mKs, mN);
            return buffer;
        }

        /**
        * Get all the paramters for the texture and the material (kd, ks, ...) on a given point in the surface
        * @param coords The coordinates of the point
        */
        std::vector<float> getParameters( [[maybe_unused]] const maths::Vector3 & coords) const override {
            std::vector<float> res;
            // first value is kd
            res.push_back(mKd);
            // second value is ks
            res.push_back(mKs);
            // third value is n
            res.push_back(mN);
            return res;
        }

};

}