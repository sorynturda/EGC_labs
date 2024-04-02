#include "clip.h"

namespace egc {

std::vector<int> computeCSCode(std::vector<vec3> clipWindow, const vec3 p) {
    std::vector<int> code(4, 0);
    //TO DO - compute the code for the point given as argument

    if (p.y < clipWindow[0].y) code[0] = 1; //top
    if (p.y > clipWindow[2].y) code[1] = 1; //bottom
    if (p.x > clipWindow[2].x) code[2] = 1; //right
    if (p.x < clipWindow[0].x) code[3] = 1; //;eft
    return code;
}

bool simpleRejection(std::vector<int> cod1, std::vector<int> cod2) {
    //TO DO - write the code to determine if the two input codes represent
    //points in the SIMPLE REJECTION case

    for (int i = 0; i < cod1.size(); i++)
        if (cod1[i] == 1 && cod2[i] == 1)
            return true;
    return false;
}

bool simpleAcceptance(std::vector<int> cod1, std::vector<int> cod2) {
    //TO DO - write the code to determine if the two input codes represent
    //points in the SIMPLE ACCEPTANCE case

    for (int i = 0; i < cod1.size(); i++)
        if (cod1[i] == 1 || cod2[i] == 1)
            return false;
    return true;
}

bool is_inside_clipping_area(std::vector<int> cod) {
    for (auto it : cod)
        if (it == 1)
            return false;
    return true;
}

//function returns -1 if the line segment cannot be clipped
int lineClip_CohenSutherland(std::vector<vec3> clipWindow, vec3& p1, vec3& p2) {
    //TO DO - implement the Cohen-Sutherland line clipping algorithm - consult the laboratory work

    bool finished = true;
    int x_min = clipWindow[0].x;
    int x_max = clipWindow[2].x;
    int y_min = clipWindow[0].y;
    int y_max = clipWindow[2].y;
    while (finished) {
        std::vector<int> codp1 = computeCSCode(clipWindow, p1);
        std::vector<int> codp2 = computeCSCode(clipWindow, p2);
        if (simpleRejection(codp1, codp2)) {
            finished = false;
            std::cout << "Ended on SR case\n";
        }
        else {
            if (simpleAcceptance(codp1, codp2)) {
                finished = false;
                std::cout << "Ended on SA case\n";
            }
            else {
                if (is_inside_clipping_area(codp1)) {
                    std::swap(p1, p2);
                    std::swap(codp1, codp2);
                }
                if (codp1[0] == 1 && p1.y != p2.y) {
                    p1.x = p1.x + (p2.x - p1.x) * (y_min - p1.y) / (p2.y - p1.y);
                    p1.y = y_min;
                }
                else if (codp1[1] == 1 && p1.y != p2.y) {
                    p1.x = p1.x + (p2.x - p1.x) * (y_max - p1.y) / (p2.y - p1.y);
                    p1.y = y_max;
                }
                else if (codp1[2] == 1 && p1.x != p2.x) {
                    p1.y = p1.y + (p2.y - p1.y) * (x_max - p1.x) / (p2.x - p1.x);
                    p1.x = x_max;
                }
                else if (codp1[3] == 1 && p1.x != p2.x) {
                    p1.y = p1.y + (p2.y - p1.y) * (x_min - p1.x) / (p2.x - p1.x);
                    p1.x = x_min;
                }

            }
        }
    }
    return 0;
}
}

