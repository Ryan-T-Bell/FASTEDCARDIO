#ifndef FORGE_H
#define FORGE_H

struct Forge {
    int x;
    int y;
};

void MyClass_init(struct MyClass* obj, int x, int y);
void MyClass_setX(struct MyClass* obj, int x);
void MyClass_setY(struct MyClass* obj, int y);
int MyClass_getX(struct MyClass* obj);
int MyClass_getY(struct MyClass* obj);

#endif // FORGE_H
