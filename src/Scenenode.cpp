#include "Scenenode.h"
#include <algorithm>
#include <cassert>

SceneNode::SceneNode()
    : mParent(nullptr)
{
}

void SceneNode::attachChild(SceneNode::Ptr& child)
{
    child->mParent = this;
    mChildren.emplace_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
    auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](const Ptr& p) {
        return p.get() == &node;
    });
    assert(found != mChildren.end());
    Ptr res = std::move(*found);
    res->mParent = nullptr;
    mChildren.erase(found);
    return res;
}

void SceneNode::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    drawCurrent(target, states);
    for (auto& el : mChildren) {
        el->draw(target, states);
    }
}

void SceneNode::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
}
