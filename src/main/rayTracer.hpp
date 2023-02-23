#pragma once

#include "Image.hpp"
#include "Scene.hpp"

/**
 * Return a basic image for which each pixel is either white or black if visible or not
 * @param scene The scene we want to draw
 * @return The image representing the new scene
*/
utils::Image* render(const scene::Scene & scene);