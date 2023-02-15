#include <cstdio>
#include <iostream>

#include "TestVector.hpp"
#include "Vector3.hpp"

using namespace maths;

void testInit(){
    Vector3* v1 = new Vector3();
    Vector3* v2 = new Vector3(0.5f, 0.8f, 0.3f, COLOR);
    Vector3* v3 = new Vector3(v1);

    assert(v1->x() == v3->r());
    assert(v1->g() == v3->y());
    assert(v1->b() == v3->b());
    
    assert(v2->r() == 0.5f);
    v2->r(0.3f);
    assert(v2->r() == 0.3f);

}

void testOp(){
    Vector3* v1 = new Vector3();
    Vector3* v2 = new Vector3(1.0f, 0.0f, 1.0f);

    Vector3 v3 = *v1 + *v2;
    assert(v3.x() == 1.0f && v3.y() == 0.0f && v3.z() == 1.0f);

    v3 = *v1 - *v2;
    assert(v3.x() == -1.0f && v3.y() == 0.0f && v3.z() == -1.0f);

    v3 = *v2/2.0f;
    assert(v3.x() == 0.5f && v3.y() == 0.0f && v3.z() == 0.5f);

    v3 = *v2 * 2.0f;
    assert(v3.x() == 2.0f && v3.y() == 0.0f && v3.z() == 2.0f);

    v3 = v3 * v3;
    assert(v3.x() == 4.0f && v3.y() == 0.0f && v3.z() == 4.0f);

    v3.y(1.0f);
    v3 = v3 / v3;
    assert(v3.x() == 1.0f && v3.y() == 1.0f && v3.z() == 1.0f);
}

void testFun(){
    Vector3* v1 = new Vector3(3.0, 4.0, 0.0);
    
    float f1 = v1->norm();
    assert(f1 == 5.0f);

    Vector3 v2 = v1->normalize();
    assert(v2.x() == 3.0f/5.0f && v2.y() == 4.0f/5.0f && v2.z() == 0.0f);

    f1 = Vector3::dot(*v1, v2);
    assert(f1 == v1->x()*v2.x() + v1->y()*v2.y() + v1->z()*v2.z());

    v2 = Vector3::cross(*v1, v2);
    assert(v2.x() == v1->y()*v2.z() - v1->z()*v2.y() 
        && v2.y() == v1->z()*v2.x() - v1->x()*v2.z() 
        && v2.z() == v1->x()*v2.y() - v1->y()*v2.x()
        );    
}

void testPrint(){
    Vector3* v1 = new Vector3();
    Vector3* v2 = new Vector3(0.8, 0.44, 0.0, COLOR);

    std::cout << *v1 << std::endl;
    std::cout << *v2 << std::endl;
}

void testVector(){
    fprintf(stdout, "##### TESTS VECTORS #####\n");
    fprintf(stdout, "\n\n##### Tests vector init #####\n");
    testInit();
    fprintf(stdout, "##### Tests vector init DONE #####\n");
    fprintf(stdout, "\n\n##### Tests vector operations #####\n");
    testOp();
    fprintf(stdout, "##### Tests vector operations DONE #####\n");
    fprintf(stdout, "\n\n##### Tests vector functions #####\n");
    testFun();
    fprintf(stdout, "##### Tests vector functions DONE #####\n");
    fprintf(stdout, "\n\n##### Tests vector printing #####\n");
    testPrint();
    fprintf(stdout, "##### Tests vector printing DONE #####\n");
    fprintf(stdout, "\n\n##### TESTS VECTORS DONE #####\n");
}