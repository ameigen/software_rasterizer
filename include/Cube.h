#include "Geometry.h"
std::vector<Vector3<int>> cubeVerts{Vector3(0, 0, 0),
                                    Vector3(1, 0, 0),
                                    Vector3(1, 1, 0),
                                    Vector3(0, 1, 0),
                                    Vector3(0, 0, 1),
                                    Vector3(1, 0, 1),
                                    Vector3(1, 1, 1),
                                    Vector3(0, 1, 1)};

std::vector<Triangle<int>> cubeTris{Triangle<int>(cubeVerts[0], cubeVerts[1], cubeVerts[2]),
                                    Triangle<int>(cubeVerts[0], cubeVerts[2], cubeVerts[3]),
                                    Triangle<int>(cubeVerts[1], cubeVerts[5], cubeVerts[6]),
                                    Triangle<int>(cubeVerts[1], cubeVerts[6], cubeVerts[2]),
                                    Triangle<int>(cubeVerts[3], cubeVerts[2], cubeVerts[6]),
                                    Triangle<int>(cubeVerts[3], cubeVerts[6], cubeVerts[7]),
                                    Triangle<int>(cubeVerts[0], cubeVerts[4], cubeVerts[5]),
                                    Triangle<int>(cubeVerts[0], cubeVerts[5], cubeVerts[1]),
                                    Triangle<int>(cubeVerts[4], cubeVerts[7], cubeVerts[6]),
                                    Triangle<int>(cubeVerts[4], cubeVerts[6], cubeVerts[5]),
                                    Triangle<int>(cubeVerts[0], cubeVerts[3], cubeVerts[7]),
                                    Triangle<int>(cubeVerts[0], cubeVerts[7], cubeVerts[4])};
