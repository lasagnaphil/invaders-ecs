cmake_minimum_required(VERSION 3.3)
project(invaders_ecs)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp Components/Body.h Components/Collider.h Components/Player.h Components/PrimitiveShape.h Components/Sprite.h
        Events/CollisionEvent.h
        Systems/BodySystem.h Systems/CollisionSystem.h DestroyManager.h Systems/PlayerSystem.h Systems/PrimitiveSystem.h Systems/RenderSystem.h Components/Bullet.h EntityFactory.cpp EntityFactory.h InputManager.h Tags.h Components/Enemy.h Systems/EnemySystem.h Game.cpp Game.h Level.cpp Level.h Components/SceneNode.h Components/Transform.h Constants.h Systems/BulletSystem.h)
add_executable(invaders_ecs ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(EntityX REQUIRED)
find_package(SFML 2 REQUIRED audio graphics window system network)
find_package(Thor REQUIRED)

include_directories(include ${ENTITYX_INCLUDE_DIR})
include_directories(include ${SFML_INCLUDE_DIR})
include_directories(include ${THOR_INCLUDE_DIR})

target_link_libraries(invaders_ecs
        ${ENTITYX_LIBRARY}
        ${SFML_LIBRARIES}
        ${THOR_LIBRARY})