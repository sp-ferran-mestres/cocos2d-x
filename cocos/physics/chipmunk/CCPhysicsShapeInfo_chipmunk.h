/****************************************************************************
 Copyright (c) 2013 cocos2d-x.org
 
 http://www.cocos2d-x.org
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in
 all copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 THE SOFTWARE.
 ****************************************************************************/

#ifndef __CCPHYSICS_SHAPE_INFO_CHIPMUNK_H__
#define __CCPHYSICS_SHAPE_INFO_CHIPMUNK_H__

#include "../CCPhysicsSetting.h"
#if (CC_PHYSICS_ENGINE == CC_PHYSICS_CHIPMUNK)

#include <vector>
#include <map>
#include "chipmunk.h"
#include "CCPlatformMacros.h"

NS_CC_BEGIN

class PhysicsShape;

class PhysicsShapeInfo
{
public:
    void add(cpShape* shape);
    void remove(cpShape* shape);
    void removeAll();
    void setGroup(cpGroup group);
    void setBody(cpBody* body);
    
public:
    PhysicsShape* getShape() const { return _shape; }
    std::vector<cpShape*>& getShapes() { return _shapes; }
    cpBody* getBody() const { return _body; }
    cpGroup getGourp() const { return _group; }
    static std::map<cpShape*, PhysicsShapeInfo*>& getMap() { return _map; }
    static cpBody* getSharedBody() { return _sharedBody; }
    
private:
    PhysicsShapeInfo(PhysicsShape* shape);
    ~PhysicsShapeInfo();
    
private:
    std::vector<cpShape*> _shapes;
    PhysicsShape* _shape;
    cpBody* _body;
    cpGroup _group;
    static std::map<cpShape*, PhysicsShapeInfo*> _map;
    static cpBody* _sharedBody;
    
    friend class PhysicsShape;
};

NS_CC_END

#endif // CC_PHYSICS_ENGINE == CC_PHYSICS_CHIPMUNK
#endif // __CCPHYSICS_SHAPE_INFO_CHIPMUNK_H__
