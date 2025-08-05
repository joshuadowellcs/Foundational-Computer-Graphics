//Psuedocode to integrate reflection and refraction colors to determine
// the appearance of a glass ball at the point of intersection

// compute reflection color
color reflectionColor = computeReflectionColor();

// compute refraction color
color refractionColor = computeRefractionColor();

float Kr; // reflection mix value
float Kt; // refraction mix value

// Calculate the mixing values using the Fresnel equation
fresnel(refractiveIndex, normalHit, primaryRayDirection, &Kr, &Kt);

// Mix the reflection and refraction colors based on the Fresnel equation. Note. Kt = 1 - Kr
glassBallColorAtHit = Kr * reflectionColor + Kt * refractionColor;
