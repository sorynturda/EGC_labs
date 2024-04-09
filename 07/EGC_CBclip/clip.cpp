#include "clip.h"
#include "vec3.h"
namespace egc {

//Cyrus-Beck clipping algorithm
//clipWindow specifies the vertices that define the clipping area in conterclockwise order
//and can represent any convex polygon
//function returns -1 if the line segment cannot be clipped
int lineClip_CyrusBeck(std::vector<vec3> clipWindow, vec3& p1, vec3& p2) {
    //TO DO - implement the Cyrus-Beck line clipping algorithm - consult the laboratory work
    std::vector<vec3> normals;
    std::vector<vec3> pei;
    float tE = 0.0f;
    float tL = 1.0f;

    for (int i = 0; i < clipWindow.size(); i++) {
        vec3 edge = vec3();
        if (i == clipWindow.size() - 1)
            edge = clipWindow[0] - clipWindow[i];
        else
            edge = clipWindow[i + 1] - clipWindow[i];
        normals.push_back(egc::crossProduct(edge, {0.0f, 0.0f, 1.0f}));
        pei.push_back(clipWindow[i]);
    }
    if (p1 == p2)
        return -1;
    for (int i = 0; i < clipWindow.size(); i++) {
        float ni_dot_d = egc::dotProduct(normals[i], p2 - p1);
        float ni_dot_pei = egc::dotProduct(normals[i], p1 - pei[i]);
        if (ni_dot_d != 0) {
            float t =  -1 * ni_dot_pei / ni_dot_d;
            if (ni_dot_d > 0)
                tE = std::max(tE, t);
            else
                tL = std::min(tL, t);
        }
    }
    if (tE > tL)
        return -1;
    vec3 new_pe = p1 + (p2 - p1) * tE;
    vec3 new_pl = p1 + (p2 - p1) * tL;
    p1 = new_pe;
    p2 = new_pl;
    return 0;
}


}

