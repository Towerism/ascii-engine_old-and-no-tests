#ifndef COMPONENT_H
#define COMPONENT_H

namespace ascii_engine {

  struct Entity;

  struct Component {

    virtual ~Component() { }

    virtual void update() { }

  protected:

    Entity* entity;
  };
}

#endif // COMPONENT_H
