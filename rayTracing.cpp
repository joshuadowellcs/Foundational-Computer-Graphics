//Psuedocode to implement the raytracing algorithm

for (int j = 0; j < imageHeight; ++j){
   for (int i = 0; i < imageWidth; ++i){
    // Determine the direction of the primary ray
    Ray primRay;
    computerPrimRay(i, j, &primRay);

    // Initiate a search for intersections within the scene
    Point pHit;
    Normal nHit;
    float minDist = INFINITY;
    Object *object = Null;
    for (int k = 0; k < object.size(); ++k){
        if (Intersect(onjects[k], primRay, &pHit, &nHit)){
            float distance = Distance(eyePosition, pHit);
            if (distance < minDist){
                object = &objects[k];
                minDist = distance; // Update the minimum distance 
            }
        }
    }
    if (object != NULL){
        // Illuminate the intersection point
        Ray shadowRay;
        shadowRay.direction = lightPosition - pHit;
        bool isInShadow = false;
        for (int k = 0; k < object.size(); ++k){
            if (Interesect(objects[k], shadowRay)){
                isInShadow = true;
                break;
            }
        }

    }
    if (!isInShadow)
        pixels[i][j] = object->color * light.brightness;
    else
        pixels[i][j] = 0;
   } 
}