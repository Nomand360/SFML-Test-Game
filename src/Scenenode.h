#ifndef SCENENODE_H
#define SCENENODE_H
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/System/Time.hpp>
#include <memory>
#include <vector>

class SceneNode : public sf::Transformable, public sf::Drawable, private sf::NonCopyable {
public:
    using Ptr = std::unique_ptr<SceneNode>;

public:
    SceneNode();
    void attachChild(Ptr& child);
    Ptr detachChild(const SceneNode& node);

private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

private:
    std::vector<Ptr> mChildren;
    SceneNode* mParent;
};

#endif // SCENENODE_H
